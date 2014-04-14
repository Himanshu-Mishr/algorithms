/* Traveling Salesman Problem Using Dynamic Programming,
starting and termination vertext is '1' */

#include<iostream.h>
#include<conio.h>
#define max 100
#define infinity 999

int tspdp(int c[][max],int tour[],int star,int n);

int main()
{
int n;
int i,j,c[max][max];
int tour[max],cost;
clrscr();

cout<<"Travelling Salesman Problem Using Dynamic Programming\n";
cout<<"\nEnter number of cities to traverse:";
cin>>n;
cout<<"Enter cost matrix:\n";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
cin>>c[i][j];
if(c[i][j]==0)
c[i][j]=999;
}
for(i=0;i<n;i++)
tour[i]=i;
cost=tspdp(c,tour,0,n);
cout<<"Minimum Cost:"<<cost<<endl;
cout<<"Tour:\n";
for(i=0;i<n;i++)
cout<<tour[i]+
1<<"-";
cout<<"1\n";
getch();
return 0;
}
int tspdp(int c[][max],int tour[],int start,int n)
{
int i,j,temp[max],mintour[max],k;
int mincost,cost;
if(start==n-2)
return c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0];
mincost=infinity;

for(i=start+1;i<n;i++)
{
for(j=0;j<n;j++)
temp[j]=tour[j];
temp[start+1]=tour[i];
temp[i]=tour[start+1];
if(c[tour[start]][tour[i]]+(cost=tspdp(c,temp,start+1,n))<mincost)
{
mincost=c[tour[start]][tour[i]]+cost;
for(k=0;k<n;k++)
mintour[k]=temp[k];
}
}
for(i=0;i<n;i++)
tour[i]=mintour[i];
return mincost;
}









