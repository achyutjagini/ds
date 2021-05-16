//right in-threaded binary search tree

//binary tree in which right pointer points to inorder successor 
//in case it's not pointing to the child (no right child)

//rightmost node of tree has NULL right pointer,as it has no inorder successor
//rthread indicates if right pointer is a thread,if it is true(1)-pointer is thread
//rthread of rightmost node also true even though rlink NULL

#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
int data;
struct node *llink; 
struct node *rlink;
int rthread; 
}
threadbst;

threadbst *root=NULL;

threadbst *getnode(int ele)
{
threadbst *temp;
temp=(threadbst *)malloc(sizeof(threadbst));
temp->data=ele;
temp->llink=NULL;
temp->rlink=NULL;
temp->rthread=1;
return temp;       
}

void insertleft(threadbst *prev,threadbst *temp)//temp is new node inserted
{
prev->llink=temp;

temp->rlink=prev;//new node rlink to inorder successor   
}

void insertright(threadbst *cur,threadbst *temp)
{
//cur points to node which has right link as thread
temp->rlink=cur->rlink;

cur->rlink=temp;//temp becomes right child of cur

cur->rthread=0;  //making 0 as node gets a rightchild so right pointer not thread
}

void insert(int ele)
{
threadbst *temp,//new node
temp=getnode(ele);

threadbst *prev=NULL;//prev should become inorder predecessor of ele
threadbst *cur=root;

if(root==NULL)
{
root=temp;
return;
}


while(cur!=NULL)
{
 prev=cur;
 if(ele<cur->data)
   cur=cur->llink;
 
  else   //ele>cur->data
 {
      if(cur->rthread==1)
        break;//exit while and else

        cur=cur->rlink;
 } 

}//end while

if(cur==NULL)
   insertleft(prev,temp);

else
    insertright(cur,temp);

}

void inorder(threadbst *root)
{
threadbst *prev,*cur=root;
printf("\n entering inorder traversal");
  do{
  prev=NULL;

  while(cur!=NULL)//make prev to point to smallest node
  {
      prev=cur;
      cur=cur->llink;
  }
  if(prev!=NULL)
  {
    printf("\n%d",prev->data);
   
     cur=prev->rlink; //cur is inorder successor of smallest node(could be right child also)

    
    while(prev->rthread==1 && cur!=NULL)//if prev node has rlink as thread
    {
     printf("\n%d",cur->data); 
     prev=cur;
     cur= cur->rlink; 
    }
  } 
    }while(prev!=NULL);
}
int main()
{
    /*
int ch,element;

while(1)
{printf("\n enter option 1.insert 2.traverse 3.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:printf("Enter the value\n");
              scanf("%d",&element);
              insert(element);
              break;

       case 2:inorder(root);
              break;
       case 3:exit(1);
              break; 
       default:
       break;       
   }
  }
 }*/

insert(100);
insert(50);
insert(120);
insert(110);
insert(130);
insert(60);
insert(30);
insert(10);
inorder(root);}




