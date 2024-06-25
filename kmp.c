#include<stdio.h>
#include<stdlib.h>

typedef struct String{
  int length;
  char* data;
}String;

String* InitString()
{
  String* str = (String*)malloc(sizeof(String));
  str -> data = NULL;
  str -> length = 0;
  return str;
}

void StringAssign(String* str,char* data)
{
  if(str -> data)
  {
    free(str->data);
  }
  int len = 0;
  char* temp = data;
  while(*temp)
  {
    len++;
    temp++;
  }
  if(len == 0)
  {
    str -> data = NULL;
    str -> length = 0;

  }
  else
  {
    temp = data;
    str -> data = (char*)malloc(sizeof(char) * (len + 1));
    str -> length = len;
    for(int i=0;i < len; i++,temp++)
    {
      str -> data[i] = *temp;
    }
  }
}
int* GetNext(String* s)
{
  int* next = (int*)malloc(sizeof(int) * s->length);
  int i = 0;
  int j = -1;
  next[i] = j;
  while(i < s->length - 1)
  {
    if(j == -1 || s->data[i] == s->data[j])
    {
      i++,j++,next[i] = j;
    }
    else
    {
      j = next[j];
    }
  }
  return next;
}

void PrintNext(int* next,int len)
{
  for(int i=0; i<len; i++)
  {
    printf(i==0 ? "%d " : " -> %d",next[i] + 1);
  }
  printf("\n");
}
void PrintString(String* s)
{
  for(int i=0; i < s->length; i++)
  {
    printf(i ==0 ? "%c":"->%c",s->data[i]);
  }
  printf("\n");
}

void KMP_Match(String* master,String* sub,int* next)
{
  int i = 0;
  int j = 0;
  while(i < master->length && j < sub->length)
  {
    if(j == -1 || master->data[i] == sub->data[j])
    {
      i++,j++;
    }
    else
    {
      j = next[j];
    }
  }
    if(j == sub->length)
    {
      printf("KMP_Match Success!\n");
    }
    else
    {
      printf("KMP_Match Failed!\n");
    }
}

int main(int charc, char* args[])
{
  String* master = InitString();
  String* sub = InitString();
  StringAssign(master,args[1]);
  StringAssign(sub,args[2]);
  PrintString(master);
  PrintString(sub);
  int* next = GetNext(sub);
  PrintNext(next,sub->length);
  KMP_Match(master,sub,next);
  return 0;
}

