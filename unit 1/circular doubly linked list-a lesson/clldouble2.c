//circular doubly linked list
//lesson even if one link not there program won't work
//pay attention to all links
//problem could be in any function not only function which isn't working
//use pesu forums and stack overflow

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *rlink;
struct node *llink;
}node;

node *head=NULL;

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

ptr->rlink=NULL;

ptr->llink=NULL;

}

return ptr;

}

void insertfront(int ele)

{

node *newnode;

newnode=getnode(ele);

if(head==NULL)

{

head=newnode;

head->rlink=head;

head->llink=head;

}

else

{

/*change-this line added*/newnode->llink=head->llink;//now newnode->llink points to last node
head->llink=newnode;
newnode->rlink=head;

/*change-this line added*/newnode->llink->rlink=newnode;//the rlink of last node is made to point at the newnode/new-head
head=newnode;

}

}

void insertend(int ele)

{

node *newnode;

newnode=getnode(ele);

if(head==NULL)

{

head=newnode;

head->rlink=head;

head->llink=head;

}

else

{

node *temp=head;

do{

temp=temp->rlink;

}while(temp!=head->llink);

newnode->rlink=temp->rlink;

temp->rlink=newnode;

newnode->llink=temp;
//change - connect the below head->llink
head->llink=newnode;

}

}

int lenlist()
{node *temp;

int count=0;

temp=head;

do{

temp=temp->rlink;

count++;

}while(temp!=head);

return count;

}

void insertatpos(int ele,int pos)

{

if(pos==1)

{

insertfront(ele);

}

else if(pos==(lenlist()+1))

{

insertend(ele);

}

else if(pos>1 && pos<=(lenlist()+1))

{

node *prev,*curr;

node *newnode=getnode(ele);

int count=1;

curr=head;

do{

prev=curr;

count++;

curr=curr->rlink;

if(count==pos)

{

prev->rlink=newnode;

newnode->llink=prev;

newnode->rlink=curr;

curr->llink=newnode;

}

}while(curr!=head);

}

else

{

printf("invalid position");

}

}

void delfront()
{

if(head==NULL)
 printf("empty list");
//change! add else statement to the below code block.
else{node *aux;

node *lastnode,*secondnode;

aux=head;

lastnode=head->llink;

secondnode=head->rlink;

secondnode->llink=lastnode;

lastnode->rlink=secondnode;

free(aux);

head=secondnode;}
}

void delend()
{ node *secondlast,*last;
if(head==NULL)
 printf("empty list");
else
{
last=head->llink;
secondlast=last->llink;

secondlast->rlink=head;
head->llink=secondlast;
free(last);
}
}

void delatpos(int pos)
{ node *curr=head;
node *prev;
int count=1;
if(pos==1)
{
  delfront();  
}
if(pos==lenlist())
{
delend();  
}
else
{
   do{ prev=curr;
    curr=curr->rlink;
    count++;
    if(count==pos)
      {
       prev->rlink=curr->rlink;
       (curr->rlink)->llink=prev;

      }
   }while(curr!=head);
}
}


void display()

{

node *aux=head;

do{

printf("%d->",aux->data);

aux=aux->rlink;

}while(aux!=head);

printf("\n");

}




int main()

{

insertfront(100);
insertend(20);
insertfront(70);
printf("\n%d\n",lenlist());
insertatpos(45,2);
display();
//delfront();
///display();
//delend();
//display();
delatpos(3);
display();
}

