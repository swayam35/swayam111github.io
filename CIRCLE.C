#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"c:\\turbocj\\dgi");
	for(i=0;i<=100;i++)
	{
	detcolor(i);
	circle(319,219-i,20+i);
	circle(319,259+i,20+i);
	circle(299-i,239,20+i);
	circle(339+i,239,20+i);
	delay(100);
	}
	getch();
}

