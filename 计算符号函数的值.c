 #include <stdio.h>
 int main()
 {
 	int a,b;
 	scanf("%d",&a);
 	
 	if(a!=0){
 	  if(a>0){
 	  	b=1;
	   }else{
	   	b=-1;
	   }
	 }else{
	 	b=0;
	 }
 	
 	printf("sign(%d) = %d",a,b);
 	return 0;
 }
