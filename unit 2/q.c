//simple queue
#include<stdio.h>
#include<stdlib.h>
#define size 5
int items[size];
int front=-1;
int rear=-1;

int isfull()
{
if(rear==size-1)
{
    return 1;
}
else
return 0;

}
int isempty()
{
if(front==-1)
  return 1;
  return 0;
}


void enqueue(int x)
{
if(isfull())
{
printf("queue full");
return;
}
else{
rear=rear+1;
items[rear]=x;
printf("inserted %d\n",x);
if(front==-1)
{
    front=0;

}

}
}

void dequeue()
{
if(isempty())
{
printf("queue empty");
return;
}
else{
int x;
x=items[front];
printf("%d dequed",x);
front++;
if(front==rear)//only one item in queue
{
front=-1;
rear=-1;
}
}
}
void display()
{int i;
if(isempty())
{
    printf("queue empty");
    return;
}
for(i=front;i<=rear;i++)
{
printf("|%d|",items[i]);
}
//printf("|%d|",items[i]);
}
int main()
{int ch,element;
while(1)
{printf("enter option 1.enqueue 2.dequeue 3.display 4.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:printf("Enter the value\n");
              scanf("%d",&element);
              enqueue(element);
              break;

       case 2:dequeue();
             
              break;
       case 3:display();
              break;
       case 4:exit(0); 
               break;
      default:
             break;
   }
  }
 }
