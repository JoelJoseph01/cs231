/* Joel Joseph,29
   Bubble sort */
#include<conio.h>
#include<stdio.h>
void main()
{  int i,j,a[10],n,temp;
   clrscr();
   printf("Enter no of elements:");
   scanf("%d",&n);
   printf("Enter elements:");
   for(i=0;i<n;i++)
	scanf("%d",&a[i]);
   for(i=0;i<n;i++)
	{  for(j=0;j<n;j++)
		{ if (a[j]>a[j+1])
			{  temp=a[j];
			   a[j]=a[j+1];
			   a[j+1]=temp;			
			}
		}
	}
   printf("Sorted elements:");
   for(i=0;i<n;i++)
	printf("%d",a[i]);
   getch();
}
