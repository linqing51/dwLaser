#include "pidFuzzy.h"
/*****************************************************************************/
//注1：自适应模糊pid最重要的就是论域的选择，要和你应该控制的对象相切合
//注2：以下各阀值、限幅值、输出值均需要根据具体的使用情况进行更改
//注3：因为我的控制对象惯性比较大，所以以下各部分取值较小
//论域e:[-5,5]  ec:[-0.5,0.5]

//误差的阀值，小于这个数值的时候，不做PID调整，避免误差较小时频繁调节引起震荡
/*****************************************************************************/


#define NB 			-3
#define NM 			-2
#define NS 			-1
#define ZO 			0
#define PS 			1
#define PM 			2
#define PB 			3

int deltaKpMatrix[7][7]={	
				{PB,PB,PM,PM,PS,ZO,ZO},
				{PB,PB,PM,PS,PS,ZO,ZO},
				{PM,PM,PM,PS,ZO,NS,NS},
				{PM,PM,PS,ZO,NS,NM,NM},
				{PS,PS,ZO,NS,NS,NM,NM},
				{PS,ZO,NS,NM,NM,NM,NB},
				{ZO,ZO,NM,NM,NM,NB,NB}};

int deltaKdMatrix[7][7]={	
				{PS,NS,NB,NB,NB,NM,PS},
				{PS,NS,NB,NM,NM,NS,ZO},
				{ZO,NS,NM,NM,NS,NS,ZO},
				{ZO,NS,NS,NS,NS,NS,ZO},
				{ZO,ZO,ZO,ZO,ZO,ZO,ZO},
				{PB,NS,PS,PS,PS,PS,PB},
				{PB,PM,PM,PM,PS,PS,PB}};

int deltaKiMatrix[7][7]={	
				{NB,NB,NM,NM,NS,ZO,ZO},
				{NB,NB,NM,NS,NS,ZO,ZO},
				{NB,NM,NS,NS,ZO,PS,PS},
				{NM,NM,NS,ZO,PS,PM,PM},
				{NM,NS,ZO,PS,PS,PM,PB},
				{ZO,ZO,PS,PS,PM,PB,PB},
				{ZO,ZO,PS,PM,PM,PB,PB}};

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

fp32_t pidFuzzyRealize(pidFuzzy_t *p, fp32_t set, fp32_t fb)
{//PID计算部分   
	
	//计算隶属度表
	fp32_t es[7], ecs[7], e, ec;
	fp32_t form[7][7];
	int i=0, j=0;
	int MaxX=0, MaxY=0;
	//记录隶属度最大项及相应推理表的p、i、d值
	fp32_t lsd;
	int temp_p, temp_d, temp_i;
	fp32_t detkp, detkd, detki;//推理后的结果
	
	p->error = set - fb; // 偏差
	e = p->error;
	ec = e - p->error1;
	
	//计算iError在es与ecs中各项的隶属度
	es[0] = FTraL(e, -3, -1);  //e 
	es[1] = FTri(e, -3, -2, 0);
	es[2] = FTri(e, -3, -1, 1);
	es[3] = FTri(e, -2, 0, 2);
	es[4] = FTri(e, -1, 1, 3);
	es[5] = FTri(e, 0, 2, 3);
	es[6] = FTraR(e, 1, 3);

	ecs[0] = FTraL(ec, -3, -1);//ec
	ecs[1] = FTri(ec, -3, -2, 0);
	ecs[2] = FTri(ec, -3, -1, 1);
	ecs[3] = FTri(ec, -2, 0, 2);
	ecs[4] = FTri(ec, -1, 1, 3);
	ecs[5] = FTri(ec, 0, 2, 3);
	ecs[6] = FTraR(ec, 1, 3);

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
	lsd = form[MaxX][MaxY];
	temp_p = deltaKpMatrix[MaxX][MaxY];
	temp_d = deltaKdMatrix[MaxX][MaxY];   
	temp_i = deltaKiMatrix[MaxX][MaxY];

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
	p->Kp += detkp;
	p->Ki += detki;
	p->Kd += detkd;
	
	////对Kp,Ki进行限幅
	//if(p->Kp_SA < 0)
	//	p->Kp = 0;
	//if(p->Ki_SA < 0)
	//	p->Ki_SA = 0;
	
	//dout = Kp*{e(n) - e(n-1)} + Ki*e(n) + Kd*{e(n) -2*e(n-1) + e(n-2)}
	p->dout = p->Kp * (p->error - p->error1);
	p->dout += p->Ki * p->error;
	p->dout -=  p->Kd * (p->error - (2 * p->error1) + p->error2);
	p->error2 = p->error1; 
	p->error1 = p->error;
	return p->dout;

}



void pidFuzzyInit(pidFuzzy_t *p, fp32_t Kp, fp32_t Ki, fp32_t Kd)
{
	p->Kp = Kp;
	p->Ki = Ki;
	p->Kd = Kd;
}