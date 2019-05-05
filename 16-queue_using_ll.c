#include<stdio.h>
#define MALLOC(p,s)\
if(!(p=malloc(s)))\
printf("Error")
typedef struct block *queue;
typedef struct block
{
	int data;
	queue link;
}block;
queue front,rear;

void push(int i,int a)
{stack temp;
MALLOC(temp,sizeof(temp));
temp->data = a;
temp->link = rear[i];
rear[i] = temp;
if(!front[i])
front[i] = rear[i];
}

void pop(int i)
{
	stack temp;
	if(!front[i]) printf("Empty Queue\n");
	else if(front[i]==rear[i])
	{
	printf("Popped %d\n",front[i]->data);	
	front[i] = rear[i] = NULL;
	}
	else{
	for(temp = rear[i];(temp->link)!=front[i];temp=temp->link);
    printf("Popped %d\n",temp->link->data);
    temp->link = NULL;
    front[i] = temp;
	}
}

void display(int i)
{
	stack temp;
	if(front[i]==NULL)
	printf("Empty Stack\n");
	else{
	for(temp = rear[i];temp!=NULL;temp = temp->link)
	printf("%d\n",temp->data);
}
}

main()
{
	int ch,i;
	while(1)
	{scanf("%d",&i);
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:scanf("%d",&ch);
			       push(i,ch); break;
			case 2:pop(i);break;
			case 3:display(i);
		}
	}
}

