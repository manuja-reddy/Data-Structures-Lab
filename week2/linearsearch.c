#include<stdio.h>
int linearsearch(int a[50],int n,int key)
{
	int i,pos=-1;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			pos=i;
			break;
		}
	}
	return pos;
}
int main()
{
	int n,key,pos,i,a[100];
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
	
