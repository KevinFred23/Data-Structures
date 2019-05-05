#include<stdio.h>
int  a[10];
// recursive function
 
int search(int key, int top, int bottom)
{
	int middle = (top+bottom)/2  ;
	if(top<bottom)
	{
		if(a[middle] == key)
		return middle+1;
		else if(a[middle] < key)
		return search(key,middle+1,bottom);
		else
		return search(key,top,middle-1);
	}
	return -1;
}

// Non - recursive function
int search_(int key, int top, int bottom)
{
	int middle = (top+bottom)/2  ;
	while(top<bottom)
	{   middle = (top+bottom)/2  ;
		if(a[middle] == key)
		return middle+1;
		else if(a[middle] < key)
		top = middle+1;
		else
		bottom = middle-1;
	}
	return -1;
}

int main()
{
	int i,n,ch,k;
	printf("Size - "); scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
while(1){
	printf("Key to be searched - "); scanf("%d",&k);
	printf("Choice \n1.Recursive 2.Non-Recursive :: ");
	scanf("%d",&ch);
	if(ch==1)
	i = search(k,0,n);
	else if(ch==2)
	i = search_(k,0,n);
	if(i!=-1)
	printf("Found at %d",i);
	else
	printf("Key not found!!",i);
}
}
