#include<stdio.h>
#include<limits.h>
 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{
 
    /* For simplicity of the program, one extra row and one extra column are
       allocated in m[][].  0th row and 0th column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
    /* m[i,j] = Minimum number of scalar multiplications needed to compute
       the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is
       p[i-1] x p[i] */
 
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
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
 
    return m[1][n-1];
}
 
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d ",
                       MatrixChainOrder(arr, size));
 
    getchar();
    return 0;
}

// algorithm :- 
// Matrix-Chain(array p[1 .. n], int n) {
//           Array s[1 .. n − 1, 2 .. n];
//           FOR i = 1 TO n DO m[i, i] = 0;                                         // initialize
//           FOR L = 2 TO n DO {                                                      // L=length of subchain
//                   FOR i = 1 TO n − L + 1 do {
//                            j = i + L − 1;
//                           m[i, j] = infinity;
//                           FOR k = i TO j − 1 DO {                                  // check all splits
//                                   q = m[i, k] + m[k + 1, j] + p[i − 1] p[k] p[j];
//                                   IF (q < m[i, j]) {
//                                           m[i, j] = q; 
//                                            s[i, j] = k; 
//                                   }
//                            } 
//                    } 
//             }
//            return m[1, n](final cost) and s (splitting markers); 
//            }

// Complexity Analysis

// Clearly, the space complexity of this procedure Ο(n2).
//  Since the tables m and s require Ο(n2) space. As far as 
//  the time complexity is concern, a simple inspection of 
//  the for-loop(s) structures gives us a running time of 
//  the procedure. Since, the three for-loops are nested three deep,
//  and each one of them iterates at most n times (that is to say 
// indices L, i, and j takes on at most n − 1 values).
//  Therefore, The running time of this procedure is Ο(n3).
