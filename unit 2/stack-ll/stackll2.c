#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *next;
};
 
struct stack
{
struct node *top;
};
 
void push(int x,struct stack *s)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=x;
 
temp->next=s->top;//inse 1:sert in front of list
s->top=temp;//make top point to new top node sruct stack pointer pointing to struct node
}
 
void pop(struct stack *s)
{
   int x;
   struct node *q;
   if(s->top==NULL)
   {
    printf("empty stack");   
    }
else
{   q=s->top;
   s->top=s->top->next;
   printf("%d element popped",q->data);
   free(q);
 
}
}
 
void display(struct stack *s)
{
struct node *temp;
temp=s->top;
for(;temp!=NULL;temp=temp->next)
{
printf("%d->",temp->data);
 
}
}
int main()
{ struct stack s;
s.top=NULL;
int ch,ele;
while(1)
{
   
  printf("enter option 1.push 2.pop 3.display 4.exit ");
  scanf("%d",&ch);
  switch(ch){
     case 1:
      printf("\nenter ele");
      scanf("%d",&ele);
      push(ele,&s);
      break;
   case 2:
       pop(&s);
       break;
   case 3:   
       display(&s);
       break;
   case 4:
        exit(0);
        break;
   default:
        break;
  }
}
}
 


