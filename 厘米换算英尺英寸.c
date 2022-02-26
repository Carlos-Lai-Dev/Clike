# include <stdio.h>
 
int main ()
{
	    int cm, foot, inch;
	    
	    scanf ("%d", &cm);
	    
	    foot = cm/30.48;
	    inch = (cm/30.48-foot)*12;
	    
	    printf ("%d %d", foot, inch);
//	    int cm=0;
//		scanf("%d",&cm);
//		int foot=cm/30.48;//1Ó¢³ß=30.48ÀåÃ×
//		int inch=((cm/30.48)-foot)*12;
//		printf("%d %d",foot,inch);
	
	    return 0;
	}
