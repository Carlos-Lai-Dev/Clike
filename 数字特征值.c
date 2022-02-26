#include <stdio.h>
int main()
{
	int a,b=1,n=1,t;
	scanf("%d",&a);
//	a=342315;
//    while(a>0){
//    	if(a%10%2==n%2){
//    		
//              t+=b;
//		
//    }
    for(t=0;a>0,a%10%2==n%2;n++){
    	
    	t+=b;
	}
       a/=10;
       
       b*=2;
	
	
   printf("%d",t);
	
	return 0;
}
