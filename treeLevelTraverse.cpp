#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
  char data;
  struct TreeNode* lchild;
  struct TreeNode* rchild;
}TreeNode;

typedef struct QueueNode{
  TreeNode* data;
  struct QueueNode* pre;
  struct QueueNode* next;
}QueueNode;

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
    CreateTree(&((*T)->lchild),data,index);      
    CreateTree(&((*T)->rchild),data,index);      
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

QueueNode* InitQueue()
{
  QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
  q -> data = NULL;
  q -> next = q;
  q -> pre = q;
  return q;
}

void EnQueue(TreeNode* data,QueueNode* q)
{
  QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
  node -> data = data;
  node -> pre = q -> pre;
  node -> next = q;
  q -> pre -> next = node;
  q -> pre = node;
}

bool IsEmpty(QueueNode* q)
{
  if(q->next == q)
  {
    return true;
  }
  else
  {
    return false;
  }
}

QueueNode* DeQueue(QueueNode* q)
{
  if(IsEmpty(q))
  {
    return NULL;
  }
  else
  {
    QueueNode* node = q->next;
    node -> next -> pre = q;
    q -> next = node -> next;
    //free(node);
    return node;
  }
}

void LevelTraverse(QueueNode* q,TreeNode* T)
{
  EnQueue(T,q);
  while(!IsEmpty(q))
  {
    QueueNode* node = DeQueue(q);
    printf("%c ",node -> data -> data);
    if(node->data->lchild)
    {
      EnQueue(node->data->lchild,q);
    }
    if(node->data->rchild)
    {
      EnQueue(node->data->rchild,q);
    }
  }
}

int main(int argc,char* args[])
{
  TreeNode* T;
  int index = 0;
  QueueNode* q = InitQueue();
  CreateTree(&T,args[1],&index);
  PreOrder(T);
  printf("\n");
  LevelTraverse(q,T);
  printf("\n");
  return 0;
}
