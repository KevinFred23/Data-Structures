// polynomial addition
#include<stdio.h>
#define COMPARE(a,b) ((a>b)?1:(a<b)?-1:0)
#define MAX 100
typedef struct
{
float coef;
int exp;	
}poly;

poly terms[MAX];
int avail=0;

void attach(float coef,int exp)
{
	if(avail==MAX)
	{
		printf("Maximum terms reached!\n"); return;
	}
	terms[avail].coef=coef;
	terms[avail++].exp=exp;
}

void padd(int starta,int finisha,int startb,int finishb,int *startd,int *finishd)
{
	float sum;
	*startd = avail;
	while(starta<=finisha && startb<=finishb)
	{
		switch(COMPARE(terms[starta].exp,terms[startb].exp))
		{
			case 1 :attach(terms[starta].coef,terms[starta].exp);
			        starta++;
			        break;
			case -1:attach(terms[startb].coef,terms[startb].exp);
			        startb++;
			        break;
			case 0 :sum = terms[starta].coef+terms[startb].coef;
			        if(sum) attach(sum,terms[startb].exp);
			        starta++;
					startb++;
					break;
		}
	}
	for(;starta<=finisha;starta++) attach(terms[starta].coef,terms[starta].exp);
	for(;startb<=finishb;startb++) attach(terms[startb].coef,terms[startb].exp);
*finishd = avail-1;
}

main()
{
	int i,n,e,a,a_,b,b_,d,d_;
	float co;
	printf("\nN(a) = "); scanf("%d",&n);
	printf("\na = "); a = 0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		scanf("%f",&co);
		attach(co,e);
	}
	a_ = n-1;
	printf("\nN(b) = "); scanf("%d",&n);
	printf("\nb = ");b = a_+1;
	for(i=b;i<b+n;i++)
	{
		scanf("%d",&e);
		scanf("%f",&co);
		attach(co,e);
	}
	b_ = b+n-1;
	padd(a,a_,b,b_,&d,&d_);
	printf("\n\n");
	for(i=d;i<=d_;i++)
	printf("%fx^%d + ",terms[i].coef,terms[i].exp);
	printf("\n");
}
