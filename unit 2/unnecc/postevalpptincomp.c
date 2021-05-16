#include <stdio.h>

int postfix_eval(char* postfix)
 {
   int i,top,r;
   int s[10];//stack
   top=-1;
   i=0;

   while(postfix[i]!='\0')
   {
     char ch=postfix[i];
     if(isoper(ch))
     {
       int op1=pop(s,&top);
       int op2=pop(s,&top);
     switch(ch)
        {
           case '+':r=op1+op2;
                    push(s,&top,r);
                    break;
           case '-':r=op2-op1;
                     push(s,&top,r);
                     break;
            case '*':r=op1*op2;
                    push(s,&top,r);
                     break;
           case '/':r=op2/op1;
                     push(s,&top,r);
                    break;
        }//end switch   
     }//end if
 else
      push(s,&top,ch-'0');//convert character to integer and push
     i++;
    }  //end while
  return(pop(s,&top));
 }
int main()
{
char postfix[100];
int result;
printf("enter postfix expression\n");
scanf("%s",postfix);
result=postfix_eval(postfix);
printf("%d\n",result);

}

