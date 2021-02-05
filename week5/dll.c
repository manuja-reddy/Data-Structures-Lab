#include<stdio.h>
#include<stdlib.h>
struct node
{
	float data;
	struct node*prev;
	struct node*next;
};
struct node*head=NULL,*tail=NULL,*cur,*t1,*t2;
void create()
{
	int i,n;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%f",&cur->data);
		cur->prev=NULL;
		cur->next=NULL;
		if(head==NULL)
			head=tail=cur;
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}
}		
void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%f",&cur->data);
	cur->prev=NULL;
    	cur->next=head;
	head->prev=cur;
    	head=cur;
}
void insert_at_position()
{
	int pos,c=1;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%f",&(cur->data));
	printf("enter position\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}
void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter current data\n");
	scanf("%f",&cur->data);
	cur->next=NULL;
	cur->prev=tail;
	tail->next=cur;
	tail=cur;
}
void insert_before()
{
	float value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%f",&cur->data);
	printf("enter data to insert before which node\n");
	scanf("%f",&value);
	t1=head;
	while(t1->data!=value && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}
void insert_after()
{
	float value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%f",&cur->data);
	printf("enter data to insert after which node\n");
	scanf("%f",&value);
	t1=head;
	while(t1->data!=value && t1!=NULL)
	{
		t1=t1->next;
	}
	cur->next=t1->next;
	t1->next->prev=cur;
	t1->next=cur;
	cur->prev=t1;
}
void delete_at_begin()
{
	cur=head;
	head=head->next;
	head->prev=NULL;
	cur->next=NULL;
	printf("deleted element is %f\n",cur->data);
	free(cur);
}
void delete_at_position()
{
	int pos,c=1;
	printf("enter position of deletion\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deleted element is %f\n",t1->data);
	free(t1);
}
void delete_at_end()
{
	cur=tail;
	tail=tail->prev;
	tail->next=NULL;
	cur->prev=NULL;
	printf("deleted element is %f\n",cur->data);
	free(cur);
}
void delete_before()
{
	float value;
	printf("enter before which node we need to delete\n");
	scanf("%f",&value);
	t1=head;
	while(t1->next->data!=value && t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deleted element is %f\n",t1->data);
	free(t1);	
}
void delete_after()
{
	float value;
	printf("enter after which node we need to delete\n");
	scanf("%f",&value);
	t1=head;
	while(t1->data!=value &&t1!=NULL)
	{
		t1=t1->next;
	}
	t2=t1->next;
	t1->next=t2->next;
	t2->next->prev=t1;
	printf("deleted element is %f\n",t2->data);
	free(t2);
}
void display_in_forward()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		cur=head;
		printf("elements of DLL are\n");
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur=cur->next;
		}
	}
}
void display_in_reverse()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		cur=tail;
		printf("elements of DLL are\n");
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur=cur->prev;
		}
	}
}	
void search()
{
	float value,flag=0;
	printf("enter value to be searched\n");
	scanf("%f",&value);
	int c=1;
	t1=head;
	while(t1!=NULL)
	{
		if(t1->data==value)
		{
			flag=1;
			break;
		}
		t1=t1->next;
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
	int i,c=0;
	float t;
	p1=head;
	while(p1!=NULL)
	{
		c++;
		p1=p1->next;
	}
	for(i=0;i<c;i++)
	{
		p2=head;
		while(p2->next!=NULL)
		{
			if(p2->data>p2->next->data)
			{
				t=p2->data;
				p2->data=p2->next->data;
				p2->next->data=t;
			}
			p2=p2->next;
		}		
	}	
}
int main()
{
	int ch;
	while(1)
	{
		printf("program for double linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before");
		printf("\n6-insert after\n7-delete at begin\n8-delete at position\n9-delete at end");
		printf("\n10-delete before\n11-delete after\n12-display in forward\n13-display in reverse");
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
			case 12: display_in_forward();
				 break;
			case 13: display_in_reverse();
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
