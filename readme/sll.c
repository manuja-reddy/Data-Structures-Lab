#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head=NULL,*tail=NULL,*cur,*prev,*next;
void create()
{
	int i,n;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%d",&cur->data);
		cur->link=NULL;
		if(head==NULL)
			head=tail=cur;
		else
			tail->link=cur;
			tail=cur;
	}
}		
void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&cur->data);
	next=head;
    cur->link=head;
    head=cur;
}
void insert_at_position()
{
	int pos,c=1;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&(cur->data));
	printf("enter position\n");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=cur;
	cur->link=next;
}
void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter current data\n");
	scanf("%d",&cur->data);
	cur->link=NULL;
	tail->link=cur;
	tail=cur;
}
void insert_before()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&cur->data);
	printf("enter data to insert before node\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!=NULL)
	{
		prev=next;
		next=next->link;
	}
	prev->link=cur;
	cur->link=next;
}
void insert_after()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&cur->data);
	printf("enter data to insert after node\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!=NULL)
	{
		next=next->link;
	}
	cur->link=next->link;
	next->link=cur;
}
void delete_at_begin()
{
	cur=head;
	head=cur->link;
	cur->link=NULL;
	printf("deleted element is %d\n",cur->data);
	free(cur);
}
void delete_at_position()
{
	int pos,c=1;
	printf("enter position of deletion\n");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=next->link;
	printf("deleted element is %d\n",next->data);
	next->link=NULL;
	free(next);
}
void delete_at_end()
{
	cur=head;
	while(cur->link!=tail)
	{
		cur=cur->link;
	}
	cur->link=NULL;
	next=tail;
	printf("deleted element is %d\n",next->data);
	free(next);
	tail=cur;
}
void delete_before()
{
	int value;
	printf("enter before which node we need to delete\n");
	scanf("%d",&value);
	next=head;
	while(next->link->data!=value)
	{
		prev=next;
		next=next->link;
	}
	prev->link=next->link;
	next->link=NULL;
	printf("deleted element is %d\n",next->data);
	free(next);	
}
void delete_after()
{
	int value;
	printf("enter after which node we need to delete\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value)
	{
		prev=next;
		next=next->link;
	}
	prev=next->link;
	next->link=prev->link;
	printf("deleted element is %d\n",prev->data);
	prev->link=NULL;
	free(prev);
}
void traversal()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		next=head;
		while(next!=NULL)
		{
			printf("%d->",next->data);
			next=next->link;
		}
	}
}
void display_in_reverse(struct node*head)
{
	if(head!=NULL)
	{
		display_in_reverse(head->link);
		printf("%d->",head->data);
	}
}	
void search()
{
	int value,flag=0,c=0;
	printf("enter value to be searched\n");
	scanf("%d",&value);
	next=head;
	while(next!=NULL)
	{
		if(next->data==value)
		{
			flag=1;
			break;
		}
		next=next->link;
		c++;
	}
	if(flag==1)
	{
		printf("element present in the list at %d location\n",c);
	}
	else
	{
		printf("element not present in the list\n");
	}
}
void sort()
{
	struct node*p1,*p2;
	int i,t,c=0;
	p1=head;
	while(p1!=NULL)
	{
		c++;
		p1=p1->link;
	}
	for(i=0;i<c;i++)
	{
		p2=head;
		while(p2->link!=NULL)
		{
			if(p2->data>p2->link->data)
			{
				t=p2->data;
				p2->data=p2->link->data;
				p2->link->data=t;
			}
			p2=p2->link;
		}		
	}	
}
int main()
{
	int ch;
	while(1)
	{
		printf("program for single linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before");
		printf("\n6-insert after\n7-delete at begin\n8-delete at position\n9-delete at end");
		printf("\n10-delete before\n11-delete after\n12-traversal\n13-display in reverse");
		printf("\n14-search\n15-sort\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
			    	break;
			case 2: insert_at_begin();
					break;
			case 3: insert_at_position();
					break;
			case 4: insert_at_end();
					break;
			case 5: insert_before();
					break;
			case 6: insert_after();
					break;
			case 7: delete_at_begin();
					break;
			case 8: delete_at_position();
					break;
			case 9: delete_at_end();
					break;
			case 10: delete_before();
					 break;
			case 11: delete_after();
					 break;	
			case 12: traversal();
				 	 break;
			case 13: display_in_reverse(head);
					 break;
			case 14: search();
					 break;
			case 15: sort();
					 break;
			case 16: exit(0);
		}
	}
	return 0;
}
