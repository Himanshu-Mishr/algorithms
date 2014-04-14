/* This program will perform a recursive binary search using Divide and
Conquer method. */

#include<stdio.h>
#include<conio.h>

/* This is a recursive binary serach routine, parameters - list of elements,
element to be serched, low and high value of the index positions. */

int binarysearch(int a[],int n,int low,int high)
	{ int mid;
	  if (low > high)
	    return -1;
	    //Search failed
	  mid = (low + high)/2;
	  // Devide the list
	  if(n == a[mid])
	    { printf("The element is at position %d\n",mid+1);
	      return 0;
	    }
	  // Recursive call
	  if(n < a[mid])
	    { high = mid - 1;
	      binarysearch(a,n,low,high);
	    }
	  if(n > a[mid])
	    { low = mid + 1;
	      binarysearch(a,n,low,high);
	    }

	 }

void main()
{
	  int a[50];
	  int n,no,x,result;
	  clrscr();
	  printf("Enter the number of terms : ");
	  scanf("%d",&no);
	  printf("Enter the elements in non decreasing order  :\n");
	  for(x=0;x<no;x++)
	   scanf("%d",&a[x]);
	  printf("Enter the element to be searched :\n");
	  scanf("%d",&n);
	  result=binarysearch(a,n,0,no-1);
	  //printf("result= %d",result);
	  if(result != 0)
	   printf("Element not found");
	  getch();
}

