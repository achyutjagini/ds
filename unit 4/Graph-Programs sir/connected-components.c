//To print the connected components of the graph
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

int check_connectivity(int *visited,int n)
{
//all nodes should be visited
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
    printf("\n%d",v);
    for(int i=1;i<=n;i++)
    {
        if(adjmat[v][i]==1 && visited[i]==0)
            dfs(adjmat,i,n,visited);
    }
}



int main()
{
    int adjmat[maxnodes][maxnodes],ch,n,visited[maxnodes],source,flag=0,s,d;
    
    
    do
    {
        printf("\nEnter 1:creategraph() 2: display() 3:check_conn 4: numbre of connected comp 5:exit()");
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
           
           case 3:  initvisited(visited,n);
                    printf("\nEnter the source node for dfs traversal");
                    scanf("%d",&source);
                    printf("\nnodes visited using DFS traversal are");
                    dfs(adjmat,source,n,visited);
                    flag=check_connectivity(visited,n);
                    if(flag==0)
                        printf("\ngraph is not connected");
                    else 
                        printf("\ngraph is connected");
                    break;
  
           case 4:  initvisited(visited,n);//all become 0
                    int count=0;
                    for(int i=1;i<=n;i++)
                    {
                        if(visited[i]==0)   //visited[1]=0
                        {
                            count++;    //count=1 
                            printf("\n connected component of %d",count);
                            dfs(adjmat,i,n,visited);//1,2,4,3 
                        }
                    }
                    printf("\nthe number of connected components are %d",count);
                    break;
        }
    }while(ch!=5);
}

