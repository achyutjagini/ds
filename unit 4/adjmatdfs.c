//implementation of adjacency matrix representation
#include<stdio.h>
#include<stdlib.h>

#define maxnodes 10

void initgraph(int adjmat[][maxnodes])
{
for(int i=0;i<=maxnodes;i++)
    for(int j=0;j<=maxnodes;j++)
        adjmat[i][j]=0;
}

void initvisited(int *visited,int n)
{
    for(int i=1;i<=n;i++)
        visited[i]=0;
}

int check_connectivity(int *visited,int n)
{
  for(int i=1;i<=n;i++)
      if(visited[i]==0)
         return 0;
  return 1;       

}


void dfs(int adjmat[][maxnodes],int v,int n,int *visited)
{
int i;
visited[v]=1;
printf("%d\n",v);
for(i=1;i<=n;i++)
   if(adjmat[v][i]==1 && visited[i]==0)
      dfs(adjmat,i,n,visited);
    
}

void creategraph(int adjmat[][maxnodes],int n)
{
int i,j;
   while(1)
   {
    printf("enter source node and destination node info");
    scanf("%d %d",&i,&j);
     if(i==0 && j==0)
        break;
     adjmat[i][j]=1;   
   }
}

void display(int adjmat[][maxnodes],int n)
{
  for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        printf("%3d",adjmat[i][j]);
    }
    printf("\n");
}

}
int main()
{
int ch,n;
int source;
int i,flag;
int visited[40];
int adjmat[maxnodes][maxnodes];
initgraph(adjmat);
while(1)
{
printf("enter option 1.creategraph 2.display 3.dfs 4.check_conn 5.exit");
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

            case 5:
             exit(1);
              break;

             case 3:
             initvisited(visited,n);
             printf("enter source node"); 
             scanf("%d",&source);
             dfs(adjmat,source,n,visited);
             for(int i=1;i<=n;i++)
                if(visited[i]==0)
                  dfs(adjmat,i,n,visited);
               break;  
             
             case 4:
             initvisited(visited,n);
             printf("enter source node for dfs traversal"); 
             scanf("%d",&source);
             dfs(adjmat,source,n,visited);
             flag=check_connectivity(visited,n);
             if(flag==0)
                printf("graph is not connected \n ");
             else 
                printf("graph is connected \n");   
             break;
}


}
}