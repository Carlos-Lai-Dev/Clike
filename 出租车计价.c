  #include <stdio.h>
  int main()
  {
  	 double x,n,t;
  	 int y;
  	 
  	 scanf("%lf %d",&x,&y);
  	
  	if(x<=10){
  		//////////////////
  	 	 if(x<=3){ 	
			n=10;
			}else{
  	 	  n=10;
  	 	  t=x-3;
  	 	 // r=x-10;
  	 	  n+=t*2;
  	    }
  ////////////////////////////////	    
	   }else{
	   	n=24;
	   	n+=(x-10)*3;
	   	}
////////////////////////////////	   	
	   	if(y>0){
	   		
	   		n+=y/5*2;
	   		
		   }
	   
  	
  	printf("%.f",n);
  	
  	return 0;
  	
  }
