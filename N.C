#include <stdio.h>
#include <string.h>

struct student {
    int no;
    char name[15];
    char email[30];
    char dob[12];
    char pno[12];
};

void st();
void stv();

void main() {

    int c;
    clrscr();
    printf("\n\t\t\t Welcome to school management system.");
    printf("\n\n\n 1. enter student detail.");
    printf("\n 2. view student detail.");
    printf("\n 3. exit.");
    printf("\n\n enter your choice: ");
    scanf("%d", &c);
    switch (c) {
	case 1: st();break;
	case 2: stv();break;
	case 3: exit(0);
	default: printf("\n please select correct option."); break;
    }
	getch();
}
void st() {
    struct student s;
    FILE *st;
    clrscr();
    st = fopen("st.txt", "a");
    if (st != NULL) {
	printf("\nEnter no: ");
	scanf("%d", &s.no);
	printf("Enter name: ");
	fflush(stdin); // Clear input buffer before using gets
	gets(s.name);
	printf("Enter email: ");
	fflush(stdin);
	gets(s.email);
	printf("Enter birthdate: ");
	fflush(stdin);
	gets(s.dob);
	printf("Enter phone number: ");
	gets(s.pno);
	fprintf(st, "%d %s %s %s %s\n", s.no, s.name, s.email, s.dob, s.pno);
	fclose(st);
    } else {
	printf("Error opening file.");
	getch();
    }
}
void stv() {
    struct student s;
    FILE *st;
    clrscr();
    st = fopen("st.txt", "r");
    if (st != NULL) {
	printf("\n\t\t\t\tStudent details:\n");
	while (fscanf(st, "%d %s %s %s %s", &s.no,&s.name,&s.email,&s.dob, &s.pno) != EOF) {
	    printf("\nNo: %d\nName: %s\nEmail: %s\nDOB: %s\nPhone: %s\n", s.no, s.name, s.email, s.dob, s.pno);
	}
	fclose(st);
    } else {
	printf("Error opening file.");
    }
}
