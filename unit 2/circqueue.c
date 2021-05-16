//circular queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
  return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) 
  return 1;
  return 0;
}

// Adding an element
void enqueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) //only happens if queue was empty before
        {front = 0;}

    rear = (rear + 1) % SIZE;//when 5 items,rear=4 queue full front=0 now dequeue 3 elements
    items[rear] = element;    // front becomes 3,rear=4, 2 items
                            //now enqueue rear=5%5 becomes 0 ,3 items
                            //enqueue rear=1,4 items
                            //now dequeue front=4 rear=1,3 items
                            //again dequeue front=0,rear=1,2 items
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
void dequeue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return;
          } 
  
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
else if(front == rear) {
    element = items[front];
      front = -1;
      rear = -1;
    } 
    
    else {
        element = items[front];
      front = (front + 1) % SIZE;//if 3 elements dequeued front becomes 3
    }
    printf("\n Deleted element -> %d \n", element);
    
  
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
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
               break;
      default:
             break;
   }
  }
 }
  

