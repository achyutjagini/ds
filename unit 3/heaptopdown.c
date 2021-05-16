#include<stdio.h>

void heaptopdown(int H[],int n)
{
 int v,k,i;
 i=n;//i=1,i=2,i=3,i=4     //i=3,k=1(round off)

//printf("\n the value of i=%d",i);
while(i>1)
{
 k=i/2; //k is parent index
 
 v=H[i];//v is val of child


 printf("\n the value of i=%d",i);
printf("\n  value of k=%d \n",k);
if(H[i]>H[k])  //// child is greater than parent,change it 
{
    H[i]=H[k];//child=parent value

    H[k]=v;//parent =child value
}

i=k;//i becomes half

}    
}
int main()
{
int n,i,H[20];
printf("\n the no of elements");
scanf("%d",&n);
for(i=1;i<=n;i++)
{scanf("%d",&H[i]);
heaptopdown(H,i);
}
printf("\n elements after heapify");
for(i=1;i<=n;i++)
   printf("\n %d",H[i]);
}