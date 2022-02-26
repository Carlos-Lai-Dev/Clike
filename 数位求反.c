#include <stdio.h>
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	a=t%10;
	b=t/10%10;
	c=t/100;
	printf("%d",a*100+b*10+c);
	return 0;
}
