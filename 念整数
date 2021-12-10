#include <stdio.h>
int main()
{
	int a,d,type;
	
	scanf("%d",&a);
	
	if(a<0){
		printf("fu ");
		a=-a;
	}
	
	 int mask=1;
	 int t=a;
	 while(t>=10){
	 	t/=10;
	 	mask*=10;
	 }
	  do{
	  	
	  	
	  	 d=a/mask;
	  	 a%=mask;
	  	 mask/=10;
	     type=d;
	     
		  switch(type){
		
	    case 1:
	    	printf("yi");
	    	break;
	    case 2:
	    	printf("er");
	    	break;
	    case 3:
	    	printf("san");
	    	break;
	    case 4:
	    	printf("si");
	    	break;
	    case 5:
	    	printf("wu");
	    	break;
	    case 6:
	    	printf("liu");
	    	break;
	    case 7:
	    	printf("qi");
	    	break;
	    case 8:
	    	printf("ba");
	    	break;
	    case 9:
	    	printf("jiu");
	    	break;
	    case 0:
	    	printf("ling");
	    	break;
	   
	    
	}  
	    if(mask>0){
	   	printf(" ");
	    }
	
		  	 
	  }while(mask>0);
   	  
	//printf("*");
	
  
	return 0;
}
