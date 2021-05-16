//Implementation to check whether the directed graph is strongly, 
//weakly or neither strogly or weakly connected
#include<stdio.h>
#define maxnodes 10

void initgraph(int adjmat[][maxnodes],int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        adjmat[i][j]=0;
}

void initvisited(int *visited,int n)
{
    
    for(int i=1;i<=n;i++)
        visited[i]=0;
}

// to check wheter the undirected graph is connected or not

int check_conn_undir(int *visited,int n)
{
    for(int i=1;i<=n;i++)
        if(visited[i]==0)
            return 0;
   return 1;
}   
            


void creategraph(int adjmat[][maxnodes])
{
    int i,j;
    while(1)
    {
    printf("enter the nodes and its adjacent node information");
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


void dfs(int adjmat[][maxnodes],int v,int n,int *visited)
{
    visited[v]=1;
    printf("\n %d",v);
    for(int i=1;i<=n;i++)
    {
        if(adjmat[v][i]==1 && visited[i]==0)
            dfs(adjmat,i,n,visited);
    }
}

int check_strongly_connected(int adjmat[][maxnodes],int n,int *visited)
{
    for(int i=1;i<=n;i++)//from each node should reach all other nodes on dfs
    {
      initvisited(visited,n);
      dfs(adjmat,i,n,visited);
      
      for(int j=1;j<=n;j++)
          if(visited[j]==0)
              return 0;
    }

    return 1;
}

int check_weakly_connected(int adjmat[][maxnodes],int n,int *visited)
{
    int b[maxnodes][maxnodes];//making undirected graph
    initgraph(b,n);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(adjmat[i][j]==1)
                b[i][j]=b[j][i]=1;//making undirected graph
 
   initvisited(visited,n);
   dfs(b,1,n,visited);
  
   for(int k=1;k<=n;k++)
     if(visited[k]==0)
        return 0;

   return 1;//changing it to undirected graph results in all visited=1
            
              
}


int main()
{
    int adjmat[maxnodes][maxnodes],ch,n,visited[maxnodes],source,flag_unconn=0,s,d,strong_conn=1,weak_conn=0;
    
    
    do
    {
        printf("\n Enter 1:creategraph() 2: display() 3:dfs() 4:check_conn_undir() 5: strong_weak() 6:Exit()");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
            case 1: printf("\n Enter the number of nodes in the graph");
                    scanf("%d",&n);
                    initgraph(adjmat,n);
                    creategraph(adjmat);
                    break;
                    
            case 2: display(adjmat,n);
                    break;
            
            case 3: initvisited(visited,n);
                    printf("\nEnter the source node for dfs traversal");
                    scanf("%d",&source);
                    printf("\n nodes visited using DFS traversal are");
                    dfs(adjmat,source,n,visited);
                    for(int i=1;i<=n;i++)
                        if(visited[i]==0)
                            dfs(adjmat,i,n,visited);
                          break;
         
           case 4:  initvisited(visited,n); 
                    dfs(adjmat,2,n,visited);
                    flag_unconn=check_conn_undir(visited,n);
                    if(flag_unconn==1)
                        printf("\n the graph is connected");
                    else
                        printf("\n the graph is not connected");
                    break;
       
          case 5:   strong_conn=check_strongly_connected(adjmat,n,visited);
                    if(strong_conn==1)
                        printf("graph is strongly connected");
                    else
                    {
                        weak_conn=check_weakly_connected(adjmat,n,visited);
                        if(weak_conn==1)
                            printf("weakly connected");
                        else
                            printf("neither strongly connected or weakly connected");
                    }
                        
          
        }
        
    }while(ch!=6);
}    
