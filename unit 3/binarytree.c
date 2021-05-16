#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node bstnode;
bstnode *root=NULL;

void insert(int ele)
{
    bstnode *cur,*prev,*temp;
    temp=(bstnode *)malloc(sizeof(bstnode));
    temp->data=ele;
    temp->llink=temp->rlink=NULL;
    cur=root;
    prev=NULL;
    if(root==NULL)
       root=temp;
    else
    {  
        while(cur!=NULL)
        {
          prev=cur;
         if(ele < cur->data)
            cur=cur->llink;
         else
           cur=cur->rlink;
        }
    if(ele < prev->data)    
      prev->llink=temp;
       else
        prev->rlink=temp;
    }
}

void inorder(bstnode *node )
{   if(node==NULL)
       {return;}
 //else if (node!=NULL)
   // {
        inorder( node->llink ); 
        printf( "%d\n", node->data );
        inorder( node->rlink );
   // }
}

/*bstnode *search(bstnode *root,int key)
{   bstnode *cur=root;
    if(cur)
    {
        if(key<cur->data)
        {
          cur=search(root->llink,key);
        }
        else if(key>cur->data)
       {
         cur=search(root->rlink,key);
       }
    }
return cur;
}*/
bstnode *search(int key,bstnode **prev)
{
    bstnode *cur;
    //(*prev)=NULL;
    cur=root;
    if(key==cur->data)
           return cur;
    while(cur!=NULL)
    {
       if(key==cur->data)
          return cur;
        else
        {
            (*prev)=cur;
           if(key<cur->data)
              cur=cur->llink;
           else
           {
                cur=cur->rlink;
           }
              
               
        }
           
    }
    //return cur;
}

void deletebst(int ele)
{
bstnode *cur,*prev,*insucc,*inprev;
cur=search(ele,&prev);
//deleted node has both left and right subtree-working
if(cur->llink!=NULL && cur->rlink!=NULL)
{
    inprev=cur;
    insucc=cur->rlink;
    while(insucc->llink!=NULL)
    {
        inprev=insucc;
        insucc=insucc->llink;
    }
    cur->data=insucc->data;
    if(inprev==cur)
    {
        inprev->rlink=insucc->rlink;
    }
    else
        inprev->llink=insucc->rlink;
free(insucc);        
return;    
}
//deleted node has only 1 subtree
if(cur->llink!=NULL||cur->rlink!=NULL)
{
if(cur==root)
{
    if(cur->llink!=NULL)
    {root=cur->llink;//i just changed
    }
    else 
    root=cur->rlink;
}
else if(prev->llink==cur)
     prev->llink=cur->llink;
else
{
    prev->rlink=cur->rlink;
}
cur=NULL;
free(cur);
return;
}

//deleted node is leaf node-working
if(cur->llink==NULL && cur->rlink==NULL)
{
if(cur==root)
   root=NULL;

else if(prev->llink==cur)
     prev->llink=NULL;
else
{
    prev->rlink=NULL;
}
   return;     
}
}

int main()
{   
int ch,element,ele;
bstnode *prev,*sersucc;
while(1)
{printf("enter option 1.insert 2.delete 3.traverse 4.exit 5.search");
scanf("%d",&ch);
switch(ch)

    {
       case 1:printf("Enter the value\n");
              scanf("%d",&element);
              insert(element);
              break;

       case 2:printf("enter element to delete");
              scanf("%d",&element);
              deletebst(element);
              break;

       case 3:if(root==NULL)
              {
                  printf("tree has no elements\n");
                  break;
              }
              inorder(root);
              break;
       case 4:exit(0); 
               break; 

        case 5:
              printf("\n enter element to search");
              scanf("%d",&ele);       
              sersucc=search(ele,&prev);
              if(sersucc==NULL)
                 printf("element not found\n");
              else 
                 printf("element found\n");
                 break;   
      default:
             break;
   }
  }







    //insert(45);
    //insert(76);
    
    //insert(50);
    //insert(85);
    //insert(33);
   // deletebst(76);
    //deletebst(85);
    //inorder(root);
    




    //bstnode *try;
    //try=search(root,33);
    //try=search(45,&(root->llink));
    //printf("%d\n",try->data);
    
}