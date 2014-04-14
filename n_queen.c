#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 10


int fnPlace(int iK,int iI,int iX[10])
{
    int iJ;
    for(iJ=1;iJ<=iK-1;iJ++)
    {
        if(iX[iJ]==iI||abs(iJ-iK)==abs(iX[iJ]-iI))
            return 0;
    }
    return 1;
}

void fnQueens(int iK,int iN)
{
    int iI,iJ,iL;
    static int iCount,iX[10];
    for(iI=1;iI<=iN;iI++)
    {
        if(fnPlace(iK,iI,iX))
        {
            iX[iK]=iI;
            if(iK==iN)
            {
                printf("\nFeassible solution : %d",++iCount);
                printf("\nSolutions are : ");
                for(iJ=1;iJ<=iN;iJ++)
                    printf(" %d ",iX[iJ]);
                for(iJ=1;iJ<=iN;iJ++)
                {
                    printf("\n");
                    for(iL=1;iL<=iN;iL++)
                    {
                        if(iL==iX[iJ])
                            printf(" X ");
                        else
                            printf(" 0 ");
                    }
                }
            }
            else
                fnQueens(iK+1,iN);
        }
    }
}


int main()
{
    int iNo;

    printf("Enter the no of Queenes : ");
    scanf("%d",&iNo);
    fnQueens(1,iNo);

}

// program description :-

// algorithm NQueen(k,n) 
// {
//     for i := 1 to n do
//     {
//         if Place (k,i) then
//         {
//             x[k] := i;
//             if(k = n) then write (x[1:n])
//             else NQueen(k+1,n);
//         }
//     }
// }

// algorithm Place(k,i) 
// {
//     for j:= 1 to k-1 do
//         if((x[j] = // in the same column
//             or (Abs( x[j] -i) = Abs(j-k)))  // or in the same diagonal
//            then return false;
//     return true;
// }

// 1) Start in the leftmost column
// 2) If all queens are placed
//     return true
// 3) Try all rows in the current column.  Do following for every tried row.
//     a) If the queen can be placed safely in this row then mark this [row, 
//         column] as part of the solution and recursively check if placing  
//         queen here leads to a solution.
//     b) If placing queen in [row, column] leads to a solution then return 
//         true.
//     c) If placing queen doesn't lead to a solution then umark this [row, 
//         column] (Backtrack) and go to step (a) to try other rows.
// 3) If all rows have been tried and nothing worked, return false to trigger 
//     backtracking.
