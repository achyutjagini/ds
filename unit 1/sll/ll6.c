#include<stdio.h>
#include<stdlib.h>
typedef struct node{
 int data;
 struct node *link;   
}node;

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

void displaylist(node *head)
{node *aux;
aux=head;
while(aux!=NULL)
{
printf("%d->",aux->data);
aux=aux->link;    
}
}

node *insert_front(node *head,int ele)
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
return head;
}

void insert_end(node *head,int ele)
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

int lenlist(node *head)
{int len=0;
node *aux;
for(aux=head;aux!=NULL;len++,aux=aux->link);
return len;
}

node *insertatpos(node *head,int ele,int pos)
{node *curr,*prev,*newnode;


curr=head;
int count=1;
int len;
len=lenlist(head);
if(pos==1){
insert_front(head,ele);
return head;
}

else if(pos==(len+1))
{
insert_end(head,ele);
return head;
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
 return head;
}
 else
 {
     printf("invalid position");
     exit(0);
 }
 
}
node *delfront(node *head){
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
  return head;
}
void delend(node *head)
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
node *delatpos(node *head,int pos)
{
if(pos==1)
{
    head=delfront(head);
    return head;
}
else if(pos==lenlist(head))
{delend(head);
return head;
}
else if(pos>1 && pos<lenlist(head))
{ node *prev,*curr;
    int count=1;
    for(curr=head;curr!=NULL;count++,prev=curr,curr=curr->link)
{    if(count==pos)
       {
           prev->link=curr->link;
           free(curr);
       }
}
return head;
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

head=insert_front(head,20);
insert_end(head,30);
//printf("%d\n",lenlist(head));
//lenlist(head);
//displaylist(head);
head=insertatpos(head,45,2);
displaylist(head);
//head=delfront(head);
//printf("\n");
//displaylist(head);
//delend(head);
printf("\n");
//displaylist(head);
head=delatpos(head,2);
displaylist(head);

}