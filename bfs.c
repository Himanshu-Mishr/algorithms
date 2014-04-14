
 
#include<stdio.h>

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
 for(i=1;i<=n;i++)
  if(a[v][i] && !visited[i])
   q[++r]=i;
 if(f<=r)
 {
  visited[q[f]]=1;
  bfs(q[f++]);
 }
}
int main()
{
 int v;
 
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }
 printf("\n Enter graph data in matrix form:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 printf("\n Enter the starting vertex:");
 scanf("%d",&v);
 bfs(v);
 printf("\n The node which are reachable are:\n");
 for(i=1;i<=n;i++)
  if(visited[i])
   printf("%d\t",i);
  else
   printf("\n Bfs is not possible");
 
}

// BFS (G, s)
//                 Times   Cost
// 1   for each vertex u ∈ G.V - {s} do    |V| O(V)
// 2      u.color ← WHITE  |V|-1    
// 3      u.d ← ∞  |V|-1    
// 4      u.Π ← NIL    |V|-1    
//     -- Initialize the source vertex and Queue        
// 5   s.color ← GRAY  1    
// 6   s.d ← 0 1    
// 7   s.Π ← NIL    1    
// 8   Q ← ∅   1    
// 9   Enqueue (Q, s)  1    
//     -- Perform breadth first search      
// 10  while Q ≠ ∅ do  |V|+1   O(V)
// 11     u ← Dequeue (Q)  |V|  
// 12     for each v ∈ G.Adj[u] do |V|+|E|+1   O(V+E)
// 13         if v.color = WHITE then  |V|+|E|  
// 14            v.color ← GRAY    |V|  
// 15            v.d ← u.d + 1 |V|  
// 16            v.Π ← u   |V|  
// 17            Enqueue (Q, v)    |V|  
// 18     u.color ← BLACK  |V|  

