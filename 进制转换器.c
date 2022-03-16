#include <stdio.h>
int main()
{
  
  int a,b=0,c=0,d=1,x=0,y=0;
  
  printf("    ****十进制转二进制****\n");
 
 out:
   printf("   请输入需要转换的十进制数:  ");  
   scanf("%d",&a);
   
      y=a;
  while(a!=0){
          
      c=a%2;     
      x=d*c;
      b+=x;
      a/=2;
      d*=10;
     
  }
  
  printf("   十进制数%d对应二进制数为:%d\n",y,b);
  b=0;  
  c=0;
  d=1;
  x=0;
  
  goto out;
  return 0;
  }
  
  
  
  
  
