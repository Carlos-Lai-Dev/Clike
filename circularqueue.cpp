#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6

typedef struct Queue{
  int front;
  int rear;
  int data[MAXSIZE];
}Queue;

Queue* QueueInit()
{
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue -> front = queue -> rear = 0; 
  return queue;
}

bool IsFull(Queue* queue)
{
  if((queue -> rear + 1) % MAXSIZE == queue -> front)
  {
    return true;
  }
  return false;
}

bool IsEmpty(Queue* queue)
{
  if(queue -> front == queue -> rear)
  {
    return true;
  }
  return false;
}

bool EnQueue(Queue* queue,int data)
{
  if(IsFull(queue))
  {
    return false;
  }
  else
  {
    queue -> data[queue -> rear] = data;
    queue -> rear = (queue->rear + 1) % MAXSIZE;
    return true;
  }
}

int DeQueue(Queue* queue)
{
  if(IsEmpty(queue))
  {
    return -1;
  }
  else
  {
    int data = queue->data[queue->front];
    queue -> front = (queue->front + 1) % MAXSIZE;
    return data;
  }
}

void PrintQueue(Queue* queue)
{
  int length = (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
  int index = queue -> front;
  for(int i=0; i<length; i++)
  {
    printf("%d->",queue->data[index]);
    index = (index + 1) % MAXSIZE;
  }
  printf("\n");
}

int main() {
  Queue* myQueue = QueueInit();
  EnQueue(myQueue,2);
  EnQueue(myQueue,8);
  EnQueue(myQueue,7);
  EnQueue(myQueue,6);
  PrintQueue(myQueue);
  DeQueue(myQueue);
  PrintQueue(myQueue);
  return 0;
}

