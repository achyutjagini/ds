//implementation of adjacency matrix representation

#include<stdio.h>
#include<stdlib.h>

#define maxnodes 6

void initgraph(int adj_mat[][maxnodes])//set all reqd elements in matrix to zero
{
for(int i=1;i<=maxnodes;i++)
    for(int j=1;j<=maxnodes;j++)
        adj_mat[i][j]=0;
}

void creategraph(int adj_mat[][maxnodes],int n)
{
int i,j;
   while(1)
   {
    printf("enter source node and destination node info");
    scanf("%d %d",&i,&j);
  
     if(i==0 && j==0)
        break;
     adj_mat[i][j]=1;   
   }
}

void display(int adj_mat[][maxnodes],int n)
{
  for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        printf("%3d",adj_mat[i][j]);
    }
    printf("\n");
}

}
int main()
{
int ch,n;
int adjmat[maxnodes][maxnodes];
initgraph(adjmat);
while(1)
{
printf("enter option 1.creategraph 2.display 3.exit");
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

            case 3:
             exit(1);
              break;
     
}


}
}