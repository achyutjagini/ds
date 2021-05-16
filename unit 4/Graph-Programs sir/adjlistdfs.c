//Implementation of DFS Traversal of a  graph using adjacency list Representation

#include<stdio.h>
#include<stdlib.h>

#define maxnodes 10

typedef struct node
{
    int data;
    struct node *link;
}graph;

void initgraph(graph **nodep,int n)
{
    for(int i=1;i<=n;i++)
        nodep[i]=NULL;
}

void initvisited(int *visited,int n)
{
    for(int i=1;i<=n;i++)
        visited[i]=0;
}

void insertnode(graph **nodep,int i,int j)
{
    graph *temp,*cur;
    temp=(graph *) malloc(sizeof(graph));
    temp->data=j;
    temp->link=NULL;
    cur=nodep[i];
    if(cur==NULL)
        nodep[i]=temp;
    else
    {
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=temp;
    } 
}


void creategraph(graph **nodep)
{
    int i,j;   
    while(1)
    {
    printf("enter the node and its adjacent node's informtion");
    scanf("%d %d",&i,&j);
    if(i==0 && j==0)
        break;
    insertnode(nodep,i,j);
    }
    
}

void display(graph **nodep,int n)
{
    graph *cur;
    for(int i=1;i<=n;i++)
    {
        cur=nodep[i];
        printf("\nthe adjacent nodes to node %d:",i);
        while(cur!=NULL)
        {
            printf("%3d",cur->data);
            cur=cur->link;
        }
    }
            
}

void dfs(graph **nodep,int v,int *visited)
{
    int adj;
    visited[v]=1;
    printf("\n%d",v);
    for(graph *p=nodep[v];p!=NULL;p=p->link)
    {
        adj=p->data;
        if(visited[adj]==0)
            dfs(nodep,adj,visited);
    }
}
    


int main()
{
    graph *listnode[maxnodes];
    int ch,n,visited[maxnodes],source;
    do
    {
        printf("\n Enter 1:creategraph() 2:display() 3: dfs() 4:Exit()");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
            case 1: printf("enter the number of nodes in the graph");
                    scanf("%d",&n);
                    initgraph(listnode,n);
                    creategraph(listnode);
                    break;
            case 2: display(listnode,n);
                    break;
            case 3: initvisited(visited,n);
                    printf("\nenter the source node");
                    scanf("%d",&source);
                    printf("\nnodes visited using DFS traversal are.....");
                    dfs(listnode,source,visited);
                    for(int i=1;i<=n;i++)
                        if(visited[i]==0)
                            dfs(listnode,i,visited);
                        break;
                    
                    break;
        }
    }while(ch!=4);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
