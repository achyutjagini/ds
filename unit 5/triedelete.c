#include<stdio.h>
#include<stdlib.h>

#define maxlength 10

typedef struct node
{
  struct node *branch[26];
  int isend;

}trinode;

char word[maxlength];
char prefix[10];
int length,count_del;

trinode *stk[10];

trinode *createnode()
{
    int ch;
    trinode *new =(trinode*) malloc(sizeof(trinode));
    
    for(ch=0;ch<26;ch++)
        new->branch[ch]=NULL;
    new->isend=0;
    return new;
}


trinode* insertTrie(trinode *root,char newkey[],int newentry)
{
    int i;
    trinode *saveroot;
    
    printf("\nthe string is %s and %d",newkey,newentry);
    if(!root)
       root=createnode();
   
   saveroot=root;
   
   for(i=0;i< maxlength;i++)
       if(newkey[i]=='\0')
           break;
       else
       {
           //printf("\n%d",(newkey[i]-'a'));    
           if(!root->branch[newkey[i]-'a'])
           {
               root->branch[newkey[i]-'a']=createnode();
               //printf("\n%d",(root->branch[newkey[i]-'a']));  
           }
           root=root->branch[newkey[i]- 'a'];
       }
       
       if(root->isend != 0)
           printf("trying to enter duplicate key");
       else
           root->isend=newentry;
       return saveroot;
}


int isempty(trinode *root)
{
    for(int ch=0;ch <= 25;ch++)
        if(root->branch[ch])
            return 0;
    return 1;
}    
    
    
trinode * delete(trinode *root,char *target,int tarsize)
{    
    if(!root)
        return NULL;
 
    if(count_del== tarsize)
    {
       // printf("\nentering");
       if(root->isend==1)
        {
            root->isend=0;
            if(isempty(root))
            {
                free(root);
                root=NULL;
                return root;
            }
       }
    }
     int index=target[count_del]-'a';
     count_del++;
    // printf("\ncount=%d",count_del);
     root->branch[index]=delete(root->branch[index],target,tarsize);
     
     
     if(isempty(root) && root->isend == 0)
     {
         free(root);
         root = NULL;
     }
        
     return root;
}
         
     



void print_trie(trinode *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->branch[i]!= NULL)
        {
            word[length++]= (i+'a');
            if((root->branch[i])->isend ==1)
            {
                printf("\n");
                for(int j=0;j<length;j++)
                {
                    printf("%c",word[j]);
                }
            }
            print_trie(root->branch[i]);
        }
    }
    length--;
}






int main()
{
    int ch,len_key,i;
    char *str;
    str = (char *)malloc(maxlength);
    trinode *root=NULL,*check;
    while(1)
    {
        printf("\n 1: insert_trie() 2:deleter() 3:display() 4: exit()");
        scanf("%d",&ch);
        //system("clear");
        switch(ch)
        {
            case 1:printf("enter the string you want to enter");
                   scanf("%s",str);
                   root=insertTrie(root,str,1);
                   break;
            case 2: count_del=0;
                    printf("enter the string to delete");
                    scanf("%s",str);
                    for(i=0;str[i]!='\0';i++)
                        ;
                    root=delete(root,str,i);
                    if(root==NULL)
                        printf("not found");
                    else
                        printf("found");
                    break;
            case 3:length=0;
                   if(root==NULL)
                       printf("empty trie");
                   else
                   print_trie(root);
                   break;
               
            case 4:
                 exit(1);       
            
        }
    }
}