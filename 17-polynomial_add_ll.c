#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
if(!(p=malloc(s)))\
printf("Error")
#define COMPARE(a,b) ((a>b)?1:(a<b)?-1:0)
struct node
{
	int exp;
	float coef;
	struct node *link;
};
typedef struct node *ptr;
void attach(float coef,int exp,ptr *p)
{
	ptr temp;
	MALLOC(temp,sizeof(ptr));
	temp->coef = coef;
	temp->exp = exp;
	(*p)->link = temp;
	(*p) = temp;
	(*p)->link = NULL;
}
ptr cadd(ptr a,ptr b)
{
	ptr c,lastc,starta;
	float sum;
	int done=0;
	starta = a;
	a=a->link;
	b=b->link;
	MALLOC(c,sizeof(ptr));
	c->exp=-1;
	lastc=c;
	do
	{
		switch(COMPARE(a->exp,b->exp))
		{
			case 1:attach(a->coef,a->exp,&lastc);
			       a=a->link;
			       break;
			case -1:attach(b->coef,b->exp,&lastc);
			       b=b->link;
			       break;
			case 0:if(starta==a) done=1;
			else{
			sum = a->coef + b->coef;
			       if(sum)
			       attach(sum,a->exp,&lastc);
			       a=a->link;
			       b=b->link;}
			       break;
		}
	}while(!done);
	lastc->link = c;
	return c;
}
void print(ptr k)
{k=k->link;
	while(((k->link)->exp)!=-1)
	{
		printf("%fx^%d + ",k->coef,k->exp);
	k=k->link;
	}
	printf("%fx^%d + ",k->coef,k->exp);
	printf("\n");
}
main()
{float co;
	int n,i,e;
	ptr a,a_,b,b_,c;
    MALLOC(a,sizeof(ptr));
    a->exp = -1;
    MALLOC(b,sizeof(ptr));
    b->exp = -1;
    a_=a;
    b_=b;
	printf("\nN(a) = "); scanf("%d",&n);
	printf("\na = ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		scanf("%f",&co);
		attach(co,e,&a_);
	}(a_)->link=a;
	printf("\nN(b) = "); scanf("%d",&n);
	printf("\nb = ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		scanf("%f",&co);
		attach(co,e,&b_);
	}(b_)->link=b;
	c = cadd(a,b);
	print(c);
}
