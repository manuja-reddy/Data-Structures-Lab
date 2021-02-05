#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left,*right;
};
struct BST *root=NULL,*temp,*cur;
void create()
{
	temp=root;
	cur=(struct BST*)malloc(sizeof(struct BST));
	printf("\n enter data:\n");
	scanf("%d",&(cur->data));
	cur->left=NULL;
	cur->right=NULL;
	if(temp==NULL)
		root=cur;
	else
	{
		while(temp!=NULL)
		{
			if((cur->data) < (temp->data))
			{
				if(temp->left==NULL)
				{
					temp->left=cur;
					return;
				}
				else
					temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=cur;
					return;
				}
			}
		}
	}
}
void postorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("\t%d",temp->data);
	}
}
void inorder(struct BST*temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("\t%d",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct BST*temp)
{
	if(temp!=NULL)
	{
		printf("\t%d",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
int main()
{
	int ch;
	printf("\nmenu options\n");
	printf("1.Create\n2.Postorder\n3.Inorder\n4.Preorder\n5.Exit\n");
	while(1)
	{
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create(); 
			break;
			case 2:printf("\nPOST ORDER TRAVERSAL\n");
			postorder(root);
			break;
			case 3:printf("\nINORDER TRAVERSAL\n");
			inorder(root);
			break;
			case 4:printf("\nPRE ORDER TRAVERSAL\n");
			preorder(root);
			break;
			case 5:exit(0);
			break;
			default:printf("\nInvalid choice\n");
		}
	}
}