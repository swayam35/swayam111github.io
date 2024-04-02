
#include<stdio.h>
#include<conio.h>

 void main()
{
	int rno,m1,m2,m3,m4,m5;
	float avg;
	clrscr();
	printf("enter roll no:");
	scanf("%d",&rno);
	printf("enter 5 sub marks");
	scanf("%d %d %d %d %d",&m1,&m2,&m3,&m4,&m5);
	clrscr();
	printf(" \n\n-------------marksheet------------");
	printf("\n marks 1   :  %d",m1);
	printf("\n marks 2   :  %d",m2);
	printf("\n marks 3   :  %d",m3);
	printf("\n marks 4   :  %d",m4);
	printf("\n marks 5   :  %d",m5);
	printf("-----------------------");
	printf("\n  total   : %d",(m1+m2+m3+m4+m5));
	avg=(m1+m2+m3+m4+m5)/5;
	printf("\n percentage   : %.2f",avg);
	getch();

}


