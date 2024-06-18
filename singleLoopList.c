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
  list -> next = list;
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
  Node* current = list;
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> next = list;
  while(current -> next != list)
  {
    current = current -> next;
  }
  current -> next = node;
  list -> data++;
}

bool Delete(Node* list,int data)
{
  Node* preNode = list;
  Node* node = list -> next;
  while(node != list)
  {
    if(node -> data == data)
    {
      preNode -> next = node -> next;
      free(node);
      list -> data--;
      return true;
    }
    preNode = node;
    node = node -> next;
  }
    return false;
}

void PrintList(Node* list)
{
  Node* node = list -> next;
  //if(node == NULL) return;
  //for(int i = list -> data;i>0;i--)
  while(node != list)
  {
    printf("%d->",node -> data);
    node = node -> next;
  }
  printf("\n");
}

int main() {
  Node* myList = Init();
  HeadInsert(myList,76);
  HeadInsert(myList,66);
  HeadInsert(myList,99);
  HeadInsert(myList,12);
  HeadInsert(myList,45);
  TailInsert(myList,5995);
  TailInsert(myList,5093);
  TailInsert(myList,53235);
  Delete(myList,66);
  PrintList(myList);
  return 0;
}

