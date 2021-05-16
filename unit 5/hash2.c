//hash-separate chaining
//The idea is to make each cell of hash table point to a linked list
// of records that have same hash function value.

//Hash table never fills up, we can always add more elements to the chain.

#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

typedef struct hashtb
{
   int data;
   struct hashtb *link;   
}
hashtb;

int hash(int key)
{
    key=key%maxsize;
    return key;
}
void insert_hash(hashtb **arr,int key,int num)
{
hashtb *new;
new=(hashtb *)malloc(sizeof(hashtb));
new->data=num;
new->link=arr[key];
arr[key]=new;
}

void display(hashtb **root)
{
int i=0;
hashtb *cur;
while(i<maxsize)
{
cur=root[i];
while(cur!=NULL)
{
    printf("\n %d",cur->data);
    cur=cur->link;
}
i++;
}
}

int main()
{
int ch,num,key,flag=0;
hashtb *arr[maxsize];

for(int i=0;i<maxsize;i++)
    arr[i]=NULL;
while(1)
{
printf("\n enter option 1.inserthash 2.display 3.exit");
scanf("%d",&ch);
switch(ch)
{
      case 1:printf("enter record number");
             scanf("%d",&num);
             key=hash(num);
             insert_hash(arr,key,num);
             break;
      
      case 2:display(arr);
            break;      

      case 3:
       exit(1);      
 

}    

}
}