#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* InitStack()
{
  Node* stack = (Node*)malloc(sizeof(Node));
  stack -> data = 0;
  stack -> next = NULL;
  return stack;
}

bool IsEmpty(Node* stack)
{
  return (stack -> data == 0 || stack -> next == NULL) ? true : false;
}

int OutStack(Node* stack)
{
  int data;
  if(!IsEmpty(stack))
  {
    Node* node = stack -> next;
    stack -> next = node -> next;
    data = node -> data;
    free(node);
    stack -> data--;
  }
  return data;
}

void InStack(Node* stack,int data)
{
  Node* node = (Node*)malloc(sizeof(Node));  
  node -> data = data;
  node -> next = stack -> next;
  stack -> next = node;
  stack -> data++;
}

void PrintStack(Node* stack)
{
  Node* node = stack -> next;
  while(node != NULL)
  {
    printf("%d->",node -> data);
    node = node -> next;
  }
  printf("\n");
}

int main()
{
  Node* stack = InitStack();
  InStack(stack,5);
  InStack(stack,9);
  InStack(stack,8);
  InStack(stack,2);
  printf("stack:");
  PrintStack(stack);
  int a = OutStack(stack);
  printf("current outstack member = %d\n",a);
  PrintStack(stack);
  return 0;
}

