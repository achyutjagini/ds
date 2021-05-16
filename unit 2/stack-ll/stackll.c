#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}node;


void push(struct node **dtop,int x)
{
node *temp;
temp=(node *)malloc(sizeof(node));
if(temp!=NULL)
{temp->data=x;
temp->next=(*dtop);//insert in front of the list,if list empty, *dtop=NULL so temp becomes first
*dtop=temp;//make top point to new top node
}
}

int pop(node **dtop)
{
int x;
node *q;
if(*dtop==NULL)
{printf("empty stack");
}

else{
q=*dtop;
x=q->data;
*dtop=q->next;
free(q);
printf("%d data is popped",x);
}
}
void display(node *top)
{
    if(top==NULL)
    {
        printf("empty stack\n");
    }
else
{
    while(top!=NULL)
    {
      printf("%d->",top->data);
    top=top->next;
}
}
}


int main()
{
node *top=NULL;

int ch,ele;
while(1)
{
   printf("enter option 1.push 2.pop 3.display 4.exit ");
   scanf("%d",&ch);
   switch(ch){
    case 1:
       printf("enter ele");
       scanf("%d",&ele);
       push(&top,ele);
       break;
    case 2:
        pop(&top);
        break;
    case 3:    
        display(top);
        break;
    case 4:
         exit(0);
         break;
    default:
         break;
}
}
}







