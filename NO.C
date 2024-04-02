void setdata(int,int [],char[]);
void displaymarksheet(int,int [],char []);
void main()
{
	int rno,marks[5];
	char name[20];
	clrscr();
	setdata(rno,marks,name);
	getch();
}
void setdata(int rno,int marks [],char name [])
{
	int i;
	printf("\n enter roll no: ");
	scanf("%d",&rno);
	printf("\n enter student name: ");
	flushall();
	gets(name);
	printf("\n enter 5 sunject marks: ");
	for(i=0;i<5;i++)
		scanf("%d",&marks[i]);
	displaymarksheet(rno,marks,name);
}
void displaymarksheet(int rno,int marks [],char name [])
{
	int i,sum=0,avg=0;
	clrscr();
	printf("\--------------marksheet---------------");
	printf("\\n                                    ");
	printf("\n roll no :                              :%d",rno);
	printf("\n name :                                 :%s",name);
	for(i=0;i<5;i++)
	{
		printf("\n marks %d                                :%d",i+1,marks[i]);
		sum+=marks[i];
	}
	printf("\n\n total                                  :%d",sum);
	avg=sum/5;
	printf("\n\n average                                :%d%",avg);
	if(avg>=70 && avg<100)
		printf("\n\n grade                                  :distintion");
	else if(avg>=60 && avg<70)
		printf("\n\n grade                                  :first");
	else if(avg>=60 && avg<50)
		printf("\n\n grade                                  :second");
	else if(avg>=35 && avg<50)
		printf("\n\n grade                                  :pass");
	else
		printf("\n\n grade                                  :fail");
	printf("\n -------------------------------------------------------------");
}
