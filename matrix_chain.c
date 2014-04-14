// See the Cormen book for details of the following algorithm

#include<stdio.h>
#include<limits.h>
#include<conio.h>


// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
long int MatrixChainOrder(long int p[], long int n)
{

    /* For simplicity of the program, one extra row and one extra column are
    /*allocated in m[][].0th row and 0th column of m[][] are not used */
    long int m[20][20];
    //long int s[20][20];
    long int i, j, k, L, q, x, y;

    /* m[i,j] = Minimum number of scalar multiplications needed to compute
       the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is
       p[i-1] x p[i] */

    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
	{
	m[i][i] = 0;
	//s[i][j] = 0;
	}
    // L is chain length.
    for (L=2; L<n; L++)
    {
	for (i=1; i<=n-L+1; i++)
	{
	    j = i+L-1;
	    m[i][j] = INT_MAX;
	    for (k=i; k<=j-1; k++)
	    {
		// q = cost/scalar multiplications
		q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
		if (q < m[i][j])
		    m[i][j] = q;
	    }
	}
    }
    printf("\n Cost matrix \n");
    for (x =1; x <= 5; x++)
	{
		for (y=1; y <= 5; y++)
		{
			printf("	   %d", m [x][y]);
		}
		printf("\n");
	}

    return m[1][n-1];
}

long int main()
{
    long int arr[] = {3, 5, 8, 2, 6};
    long int size = sizeof(arr)/sizeof(arr[0]);

    clrscr();
    printf("Minimum number of multiplications is %d ",
		       MatrixChainOrder(arr, size));

    getch();
    return 0;
}
