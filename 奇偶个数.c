#include <stdio.h>
int main()
{    
    int a,n,t;
	scanf("%d",&a);
	
	
		     // while(a!=-1){
		     // t+=a%2;
		     // n++;
			//  scanf("%d",&a);
			for(t=0,n=0;a!=-1;n++){
   	        t+=a%2;
   	        scanf("%d",&a);
   }	
	
	
		printf("%d %d",t,n-t);
		return 0;
	}
	
