//Program to print, search and print the word of given lenght in a trie
#include<stdio.h>
#include<stdlib.h>

#define letters 26
#define maxlenght 10
typedef struct node
{
  struct node *branch[letters];
  int ref;
}trienode;

char word[maxlenght];
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
   
   for(i=0;i< maxlenght;i++)
       if(newkey[i]=='\0')
           break;
       else
       {   
           if(!root->branch[newkey[i]-'a'])
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


int trie_search(trienode *root,char *target)
{
    int ind;

   for(int i=0; i < maxlenght && root;i++)
   {
       ind=target[i]-'a';
       if(target[i] == '\0')
           break;
       else
           root=root->branch[ind];
   }
   if(root && root->ref==1)
       return root;
   else
       return 0;
}



void print_trie_len(trienode *root, int len_key)
{
    for(int i=0;i<26;i++)
    {
        if(root->branch[i]!= NULL)
        {
            word[count++]= (i+'a');
            if((root->branch[i])->ref ==1 && count ==len_key)
            {
                printf("\n");
                for(int j=0;j<count;j++)
                {
                    printf("%c",word[j]);
                }
            }
            print_trie_len(root->branch[i],len_key);
        }
    }
    count--;
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



     
    
int main()
{
    int ch,len_key;
    char *str;
    trienode *root=NULL,*check;
    do
    {
        printf("\n\n 1:insert_trie()\n 2:search()\n 3:display()\n 4: words_len()\n 5: exit()");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
            case 1:printf("enter the string you want to enter");
                   scanf("%s",str);
                   root=insertTrie(root,str,1);
                   break;
            case 2: printf("enter the string to search");
                    scanf("%s",str);
                    check=trie_search(root,str);
                    if(check==NULL)
                        printf("not found");
                    else
                        printf("found");
                    break;
            case 3:lenght=0;
                   printf("List of keys in the trie are");
                   print_trie(root);
                   break;
                  
            case 4:count=0;
                   printf("enter the lenght of the key");
                   scanf("%d",&len_key);
                   print_trie_len(root,len_key);
                   break;
            
        }
    }while(ch!=5);
}