/* Job sequencing using greedy method */

#include<stdio.h>

int n,i,j,k,t;
int check(int s[],int p)
       {  int ptr=0;
	   for(int i=0;i<n;i++)
	   {if(s[i]==p)
	       ptr++;
      }
	    if(ptr==0)
	    return 1;
	    else
	    return 0;
	}

int main()
{
     printf("enter the no of jobs      : ");
     scanf("%d",&n);
     int slot[20],profit,p[20],d[20];
     for(i=0;i<n;i++)
       {printf("\nenter the profit of job #%d      :",i+1);
       scanf("%d",&p[i]);
       printf("\nenter the deadline of job #%d    :",i+1);
       scanf("%d",&d[i]);
       }

     for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	 if(p[i]<p[j])
	    { t=p[i];
	      p[i]=p[j];
	      p[j]=t;
	      t=d[i];
	      d[i]=d[j];
	      d[j]=t;
	    }

       for(i=0;i<n;i++)
	   slot[i]=0;

    for(i=0;i<n;i++)
	   for(j=d[i];j>0;j--)
	   {
            if(check(slot,j)==1)
		      {
                slot[i]=j;
	           	break;
                }
	   }

     printf("\n\n INDEX   PROFIT  DEADLINE  SLOT ALLOTED ");
     for(i=0;i<n;i++)
     {
        if(slot[i]>0)
            printf("\n\n   %d       %d        %d        [%d - %d]", i+1,p[i],d[i],(slot[i]-1),slot[i]);
        else
            printf("\n\n   %d       %d        %d       REJECTED", i+1,p[i],d[i]);
     }
}

// enter the no of jobs      : 4

// enter the profit of job #1      :70
// enter the deadline of job #1    :2
// enter the profit of job #2      :12
// enter the deadline of job #2    :1
// enter the profit of job #3      :18
// enter the deadline of job #3    :2
// enter the profit of job #4      :35
// enter the deadline of job #4    :1
 
//  INDEX   PROFIT  DEADLINE  SLOT ALLOTED 
//    1       70        2        [1 - 2]
//    2       35        1        [0 - 1]
//    3       18        2       REJECTED
//    4       12        1       REJECTED~     
