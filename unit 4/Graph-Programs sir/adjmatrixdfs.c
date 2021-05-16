//Implementation of DFS Traversal using adjacency matrix Representation
#include<stdio.h>

#define maxnodes 10

void initgraph(int [][maxnodes],int);
void creategraph(int [][maxnodes]);
void display(int [][maxnodes],int);
void initvisited(int *,int);
void dfs(int adjmat[][maxnodes],int,int,int *);
int check_connectivity(int *,int);



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
        if(adjmat[v][i]==1 && visited[i]==0)
            dfs(adjmat,i,n,visited);
            
    
}


int check_connectivity(int *visited,int n)
{
    for(int i=1;i<=n;i++)
        if(visited[i]==0)
            return 0;
    return 1;
        
}



int main()
{
    int adjmat[maxnodes][maxnodes],ch,n,visited[maxnodes],source,flag=0;
    
    
    do
    {
        printf("\nEnter 1:creategraph() 2: display() 3:dfs() 4:check_connectivity() 5:exit()");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
            case 1: printf("\Enter the number of nodes in the graph");
                    scanf("%d",&n);
                    initgraph(adjmat,n);
                    creategraph(adjmat);
                    break;
            case 2: display(adjmat,n);
                    break;
            case 3: initvisited(visited,n);
                    printf("enter the source node");
                    scanf("%d",&source);
                    dfs(adjmat,source,n,visited);
                    for(int i=1;i<=n;i++)
                        if(visited[i]==0)
                            dfs(adjmat,i,n,visited);
                    break;
            case 4: initvisited(visited,n);
                    printf("enter the source node for DFS traversal");
                    scanf("%d",&source);
                    dfs(adjmat,source,n,visited);
                    flag=check_connectivity(visited,n);
                    if(flag==0)
                        printf("\n graph is not connected");
                    else
                        printf("\n graph is connected");
            
        }
    }while(ch!=5);
}

