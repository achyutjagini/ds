//Implementation of graphs using adjacency matrix
#include<stdio.h>

#define maxnodes 10

void initgraph(int [][maxnodes],int);
void creategraph(int [][maxnodes]);
void display(int [][maxnodes],int);
void initvisited(int *,int);
int check_connectivity(int *,int);
void bfs(int[][maxnodes],int,int,int *);



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




void insert_queue(int q[],int v,int *f,int *r)
{
    q[++(*r)]=v;
}

int qempty(int *f,int *r)
{
    if(*r< *f)
        return 0;
    else
        return 1;
}

int delete_queue(int q[],int *f,int *r)
{
    return (q[(*f)++]);
}


void bfs(int adjmat[][maxnodes],int v,int n,int *visited)
{
    int q[10],f=0,r=-1,q_front;
    visited[v]=1;
    printf("\n%d",v);
    insert_queue(q,v,&f,&r);
    while(qempty(&f,&r))
    {
        q_front=delete_queue(q,&f,&r);
        for(int i=1;i<=n;i++)
        {
            if(adjmat[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                printf("\n%d",i);
                insert_queue(q,i,&f,&r);
            }
        }
    }
}
            
        
    
    



int main()
{
    int adjmat[maxnodes][maxnodes],ch,n,visited[maxnodes],source,flag=0;
    
    
    do
    {
        printf("\nEnter 1:creategraph() 2: display() 3:check_connectivity 4: bfs 5:exit()");
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
            
            case 3: flag=check_connectivity(visited,n);
                    if(flag==0)
                        printf("\ngraph is not connected");
                    else 
                        printf("\ngraph is connected");
                    break;
            case 4: initvisited(visited,n);
                    printf("enter the source node to visit");
                    scanf("%d",&source);
                    printf("\nthe nodes visited using bfs traversal are");
                    bfs(adjmat,source,n,visited);
                    for(int i=1;i<=n;i++)
                        if(visited[i]==0)
                            bfs(adjmat,i,n,visited);
                    break;
                        
        }
    }while(ch!=5);
}

