#include "pidFuzzy.h"
/*****************************************************************************/
//ע1������Ӧģ��pid����Ҫ�ľ��������ѡ��Ҫ����Ӧ�ÿ��ƵĶ������к�
//ע2�����¸���ֵ���޷�ֵ�����ֵ����Ҫ���ݾ����ʹ��������и���
//ע3����Ϊ�ҵĿ��ƶ�����ԱȽϴ��������¸�����ȡֵ��С
//����e:[-5,5]  ec:[-0.5,0.5]

//���ķ�ֵ��С�������ֵ��ʱ�򣬲���PID��������������СʱƵ������������
/*****************************************************************************/


#define NB 									0
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

/**************�������ȣ������Σ�***************/
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
/*****************�������ȣ�������*******************/
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
/*****************�������ȣ������ң�*******************/
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
/****************�����η�ģ��������**********************/
fp32_t uFTri(fp32_t x,fp32_t a,fp32_t b,fp32_t c)
{ 
	fp32_t y,z;
	z=(b-a)*x+a;
	y=c-(c-b)*x;
	return (y+z)/2;
}
/*******************���Σ��󣩷�ģ����***********************/
fp32_t uFTraL(fp32_t x,fp32_t a,fp32_t b)
{
	return b-(b-a)*x;
}
/*******************���Σ��ң���ģ����***********************/
fp32_t uFTraR(fp32_t x,fp32_t a,fp32_t b)
{
	return (b-a)*x +a;
}
/**************************�󽻼�****************************/
fp32_t fand(fp32_t a,fp32_t b)
{
	return (a<b)?a:b;
}
/**************************�󲢼�****************************/
fp32_t forr(fp32_t a,fp32_t b)
{
	return (a<b)?b:a;
}
fp32_t ec;

int16_t pidFuzzyRealize(pidFuzzy_t *p, fp32_t set, fp32_t fb)
{//PID���㲿��   
	
	//���������ȱ�
	fp32_t es[7], ecs[7], e;
	fp32_t form[7][7];
	int i=0, j=0;
	int MaxX=0, MaxY=0;
	//��¼������������Ӧ������p��i��dֵ
	fp32_t lsd;
	int temp_p, temp_d, temp_i;
	fp32_t detkp, detkd, detki;//�����Ľ��
	
	p->error = set - fb; // ƫ��
	e = p->error;
	ec = e - p->error1;
	

	//����iError��es��ecs�и����������
	es[NB] = FTraL(e*5, -3, -1);  //e 
	es[NM] = FTri(e*5, -3, -2, 0);
	es[NS] = FTri(e*5, -3, -1, 1);
	es[ZO] = FTri(e*5, -2, 0, 2);
	es[PS] = FTri(e*5, -1, 1, 3);
	es[PM] = FTri(e*5, 0, 2, 3);
	es[PB] = FTraR(e*5, 1, 3);

	ecs[NB] = FTraL(ec * 30, -3, -1);//ec
	ecs[NM] = FTri(ec * 30, -3, -2, 0);
	ecs[NS] = FTri(ec * 30, -3, -1, 1);
	ecs[ZO] = FTri(ec * 30, -2, 0, 2);
	ecs[PS] = FTri(ec * 30, -1, 1, 3);
	ecs[PM] = FTri(ec * 30, 0, 2, 3);
	ecs[PB] = FTraR(ec * 30, 1, 3);

	//���������ȱ�ȷ��e��ec�����������������ȵ�ֵ
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			form[i][j]=fand(es[i],ecs[j]);
		}
	}

	//ȡ��������������ȵ���һ��
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
	//����ģ��������ȥģ��
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

	//pid����ϵ�����޸�
	p->Kp_SA += detkp;
	p->Ki_SA += detki;
	p->Kd_SA += detkd;
	
	//��Kp,Ki�����޷�
	if(p->Kp_SA < 0)
		p->Kp = 0;
	if(p->Ki_SA < 0)
		p->Ki_SA = 0;
	
	
	//dout = Kp*{e(n) - e(n-1)} + Ki*e(n) + Kd*{e(n) -2*e(n-1) + e(n-2)}
	p->dout = p->Kp_SA * (p->error - p->error1);
	p->dout += p->Ki_SA * p->error;
	p->dout -=  p->Kd_SA * (p->error - (2 * p->error1) + p->error2);
	p->error2 = p->error1; 
	p->error1 = p->error;
	return p->dout;

}



void pidFuzzyInit(pidFuzzy_t *p, fp32_t Kp, fp32_t Ki, fp32_t Kd)
{
	p->Kp = Kp;
	p->Ki = Ki;
	p->Kd = Kd;
	p->Kp_SA = Kp;
	p->Ki_SA = Ki;
	p->Kd_SA = Kd;

}