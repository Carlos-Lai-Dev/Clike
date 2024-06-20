#include <stdio.h>
#include <stdlib.h>

typedef struct String{
  int length;
  char* data;
}String;

String* InitString()
{
  String* s = (String*)malloc(sizeof(String));
  s -> length = 0;
  s -> data = NULL;
  return s;
}

void StringAssign(String* s,char* data)
{
  if(s -> data)
  {
    free(s -> data);
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
    s -> data = NULL;
    s -> length = 0;
  }
  else
  {
    temp = data;
    s -> length = len;
    s -> data = (char*)malloc(sizeof(char) * (len + 1));
    for(int i=0; i<len; i++,temp++)
    {
      s -> data[i] = *temp;
    }

  }
}

void PrintString(String* s)
{
  for(int i=0; i<s->length; i++)
  {
    printf(i==0?"%c":"->%c",s -> data[i]);
  }
  printf("\n");
}

void ForceMatch(String* master,String* sub)
{
  int i = 0;
  int j = 0;
  while(i < master->length && j < sub->length)
  {
    if(master->data[i] == sub->data[j])
    {
      i++,j++;
    }
    else
    {
      i = i - j + 1;
      j = 0;
    }
  }
  if(j == sub->length)
  {
    printf("j=%d,sub->length=%d\n",j,sub->length);
    printf("Force Match Success!\n");
  }
  else
  {
    printf("j=%d,sub->length=%d\n",j,sub->length);
    printf("Force Match Failed!\n");
  }
}

int main(int argc,char* args[]) {
  String* s = InitString();
  String* s1 = InitString();
  //String* s2 = InitString();
  StringAssign(s,args[1]);
  StringAssign(s1,args[2]);
  //StringAssign(s2,"World");
  PrintString(s);
  PrintString(s1);
  //PrintString(s2);
  ForceMatch(s,s1);
  //ForceMatch(s1,s2);
  return 0;
}

