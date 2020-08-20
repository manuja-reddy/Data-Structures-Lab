#include<stdio.h>
int binarysearch(int first,int last,int a[50],int key)
{
	int pos=-1,mid;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(a[mid]==key)
		{
			pos = mid;
			break;
		}
		else if(a[mid]<key)
			first = mid + 1;
		else
			last = mid - 1;
	}
	return pos;	
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
	pos=binarysearch(0,n-1,a,key);
	if(pos==-1)
	printf("element not found\n");
	else
	printf("element found at %d location",pos+1);
}
	