#include<stdio.h>
#include<stdlib.h>
struct node
{
   	int data;
	struct node *link;
};
void main()
{
    	int key,x,c,l,n;
    	struct node *head,*temp,*ptr,*ptr1;
    	head=(struct node*)malloc(sizeof(struct node));
    	head->data=0;
    	head->link=head;
	do
    	{
        	ptr=head;
        	printf("\nCHOOSE\n1.Insertion(begin)\n2.Insertion(end)\n3.Insertion(after key)\n4.Deletion\n5.Search\n6.Display\nEnter choice:");
        	scanf("%d",&c);
		if(c==1)
		{
			ptr=head;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->link=ptr->link;	
			ptr->link=temp;
            		printf("Enter data: ");
            		scanf("%d",&x);
            		temp->data=x;
		}
		else if(c==2)
        	{
        		while(ptr->link!=head)
            		{
                		ptr=ptr->link;
            		}
            		temp=(struct node*)malloc(sizeof(struct node));
            		ptr->link=temp;
            		printf("Enter data: ");
            		scanf("%d",&x);
            		temp->data=x;
            		temp->link=head;
        	}
        	else if(c==3)
        	{
            		printf("Enter key: ");
            		scanf("%d",&key);
            		ptr=ptr->link;
            		while(ptr!=head)
            		{
                		if(ptr->data==key)
                		{
                    			temp=(struct node*)malloc(sizeof(struct node));
                    			ptr1=ptr->link;
                    			ptr->link=temp;
                    			temp->link=ptr1;
                    			printf("Enter data: ");
                    			scanf("%d",&x);
                    			temp->data=x;
		                }
                		ptr=ptr->link;
            		}
        	}
        	else if(c==4)
        	{
            		if(ptr->link==NULL)
            		{
                		printf("List is empty!!!");
            		}
            		else
           	 	{
                		printf("Enter key: ");
                		scanf("%d",&key);
                		l=0;
                		while(ptr->link!=head)
                		{
                    			ptr1=ptr;
                    			ptr=ptr->link;
                    			if(ptr->data==key)
                    			{
                        			ptr1->link=ptr->link;
                        			free(ptr);
                        			l+=1;
                    			}
                		}
                		if(l==0)
                		{
                    			printf("Key not found!!!");
                		}
            		}
        	}
        	else if(c==5)
        	{
            		if(ptr->link==head)
            		{
                		printf("Empty list!!!");
            		}
            		ptr=ptr->link;
            		l=0;
			n=0;
            		printf("Enter key: ");
            		scanf("%d",&key);
            		while(ptr!=head)
            		{
				n=n+1;
                		if(ptr->data==key)
                		{
                    			printf("\nElement found at %d",n);
                    			l+=1;
                		}
                		ptr=ptr->link;
            		}
            		if(l==0)
            		{
                		printf("\nElement not found...");
            		}
        	}
        	else if(c==6)
        	{
            		ptr=head->link;
            		while(ptr->link!=head->link)
            		{
                		printf("%d   ",ptr->data);
                		ptr=ptr->link;
            		}
            		
        	}
    	}while(c==1 || c==2 || c==3 || c==4 || c==5 || c==6);
}