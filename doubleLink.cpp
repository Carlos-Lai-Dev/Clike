#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  struct Node* pre;
  int data;
  struct Node* next;
}Node;

Node* Init()
{
  Node* list = (Node*)malloc(sizeof(Node));
  list -> pre = NULL;
  list -> data = 0;
  list -> next = NULL;
  return list;
}

void HeadInsert(Node* list,int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  if(list -> data == 0)
  {
    node -> next = list -> next;
    list -> next = node;
    node -> pre = list;
  }
  else
  {
    node -> next = list -> next;
    node -> pre = list;
    list -> next -> pre = node;
    list -> next = node;
  }
  list -> data++;
}

void TailInsert(Node* list, int data)
{
  Node* current = list;
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  while(current -> next)
  {
    current = current -> next;
  }
  node -> next = current -> next;
  current -> next = node;
  node -> pre = current;
  list -> data++;
}

bool Delete(Node* list, int data)
{
  Node* current = list ->next;
  while(current)
  {
    if(current -> data == data)
    {
      current -> pre -> next = current -> next;

      if(current -> next)
      current -> next -> pre = current -> pre;

      list -> data--;
      free(current);
      return true;
    }
    current = current -> next;
  }
  return false;
}

void PrintList(Node* list)
{
  Node* node = list -> next;
  while(node)
  {
    printf("%d ->",node -> data);
    node = node -> next;
  }
  printf("\n");
}

int main()
{
  Node* myList = Init();
  HeadInsert(myList,12);
  HeadInsert(myList,98);
  HeadInsert(myList,54);
  HeadInsert(myList,66);
  HeadInsert(myList,78);
  PrintList(myList);
  return 0;
}

