//
// complexity : O(log(N))
//              worst case O(1)
//              
#include <stdio.h>

int main() 
{   
    // target = search
    int c,first,last,middle,n,search,array[100];

    printf("\nenterthe no of element ");
    scanf("%d",&n);

    printf("\nenter the %d integers ",n);

    for (c = 0; c < n; ++c)
    {
        scanf("%d",&array[c]);
    }
    printf("Enter the value to find \n");
    scanf("%d",&search);

    first = 0;
    last = n-1;
    middle = (first  + last)/2;

    while(first <= last) 
    {
        if (array[middle] < search)
        {
            first = middle + 1;
        }
        else if (array[middle] == search) {
            printf("%d found at location %d\n",search,middle+1 );
            break;
        }
        else
            last = middle +1;
        
        middle  = (first + last)/2;

    }
    if (first > last)
    {
        printf("Not found \n");
    }
    return 0;

}

