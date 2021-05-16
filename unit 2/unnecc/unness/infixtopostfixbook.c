#include<stdio.h>
#include<stdlib.h>
#define MAXCOLS 80
struct stack
{int top;
char items[MAXCOLS];
};
struct stack opstk;

void push(struct stack *ps,char x)
{if(ps->top==MAXCOLS-1)
   { printf("stack overflow");
    exit(1);
    }
else
{   
    ps->top++;
    ps->items[ps->top]=x;
    return;
}
}

int prcd(char topsymb,char symb)
{
if(topsymb=='*' && symb=='+')
   return 1;
else if(topsymb=='+' && symb=='*')
   return 0;
else if(topsymb=='+' && symb=='+')
   return 1;
else if(topsymb=='+' && symb=='-')
   return 1;
else if(topsymb=='-' && symb=='-')
   return 0;
else if(topsymb=='$' && symb=='$')
   return 0; 
else if(topsymb=='(' && (symb=='*'||symb=='+'||symb=='-'||symb=='$'))
   return 0; 
else if((topsymb=='*'||topsymb=='+'||topsymb=='-'||topsymb=='$') && symb=='(')
   return 0; 
else if((topsymb=='*'||topsymb=='+'||topsymb=='-'||topsymb=='$') && symb==')')
   return 1; 
else if(topsymb=='(' && symb==')')
   return 0; 


}

int isoperand(char symb)
{
if((symb>='a' && symb<='z')||(symb>='A' && symb<='Z'))
return 1;
return 0;
}

int empty(struct stack *ps)
{
if(ps->top==-1)
   return(1);
else
{
    return(0);
}
}

char pop(struct stack *ps)
{if(empty(ps))
{printf("stack underflow");
exit(1);
}
return(ps->items[ps->top--]);
}

void popandtest(struct stack *ps,char *px,int *pund)
{if(empty(ps))
{*pund=1;
return;}//end if

*pund=0;
*px=ps->items[ps->top--];
return;
}//end pop and test





void postfix(char infix[],char postr[])
{
opstk.top=-1;//the empty stack
int position,und=0;
int outpos=0;
char topsymb='+';
char symb;

for(position=0;(symb=infix[position])!='\0';position++)

{
if(isoperand(symb))
postr[outpos++]=symb;
else
{
popandtest(&opstk,&topsymb,&und);
while(!und && prcd(topsymb,symb))
{postr[outpos++]=topsymb;

popandtest(&opstk,&topsymb,&und);
}//end while

if(!und)
{push(&opstk,topsymb);}

if(und||(symb!=')'))
push(&opstk,symb);
else
topsymb=pop(&opstk);
}
}//end for
while(!empty(&opstk))
      postr[outpos++]=pop(&opstk);
postr[outpos]='\0';
return;
}

int main()
{struct stack *ps;
char infix[MAXCOLS];
char postr[MAXCOLS];
int pos=0;
printf("enter infix expression");
scanf("%s",infix);
printf("the original infix expresssion is %s",infix);

postfix(infix,postr);
printf("\n the postfix expression is %s",postr);
}











