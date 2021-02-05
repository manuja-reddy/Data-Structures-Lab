#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
	
};
struct node*f=NULL,*r=NULL,*cur;
void enqueue()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to insert:\n");
	scanf("%d",&(cur->data));
	cur->link=NULL;
	if(f==NULL)
		f=r=cur;
	else
	{
		r->link=cur;
		r=cur;
	}
}
void dequeue()
{
	if(f==NULL)
		printf("Queue Underflow.\n");
	else if(f==r)
	{
		printf("Deleted data is %d: \n",f->data);
		f=r=NULL;
	}
	else
	{
		cur=f;
		f=f->link;
		printf("Deleted data is %d  \n",cur->data);
		free(cur);
	}
}
void display()
{
	if(f==NULL)
		printf("Queue is empty");
	else
	{
		cur=f;
		while(cur!=NULL)
		{
			printf("%d -> ",cur->data);
			cur=cur->link;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n\n");
	    printf("PROGRAM FOR QUEUE:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("ENTER YOUR CHOICE:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:exit(0);
		}
	}
}