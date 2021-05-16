//circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *link;   
};
typedef struct node node;
node *tail=NULL;

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

void insertfront(int ele)
{
node *newnode;
newnode=getnode(ele);
if(tail==NULL)
{
tail=newnode;
tail->link=tail;
}
else
{
    newnode->link=tail->link;
    tail->link=newnode;
}
}

void insertend(int ele)
{
node *newnode;
newnode=getnode(ele);    
if(tail==NULL)
{
tail=newnode;
tail->link=tail;
}
else
{
    newnode->link=tail->link;
    tail->link=newnode;
    tail=newnode;
}
}
int lenlist()
{node *temp;
int count=0;
temp=tail;
do{
    temp=temp->link;
    count++;
}while(temp!=tail);

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
else if(pos>1 && pos<=lenlist())
{
node *prev,*curr;
node *newnode=getnode(ele);
int count=0;
curr=tail->link;//curr points to 1st node
do{
prev=curr;   
count++; 
curr=curr->link;
if(count==pos)
{
prev->link=newnode;
newnode->link=curr;    
}
}while(curr!=tail->link);

}
else
{
    printf("invalid position");
}

}

void addafter(int ele,int item)
{
node *newnode, *prev; 
    prev = tail-> link; //prev points to 1st node
int flag=0;
    do
    { 
        if (prev ->data == item) 
        {   newnode=getnode(ele);

            newnode-> link =prev-> link; 
            prev -> link =newnode; 
   
            if (prev == tail) 
                tail=newnode; 
            flag=1;
            break;
        } 
        prev = prev -> link; 
    }  while(prev != tail-> link); 
    if(flag==0)
    printf("%d not present in the list.",item);
}

void display()
{node *aux;
aux=tail->link; //aux points to first node
while(1)
{
printf("%d->",aux->data);
aux=aux->link;
if(aux==tail->link)
    break;
}
printf("\n");
   }  

void delfront()
{
node *aux;
aux=tail->link;
tail->link=aux->link;
free(aux);
}
void delend()
{node *aux,*temp;
temp=tail;
aux=tail->link;
while(aux!=tail)
{
aux=aux->link;
if(aux->link==tail)
break;
}
aux->link=tail->link;
tail=aux;
free(temp);
}

void delatpos(int pos)
{
if(pos==1)
{
    delfront();
}
else if(pos==lenlist())
{
    delend();
}
else if(pos>1 && pos<lenlist())
{node *prev,*curr;

int count=1;
curr=tail->link;//curr points to 1st node
do{
prev=curr;   
curr=curr->link;
count++;
if(count==pos)
{
    prev->link=curr->link;
    free(curr);
    break;
}
}while(curr!=tail->link);

}
else
    {
printf("invalid pos");
    }
}



int main()
{
insertfront(20);
insertfront(40);
insertend(80);
display();
printf("\n%d\n",lenlist());
insertatpos(100,4);
display();
insertatpos(150,3);
display();
addafter(70,80);
display();
delfront();
display();
delend();
display();
delatpos(2);
display();
}
