#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *link;   
}*head=NULL;
typedef struct node node;

node *getnode(int ele)
{
node *ptr;
ptr=(node *)malloc(sizeof(node));
if(ptr==NULL)
{
printf("memory not alloc");
exit(0);    
}
if(ptr!=NULL)
{ptr->data=ele;
ptr->link=NULL;}
return ptr; 
}

void displaylist()
{node *aux;
aux=head;
while(aux!=NULL)
{
printf("%d->",aux->data);
aux=aux->link;    
}
}

void insert_front(int ele)
{node *newnode;
if(head==NULL)
{
head=getnode(ele);
}
else{
  newnode=getnode(ele);
  newnode->link=head;
  head=newnode;  
}
}

void insert_end(int ele)
{node *aux;
node *newnode;
aux=head;
if(aux==NULL)
{
head=getnode(ele);
}
else{
while(aux->link!=NULL)
{aux=aux->link;
}
newnode=getnode(ele);
aux->link=newnode;
}
}

int lenlist()
{int len=0;
node *aux;
for(aux=head;aux!=NULL;len++,aux=aux->link);
return len;
}

void insertatpos(int ele,int pos)
{node *curr,*prev,*newnode;


curr=head;
int count=1;
int len;
len=lenlist();
if(pos==1){
insert_front(ele);

}

else if(pos==(len+1))
{
insert_end(ele);

}

else if(pos>1 && pos<(len+1))
{ newnode=getnode(ele);
 for(;curr!=NULL;prev=curr,curr=curr->link,count++)  
 {
  if(count==pos)
  {
    if (newnode!=NULL)
    {prev->link=newnode;
    newnode->link=curr;
    break;}
  }  
 }

}
 else
 {
     printf("invalid position");
     exit(0);
 }
 
}
void delfront(){
  node *temp;
  temp=head;
  if(head==NULL)
  {
    printf("empty linked list");
  }
  else
  {head=head->link;
    free(temp);
  }
  
}
void delend()
{node *prev,*curr;
  curr=head;
  if(head==NULL)
  {
    printf("empty linked list");
  }
  else
  {
   //for(;curr->link!=NULL;prev=curr,curr=curr->link);
   while(curr->link!=NULL)
   {prev=curr;
    curr=curr->link;
   }
   prev->link=NULL;
   free(curr);
}
}
void delatpos(int pos)
{
if(pos==1)
{
    delfront();
    
}
else if(pos==lenlist())
{delend();
}
else if(pos>1 && pos<lenlist())
{ node *prev,*curr;
    int count=1;
    for(curr=head;curr!=NULL;count++,prev=curr,curr=curr->link)
{    if(count==pos)
       {
           prev->link=curr->link;
           free(curr);
       }
}
}

else
{
    printf("invalid delete position");
}


}

int main()
{
node *head=NULL;
//printf("enter value of head");
//scanf("%d",ele);
//head=getnode(ele);

insert_front(20);
insert_end(30);
//printf("%d\n",lenlist());
//lenlist();
//displaylist();
insertatpos(45,2);
displaylist();
//delfront();
//printf("\n");
//displaylist();
//delend();
printf("\n");
//displaylist();
delatpos(2);
displaylist();

}