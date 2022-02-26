#include <stdio.h>
int main()
{
	int type;
	
	scanf("%d",&type);
	
	switch(type){
		
		case 1:
			printf("狐臭不洗澡！");
			break;
		case 2:
		    printf("狐臭是个害人精！");
			break;
		case 3:
		    printf("狐臭不洗脚！");
			break;
		case 4:
		    printf("狐臭不睡觉！");		 
		    break;
		case 5:
			printf("狐臭，牛牛恩了！");
			break;
		default:
			printf("不可以色色！");
		    break;
		
	}
	
	return 0;
}
