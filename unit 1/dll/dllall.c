#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}node;

node *getnode(int data)
{node *newnode;
newnode=(node *)malloc(sizeof(node));
if(newnode!=NULL)
{
newnode->data=data;
newnode->llink=NULL;
newnode->rlink=NULL;
}
return newnode;
}

void insert_front(node **dhead,int ele)
{node *newnode;
newnode=getnode(ele);
if((*dhead)==NULL)
{
    (*dhead)=newnode;
    return;
}
else
{
    newnode->rlink=(*dhead);
    (*dhead)->llink=newnode;
    (*dhead)=newnode;
}

}
void insert_end(node **dhead,int ele)
{node *newnode;
newnode=getnode(ele);
if((*dhead)==NULL)
{
    (*dhead)=newnode;
    return;
}
else
{
   while((*dhead)->rlink!=NULL) 
   {
      (*dhead)=(*dhead)->rlink;
   }
(*dhead)->rlink=newnode;
newnode->llink=(*dhead);
}
}

int lenlist(node **dhead)
{node *curr;
int count=0;
for(curr=(*dhead);curr!=NULL;curr=curr->rlink)
{count++; 
}
return count;
}

void insertatpos(node **dhead,int pos,int ele)
{node *newnode;
int count=1;
node *prev,*curr;
newnode=getnode(ele);
if((*dhead)==NULL)
{(*dhead)=newnode;
return;
}
else if(pos==1)
{
newnode->rlink=(*dhead);
(*dhead)->llink=newnode;  
(*dhead)=newnode;  
}
else if(pos==(lenlist(dhead)+1))
{
curr=(*dhead);
while(curr->rlink!=NULL)
{
    curr=curr->rlink;
}
curr->rlink=newnode;
newnode->llink=curr;  
}
else if(pos>1 && pos<(lenlist(dhead)+1))
for(curr=*dhead;curr!=NULL;prev=curr,curr=curr->rlink,count++)
{
if(count==pos)
{
prev->rlink=newnode;
newnode->llink=prev;
newnode->rlink=curr;
curr->llink=newnode;
}
}
}
void display(node *head)
{
while(head!=NULL)
{
    printf("%d->",head->data);
    head=head->rlink;
}
printf("\n");
}
void deletefront(node **dhead)
{node *curr;
curr=(*dhead);
(*dhead)=(*dhead)->rlink;
free(curr);

}
void deleteend(node **dhead)
{node *curr,*prev;
for(curr=(*dhead);curr->rlink!=NULL;prev=curr,curr=curr->rlink);

prev->rlink=NULL;
free(curr);
}

void delatpos(node **dhead,int pos)
{node *curr,*prev;
if(pos==1)
{deletefront(dhead);
curr=(*dhead);
(*dhead)=(*dhead)->rlink;
free(curr);
}
if(pos==lenlist(dhead))
{
 for(curr=(*dhead);curr->rlink!=NULL;prev=curr,curr=curr->rlink);

prev->rlink=NULL;
free(curr);   
}
else if(pos>1 && pos<(lenlist(dhead)))
{int count=1;
    for(curr=(*dhead);curr!=NULL;prev=curr,count++,curr=curr->rlink){
      if(count==pos)
      {
       prev->rlink=curr->rlink;
       (curr->rlink)->llink=prev;
       free(curr);  
      }
    }
}
}
int main()
{
node *head=NULL;
insert_front(&head,30);
insert_end(&head,40);
insert_front(&head,60);
display(head);
printf("%d\n",lenlist(&head));
insertatpos(&head,2,20);
display(head);
insertatpos(&head,1,90);
display(head);
insertatpos(&head,6,100);
display(head);
deletefront(&head);
display(head);
deleteend(&head);
display(head);
delatpos(&head,2);
display(head);
}
