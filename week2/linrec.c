#include<stdio.h>
int linearsearch(int a[50],int n,int key)
{
	static int i;
	if(a[i]==key)
		return i;
	else if(i<n)
	{
		i++;
		linearsearch(a,n,key);
	}
	else
		return -1;	
}	
int main()
{
	int n,pos,key,i,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	pos=linearsearch(a,n,key);
	if(pos==-1)
	printf("element not found\n");
	else
	printf("element found at %d location",pos+1);
}
	