/* Double-Click To Select Code */
 
#include <stdio.h>
  
void mergesort(int arr[], int l, int h);
  
int main() 
{
 int array[100],n,i = 0; 
 
 printf("Enter the number of elements to be sorted: ");
 scanf("%d",&n);
 printf("\nEnter the elements to be sorted: \n");
 for(i = 0 ; i < n ; i++ )
 {
  printf("\tArray[%d] = ",i);
  scanf("%d",&array[i]);
 }
  
  
 printf("\nBefore Mergesort:");  //Array Before Mergesort
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");
  
 mergesort(array, 0, n - 1); 
 
 printf("\nAfter Mergesort:");  //Array After Mergesort
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");

}
  
void mergesort(int arr[], int l, int h) 
{
 int i = 0;
 int length = h - l + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int temp[100];
  
 if(l == h)
 return;
  
 pivot  = (l + h) / 2;
  
 mergesort(arr, l, pivot);
 mergesort(arr, pivot + 1, h);
   
 for(i = 0; i < length; i++)
 {
  temp[i] = arr[l + i];
 }
  
 merge1 = 0;
 merge2 = pivot - l + 1;
  
 for(i = 0; i < length; i++) 
 {
  if(merge2 <= h - l)
  {
   if(merge1 <= pivot - l)
   {
    if(temp[merge1] > temp[merge2])
    {
     arr[i + l] = temp[merge2++];
    }
 
    else
    {
     arr[i + l] = temp[merge1++];
    }
   }
 
   else
   {
    arr[i + l] = temp[merge2++];
   }
  }
 
  else
  {
   arr[i + l] = temp[merge1++];
  }
 }
}


/*
The pseudocode of the MERGE procedure is as follow:
MERGE (A, p, q, r )

1.      n1 ← q − p + 1
2.      n2 ← r − q
3.      Create arrays L[1 . . n1 + 1] and R[1 . . n2 + 1]
4.      FOR i ← 1 TO n1
5.            DO L[i] ← A[p + i − 1]
6.      FOR j ← 1 TO n2
7.            DO R[j] ← A[q + j ]
8.      L[n1 + 1] ← ∞
9.      R[n2 + 1] ← ∞
10.    i ← 1
11.    j ← 1
12.    FOR k ← p TO r
13.         DO IF L[i ] ≤ R[ j]
14.                THEN A[k] ← L[i]
15.                        i ← i + 1
16.                ELSE A[k] ← R[j]
17.                        j ← j + 1
*/
