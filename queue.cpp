#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* InitQueue()
{
  Node* queue = (Node*)malloc(sizeof(Node));
  queue -> data = 0;
  queue -> next = NULL;
  return queue;
}


void EnQueue(Node* queue,int data)
{
  Node* current = queue;
  Node* node = (Node*)malloc(sizeof(Node));  
  node -> data = data;
  while(current -> next)
  {
    current = current -> next;
  }
  node -> next = current -> next;
  current -> next = node;
  queue -> data++;
}

int DeQueue(Node* queue)
{
  int data;
  if(queue -> next)
  {
    Node* node = queue -> next;
    queue -> next = node -> next;
    data = node -> data;
    free(node);
    queue -> data--;
  }
  return data;
}

void PrintQueue(Node* queue)
{
  Node* node = queue -> next;
  printf("Queue:");
  while(node)
  {
    printf("<-%d",node -> data);
    node = node -> next;  
  }
  printf("\n");
}

int main() {
  Node* myQueue = InitQueue();
  EnQueue(myQueue,8);
  EnQueue(myQueue,4);
  EnQueue(myQueue,6);
  EnQueue(myQueue,3);
  EnQueue(myQueue,1);
  PrintQueue(myQueue);
  int a = DeQueue(myQueue);
  printf("current Queue member:%d\n",a);
  PrintQueue(myQueue);
  return 0;
}

