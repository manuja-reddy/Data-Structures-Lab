#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * link;
};
struct node* top=NULL,*cur,*next;
void push()
{
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%d",(&cur->data));
	cur->link = top;
	top = cur;
}
void pop()
{
	cur = top;
	top = cur->link;
	cur->link= NULL;
	printf("Deleted elementis %d\n",cur->data);
	free (cur);
}
void display()
{
	if(top == NULL)
		printf("list is empty");
	else
	{
		next = top;
		while(next!=NULL)
		{
			printf("%d->",next->data);
			next = next->link;
		}
	}
}
void peek()
{
	printf("top most data is %d ",top->data);
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break; 
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: peek();
				break;
			case 5: exit(0);
		}
	}
}