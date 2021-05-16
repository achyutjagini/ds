#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node expnode;

expnode *stk[20];

void preorder(expnode *root)
{
     if(root==NULL)
       return;
    printf("%c",root->data);
    preorder(root->llink);
    preorder(root->rlink);

}
void postorder(expnode *root)
{
     if(root==NULL)
       return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%c",root->data);

}
void inorder(expnode *root)
{
    if(root==NULL)
       return;
    inorder(root->llink);
    printf("%c",root->data);  
    inorder(root->rlink); 
}

int eval(expnode *root)
{
int val,leftval,rightval;
if(root==NULL)
   return 0;
else if(root->llink==NULL && root->rlink==NULL)//for alphabets only go in,+ doesn't in 1st call
{
printf("\n enter value of %c",root->data);
scanf("%d",&val);
return val;
}
leftval=eval(root->llink);   //for a+b*c a goes into else if
//printf("%d\n",leftval);
rightval=eval(root->rlink);
//printf("%d\n",rightval);
if(root->data=='+') 
   return(leftval+rightval);
if(root->data=='-')
   return(leftval-rightval);
if(root->data=='*')
   return(leftval*rightval);
else
{
    return(leftval/rightval);
}
          
}
int main()
{
char postfix[20],symb;
expnode *temp;
int i=0,k=-1,succ;
printf("enter postfix expression");
scanf("%s",postfix);
while(postfix[i]!='\0')
{
    symb=postfix[i];
    if(isalpha(symb))
    {
        temp=(expnode *)malloc(sizeof(expnode));
        temp->data=symb;
        temp->llink=NULL;
        temp->rlink=NULL;
        stk[++k]=temp;
    }
 else if(symb=='+'||symb=='-'||symb=='*'||symb=='/')   
 {
    temp=(expnode *)malloc(sizeof(expnode));
    temp->data=symb;
    temp->llink=NULL;
    temp->rlink=NULL;
    temp->rlink=stk[k--];
    temp->llink=stk[k--];
    stk[++k]=temp;
 }
 i++;
}
printf("\n");
printf("prefix expression =");
preorder(stk[k]);
printf("\n");
printf("infix expression =");
inorder(stk[k]);
printf("\npostfix expression =");
postorder(stk[k]);


succ=eval(temp);
printf("\n value of expression is %d",succ);
}






