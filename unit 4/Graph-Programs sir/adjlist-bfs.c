//Implementation of BFS traversal of graph using adjacency list representation

#include<stdio.h>
#include<stdlib.h>
#define maxnodes 10

typedef struct node
{
    int data;
    struct node *link;
}graph;

void initgraph(graph **, int);
void insert_node(graph **,int ,int);
void creategraph(graph **);
void display(graph **,int);

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

      
void creategraph(graph **nodep)
{
    int i,j;
    while(1)
    {
    printf("enter the node and its adjacdnt node information");
    scanf("%d %d",&i,&j);
    if(i==0 && j==0)
        break;
    insert_node(nodep,i,j);
    }
}


void insert_node(graph **nodep,int i,int j)
{
   graph *temp,*cur;
   temp= (graph *) malloc(sizeof(graph));
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
   

void display(graph **nodep,int n)
{
    graph *cur;
    for(int i=1;i<=n;i++)
    {
        cur=nodep[i];
        printf("\nthe nodes adjecent to node %d:",i);
        while(cur!=NULL)
        {
            printf("%3d",cur->data);
            cur=cur->link;
        }
    } 
} 

void bfs(graph **nodep,int v,int *visited)
{
    int queue[10],r=-1,f=0,q_front,adj; 
    
    visited[v]=1;
    printf("\n%d",v);
    queue[++r]=v;
    while(f<=r)
    {
        q_front=queue[f++];
        //printf("\nthe value of front=%d",q_front);
        for(graph *p=nodep[q_front];p!=NULL;p=p->link)
        {
            adj=p->data;

            if(visited[adj]==0)
            {
                visited[adj]=1;
                queue[++r]=adj;
                printf("\n%d",adj);
            }
        }
    }
}
                
               
int main()
{
    
    graph *nodelist[maxnodes];
    int n,ch,visited[maxnodes],source;
     
    do
    {
        printf("\nEnter 1: creategraph() 2: display 3:bfs() 4:exit()");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
            case 1:printf("enter the number of nodes in the graph");
                   scanf("%d",&n);
                   initgraph(nodelist,n);
                   creategraph(nodelist);
                   break;
            case 2: display(nodelist,n);
                    break;
            
            case 3: initvisited(visited,n);
                    printf("enter the source node");
                    scanf("%d",&source);
                    printf("\nThe nodes visited using BFS traversal are");
                    bfs(nodelist,source,visited);  
                    for(int i=1;i<=n;i++)
                       if(visited[i]==0)
                            bfs(nodelist,i,visited);
                    break;
                            
                                              
        }
    }while(ch!=4);
}
             
    
    
    
    
    
    
    
    
    
    
    
    
    