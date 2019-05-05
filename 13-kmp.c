//end indices
#include<stdio.h>
#include<string.h>
char string[100];
char pat[100];
int failure[100];

void fail()
{
	int i=0,j=0,lastp = strlen(pat);
	failure[0]=-1;
	for(j=1;j<lastp;j++)
	{
		i = failure[j-1];
		while((pat[j]!=pat[i+1])&& (i>=0))
		i=failure[i];
		if(pat[j]==pat[i+1])
		failure[j] = i+1;
		else
		failure[j] = -1;
	}
}
int find()
{
	int i=0,j=0,lasts=strlen(string),lastp=strlen(pat);
    while((i<lasts) && (j<lastp))
	{
	if(string[i] == pat[j]){
		i++;j++;
	}	
	else if(j==0) i++;
	else j=failure[j-1]+1;
	}	
	return ((j==lastp)?(i-lastp):-1);
}
main()
{while(1){
	printf("String - ");
	scanf("%s",string);
	printf("\nPattern - ");
	scanf("%s",pat);
	fail();
	printf("\n Found at location - %d\n\n",find());
}
}
