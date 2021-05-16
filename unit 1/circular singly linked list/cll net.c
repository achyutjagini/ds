//circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ 
    int data; 
    struct node *link; 
}node; 
  
node *addToEmpty(node *tail, int data) 
{ 
    // This function is only for empty list 
    if (tail!= NULL) 
      return tail; 
  
    // Creating a node dynamically. 
    node *temp =  
           (node*)malloc(sizeof(node)); 
  
    // Assigning the data. 
    temp -> data = data; 
    tail= temp; 
  
    // Creating the link. 
    tail-> link = tail; 
  
    return tail; 
} 
  
node *addBegin(node *tail, int data) 
{ 
    if (tail== NULL) 
        return addToEmpty(tail, data); 

        node *temp =  
            (node *)malloc(sizeof(node)); 
  
    temp -> data = data; 
    temp -> link = tail-> link; 
    tail-> link = temp; 
  
    return tail; 
} 
  
node *addEnd(node *tail, int data) 
{ 
    if (tail== NULL) 
        return addToEmpty(tail, data); 
      
    node *temp =  
        (node *)malloc(sizeof(node)); 
  
    temp -> data = data; 
    temp -> link = tail-> link; 
    tail-> link = temp; 
    tail= temp; 
  
    return tail; 
} 
  
node *addAfter(node *tail, int data, int item) 
{ 
    if (tail== NULL) 
        return NULL; 
  
    node *temp, *p; 
    p = tail-> link; 

    do
    { 
        if (p ->data == item) 
        { 
            temp = (node *)malloc(sizeof(node)); 
            temp -> data = data; 
            temp -> link = p -> link; 
            p -> link = temp; 
  
            if (p == tail) 
                tail= temp; 
            return tail; 
        } 
        p = p -> link; 
    }  while(p != tail-> link); 
  
    printf("%d not present in the list.",item);
    return tail; 
  
} 
  
void traverse(node *tail) 
{ 
    node *p; 
  
    // If list is empty, return. 
    if (tail== NULL) 
    { 
        printf("list is empty"); 
        return; 
    } 
  
    // Pointing to first Node of the list. 
    p = tail-> link; 

do
    { 
        printf("%d->",p->data);
        p = p -> link; 
  
    } 
    while(p != tail->link); 
  
} 
  
// Driven Program 
int main() 
{ 
    node *tail= NULL; 
  
    tail= addToEmpty(tail, 6); 
    tail= addBegin(tail, 4); 
    tail= addBegin(tail, 2); 
    tail= addEnd(tail, 8); 
    tail= addEnd(tail, 12); 
    tail= addAfter(tail, 10, 8); 
  
    traverse(tail); 
  
   
}