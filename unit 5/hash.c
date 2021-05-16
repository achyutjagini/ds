//hash-open addressing
// open addressing is a method for handling collisions. In Open Addressing, 
//all elements are stored in the hash table itself. 
//So at any point, the size of the table must be greater than
// or equal to the total number of keys 

#include<stdio.h>
#include<stdlib.h>

int count;
#define maxsize 10

int insert_hash(int arr[],int num)
{
int key=num%maxsize;
while(arr[key]!=-1 && count!=maxsize)
{
key=(key+1)%maxsize;
count++;

}
if(count<maxsize)
   arr[key]=num;
   return 1;
}

int search(int arr[],int num)
{
    int count=0;
    int key=num%maxsize;
while(arr[key]!=num && count!=maxsize)
{
    key=key+1%maxsize;
    count++;
}    
if(count<maxsize)
   return 1;
else
   return 0;
}

void display(int arr[])
{
    for(int i=0;i<maxsize;i++)
        printf("\n%d",arr[i]);

}

void delete(int arr[],int num)
{
    int count=0;
    int key=num%maxsize;
while(arr[key]!=num && count!=maxsize)  
{
key=key+1%(maxsize);
count++;
} 
if(count<maxsize)
   arr[key]=-1;
}

int main()
{
    int arr[maxsize];
    int flag=0;
    int num;
    int ch;
    for(int i=0;i<maxsize;i++)
        arr[i]=-1;
while(1)
{
printf("\n enter option 1.inserthash 2.display 3.search 4.delete 5.exit");
scanf("%d",&ch);
switch(ch)

    {
       case 1:count=0;
        printf("enter record no");
        scanf("%d",&num);
        flag=insert_hash(arr,num);
        if(flag==0)
        printf("\n hash table full");
              break;

             case 2:
            display(arr);
              break;

            case 3:
     printf("enter key to search");
     scanf("%d",&num);
      int s_flag=search(arr,num);
if(s_flag==1)
   printf("key found");
else
    printf("key not found");
break;
case 4:
printf("enter key to search");
scanf("%d",&num);
delete(arr,num);
break;

case 5:
 exit(1);
    }


     
}

}