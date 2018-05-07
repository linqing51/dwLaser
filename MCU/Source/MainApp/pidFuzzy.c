#include "pidFuzzy.h"
/*****************************************************************************/
//注1：自适应模糊pid最重要的就是论域的选择，要和你应该控制的对象相切合
//注2：以下各阀值、限幅值、输出值均需要根据具体的使用情况进行更改
//注3：因为我的控制对象惯性比较大，所以以下各部分取值较小
//论域e:[-5,5]  ec:[-0.5,0.5]

//误差的阀值，小于这个数值的时候，不做PID调整，避免误差较小时频繁调节引起震荡
/*****************************************************************************/

#define NB 0
#define NM 1
#define NS 2
#define ZO 3
#define PS 4
#define PM 5
#define PB 6

int kp[7][7]={	{PB,PB,PM,PM,PS,ZO,ZO},
				{PB,PB,PM,PS,PS,ZO,ZO},
				{PM,PM,PM,PS,ZO,NS,NS},
				{PM,PM,PS,ZO,NS,NM,NM},
				{PS,PS,ZO,NS,NS,NM,NM},
				{PS,ZO,NS,NM,NM,NM,NB},
				{ZO,ZO,NM,NM,NM,NB,NB}    };

int kd[7][7]={	{PS,NS,NB,NB,NB,NM,PS},
				{PS,NS,NB,NM,NM,NS,ZO},
				{ZO,NS,NM,NM,NS,NS,ZO},
				{ZO,NS,NS,NS,NS,NS,ZO},
				{ZO,ZO,ZO,ZO,ZO,ZO,ZO},
				{PB,NS,PS,PS,PS,PS,PB},
				{PB,PM,PM,PM,PS,PS,PB}    };

int ki[7][7]={	{NB,NB,NM,NM,NS,ZO,ZO},
				{NB,NB,NM,NS,NS,ZO,ZO},
				{NB,NM,NS,NS,ZO,PS,PS},
				{NM,NM,NS,ZO,PS,PM,PM},
				{NM,NS,ZO,PS,PS,PM,PB},
				{ZO,ZO,PS,PS,PM,PB,PB},
				{ZO,ZO,PS,PM,PM,PB,PB}    };

/**************求隶属度（三角形）***************/
fp32_t FTri(fp32_t x,fp32_t a,fp32_t b,fp32_t c)//FuzzyTriangle
{
	if(x<=a)
		return 0;
	else if((a<x)&&(x<=b))
		return (x-a)/(b-a);
	else if((b<x)&&(x<=c))
		return (c-x)/(c-b);
	else if(x>c)
		return 0;
	else
		return 0;
}
/*****************求隶属度（梯形左）*******************/
fp32_t FTraL(fp32_t x,fp32_t a,fp32_t b)//FuzzyTrapezoidLeft
{
	if(x<=a)  
		return 1;
	else if((a<x)&&(x<=b))
		return (b-x)/(b-a);
	else if(x>b)
		return 0;
	else
		return 0;
}
/*****************求隶属度（梯形右）*******************/
fp32_t FTraR(fp32_t x,fp32_t a,fp32_t b)//FuzzyTrapezoidRight
{
	if(x<=a)
		return 0;
	if((a<x)&&(x<b))
		return (x-a)/(b-a);
	if(x>=b)
		return 1;
	else
		return 1;
}
/****************三角形反模糊化处理**********************/
fp32_t uFTri(fp32_t x,fp32_t a,fp32_t b,fp32_t c)
{ 
	fp32_t y,z;
	z=(b-a)*x+a;
	y=c-(c-b)*x;
	return (y+z)/2;
}
/*******************梯形（左）反模糊化***********************/
fp32_t uFTraL(fp32_t x,fp32_t a,fp32_t b)
{
	return b-(b-a)*x;
}
/*******************梯形（右）反模糊化***********************/
fp32_t uFTraR(fp32_t x,fp32_t a,fp32_t b)
{
	return (b-a)*x +a;
}
/**************************求交集****************************/
fp32_t fand(fp32_t a,fp32_t b)
{
	return (a<b)?a:b;
}
/**************************求并集****************************/
fp32_t forr(fp32_t a,fp32_t b)
{
	return (a<b)?b:a;
}
fp32_t ec;
 
int16_t pidFuzzyRealize(pidFuzzy_t *structpid,uint16_t s,uint16_t in)
{//PID计算部分
	fp32_t pwm_var;//pwm调整量
	fp32_t iError;//当前误差
	fp32_t set, input;
	
	//计算隶属度表
	fp32_t es[7], ecs[7],e;
	fp32_t form[7][7];
	int i=0,j=0;
	int MaxX=0, MaxY=0;
	
	//记录隶属度最大项及相应推理表的p、i、d值
	fp32_t lsd;
	int temp_p, temp_d, temp_i;
	fp32_t detkp, detkd, detki;//推理后的结果
	
	//输入格式的转化及偏差计算
	set=(fp32_t)s/100.0;
	input=(fp32_t)in/100.0;
	iError = set - input; // 偏差
	
	e = iError;
	ec = iError - structpid->LastError;
	
	//当温度差的绝对值小于Emax时，对pid的参数进行调整
	if(fabs(iError)<=CONFIG_PID_FUZZY_EMAX)
	{
		//计算iError在es与ecs中各项的隶属度
		es[NB]=FTraL(e*5,-3,-1);  //e 
		es[NM]=FTri(e*5,-3,-2,0);
		es[NS]=FTri(e*5,-3,-1,1);
		es[ZO]=FTri(e*5,-2,0,2);
		es[PS]=FTri(e*5,-1,1,3);
		es[PM]=FTri(e*5,0,2,3);
		es[PB]=FTraR(e*5,1,3);

		ecs[NB]=FTraL(ec*30,-3,-1);//ec
		ecs[NM]=FTri(ec*30,-3,-2,0);
		ecs[NS]=FTri(ec*30,-3,-1,1);
		ecs[ZO]=FTri(ec*30,-2,0,2);
		ecs[PS]=FTri(ec*30,-1,1,3);
		ecs[PM]=FTri(ec*30,0,2,3);
		ecs[PB]=FTraR(ec*30,1,3);
	
		//计算隶属度表，确定e和ec相关联后表格各项隶属度的值
		for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
			{
				form[i][j]=fand(es[i],ecs[j]);
			}
		}
	
		//取出具有最大隶属度的那一项
		for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
			{
				if(form[MaxX][MaxY]<form[i][j]) 
				{
					MaxX=i;
					MaxY=j;
				}
			}
		}
		//进行模糊推理，并去模糊
		lsd=form[MaxX][MaxY];
		temp_p=kp[MaxX][MaxY];
		temp_d=kd[MaxX][MaxY];   
		temp_i=ki[MaxX][MaxY];
	
		if(temp_p==NB)
			detkp=uFTraL(lsd,-0.3,-0.1);
		else if(temp_p==NM)
			detkp=uFTri(lsd,-0.3,-0.2,0);
		else if(temp_p==NS)
			detkp=uFTri(lsd,-0.3,-0.1,0.1);
		else if(temp_p==ZO)
			detkp=uFTri(lsd,-0.2,0,0.2);
		else if(temp_p==PS)
			detkp=uFTri(lsd,-0.1,0.1,0.3);
		else if(temp_p==PM)
			detkp=uFTri(lsd,0,0.2,0.3);
		else if(temp_p==PB)
			detkp=uFTraR(lsd,0.1,0.3);

		if(temp_d==NB)
			detkd=uFTraL(lsd,-3,-1);
		else if(temp_d==NM)
			detkd=uFTri(lsd,-3,-2,0);
		else if(temp_d==NS)
			detkd=uFTri(lsd,-3,1,1);
		else if(temp_d==ZO)
			detkd=uFTri(lsd,-2,0,2);
		else if(temp_d==PS)
			detkd=uFTri(lsd,-1,1,3);
		else if(temp_d==PM)
			detkd=uFTri(lsd,0,2,3);
		else if(temp_d==PB)
			detkd=uFTraR(lsd,1,3);

		if(temp_i==NB)
			detki=uFTraL(lsd,-0.06,-0.02);
		else if(temp_i==NM)
			detki=uFTri(lsd,-0.06,-0.04,0);
		else if(temp_i==NS)
			detki=uFTri(lsd,-0.06,-0.02,0.02);
		else if(temp_i==ZO)
			detki=uFTri(lsd,-0.04,0,0.04);
		else if(temp_i==PS)
			detki=uFTri(lsd,-0.02,0.02,0.06);
		else if(temp_i==PM)
			detki=uFTri(lsd,0,0.04,0.06);
		else if (temp_i==PB)
			detki=uFTraR(lsd,0.02,0.06);

		//pid三项系数的修改
		structpid->Kp+=detkp;
		structpid->Ki+=detki;
		//structpid->Kd+=detkd;
		structpid->Kd=0;//取消微分作用
		
		//对Kp,Ki进行限幅
		if(structpid->Kp<0)
		{
			structpid->Kp=0;
		}
		if(structpid->Ki<0)
		{
			structpid->Ki=0;
		}
		
		//计算新的K1,K2,K3
		structpid->K1=structpid->Kp+structpid->Ki+structpid->Kd;
		structpid->K2=-(structpid->Kp+2*structpid->Kd);
		structpid->K3=structpid->Kd;
	}
	
	if(iError>CONFIG_PID_FUZZY_EMAX)
	{
		structpid->pwm_out=7200;
		pwm_var = 0;
		structpid->flag=1;//设定标志位，如果误差超过了门限值，则认为当控制量第一次到达给定值时，应该采取下面的 抑制超调 的措施
	}
	else if(iError<-CONFIG_PID_FUZZY_EMAX)
	{
		structpid->pwm_out=0;
		pwm_var = 0;
	}
	else if( fabs(iError) < CONFIG_PID_FUZZY_EMIN ) //误差的阀值(死区控制??)
	{
		pwm_var = 0;
	}
	else
	{
		if( iError<CONFIG_PID_FUZZY_EMID && structpid->flag==1 )//第一次超过(设定值-Emid(-0.08)摄氏度)，是输出为零，防止超调，也可以输出其他值，不至于太小而引起震荡
		{
			structpid->pwm_out=0;
			structpid->flag=0;
		}
		else if( -iError>CONFIG_PID_FUZZY_EMID)//超过(设定+Emid(+0.08)摄氏度)
		{
			pwm_var=-1;
		}
		else
		{
			//增量计算
			pwm_var=(structpid->K1 * iError  //e[k]
			+ structpid->K2 * structpid->LastError	//e[k-1]
			+ structpid->K3 * structpid->PrevError);	//e[k-2]
		}
		if(pwm_var >= CONFIG_PID_FUZZY_UMAX)
			pwm_var = CONFIG_PID_FUZZY_UMAX;      //调整值限幅，防止积分饱和
		if(pwm_var <= CONFIG_PID_FUZZY_UMIN)
			pwm_var = CONFIG_PID_FUZZY_UMIN;    	//调整值限幅，防止积分饱和

	}
	structpid->PrevError = structpid->LastError;
	structpid->LastError = iError;
	
	structpid->pwm_out += 360*pwm_var;        //调整PWM输出
  
	if(structpid->pwm_out > CONFIG_PID_FUZZY_PMAX)
		structpid->pwm_out = CONFIG_PID_FUZZY_PMAX;    //输出值限幅
	if(structpid->pwm_out < CONFIG_PID_FUZZY_PMIN)
		structpid->pwm_out = CONFIG_PID_FUZZY_PMIN;    //输出值限幅
	return (int16_t)(structpid->pwm_out); // 微分项
}

void pidFuzzySet(pidFuzzy_t *structpid, fp32_t Kp, fp32_t Ki, fp32_t Kd, fp32_t T)
{
	(*structpid).Kp=Kp;//Kp*(1+(Td/T));
	(*structpid).Ki=Ki;
	(*structpid).Kd=Kd;
	(*structpid).T=T;
	
	structpid->K1 = structpid->Kp * (1 + structpid->Ki + structpid->Kd);
	structpid->K2 = -(structpid->Kp + 2 * structpid->Kp * structpid->Kd);
	structpid->K3 = structpid->Kp * structpid->Kd;
}

void pidFuzzyInit(pidFuzzy_t *structpid)
{
	pidFuzzySet(structpid, 8.3, 1.2, 0,1);
	structpid->flag=0;
	structpid->pwm_out=0;
}