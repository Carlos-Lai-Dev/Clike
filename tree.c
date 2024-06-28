#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
  char data;
  struct TreeNode* lchild;
  struct TreeNode* rchild;
}TreeNode;

void CreatTree(TreeNode** T,char* data,int* index)
{
  char ch;
  ch = data[*index];
  *index += 1;
  if(ch == '#')
  {
    *T = NULL;
  }
  else
  {
    *T = (TreeNode*)malloc(sizeof(TreeNode));
    (*T) -> data = ch;
    CreatTree(&((*T)->lchild),data,index);
    CreatTree(&((*T)->rchild),data,index);
  }
}

void PreOrder(TreeNode* T)
{
   if(T == NULL)
   {
     return;
   }
   else
   {
    printf("%c ",T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
   }
}

void InOrder(TreeNode* T)
{
   if(T == NULL)
   {
     return;
   }
   else
   {
    InOrder(T->lchild);
    printf("%c ",T->data);
    InOrder(T->rchild);
   }
}

void PostOrder(TreeNode* T)
{
   if(T == NULL)
   {
     return;
   }
   else
   {
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c ",T->data);
   }
}

int main(int argc,char* args[])
{
  TreeNode* T;
  int index = 0;
  CreatTree(&T,args[1],&index);
  PreOrder(T);
  printf("\n");
  InOrder(T);
  printf("\n");
  PostOrder(T);
  printf("\n");
  return 0;
}
