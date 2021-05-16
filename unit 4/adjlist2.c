//implementation of adjacency list representation
#include<stdio.h>
#include<stdlib.h>
#define maxnodes 50
typedef struct node
{
int data;
struct node *link;    
}graph;

void insert_node(graph **node_p,int i,int j)
    {
        /* Add j to adj list of i */
        graph *temp;
        graph *cur;
        temp=(graph *)malloc(sizeof(graph));
        temp->data=j;
        temp->link=NULL;
         
         
         cur = node_p[i];

        if(node_p[i] == NULL) /* First Node */
            node_p[i]=temp;
        else
        {
            while(cur->link != NULL)
                cur = cur->link;
            cur->link = temp;
        }

 /*       // Add i to adj list of j 
        graph *temp1;
        temp1 = (graph *)malcur(sizeof(graph));
        temp1->data = i;
        temp1->link = NULL;

        if(node_p[j] == NULL) // First Node 
            node_p[j]=temp1;
        else
        {
            graph *cur;
            cur = node_p[j];
            while(cur->link != NULL)
                cur = cur->link;
            cur->link = temp1;
        }*/
    }

void create_graph(graph **nodep)
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
graph *nodelist[maxnodes];
printf("enter number of number of nodes in the graph");
scanf("%d",&n);
for(i=1;i<=n;i++)
    nodelist[i]=NULL;

while(1)
{printf("\nenter option 1.create graph 2.display 3.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:for(i=1;i<=n;i++)
                nodelist[i]=NULL;
             create_graph(nodelist);
              break;

       case 2:display(nodelist,n);
              break;
              

       case 3:exit(0); 
               break; 

      default:
             break;
   }
   
  }    



}

