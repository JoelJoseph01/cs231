#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp,coef;
    struct node *link;
};

void main()
{
    struct node *temp,*head,*ptr;
    int ex,coe,c;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->exp=0;
    temp->coef=0;
    temp->link=NULL;
    ptr=head;

    do
    {
	printf("Enter coefficient: ");
	scanf("%d",&coe);
	printf("Enter exponent: ");
	scanf("%d",&ex);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->exp=ex;
	temp->coef=coe;
	temp->link=NULL;
	ptr->link=temp;
	ptr=ptr->link;
	printf("1. Add more elements\n2. Continue\nEnter choice: ");
	scanf("%d",&c);
    }while(c==1);
    printf("1. Display polynomial\n2. Exit\nEnter choice: ");
    scanf("%d",&c);
    if(c==1)
    {
	ptr=head->link;
	printf("F(p) = ");
	while(ptr!=NULL)
	{
	    printf("%d p^%d + ",ptr->coef,ptr->exp);
	    ptr=ptr->link;
	}
	printf("0\n");
    }
}