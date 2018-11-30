/* Joel Joseph
     S3D 29
     Queue using array */
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int queue[15],i,front=0,choice,end=0,ele,cho,limit=14;

    do
    {
        printf("\nMENU\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value of element: ");
                    scanf("%d",&ele);
                    if(front==0)
                    {
                        front=1;
                        end=1;
                        queue[end]=ele;
                    }
                    else if(end==limit)
                    {
                        printf("Queue is FULL");
                    }
                    else
                    {
                        end+=1;
                        queue[end]=ele;
                    }
                    break;

            case 2: if(front==0)
                    {
                        printf("Queue is EMPTY");
                    }
                    else if(front==end)
                    {
                        printf("Deleted %d",queue[end]);
                        front=0;
                        end=0;
                    }
                    else
                    {
                        printf("DeletedDD %d",queue[front]);
                        front+=1; 
                    }
                    break;
            case 3: if(front==0)
                    {
                        printf("Queue is EMPTY");
                    }
                    else
                    {
                        for(i=front;i<=end;i++)
                        {
                            printf("%d -> ",queue[i]);
                        }
                        printf("\nFront: %d",front);
                        printf("\nEnd: %d",end);
                    }
        } 
    }while(choice==1 || choice==2 || choice==3);

}
