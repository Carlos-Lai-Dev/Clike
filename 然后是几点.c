   #include <stdio.h>
   int main()
   {
   	
	int x,y,a,b,c,d,t;
   	
//  int x=1120,y=-30;
   	
	scanf("%d %d",&x,&y);
    a=x/100;
    b=x%100;
    c=y/60;
	d=y%60;
	
	
	if(y>=0){
		if((b+d)>=60){
		a++;
		t=(b+d)-60;
		}else{
		t=b+d;
	   }
	   
     }else{
     	
     		if(b<-d){
     			a--;
     			t=b+d+60;
			 }else{
			 	t=b+d;
			 }	 	
		 }
		 	
		 
     	
	 
	 
	
	printf("%03d",(a+c)*100+t);
	
	return 0;
	
}
