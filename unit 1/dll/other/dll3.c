#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}node;

node *getnode()
{node *newnode;
int data;
newnode=(node *)malloc(sizeof(node));
if(newnode!=NULL)
{
printf("\n enter data\n");
scanf("%d",&data);
newnode->data=data;
newnode->llink=NULL;
newnode->rlink=NULL;
}
return newnode;
}

void insert_front(node **dhead)
{node *newnode;
newnode=getnode();
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

void display(node *head)
{
while(head!=NULL)
{
    printf("%d->",head->data);
    head=head->rlink;
}
}

int main()
{
node *head=NULL;
insert_front(&head);
display(head);

}
