#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
  char data;
  bool flag;
  struct TreeNode* lchild;
  struct TreeNode* rchild;
}TreeNode;

typedef struct StackNode{
  TreeNode* data;
  struct StackNode* next;
}StackNode;

void CreateTree(TreeNode** T,char* data,int* index)
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
    (*T) -> flag = false;
    CreateTree(&((*T)->lchild),data,index);
    CreateTree(&((*T)->rchild),data,index);
  }
}

StackNode* InitStack()
{
  StackNode* node = (StackNode*)malloc(sizeof(StackNode));
  node -> data = NULL;
  node -> next = NULL;
  return node;
}

void Push(TreeNode* data,StackNode* S)
{
  StackNode* node = (StackNode*)malloc(sizeof(StackNode));
  node -> data = data;
  node -> next = S -> next;
  S -> next = node;
}

bool IsEmpty(StackNode* S)
{
  if(S->next == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

StackNode* Pop(StackNode* S)
{
  StackNode* node = NULL;
  if(!IsEmpty(S))
  {
    node = S->next;
    S -> next = node -> next;
  }
  return node;
}

StackNode* GetTop(StackNode* S)
{
  StackNode* node = NULL;
  if(!IsEmpty(S))
  {
    node = S->next;
  }
  return node;
}

void PreOrder(TreeNode* T)
{
  TreeNode* node = T; 
  StackNode* S = InitStack();
  while(node || !IsEmpty(S))
  {
    if(node)
    {
      printf("%c ",node->data);
      Push(node,S);
      node = node -> lchild;
    }
    else
    {
      node = Pop(S) -> data;
      node = node -> rchild;
    }
  }
}

void InOrder(TreeNode* T)
{
  TreeNode* node = T; 
  StackNode* S = InitStack();
  while(node || !IsEmpty(S))
  {
    if(node)
    {
      Push(node,S);
      node = node -> lchild;
    }
    else
    {
      node = Pop(S) -> data;
      printf("%c ",node->data);
      node = node -> rchild;
    }
  }
}

void PostOrder(TreeNode* T)
{
  TreeNode* node = T; 
  StackNode* S = InitStack();
  while(node || !IsEmpty(S))
  {
    if(node)
    {
      Push(node,S);
      node = node -> lchild;
    }
    else
    {
      TreeNode* top = GetTop(S) -> data;
      if(top -> rchild && top->rchild->flag == false)
      {
        top = top -> rchild;
        Push(top,S);
        node = top -> lchild;
      }
      else
      {
        top = Pop(S) -> data;
        printf("%c ",top->data);
        top -> flag = true;
      }
    }
  }
}

int main(int argc,char* args[])
{
  TreeNode* T;
  int index = 0;
  CreateTree(&T,args[1],&index);
  PreOrder(T);
  printf("\n");
  InOrder(T);
  printf("\n");
  PostOrder(T);
  printf("\n");

}
