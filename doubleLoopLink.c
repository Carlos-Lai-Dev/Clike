#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data = 0;
  struct Node* next = NULL;
  struct Node* pre = NULL;
}Node;

Node* Init()
{
  Node* list = (Node*)malloc(sizeof(Node));
  list -> data = 0;
  list -> next = list;
  list -> pre = list;
  return list;
}

void HeadInsert(Node* list,int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> next = list -> next;
  node -> pre = list;
  list -> next -> pre = node;
  list -> next = node;
  list -> data++;
}

void TailInsert(Node* list,int data)
{
  Node* current = list;
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  while(current -> next != list)
  {
    current = current -> next;
  }
  node -> next = list;
  node -> pre = current;
  list -> pre -> next = node;
  list -> pre = node;
  list -> data++;
}

bool Delete(Node* list,int data)
{
  Node* node = list -> next;
  while(node != list)
  {
    if(node -> data == data)
    {
      node -> pre -> next = node -> next;
      node -> next -> pre = node -> pre;
      free(node);
      list -> data--;
      return true;
    }
    node = node -> next;
  }
  return false;
}

void PrintList(Node* list)
{
  Node* node = list -> next;
  while(node != list)
  {
    printf("%d->",node -> data);
    node = node -> next;
  }
  printf("\n");
}

int main() {
  Node* myList = Init();
  HeadInsert(myList,321);
  HeadInsert(myList,76);
  HeadInsert(myList,9);
  HeadInsert(myList,8);
  HeadInsert(myList,5);
  Delete(myList,321);
  PrintList(myList);
  return 0;
}

