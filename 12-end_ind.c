//end indices
#include<stdio.h>
#include<string.h>
char string[100];
char pat[100];
int find()
{
	int i,j,start=0,lasts=strlen(string)-1,lastp=strlen(pat)-1,endmatch=lastp;
	for(i=0;endmatch<=lasts;start++,endmatch++)
	{
		if(string[endmatch] == pat[lastp])
		for(j=0,i=start;(j<lastp) && (string[i]==pat[j]);i++,j++);
		if(j==lastp)
		return start; 
	}
	return -1;	
}
main()
{while(1){
	printf("String - ");
	scanf("%s",string);
	printf("\nPattern - ");
	scanf("%s",pat);
	printf("\n Found at location - %d\n\n",find());
}
}
