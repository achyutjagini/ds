#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}node;

void insert_front(node **dhead)
{node *newnode;
int data;
newnode=(node *)malloc(sizeof(node));
printf("\n enter data\n");
scanf("%d",&data);
newnode->data=data;
newnode->llink=NULL;
newnode->rlink=NULL;

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

void display(node *head1)
{
node *aux=head1;
while(aux!=NULL)
{
    printf("%d->",aux->data);
    aux=aux->rlink;
}
}
int main()
{
node *head=NULL;
insert_front(&head);
display(head);

}

