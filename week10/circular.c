#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node*head = NULL,*cur,*temp,*t1,*t2;
void create()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current data: ");
	scanf("%d",&cur->data);
	cur->link = cur;
	if(head==NULL)
		head=cur;
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			temp=temp->link;
		}
		temp->link=cur;
		cur->link=head;
	}

}
void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter current data: ");
	scanf("%d",&cur->data);
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=cur;
	cur->link=head;
	head=cur; //not required for insert at end
}
void insert_at_pos()
{
	int c=1,pos;
	printf("Enter the position : ");
	scanf("%d",&pos);
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter current data: ");
	scanf("%d",&cur->data);
	t1 = head;
	while(c < pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=cur;
	cur->link=t1;
}
void delete_at_begin()
{
	cur=temp = head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=head->link;
	head=cur->link;
	cur->link=NULL;
	printf("Deleted element : %d",cur->data);
	free(cur);
}
void delete_at_end()
{
	t1=head;
	while(t1->link!=head)
	{
		t2=t1;
		t1=t1->link;
	}
		t2->link=head;
		t1->link=NULL;
		printf("Deleted element : %d",t1->data);
		free(t1);
}
void delete_at_pos()
{
	int c=1,pos;
	printf("Enter position of deletion : ");
	scanf("%d",&pos);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=t1->link;
	t1->link=NULL;
	printf("Deleted element %d : ",t1->data);
	free(t1);
}
void display()
{
	if(head==NULL)
	printf("CIRCULAR LINKED LIST is empty");
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			printf("%d->",temp->data);
			temp=temp->link;
		}
			printf("%d",temp->data);
	}
}	
int main()
{
	int ch;
	while(1)
	{
		printf("\n1-Create\n2-Insert at begin\n3-Insert at position\n4-Delete at begin\n5-Delete at end\n6-Delete at position\n7-Traversal\n8-Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_pos();
				break;
			case 4: delete_at_begin();
				break;
			case 5: delete_at_end();
				break;
			case 6: delete_at_pos();
				break;
			case 7:display();
				break;
			case 8: exit(0);

	}
	}
}