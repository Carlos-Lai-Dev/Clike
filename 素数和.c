 #include <stdio.h>
 int main()
 {
 	int a,b,c,i,j,k,x,l;
 	int t=0,sum=0;
 	scanf("%d %d",&a,&b);
 	
 	for(x=2;x<=200;x++){
 		  c=1;
 	for(i=2;i<x;i++){
 		
 		if(x%i==0){
 			c=0;
 			break;
		 }
	 }	
 		
 		
 		
 		if(c==1){
 			sum+=x;
 			t++;
 			l=x;
		 }
		 if(a==t){
		 	j=sum-l;
		 }else{
		 	if(b==t){
		 		k=sum;
			 }
		 }
	 }
	 
	 printf("%d",k-j);
	 
 	return 0;
 }
