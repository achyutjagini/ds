#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int input_prec(char c)
{
if(c=='+'||c=='-')
   return 1;
else if(c=='*'||c=='/')
   return 3;
else if(c=='$')
    return 6;

else if(isalpha(c))
    return 7;
else if(c==')')
     return 0;          
else if(c=='(')
     return 9;

else if(c==')')
     return 0; 
}

//set stack precedence of operator and operands
int stack_prec(char c)
{
if(c=='+'||c=='-')
   return 2;
else if(c=='*'||c=='/')
   return 4;
else if(c=='$')
     return 5;
else if(isalpha(c))     
     return 8;
else if(c=='(')
     return 0;
else if(c=='#')
     return -1;          
} 
//use above prcd operator to compare precedence of
//two operators or operator and operator or open brace and
//operator or open brace or close brace

//stack push operation implementation

void push(char *s,int *top,char ch)
{
s[++(*top)]=ch;

printf("\n element pushed %c",s[*top]);
}

//stack pop operation 
char pop(char *s,int *top)
{
char c;
c=s[(*top)--];
printf("\n element poped %c",c);
return c;
}

//stack peep operation to check prcd of stack top element
char peep(char *s,int *top)
{
return (s[*top]);
}

//function to convert infix to postfix
void convert_postfix(char *infix,char *postfix)
{
int k=0,i=0,top=-1;
char ch,s[20];
push(s,&top,'#');

if(s[top]==-1)
   printf("stack empty");
while(infix[i]!='\0')
{
ch=infix[i];
//if precedence of stacktop element is greater than
//input symb then pop element and store in postfix string

while(stack_prec(peep(s,&top))>input_prec(ch))
{
postfix[k++]=pop(s,&top);
}
// if not then push element into stack

if(input_prec(ch)!=stack_prec(peep(s,&top)))  //to avoid pushing ')'
   push(s,&top,ch);

//if element is ')' pop it from stack
else
    pop(s,&top);

i++;

}
//once we reach end of infix string pop remaining elements and place 
//it in the postfix array
while(s[top]!='#')
{
 postfix[k++]=pop(s,&top);
}
postfix[k]='\0';

}
int main()
{
char infix[20],postfix[20];
printf("enter infix expression");
scanf("%s",infix);
convert_postfix(infix,postfix);
printf("\n postfix expression is %s \n",postfix);
}



