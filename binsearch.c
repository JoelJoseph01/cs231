#include<stdio.h>
void main()
{ int f,l,n,mid,a[10],i,s;
  printf("Enter no of elements:");
  scanf("%d",&n);
  printf("Enter elements:");
  for(i=0;i<n;i++)
	scanf("%d",&a[i]);
  printf("Enter element to search:");
  scanf("%d",&s);
  f=0;
  l=n-1;
  mid=(f+l)/2;
  while(f<=l)
	{ if(a[mid]<s)
		f=mid+1;
          else if(a[mid]==s)
		{  printf("Element found:%d",mid+1);
              	   break;
	        }
          else 
		l=mid-1;
          	mid=(f+l)/2;
	}

  if (f>l)
      printf("Not found!");
}
	
		
