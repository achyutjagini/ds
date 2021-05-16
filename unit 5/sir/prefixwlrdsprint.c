//Program to print the words in the trie for given prefix

#include<stdio.h>
#include<stdlib.h>

#define letters 26
#define maxlength 10
typedef struct node
{
  struct node *branch[letters];
  int ref;
}trienode;

char word[maxlength];
char prefix[10];
int lenght,count;

trienode* createnode()
{
    int ch;
    trienode *new =(trienode*) malloc(sizeof(trienode));
    
    for(ch=0;ch<letters;ch++)
        new->branch[ch]=NULL;
    new->ref=0;
    return new;
}


trienode* insertTrie(trienode *root,char newkey[],int newentry)
{
    int i;
    trienode *saveroot;
    
  
    if(!root)
       root=createnode();
   
   saveroot=root;
   
   for(i=0;i< maxlength;i++)
       if(newkey[i]=='\0')
           break;
       else
       {   
           if(root->branch[newkey[i]-'a']==NULL)
           {
               root->branch[newkey[i]-'a']=createnode();
           
           }
           root=root->branch[newkey[i]- 'a'];
       }
       
       if(root->ref != 0)
           printf("trying to enter duplicate key");
       else
           root->ref=newentry;
       return saveroot;
}


void print_trie(trienode *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->branch[i]!= NULL)
        {
            word[lenght++]= (i+'a');
            if((root->branch[i])->ref ==1)
            {
                printf("\n");
                for(int j=0;j<lenght;j++)
                {
                    printf("%c",word[j]);
                }
            }
            print_trie(root->branch[i]);
        }
    }
    lenght--;
}





void display(trienode *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->branch[i]!= NULL)
        {
            word[lenght++]= (i+'a');
            if((root->branch[i])->ref ==1)
            {
                printf("\n%s",prefix);
                for(int j=0;j<lenght;j++)
                {
                    printf("%c",word[j]);
                }
            }
            display(root->branch[i]);
        }
    }
    lenght--;
}

void print_pre_words(trienode *root,char *prefix)
{
    int i=0,ind;
    
    while(root!=NULL && i < maxlength)
    {
        ind=prefix[i]-'a';
        if(prefix[i] == '\0')
            break;
        else
            root=root->branch[ind];
        i++;
    }
  
  if(root==NULL)
      printf("\nno words with this prefix in the trie");
  else if(root->ref==1)
  {
      printf("\n%s",prefix);
      display(root);
  }
  else
      display(root);
}
                   
                   


int main()
{
    int ch,len_key;
    char *str;
    trienode *root=NULL,*check;
    do
    {
        printf("\n1:insert_trie() \n 2:print_tire \n 3:prefix_words()\n 4:exit()");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
            case 1:printf("enter the string you want to enter");
                   scanf("%s",str);
                   root=insertTrie(root,str,1);
                   break;
                   
           case 2:lenght=0;
                   printf("List of keys in the trie are");
                   print_trie(root);
                   break;
           case 3: lenght=0;
                    printf("enter the words with prefix you want to print");
                    scanf("%s",prefix);
                    print_pre_words(root,prefix);
                    break;
        }

    }while(ch!=4);
}