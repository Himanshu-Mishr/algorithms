/* This program will find the value of minimum and maximum from
a list of elements stored in an array using Divide and Conquer method.
A structure is used to return two values from minMax().
The input data is hard coded in the program itself. It can me modified
to accept input data or a procedure to generate a set of randome numbers
can be used. Also the input data can be displayed to enhance the
readability of the program.   */

#include<stdio.h>
#include<conio.h>

struct pair
{
  int min;
  int max;
};

struct pair getMinMax(int arr[], int low, int high)
{
  struct pair minmax, mml, mmr;
  int mid;

  /* If there is only one element */
  if(low == high)
  {
     minmax.max = arr[low];
     minmax.min = arr[low];
     return minmax;
  }

  /* If there are two elements */
  if(high == low + 1)
  {
     if(arr[low] > arr[high])
     {
	minmax.max = arr[low];
	minmax.min = arr[high];
     }
     else
     {
	minmax.max = arr[high];
	minmax.min = arr[low];
     }
     return minmax;
  }

  /* If there are more than 2 elements, then divide the data in two parts
  low..mid and mid+1..high and the same function is called recursively on
  both parts */
  mid = (low + high)/2;
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid+1, high);

  /* compare minimums of two parts*/
  if(mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;

  /* compare maximums of two parts*/
  if(mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;     

  return minmax;
}
 
/* Driver program to test above function */
void main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  struct pair minmax = getMinMax(arr, 0, arr_size-1);
  clrscr();
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
  getch();
}
