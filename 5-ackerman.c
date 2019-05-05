#include<stdio.h>
int ack(int x,int y)
{
	int ans;
	if(x==0)
	return y+1;
	else if(y==0)
    return ack(x-1,1);
	else
	return ack(x-1,ack(x,y-1));	
}

main()
{
	int m,n,ans;
	scanf("%d%d",&m,&n);
	ans = ack(m,n);
	printf("%d",ans);
}
