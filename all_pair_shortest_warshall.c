/* Warshall's METHOD */
/* All pair shortest path cost matirx as well as path matrix */

  # include<stdio.h>
  #include<conio.h>

  # define Infinity 9999
  # define size 20

 int i,k,j;
 void Input(int , int a[size][size]);
 void Output(int , int a[size][size]);
 void warshall(int , int a[size][size], int r[size][size], int p[size][size]);

/* Input function */

  void Input(int n, int a[size][size])
     {
	int i, j;
      printf("\n Input adjacency matrix, with spaces between values one row at a time\n");
      printf(" and 9999 for infinity, when the edge does not exists for a pair of nodes:\n");
       for (i = 0; i < n; i++)
	{
	  for (j = 0; j < n; j++)
	   {
	scanf("%d", &a[i][j]);
	   }
	 printf("\n");
       }
    }

/* Output function */

 void Output (int n, int a[size][size])
     {
	int i, j;
      for (i =0; i < n; i++)
	{
	  for (j =0; j < n; j++)
	   {
	     printf(" %d", a[i][j]);
	   }
	 printf("\n");
       }
    }

/* Shortest path evaluation function */

void warshall(int n, int a[size][size], int r[size][size], int p[size][size])
       {
	 for (i = 0; i < n; i ++)
	   a[i][i] = 0; 	/* Set diagonal elements zero */
	  // printf("\n After setting diagonal elements to zero \n");
	  // Output(n, a);
	  // Output(n,r);
	  // Output(n,p);
	  // getch();
	   for (i = 0; i < n; i++)
	     {
	      for (j = 0; j < n; j++)
	       {
		if ((a[i][j] == 0) && (i != j))
		 r[i][j] = Infinity;
		 else
		  r[i][j] = a[i][j];
	       }
	    }
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
				p [i][j] = 9;
			else
				p[i][j] = 9;
		}
	}

	   // printf("\n Replacing zeros by very large value \n");
	   // Output(n, a);
	   // Output(n,r);
	   // Output(n,p);
	   //getch();
	  for (k = 0; k < n; k++)
	  {
	   for (i = 0; i < n; i++)
	     {
	      for (j = 0; j < n; j++)
	       {
		  if (r[i][k] + r[k][j]< r[i][j])
		     {
		      printf("\n r[%d][%d] = %d ", i, k, r[i][k]);
		      printf("\n r[%d][%d] = %d ", k, j, r[k][j]);
		      printf("\n r[%d][%d] = %d ", i, j, r[i][j]);
		      r[i][j] = r[i][k] +  r[k][j];
		      p[i][j] =k;
		      //printf("\n r[%d][%d] = r[%d][%d] + r[%d][%d] = %d ", i, j, i, k, k, j, r[i][j]);
		      //getch();
		     }
		     else
		     {
		       r[i][j] = r[i][j];
		      printf("\n r[%d][%d] = r[%d][%d] = %d ", i, j, i, j, r[i][j]);
		     }
	      }
	      printf("\n");
	    }
	    //printf("\n Step %d \n", k);
	   // Output(n, a);
	   // Output(n,r);
	    //Output(n,p);
	   //getch();
	}
}

/* Function main */

    void main()
       {
	 int a[size][size];
	 int r[size][size];
	 int p[size][size];
	 int n;
	 clrscr();
	 printf("\n Input number of vertices in the graph: ");
	 scanf("%d", &n);
	 Input(n,a);
	 printf("\n Adjacency matrix\n");
	 Output(n,a);
	 warshall(n,a,r,p);
	 printf("\n Shortest cost matrix \n");
	 Output(n,r);
	 printf("\n Shortest path matrix \n");
	 Output(n,p);
	 printf("The value of 9 in path matrix means no change from initial matix");

	 getch();
      }

