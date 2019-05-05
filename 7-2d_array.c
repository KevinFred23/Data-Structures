#include<stdio.h>
void student(int n)
{
	int **a,i,j;
	a = (int **)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{a[i] = (int *)malloc(3*sizeof(int));
		printf("Student-%d\n",i+1);
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		printf("\n");
	}
	printf("***************************************************");
	for(i=0;i<n;i++)
	{
		printf("Student-%d\n",i+1);
		for(j=0;j<3;j++)
			printf("%d\n",a[i][j]);
		printf("\n");
	}
	
}

main()
{
	int n;
	scanf("%d",&n);
	student(n);
}
