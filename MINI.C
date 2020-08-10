#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
struct BSTnode
{
 char word[150],meaning[250];
 struct BSTnode*left,*right;
}*root=NULL;
void insertnode(char *word,char *meaning);
void traverse(struct BSTnode *temp);
struct BSTnode *deleteNode(char *word);
void search(char *word);
struct BSTnode *createnode(char *word,char *meaning)
{
 struct BSTnode*newnode;
 newnode=(struct BSTnode*)malloc(sizeof(struct BSTnode));
 strcpy(newnode->word,word);
 strcpy(newnode->meaning,meaning);
 newnode->left=newnode->right=NULL;
 return newnode;
}
int main()
{
 int choice;
 char str[150],meaning[250];
 clrscr();
 while(1)
 {
  printf("Menu\n 1.Insert Node\n 2.Traverse Node\n 3.Delete Node\n 4.Search node\n 5.Exit\n");
  scanf("%d",&choice);
  if(choice==1)
  {
   printf("Enter the word to be inserted\n");
   scanf("%s",str);
   printf("enter the meaning\n");
   scanf("%s",meaning);
   insertnode(str,meaning);
  }
  else if(choice==2)
  {
   traverse(root);
  }
  else if(choice==3)
  {
   printf("enter the word to be deleted\n");
   scanf("%s",str);
   deleteNode(str);
  }
  else if(choice==4)
  {
    printf("enter the word to be searched\n");
    scanf("%s",str);
    search(str);
  }
  else if(choice==5)
  {
   exit(0);
  }
  else
  {
   printf("Wrong option has been entered\n");
  }
 }
}
void insertnode(char *word,char *meaning)
{
  struct BSTnode*parent=NULL,*current=NULL,*newnode=NULL;
  int res=0,flag=0;
  if(root==NULL)
  {
   root=createnode(word,meaning);
  }
  else
  {
  current=root;
  newnode=createnode(word,meaning);
  while(current!=NULL)
  {
   parent=current;
   res=stricmp(newnode->word,current->word);
   if(res>0)
   { current=current->right; }
   else if(res<0)
   { current=current->left; }
   else
   {  flag=1;
      break;  }
  }
  if(flag==1)
  { printf("Duplicate entry\n"); }
  if(res>0)
  { parent->right=newnode; }
  else
  { parent->left=newnode; }
 }
}
void traverse(struct BSTnode *temp)
{
 if(temp!=NULL)
 {
  traverse(temp->left);
  printf("Word : %s\n",temp->word);
  printf("Meaning : %s\n",temp->meaning);
  printf("\n");
  traverse(temp->right);
 }
 return;
}
struct BSTnode *deleteNode(char *word)
{
 struct BSTnode *parent=NULL, *cur=NULL, *temp=NULL, *suc=NULL;
 int res=0;
 if(root==NULL)
 { printf("The Tree does not exist\n"); }
 cur=root;
 while(cur!=NULL)
 { res=stricmp(cur->word,word);
   if(res==0)
   { break; }
   parent=cur;
   if(res<0)
   { cur=cur->right; }
   else
   { cur=cur->left; }
 }
 if(cur==NULL)
 { printf("The data entered is not found \n");
   return root; }
 if(cur->right==NULL)
 { temp=cur->left; }
 else if(cur->left==NULL)
 { temp=cur->right; }
 else
 {  suc=cur->right;
    while(suc->left!=NULL)
    { suc=suc->left; }
    suc->left=cur->left;
    temp=cur->right;
 }
 if(parent==NULL)
 { return temp; }
 if(cur==parent->left)
 { parent->left=temp; }
 else
 { parent->right=temp; }
 free(cur);
 return root;
}
void search(char *word)
{
 struct BSTnode *temp=NULL;
 int flag=0,res=0;
 if(root==NULL)
 { printf("The tree is empty\n"); }
 temp=root;
 while(temp!=NULL)
 { if((res=stricmp(temp->word,word))==0)
   { printf("Word found\n");
     printf("Word : %s\n",word);
     printf("Meaning : %s\n",temp->meaning);
     flag=1;
     break; }
   if(res>0)
   { temp=temp->left; }
   else
   { temp=temp->right; }
 }
 if(flag==0)
 { printf("Searched element does not exist in the tree\n"); }
 return;
}






