#include<stdio.h>
typedef struct
{
	int row;
	int col;
	int val;
}matrix;
matrix a[100],b[100];

void read()
{
	int i;
	printf("Number of rows and columns? :: "); scanf("%d",&a[0].row);
	scanf("%d",&a[0].col);
	printf("\nNumber of non zero elements :: "); scanf("%d",&a[0].val);
	for(i=1;i<=a[0].val;i++)
	{
		scanf("%d",&a[i].row);
		scanf("%d",&a[i].col);
		scanf("%d",&a[i].val);
	}
}

void fast()
{int i,j;
	int rowt[100],start[100];
	int c=a[0].col,n=a[0].val;
	b[0].col = a[0].row; 
	b[0].row = a[0].col;
	b[0].val = a[0].val;
	for(i=0;i<c;i++) rowt[i]=0;
	for(i=1;i<=n;i++) rowt[a[i].col]++;
	start[0]=1;
	for(i=1;i<c;i++) start[i] = start[i-1]+rowt[i-1];
	for(i=1;i<=n;i++)
	{
		j=start[a[i].col]++;
		b[j].row=a[i].col;
		b[j].col=a[i].row;
		b[j].val=a[i].val;
	}
}

void display()
{
	int i;
	printf("\nB Matrix\n");
	for(i=0;i<=b[0].val;i++)
	{if(i==0)
		printf("**********\n%d   %d   %d\n**********\n",b[i].row,b[i].col,b[i].val);
	else
	printf("%d   %d   %d\n",b[i].row,b[i].col,b[i].val);
}}

main()
{
	read();
	fast();
	display();
}
