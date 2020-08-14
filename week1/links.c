#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
int main()
{
	struct node*s;
	s=(struct node*)malloc(sizeof(struct node));
	s->data = 10;
	s->prev = NULL;
	s->next = NULL;
	printf("data=%d",s->data);
}