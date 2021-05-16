#include <stdio.h>
#include<ctype.h>
#include<math.h>

int opndstk[10],top=-1;

int isnum(int op)
{
if(op>=0 && op<=9)
   return 1;
else
   return 0;

}

int oper(int op1,int op2,char op)
{
  switch(op)
  {
   case '+':return(op1+op2);
   case '-':return(op1-op2);
   case '*':return(op1*op2);
   case '/':return(op1/op2);
   case '$':return pow(op1,op2);
  }
}
int main()
{
char postfix[100],ch;
int i=0,op1,op2,res;
printf("enter postfix expression");
scanf("%s",postfix);
while(postfix[i]!='\0')
{
ch=postfix[i];
printf("\n value in ch=%d",ch);
if(isnum(ch-'0'))
{
printf("\n value is %d",ch-'0');
opndstk[++top]=ch-'0';
}
else
{
op2=opndstk[top--];
op1=opndstk[top--];
res=oper(op1,op2,ch);
printf("\n result is %d",res);
opndstk[++top]=res;
}
i++;
}

printf("\n value of postfix expression is %d \n",opndstk[top--]);
}



