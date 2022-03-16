#include <stdio.h>
int main()
{
    // 先将十进制数转换成二进制，在把二进制转换成十六进制
	int a,b,x=0,y=0,t=0,n=1,j,k;
	scanf("%d",&a);
	
	while(a!=0){
		
		t=a%2;
	    x=n*t;
		y+=x;
	    a/=2;
		n*=10;
	}	
	  j=y/10000;
	  k=y%10000;
   	
     j=j%10*1+j%100/10*2+j/100%10*4+j/1000*8;
	 k=k%10*1+k%100/10*2+k/100%10*4+k/1000*8;	
      b=10*j+k;
	  	
	printf("%d",b);
	
	return 0;
}
