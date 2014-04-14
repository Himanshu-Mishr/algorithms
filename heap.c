#include <stdio.h>

void makeheap ( int [ ], int ) ;
void heapsort ( int [ ], int ) ;

int main( )
{
    int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
    int i ;

   
    printf ( "Heap Sort.\n" ) ;

    makeheap ( arr, 10 ) ;

    printf ( "\nBefore Sorting:\n" ) ;
    for ( i = 0 ; i <= 9 ; i++ )
        printf ( "%d\t", arr[i] ) ;

    heapsort ( arr, 10 ) ;

    printf ( "\nAfter Sorting:\n" ) ;
    for ( i = 0 ; i <= 9 ; i++ )
        printf ( "%d\t", arr[i] ) ;

}

void makeheap ( int x[ ], int n )
{
    int i, val, s, f ;
    for ( i = 1 ; i < n ; i++ )
    {
        val = x[i] ;
        s = i ;
        f = ( s - 1 ) / 2 ;
        while ( s > 0 && x[f] < val )
        {
            x[s] = x[f] ;
            s = f ;
            f = ( s - 1 ) / 2 ;
        }
        x[s] = val ;
    }
}

void heapsort ( int x[ ], int n )
{
    int i, s, f, ivalue ;
    for ( i = n - 1 ; i > 0 ; i-- )
    {
        ivalue = x[i] ;
        x[i] = x[0] ;
        f = 0 ;

        if ( i == 1 )
            s = -1 ;
        else
            s = 1 ;

        if ( i > 2 && x[2] > x[1] )
            s = 2 ;

        while ( s >= 0 && ivalue < x[s] )
        {
            x[f] = x[s] ;
            f = s ;
            s = 2 * f + 1 ;

            if ( s + 1 <= i - 1 && x[s] < x[s + 1] )
                s++ ;
            if ( s > i - 1 )
                s = -1 ;
        }
        x[f] = ivalue ;
    }
}

//  ALGORITHM 
// function heapSort(a, count) is
//      input:  an unordered array a of length count
//   
//      (first place a in max-heap order)
//      heapify(a, count)
//   
//      end := count-1 
//     /* In languages with zero-based arrays the children are 2*i+1 and 2*i+2 */
//      while end > 0 do
//          (swap the root(maximum value) of the heap with the last element of the heap)
//          swap(a[end], a[0])
//          (decrease <span id="IL_AD7" class="IL_AD">the size</span> of the heap by one so that the previous max value will
//          stay in its proper placement) 
//          end := end - 1
//          (put the heap back in max-heap order)
//          siftDown(a, 0, end)
//           
//   
//  function heapify(a, count) is
//      (start is assigned the index in a of the last parent node)
//      start := (count - 1) / 2 
//       
//      while start ≥ 0 do
//          (sift down the node at index start to the proper place such that all nodes
//           below the start index are in heap order)
//          siftDown(a, start, count-1)
//          start := start - 1
//      (after sifting down the root all nodes/elements are in heap order)
//   
//  function siftDown(a, start, end) is
//      input:  end represents <span id="IL_AD10" class="IL_AD">the limit</span> of how far down the heap
//                    to sift.
//      root := start
//  
//      while root * 2 + 1 ≤ end do          (While the root has at <span id="IL_AD9" class="IL_AD">least one</span> child)
//          child := root * 2 + 1        (root*2 + 1 points to the left child)
//          swap := root        (keeps track of child to swap with)
//          (check if root is smaller than left child)
//          if a[swap] < a[child]
//              swap := child
//          (check if right child exists, and if it's bigger than what we're 
//           currently swapping with)
//          if child+1 ≤ end and a[swap] < a[child+1]
//              swap := child + 1
//          (check if we need to swap at all)
//          if swap != root
//              swap(a[root], a[swap])
//              root := swap          (repeat to continue sifting down the child now)
//          else
//              return


// Algorithm
// HEAPSORT(A)
// 1 BUILD-HEAP(A)
// 2 for i -> length[A] downto 2
// 3 do exchange A[1] <-> A[i]
// 4 heap-size[A] <- heap-size[A] -1
// 5 HEAPIFY(A, 1)
 
// The HEAPSORT procedure takes time O(n lg n), since the call to BUILD-HEAP takes time O(n) and each of the n - 1 calls to HEAPIFY takes time O(lg n).
 
// BUILD-HEAP(A)
// 1 heap-size[A] <- length[A]
// 2 for i <- length[A]/2 downto 1
// 3 do HEAPIFY(A, i)


// HEAPIFY(A, i)
// 1 l <- LEFT(i)
// 2 r <- RIGHT(i)
// 3 if l <= heap-size[A] and A[l] > A[i]
// 4 then largest <- l
// 5 else largest <- i
// 6 if r <= heap-size[A] and A[r] > A[largest]
// 7 then largest <- r
// 8 if largest != i
// 9 then exchange A[i] <- A[largest]
// 10 HEAPIFY(A,largest)
 

// /* Double-Click To Select Code */
//  
// #include<stdio.h>
// #include<conio.h>
//  
// void heapsort(int[], int);
// void heapify(int[], int);
// void adjust(int[], int);
//  
// int main()
// {
//  int array[50],n,i;
//  clrscr();
//  
//  printf("Enter the no. of elements to be sorted: ");
//  scanf("%d",&n);
//  
//  printf("\nEnter the elements: \n");
//  for(i=0 ; i<n ; i++)
//  scanf("%d",&array[i]);
//  
//  printf("\nBefore Heapsort:");  //Array Before Mergesort
//  for(i = 0; i < n; i++)
//  {
//   printf("%4d", array[i]);
//  }
//  printf("\n");
//  
//  heapsort(array,n);
//  
//  printf("\nAfter Heapsort:");  //Array After Mergesort
//  for(i = 0; i < n; i++)
//  {
//   printf("%4d", array[i]);
//  }
//  printf("\n");
//  getch();
//  return 0;
// }
//  
// void heapsort(int array[], int n)
// {
//  int i,t;
//  
//  heapify(array,n);
//  
//  for(i=n-1 ; i>0 ; i--)
//  {
//   t = array[0];
//   array[0] = array[i];
//   array[i] = t;
//   adjust(array,i);
//  }
// }
//  
//  
// void heapify(int array[], int n)
// {
//  int item,i,j,k;
//  
//  for(k=1 ; k<n ; k++)
//  {
//   item = array[k];
//   i = k;
//   j = (i-1)/2;
//  
//   while( (i>0) && (item>array[j]) )
//   {
//    array[i] = array[j];
//    i = j;
//    j = (i-1)/2;
//   }
//   array[i] = item;
//  }
// }
//  
// void adjust(int array[], int n)
// {
//  int item,i,j;
//  
//  j = 0;
//  item = array[j];
//  i = 2*j+1;
//  
//   while(i<=n-1)
//  {
//   if(i+1 <= n-1)
//    if(array[i] < array[i+1])
//     i++;
//   if(item < array[i])
//   {
//    array[j] = array[i];
//    j = i;
//    i = 2*j+1;
//   }
//   else
//    break;
//  }
//  array[j] = item;
// }