//Implementation of finding and printing the path between
// source and destination nodes in a graph
#include<stdio.h>
#define maxnodes 10

int visited[maxnodes],path[maxnodes],path_index;

void init_visited()
{
for(int i=1;i<=maxnodes;i++)
    visited[i]=0;
}

void initgraph(int adjmat[][maxnodes],int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        adjmat[i][j]=0;
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


int findpath_dfs(int adjmat[][maxnodes],int s,int d,int n)
{
    visited[s]=1;
    path[path_index++]=s;
    if(s==d)
        return 1;
     for(int i=1;i<=n;i++)
     {
        if(adjmat[s][i]==1 && visited[i]==0)
            if(findpath_dfs(adjmat,i,d,n)==1)
                return 1; 
               
     }
     path_index--;
}


        
int main()
{
    int adjmat[maxnodes][maxnodes],ch,n,s,d,flag=0; 
     
    do
    {
        printf("\nEnter 1:creategraph() 2: display() 3:find path() 4:exit()");
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
            
            case 3: init_visited();
                    path_index=0;
                    printf("enter the source and destination");
                    scanf("%d %d",&s,&d);
                    flag=findpath_dfs(adjmat,s,d,n);
                    if(flag==1)
                    {
                    printf("\nthere exists path");
                    printf("the length of the path is=%d",(path_index-1));
                    for(int i=0;i<path_index;i++)
                        printf("\n%d",path[i]);   
                    }                    
                    else
                         printf("\npath does not exist");
                           
        }
    }while(ch!=4);
}

