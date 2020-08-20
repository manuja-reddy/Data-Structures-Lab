#include<stdio.h>
int binarysearch(int first,int last,int a[50],int key)
{
	int pos=-1, mid;
	if(first<=last)
	{
		mid=(first+last)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]<key)
			binarysearch(mid+1,last,a,key);
		else
			binarysearch(first,mid-1,a,key);	
	}
	else 
		return pos;	
}	
int main()
{
	int n,pos,key,i,a[100],mid;
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
	
