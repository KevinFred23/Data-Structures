#include<stdio.h>
void student(int n)
{
	int *s,i;
	s = malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&s[i]);
    printf("\n");
	for(i=0;i<n;i++)
    printf("%d\n",s[i]);	
}

main()
{
	int n;
	scanf("%d",&n);
	student(n);
}
