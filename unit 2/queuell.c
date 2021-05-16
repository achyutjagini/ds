#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
typedef struct node node;
node *front,*rear=NULL;

void enqueue(int ele)
{
node *temp=(node *)malloc(sizeof(node));
temp->data=ele;
temp->link=NULL;

if(rear==NULL)//list empty
{
rear=temp;
front=rear;
}
else
{
rear->link=temp;
rear=temp;
}
}

void dequeue()
{
if(front==NULL)
{printf("list empty");
return;}
else
{node *p=front;
printf("%d is dequeued",front->data);
front=front->link;
free(p);
}}

void display()
{if(front==NULL)
{printf("list empty");
return;}

node *temp=front;
while(temp!=NULL)
{
printf("|%d|",temp->data);
temp=temp->link;
}
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
   }
  }
 }



