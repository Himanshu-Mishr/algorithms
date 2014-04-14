/* This program will place 8 queens in a chessboard, so that they don't
attack each other, which means to two queens can be in the same row,
column and diagonal */

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<process.h>
#include<graphics.h>
#include<stdio.h>

static int t[10]={-1};
void queens(int i);
int empty(int i);

void print_solution();

int main()
{
clrscr();
queens(1);
print_solution();
getch();
return(0);
}

void queens(int i)
{
char resp;
for(t[i]=1;t[i]<=8;t[i]++)
{
if(empty(i))
{
if(i==8)
{
print_solution();
/* If this exit is commented, it will show ALL possible combinations */
printf ("\nType any letter to get another solution (Q for Quit):  \n");
scanf (" %c",&resp);
if (resp== 'Q') exit(0);
//getch();
//exit(0);
//getch();
}
else
{
// Recurse!
queens(i+1);
}
}// if
}// for
}



int empty(int i)
{
int j;
j=1;

while(t[i]!=t[j] && abs(t[i]-t[j])!=(i-j) &&j<8)j++;
return((i==j)?1:0);
}

void print_solution()
{
int i;
printf("Row -- Column \n");
for(i=1;i<=8;i++)printf("\nt[%d] = [%d]",i,t[i]);
}


