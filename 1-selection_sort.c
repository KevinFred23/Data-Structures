#include<stdio.h>
int* sort(int *a,int n)
{
	int i,j,index,small;
	small = a[0];
	for(i=0;i<n;i++)
	{
		index = i;
		for(j=i+1;j<n;j++)
		if(a[j]<a[index])
        index = j;
        if(i!=index)
        {
        	small = a[i];
        	a[i] = a[index];
        	a[index] = small;
		}
	}
	return a;
}
main()
{
	int a[10],i;
	int *m,n;
	printf("Size : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	m = sort(a,n);
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);	
}
