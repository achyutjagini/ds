#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
struct stack
{
  int top;
  int items[STACKSIZE];
};
int isempty(struct stack s)
{
if(s.top==-1)
{
return 1;
}
return 0;
}
int pop(struct stack *ps)
   {   int i,x=0;
       if (ps->top == -1) // check if the stack is the empty
             printf("STACK EMPTY Cannot DELETE..");
  else
   {
       x=ps->items[ps->top]; //delete the element
       //printf("popped element is %d\n",x);
       --(ps->top); //decrement top
       return x;
     }
}

void display(struct stack *ps){
int i,x=0;
    if (ps->top==-1) // check if the stack is the empty
             printf("STACK EMPTY ");
  else
    {  printf("stack is \n");
       for (i=ps->top;i>=0;i--) // displays the elements from top
           printf("%d\n",ps->items[i]);
    }
   }
int push(struct stack *ps,int ele)
{int i,x=0;
   if(ps->top==STACKSIZE-1)//check if the stack is full
  {
     printf("stack full cannot insert");
     return 0;
 }
 else
   {
      ++(ps->top); //increment the top
      ps->items[ps->top]=ele;//insert the element
   }
 
}
void peep(struct stack *ps )
{int x;
    if (ps->top == -1)
             printf("STACK EMPTY ..");
  else
   {
       x=ps->items[ps->top]; //get the element
       printf("\nelement at top is %d\n",x);
     }
}
void set(struct stack *ps)
{  int i;
struct stack aux;
aux=(*ps);
    while(!isempty(aux))
    {
        i=pop(&aux);
    }
printf("%d\n",i);
}
int main()
{
struct stack s;
s.top=-1;
int ele=0;
int ch;
while(1)
{  
   printf("enter option 1.push 2.pop 3.display 4.exit 5.peep 6.set\n");
   scanf("%d",&ch);
   switch(ch){
    case 1:
       printf("enter ele");
       scanf("%d",&ele);
       push(&s,ele);
       break;
    case 2:
        pop(&s);
        break;
    case 3:    
        display(&s);
        break;
    case 4:
        exit(0); 
    case 5:
        peep(&s);  
        break;
    case 6:
        set(&s);       
     default:
         break;     
            }   

}

}
