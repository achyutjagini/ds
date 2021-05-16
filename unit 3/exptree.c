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

void inorder(expnode *root)
{
    if(root==NULL)
       return;
    inorder(root->llink);
    printf("%c",root->data);  
    inorder(root->rlink); 
}
void preorder(expnode *root)
{
     if(root==NULL)
       return;
    printf("%c",root->data);
    preorder(root->llink);
    preorder(root->rlink);

}
int main()
{
char postfix[20],symb;
expnode *temp;
int i=0;

k=-1;// k is similiar to top,initially -1,when pushing and popping change

printf("enter postfix expression");
scanf("%s",postfix);
while(postfix[i]!='\0')
{
    symb=postfix[i];//each char of expression

    //if symb is alphabet,allocate memory,push it into the stack
    if(isalpha(symb))
    {
        temp=(expnode *)malloc(sizeof(expnode));
        temp->data=symb;
        temp->llink=NULL;
        temp->rlink=NULL;
        stk[++k]=temp;
    }
    //is symb is operator,allocate memory,  pop out alphabets and link them as rlink and llink
    //then push operator into stack
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
printf("prefix expression");
preorder(stk[k]);

printf("\n");
printf("infix expression");
inorder(stk[k]);
}