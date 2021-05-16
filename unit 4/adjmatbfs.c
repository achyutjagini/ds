//implementation of adjacency matrix representation

#include<stdio.h>
#include<stdlib.h>
#define maxnodes 20
void initvisited(int *visited,int n)
{
    for(int i=1;i<=n;i++)
        visited[i]=0;
}

void initgraph(int adj_mat[][maxnodes])//set all reqd elements in matrix to zero
{
for(int i=1;i<=maxnodes;i++)
    for(int j=1;j<=maxnodes;j++)
        adj_mat[i][j]=0;
}

void insertqueue(int q[],int v,int *r)
{
    q[++(*r)]=v;
}
int qempty(int *f,int *r)
{
  if(*r<*f)
     return 0;
   else
   {
    return 1;
   }
     
}

int deletequeue(int q[],int *f)
{
    return(q[(*f)++]);
}

void bfs(int adj[][maxnodes],int v,int n,int *visited)
{
int q[10],f=0,r=-1,q_front;
visited[v]=1;
printf("\n %d",v);
insertqueue(q,v,&r);
while (qempty(&f,&r))
{
    q_front=deletequeue(q,&f);
    for(int i=1;i<=n;i++)
    {
     if(adj[v][i]==1 && visited[i]==0)
     {
         visited[i]=1;
         printf("\n %d",i);
         insertqueue(q,i,&r);
     }
    }
}
}



void creategraph(int adj_mat[][maxnodes],int n)
{
int i,j;
   while(1)
   {
    printf("enter source node and destination node info");
    scanf("%d %d",&i,&j);
  
     if(i==0 && j==0)
        break;
     adj_mat[i][j]=1;   
   }
}

void display(int adj_mat[][maxnodes],int n)
{
  for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        printf("%3d",adj_mat[i][j]);
    }
    printf("\n");
}

}
int main()
{
int source;
int ch,n;
int adjmat[maxnodes][maxnodes];
initgraph(adjmat);
int visited[40];
while(1)
{
printf("\n enter option 1.creategraph 2.display 3.bfs 4.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:printf("no of nodes you want to enter information");
              scanf("%d",&n);
              creategraph(adjmat,n);
              break;

             case 2:
            display(adjmat,n);
              break;

            case 4:
             exit(1);
              break;

            case 3:
              initvisited(visited,n);
             printf("enter source node"); 
             scanf("%d",&source);
             printf("\n nodes visited using bfs traversal are");
             bfs(adjmat,source,n,visited);
             for(int i=1;i<=n;i++)
                if(visited[i]==0)
                  bfs(adjmat,i,n,visited);
               break;
             break;
}


}
}