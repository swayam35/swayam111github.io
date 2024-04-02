#include<stdio.h>
#include<conio.h>

void  main() {
    FILE *fp;
    char ch; // Assuming the name won't exceed 100 characters

    fp = fopen("file.txt", "w");
    if (fp)
    {
	while((ch=putc(fp))!=EOF)
	{
		putchar(fp);
	}

    }
    else
    {
	printf("error");
    }


    fclose(fp);

	getch();
}
