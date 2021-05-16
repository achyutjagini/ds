//dequeue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int items[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull() {
  if ((front==0 && rear==SIZE-1)||front==rear+1) 
  return 1;
  return 0;
}

// Check if the queue is empty
int isempty() {
  if (front== -1) 
  return 1;
  return 0;
}

void insertfront(int x)
{
if (isFull())
{printf("queue full");
return;}
if(front==-1)
{
   front=0;
   rear=0; 
}
else if(front==0)
{
front=SIZE-1; 
}
else
{
front=front-1;
}
items[front]=x;
}

void insertend(int x)
{
if(isFull())
{
    printf("queue full");
    return;
}
if(front==-1)//queue initially empty
{
  front=0;
  rear=0;
}
else if(rear==SIZE-1)
   rear=0;
else
{
    rear=rear+1;
}
items[rear]=x;
}

void delfront()
{
if(isempty())
{
    printf("queue empty");
    return;
}
if(front==rear)//dequeue has only one element
{
front=-1;
rear=-1;
}
else 
     if(front==SIZE-1)
       front=0;
      else
      front=front+1;
}
void delend()
{
if(isempty())
{
  printf("queue empty");
  return;
}
if(front==rear)//queue has only one element
{
  front=-1;
  rear=-1;
}
else if(rear==0)
{
rear=SIZE-1;
}
else
{
  rear=rear-1;
}
}

void display()
{
int i;
if(isempty())
{
  printf("empty queue");
  return;
}
printf("\nQueue elements :\n");
 i=front;
        if( front<=rear )
        {
                while(i<=rear)
                        printf("%d ",items[i++]);
        }
        else
        {
                while(i<=SIZE-1)
                        printf("%d ",items[i++]);
                i=0;
                while(i<=rear)
                        printf("%d ",items[i++]);
        }
        printf("\n");
}
int main()
{int ch,element;
while(1)
{printf("enter option 1.insertfront 2.insertend 3.delfront 4.delend 5.display 6.exit");
scanf("%d",&ch);
switch(ch)
    {
       case 1:
       printf("Enter the value\n");
              scanf("%d",&element);
              insertfront(element);
              break;

       case 2:
        printf("Enter the value\n");
              scanf("%d",&element);
              insertend(element);
              break;
             
             
       case 3:
             delfront();
             break;
       case 4:
             delend();
             break;
          
        case 5:
           display();
           break;
           case 6:
           exit(0);
           break;

      default:
             break;
   }
  }
 }




