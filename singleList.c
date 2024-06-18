#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* Init()
{
  Node* list = (Node*)malloc(sizeof(Node));
  list -> data = 0;
  list -> next = NULL;
  return list;
}

void HeadInsert(Node* list,int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> next = list -> next;
  list -> next = node;
  list -> data++;
}

void TailInsert(Node* list,int data)
{
  Node* head = list;
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> next = NULL;
  while(list -> next)
  {
    list = list -> next;
  }
  list -> next = node;
  head -> data++;
}

void Delete(Node* list,int data)
{
  Node* pre = list;
  Node* current = list -> next;
  while(current)
  {
    if(current -> data == data)
    {
      pre -> next = current -> next;
      free(current);
      list -> data--;
      break;
    }
    pre = current;
    current = current -> next;
  }

}
void PrintList(Node* list)
{
  Node* current = list -> next;
  while(current)
  {
    printf("%d ",current -> data);
    current = current -> next;
  }
  printf("\n");
}

int main() {
  Node* mylist = Init();
  HeadInsert(mylist,14);
  HeadInsert(mylist,77);
  HeadInsert(mylist,39);
  HeadInsert(mylist,88);
  HeadInsert(mylist,12);
  HeadInsert(mylist,67);
  HeadInsert(mylist,56);
  TailInsert(mylist,46);
  Delete(mylist,14);
  PrintList(mylist);
  return 0;
}
