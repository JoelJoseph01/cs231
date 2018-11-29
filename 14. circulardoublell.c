/* Joel Joseph,29
   Circular Doubly Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
    	struct node *llink,*rlink;
};
void main()
{
    	int key,x,n,c,l;
    	struct node *head,*temp,*ptr,*ptr1,*ptr2;
    	head=(struct node*)malloc(sizeof(struct node));
    	head->data=0;
    	head->llink=head;
    	head->rlink=head;
	do
    	{
        	ptr=head;
        	printf("\nCHOOSE\n1.Insertion(begining)\n2.Insertion(end)\n3.Insertion(after key)\n4.Deletion\n5.Search\n6.Display\nEnter choice:");
        	scanf("%d",&c);
		if(c==1)
        	{
            		ptr=head;
			ptr1=ptr->rlink;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->rlink=ptr1;
			temp->llink=ptr;	
			ptr->rlink=temp;
			ptr1->llink=temp;
            		printf("Enter data: ");
            		scanf("%d",&x);
            		temp->data=x;
        	}
        	else if(c==2)
        	{
            		while(ptr->rlink!=head)
            		{
                		ptr=ptr->rlink;
            		}
            		temp=(struct node*)malloc(sizeof(struct node));
            		ptr->rlink=temp;
			temp->rlink=head;
            		printf("Enter data: ");
            		scanf("%d",&x);
            		temp->data=x;
            		temp->llink=ptr;
            		head->llink=temp;
        	}
        	else if(c==3)
        	{
			ptr=ptr->rlink;
            		printf("Enter key: ");
            		scanf("%d",&key);
            		while(ptr!=head)
            		{
                		if(ptr->data==key)
                		{
                    			temp=(struct node*)malloc(sizeof(struct node));
                    			ptr1=ptr->rlink;
                    			ptr->rlink=temp;
                    			temp->llink=ptr;
                    			ptr1->llink=temp;
                    			temp->rlink=ptr1;
                    			printf("Enter data: ");
                    			scanf("%d",&x);
                    			temp->data=x;
                		}
                		ptr=ptr->rlink;
            		}
        	}		
       		else if(c==4)
        	{
            		if(ptr->rlink==head)
            		{
                		printf("List is empty!!!");
            		}
            		else
            		{
                		printf("Enter key: ");
               	 		scanf("%d",&key);
                		l=0;
                		while(ptr->rlink!=head)
                		{
                    			ptr1=ptr;
                    			ptr=ptr->rlink;
                    			ptr2=ptr->rlink;
                    			if(ptr->data==key)
                    			{
                        			if(ptr->rlink==head)
                        			{
                            				ptr1=ptr->llink;
                            				ptr1->rlink=head;
                            				free(ptr);
                            				l+=1;    
						}
                        			else
                        			{
                            				ptr1=ptr->llink;
                            				ptr2=ptr->rlink;
                            				ptr1->rlink=ptr2;
                            				ptr2->llink=ptr1;
                            				free(ptr);
                            				l+=1;
                        			}
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
            		if(ptr->rlink==head)
            		{
                		printf("Empty list!!!");
            		}
            		else
            		{
                		ptr=ptr->rlink;
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
                    			ptr=ptr->rlink;
                		}
                		if(l==0)
                		{
                    			printf("\nElement not found...");
                		}
            		}
        	}
        	else if(c==6)
        	{
            		ptr=head->rlink;
            		while(ptr->rlink!=head->rlink)
            		{	
                		printf("%d    ",ptr->data);
                		ptr=ptr->rlink;
            		}
        	}
    	}while(c==1 || c==2 || c==3 || c==4 || c==5 || c==6);
}
