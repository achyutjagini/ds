//implementation of adjacency list representation
#include<stdio.h>
#include<stdlib.h>
#define maxnodes 50
typedef struct node
{
int data;
struct node *link;    
}graph;

void insert_node(graph **nodep,int i,int j)
    {
        graph *cur;
        graph *temp;
        temp=(graph *)malloc(sizeof(graph));
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

void initvisited(int *visited,int n)
{
    for(int i=1;i<=n;i++)
        visited[i]=0;

}

void dfs(graph **nodep,int v,int n,int *visited)
{
visited[v]=1;
int adj;
printf("%d \n",v);

for(graph *p=nodep[v];p!=NULL;p=p->link)
{
     adj=p->data;
     if(visited[adj]==0)
       dfs(nodep,adj,v,visited);
}
}



void create_graph(graph *nodep)
{
int i,j;
while(1)
{
printf("enter source and destination nodes");
scanf("%d %d",&i,&j);
if(i==0 && j==0)
   break;
insert_node(nodep,i,j);   
}
}

void display(graph **nodep,int n)
{
int i;
graph *cur;
for(i=1;i<=n;i++)
{
    cur=nodep[i];
    printf("\n the nodes adjacent to node %d are=",i);
    while(cur!=NULL)
    {
      printf("\t%d",cur->data); 
      cur=cur->link; 
    }
}


}
int main()
{
int i;
int n,ch;
int visited[40];
int source;
graph *nodelist[maxnodes];

printf("enter number of number of nodes in the graph");
scanf("%d",&n);
for(i=1;i<=n;i++)
    nodelist[i]=NULL;

while(1)
{printf("\nenter option 1.create graph 2.display 3.dfs 4.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:create_graph(nodelist);
              break;

       case 2:display(nodelist,n);
              break;
              

       case 4:exit(0); 
               break; 
       
        case 3:
             initvisited(visited,n);
             printf("enter source node"); 
             scanf("%d",&source);
             dfs(nodelist,source,n,visited);
             for(int i=1;i<=n;i++)
                if(visited[i]==0)
                  dfs(nodelist,i,n,visited);
               break;  

               

      default:
             break;
   }
   
  }    



}
