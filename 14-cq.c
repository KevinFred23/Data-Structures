#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
if(!(p=malloc(s)))\
printf("Error")
typedef struct
{
	int data;
}element;

element *q=NULL;
int front=0;
int rear=0;
int size=2;
void create()
{
	MALLOC(q,size*sizeof(element));
}
void copy(element *start,element *end,element *nq)
{
	while(start!=end)
	{
		*nq = *start;
		nq++;
		start++;
	}
}
void queuefull()
{
	element* nq;
	MALLOC(nq,2*size*sizeof(element));
	int start =(front+1)%size;
	if(start<2) //Nowrap around
	copy(q+start,q+start+size-1,nq);
	else
	{
		copy(q+start,q+size,nq);
		copy(q,q+rear+1,nq+size-start);
	}
	front = 2*size-1;
	rear = size-2;
	size*=2;
	free(q);
	q=nq;
}

void add(int item)
{
	rear = (rear+1)%size;
	if(front==rear){
	queuefull();
	rear = (rear+1)%size;
}
	q[rear].data = item;
}

void del()
{
	if(front==rear) printf("Empty queue");
	else
	{   
	    front = (front+1)%size;
		printf("Deleted %d\n",q[front].data);
	}
}

void display()
{int i;
	if(front==rear)
	printf("Empty Queue");
	else
	{
		for(i=(front+1)%size;i!=rear;i=(i+1)%size)
		printf("%d\n",q[i].data);
		printf("%d\n",q[i].data);
	}
}

main()
{create();
	int ch,i=1;
	while(1)
	{i++;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add(i);break;
			case 2: del();break;
			case 3: display();break;
			default: continue;
		}
	}
}
