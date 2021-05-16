//stack
#include<stdio.h>
#include<stdlib.h> 
int top=-1;//if top=4 stack is full st[0],st[1],st[2]..
#define stacksize 5
int st[stacksize];

void push(int ele)
{if(top==(stacksize-1))
    printf("\nstack full\n");
    else
    {
        top++;
        st[top]=ele;
    }
}

void pop()
{int x;
    if(top==-1)
       printf("stack empty");
   else{
       x=st[top];
       top--;
       printf("poped element is %d\n",x);
       
   }
}

void display()
{int i;
printf("stack is\n");
    for(i=top;i>-1;i--)
        printf("%d\n",st[i]);
    
}

int main()
{  int ch,ele;
/*push(10);
push(20);
push(30);
pop();
display();
push(40);
push(50);
display();*/

while(1)
{
   printf("enter option 1.push 2.pop 3.display 4.exit ");
   scanf("%d",&ch);
   switch(ch){
    case 1:
       printf("enter ele");
       scanf("%d",&ele);
       push(ele);
       break;
    case 2:
        pop();
        break;
    case 3:    
        display();
        break;
    case 4:
         exit(0);
         break;
    default:
         break;
}
}
}