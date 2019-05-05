//fibonacci series 
// 0 1 1 2 3 5 8 13 21 ......

#include<stdio.h>
void fib(int n)
{
	int i,c=0,a=0,b=1;
	for(i=0;i<n;i++)
	{
		if(c<=1&&a==0)
			printf("%d ",c++);
	    else
	    {
	    	c = a+b;
	    	printf("%d ",c);
	    	a=b;
	    	b=c;
		}
	}
}

main()
{
	int n;
	scanf("%d",&n);
	fib(n);
}
