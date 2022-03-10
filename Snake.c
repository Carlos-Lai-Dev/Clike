#include <stdio.h>
int main()
{
	int input_x, input_y, count_i, count_j ;     //     intputXXX为你输入的数   countXXX 为循环计数 
	int count_n=1, count_k = 0;
	scanf("%d*%d", &input_x, &input_y);
	
	int a[input_x][input_y];
	
	for( count_j=0; count_j<input_y; count_j++ ) {          //   将自然数组填入  交换两个循环的位置  先填入纵轴 
		
		if( count_j%2==0 ) {                                 //  当为a[3][5]时 蛇形填入下标发生的变化为：a[0][0]   a[0][1]   a[0][2]  ....   1   6   7  ...
		                                                     //     阿拉伯数字代表填入的顺序先后         a[1][0]   a[1][1]   a[1][2]  ....   2   5   8  ...
		                                                     //                                          a[2][0]   a[2][1]   a[2][2]  ....   3   4   9  ...
		for( count_i=0; count_i<input_x; count_i++ ) {       //      第一维 x  发生的变化为   0 ->  1   1 -> 2  或   2 -> 1  1->0 
			                                                 //      第二维 y  自然递增    根据第二维的奇偶性  控制数组的填入顺序  写两个 for  循环即可 
			a[count_i][count_j]=count_n;
			count_n++;
			
		  }
		}else{
			for( count_i=input_x-1; count_i>=0; count_i-- ) {
				
				a[count_i][count_j]=count_n;
				count_n++;
			}
			
		}
			
		
	}
	
	for( count_i=0; count_i<input_x; count_i++) {         //正常  遍历数组   
	
	for( count_j=0; count_j<input_y; count_j++){
	     
		printf("%2d", a[count_i][count_j]);
		count_k++;
	    	if( count_k%input_y==0 ) {     //   每输出 input_y 个数 换行一次 
			printf("\n");
		
		   }
			
			if(count_j!=input_y-1){      //  数组下标第二维是 input_y-1  时，只输出数据而不用输出逗号 
				printf(", ");
				
			}
	   }
	}
	
	return 0;                         // 我代码效率很低   如果你可以想办法让它简短一点就好了  qwq
	 
}
