#include<stdio.h>
#include<stdlib.h>
#define NUMNODES 7
int node[NUMNODES];

void inserttree(int ele)
{
int q=0;
if(node[q]==-1)
   node[q]=ele;
   else if(node[q]==ele)
   {
       printf("duplicate can't insert");
   }
else
{
    while(q<NUMNODES && node[q]!=-1 && ele!=node[q])
    {
        if(ele<node[q])
           q=2*q+1;
        else
        {
            q=2*q+2;
        }
    }   
 }
if(q!=0 && ele==node[q])
   printf("duplicate element can't insert");
else if(q>=NUMNODES)
      printf("invalid insertion");
 else
 {
     node[q]=ele;
 }
      
}


void inorder(int i)
{
if(node[i]==-1 || i>NUMNODES-1)
   return;
inorder(2*i+1);
printf("\n%d",node[i]);
inorder(2*i+2);
}

int main()
{
int element,ch,i;
for(i=0;i<NUMNODES;i++)
   node[i]=-1;
while(1)
{printf("\nenter option 1.insert 2.traverse 3.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:printf("Enter the value\n");
              scanf("%d",&element);
              inserttree(element);
              break;

       case 2:printf("\n array elements are");
              for(i=0;i<NUMNODES;i++)
              {
                 printf("\n%d",node[i]); 
              }
              printf("\ninorder traversal of tree");
              inorder(0);
              break;
       case 3:exit(0); 
               break;
      default:
             break;
   }
  }
}