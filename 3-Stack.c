#include<stdio.h>
#define MALLOC(p,s)\
if(!(p=malloc(s)))\
printf("Error allocating memory!\n");
int *s;
int capacity=1;
int top=-1;

void stackfull()
{
realloc(s,2*capacity*sizeof(int));
capacity*=2;	
}

void push(int item)
{
	if(top>=capacity)
	stackfull();
	s[++top] = item;
}

int pop()
{
	if(top==-1)
	return -1;
	return s[top--];
}

void display()
{
	int i;
	if(top==-1)
	printf("Empty Stack!\n");
	else{
	for(i=top;i>=0;i--)
	printf("%d\n",s[i]);
}}

main()
{MALLOC(s,sizeof(capacity*sizeof(int)));
	int ch;
	while(1)
	{
	printf("1.Push\n2.Pop\n3.Display\n::"); scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter data : "); scanf("%d",&ch);
		        push(ch);
		        break;
		case 2: ch = pop();
		        if(ch!=-1)
		        printf("Popped %d",ch);
                else
                printf("Empty Stack!\n");
                break;
        case 3: display();
                break;
        default:continue;
	}           
}}
