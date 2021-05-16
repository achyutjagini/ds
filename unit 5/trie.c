#include<stdio.h>
#include<stdlib.h>
#define maxlength 10

typedef struct node
{
  int isend;
  struct node *branch[26];
}trinode;

int len=0,count=0;
char word[maxlength];

trinode *createnode()
{
  trinode *new=(trinode *)malloc(sizeof(trinode));
  int ch;
  for(ch=0;ch<26;ch++)
  {
    new->branch[ch]=NULL;
  }
  new->isend=0;
  return new;
}

trinode *insert_trie(trinode *root,char *newenty)
{   int ind;
    trinode *proot;
    if(root==NULL)
       root=createnode();
    proot=root;
  for(int i=0;i<maxlength;i++)
  {
      ind=newenty[i]-'a';
      if(newenty[i]=='\0')
         break;
     else
     {
       if(root->branch[ind]==NULL)
          root->branch[ind]=createnode();
        root=root->branch[ind];
     }
  }
    if(root->isend!=0)
       printf("trying to insert duplicate");
    else   
       root->isend=1;
         
     return proot;  
}

void print_trie(trinode *cur)
{
   
   for(int i=0;i<26;i++)
   {
    if(cur->branch[i]!=NULL)
    {
      word[count++]=(i+'a');
    
    if((cur->branch[i]->isend)==1)
    {
      printf("\n");
     
      for(int j=0;j<count;j++)
      {
        printf("%c",word[j]);
      }
    } 
    print_trie(cur->branch[i]); 
    }
  
   }
  count--; 
}

int search_trie(trinode *root,char *target)
{
  int ind;
for(int i=0;i<maxlength &&root;i++)
{
  ind=target[i]-'a';
  if(target[i]=='\0')
    break;
  else
     root=root->branch[ind]; 
}

if(root && root->isend==1)
   return 1;
else   
   return 0;
}
int main()
{
int ch;
trinode *root=NULL;
char *newenty;
char *target;
int check=0;
newenty = (char *)malloc(maxlength);
 target= (char *)malloc(maxlength);
while(1)
{
printf("\n enter option 1.insert_trie 2.display 3.search 4.exit");
scanf("%d",&ch);
switch(ch)

{
     case 1:
        printf("enter word");
        scanf("%s",newenty);
      root=insert_trie(root,newenty);
        break;
        
     case 2:
        count =0;
        print_trie(root);
        break;

       case 3:
        printf("enter elem you want to search");
        scanf("%s",target);
       check=search_trie(root,target);
       if(check==0)
          printf("word not found");
        else
          printf("found");
        break;
        
        case 4:
        exit(0);
        break;

}
}
}
