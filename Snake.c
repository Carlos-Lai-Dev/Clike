#include <stdio.h>
int main()
{
	int input_x, input_y, count_i, count_j ;     //     intputXXXΪ���������   countXXX Ϊѭ������ 
	int count_n=1, count_k = 0;
	scanf("%d*%d", &input_x, &input_y);
	
	int a[input_x][input_y];
	
	for( count_j=0; count_j<input_y; count_j++ ) {          //   ����Ȼ��������  ��������ѭ����λ��  ���������� 
		
		if( count_j%2==0 ) {                                 //  ��Ϊa[3][5]ʱ ���������±귢���ı仯Ϊ��a[0][0]   a[0][1]   a[0][2]  ....   1   6   7  ...
		                                                     //     ���������ִ��������˳���Ⱥ�         a[1][0]   a[1][1]   a[1][2]  ....   2   5   8  ...
		                                                     //                                          a[2][0]   a[2][1]   a[2][2]  ....   3   4   9  ...
		for( count_i=0; count_i<input_x; count_i++ ) {       //      ��һά x  �����ı仯Ϊ   0 ->  1   1 -> 2  ��   2 -> 1  1->0 
			                                                 //      �ڶ�ά y  ��Ȼ����    ���ݵڶ�ά����ż��  �������������˳��  д���� for  ѭ������ 
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
	
	for( count_i=0; count_i<input_x; count_i++) {         //����  ��������   
	
	for( count_j=0; count_j<input_y; count_j++){
	     
		printf("%2d", a[count_i][count_j]);
		count_k++;
	    	if( count_k%input_y==0 ) {     //   ÿ��� input_y ���� ����һ�� 
			printf("\n");
		
		   }
			
			if(count_j!=input_y-1){      //  �����±�ڶ�ά�� input_y-1  ʱ��ֻ������ݶ������������ 
				printf(", ");
				
			}
	   }
	}
	
	return 0;                         // �Ҵ���Ч�ʺܵ�   ����������취�������һ��ͺ���  qwq
	 
}
