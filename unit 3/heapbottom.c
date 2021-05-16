#include<stdio.h>
void heapify(int H[],int n)
{
   int k,parent,v,j;
   int heap;
   parent=n/2;
for(int i=n/2;i>=1;i--)
{
   k=i;
  
   v=H[k];
   heap=0;
   while(!heap && 2*k<=n)
   {    
      printf("%d\n",k);
       j=2*k;
       if(j<n)
       {
          if(H[j]<H[j+1])
             j=j+1; 
       }
      if(v>=H[j])
        heap=1;
else
{
    H[k]=H[j];
    k=j;
}

}
H[k]=v;
}    
}

void delete(int H[],int *n)
{
int x;
x=*n;
//printf("value of n ponter %d",*n);
printf("\n deleted element is %d",H[1]);
H[1]=H[*n];
*n=*n-1;
heapify(H,*n);
}

int main()
{
int n,i,H[20];
printf("\n the no of elements");
scanf("%d",&n);
for(i=1;i<=n;i++)
{scanf("%d",&H[i]);}
heapify(H,n);
printf("\n elements after heapify");
for(i=1;i<=n;i++)
   printf("\n%d",H[i]);
   
printf("\n");
/*
delete(H,&n);
delete(H,&n);
delete(H,&n);
delete(H,&n);
delete(H,&n);
delete(H,&n);
printf("\n elements after heapify");
for(i=1;i<=n;i++)
   printf("\n %d",H[i]);
*/
}