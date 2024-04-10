#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

struct regi{
	char u_name[16];
	char pwd[9];
	char cpwd[9];
};

struct student{
	char fname[13];
	char lname[13];
	char gd[8];
	char dob[17];
	char email[20];
	int age;
	int year;
	char add[30];
	char pno[13];
};
struct school{
	char name[20];
	char type[20];
	char add[30];
	char timing[20];
};
struct payid{
	char amount[13];
	char balance[13];
	char mpay[13];
	char rp[13];

};
struct course{
	char type[16];
	int sid;
	char name[15];
};
struct registration{
	int id;
	char type[20];
	char enroll[15];
	char adhno[15];
};

struct regi registr();
void student();
void school();
void pid();
void course();
void registration();
void studentv();
void schoolv();
void pidv();
void coursev();
void registrationv();
void d();
void students();
void schools();
void pids();
void courses();
void registrations();


void main(){
	struct regi r;
	char ch='y';
	int choice;
	int e =16;
	clrscr();
	r = registr();
	clrscr();
	while(ch=='y')
	{
		printf("\n\n  1 %c enter registration form.",e);
		printf("\n  2 %c show registrations.",e);
		printf("\n  3 %c search from registraton detail",e);
		printf("\n  4 %c enter student detail.",e);
		printf("\n  5 %c show student detail.",e);
		printf("\n  6 %c search form student detail.",e);
		printf("\n  7 %c enter school detail.",e);
		printf("\n  8 %c show school details.",e);
		printf("\n  9 %c search from school detail.",e);
		printf("\n 10 %c enter payment detail.",e);
		printf("\n 11 %c show payment details.",e);
		printf("\n 12 %c search from payment detail.",e);
		printf("\n 13 %c enter course detail.",e);
		printf("\n 14 %c show course details.",e);
		printf("\n 15 %c search from course detail.",e);
		printf("\n 16 %c exit.",e);
		printf("\n\n enter your choice %c%c ",e,e);
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:registration();break;
		 case 2:registrationv();break;
		 case 3:registrations();break;
		 case 4:student();break;
		 case 5:studentv();break;
		 case 6:students();break;
		 case 7:school();break;
		 case 8:schoolv();break;
		 case 9:schools();break;
		 case 10:pid();break;
		 case 11:pidv();break;
		 case 12:pids();break;
		 case 13:course();break;
		 case 14:coursev();break;
		 case 15:courses();break;
		 case 16:exit(0);break;
		default : printf("\n please choose right choice...!");break;
		}
		printf("\n\n\n enter 'y' to countinue.....");
		flushall();
		scanf("%c",&ch);  //while
	}

	getch();
}

//design
void d()
{
	int i;
	for(i=1;i<=80;i++)
	{
	   printf("*");
	}
}

struct regi registr(){
	struct regi r;
	int p;
	int e = 3;
	clrscr();
	d();
	printf("\n\t\t\t%c registration for countinue %c",e,e);
	printf("\n\n");
	d();
	printf("\n\n\n \t Enter Username : ");
	scanf("%s",r.u_name);
	printf("\n\t Enter Password : ");
	scanf("%s",r.pwd);
	printf("\n\t Re-Enter Password : ");
	scanf("%s",r.cpwd);
	p = strcmp(r.pwd,r.cpwd);
	if(strlen(r.pwd) >= 6 && strlen(r.pwd) <=10 && p==0){
		return r;
		printf("\n\n\t\t\t\t%c register successful %c",e,e);
	}
	else{
		printf("\n\t Register Failed");
		printf("\n\t Try Again ");
		getch();
		registr();
	}
}

//defin functions
void registration()
{
   struct registration r;
   FILE *rg;
   clrscr();
   rg=fopen("registration","a+");
   if(rg)
   {
   printf("\n enter student id: ");
   scanf("%d",&r.id);
   printf("\n enter type: ");
   flushall();
   gets(r.type);
   printf("\n enter enrollment number: ");
   flushall();
   gets(r.enroll);
   printf("\n enter adharcard number: ");
   flushall();
   gets(r.adhno);
   fwrite(&r,sizeof(struct registration),1,rg);

   }
   else{
	printf("error..");
	getch();
   }
   fclose(rg);

}


//view function
void registrationv()
{
	struct registration r;
	FILE *rg;
	clrscr();
	rg=fopen("registration","r+");

	if (rg) {
	while( fread(&r,sizeof(struct registration),1,rg)) {
	    printf("\n");
	    printf("\nid: %d", r.id);
	    printf("\nregistration type: %s", r.type);
	    printf("\nenrollment number: %s", r.enroll);
	    printf("\nadharcard number: %s", r.adhno);
	       }
		fclose(rg);

		} else {
			printf("Error opening student file.");
		   }

    getch();
}

//search
void registrations()
{
	struct registration r;
	FILE *rg;
	int found =0;
	int e=16;
	char temp[12];
	int n;
	clrscr();
	rg=fopen("registration","r+");

	printf("\n input adharcar %c",e);
	flushall();
	gets(temp);
	if (rg) {
	while( fread(&r,sizeof(struct registration),1,rg)) {

	   n=strcmp(temp,r.adhno);
	   if(n==0){

	    found=1;
	    printf("\nid: %d", r.id);
	    printf("\nregistration type: %s", r.type);
	    printf("\nenrollment number: %s", r.enroll);
	    printf("\nadharcard number: %s", r.adhno);
	    }
	       }//while
	       if(found==0){
		printf("recoard not found");
	       }

		fclose(rg);

		} else {
			printf("Error opening student file.");
		   }


}

//insert function
void student() {
    struct student s;
    FILE *st;
	clrscr();
    st = fopen("student", "a+");
    if (st) {
        printf("\nEnter first name: ");
		flushall();
		gets(s.fname);
	    printf("Enter last name: ");
	    flushall();
		gets(s.lname);
	    printf("Enter gender: ");
        flushall();
		gets(s.gd);
	    printf("Enter birthdate: ");
        flushall();
		gets(s.dob);
	    printf("Enter email: ");
        flushall();
		gets(s.email);
	    printf("Enter age: ");
		flushall();
        scanf("%d", &s.age);
        printf("Enter entry year: ");
		flushall();
        scanf("%d", &s.year);
        printf("Enter address: ");
        flushall();
		gets(s.add);
	    printf("Enter phone number: ");
        flushall();
		gets(s.pno);
	    fwrite(&s, sizeof(struct student), 1, st);
        fclose(st);
    } else {
        printf("Error opening file.");
    }
}

// view
void studentv() {
    struct student s;
    FILE *st;
	clrscr();
    st = fopen("student", "r+");

    if (st) {
	while ( fread(&s,sizeof(struct student),1,st)) {
	    printf("\n");
	    printf("\nFirst Name: %s", s.fname);
	    printf("\nLast Name: %s", s.lname);
	    printf("\nGender: %s", s.gd);
        printf("\nDate of Birth: %s", s.dob);
        printf("\nEmail: %s", s.email);
        printf("\nAge: %d", s.age);
        printf("\nYear: %d", s.year);
        printf("\nAddress: %s", s.add);
        printf("\nPhone Number: %s", s.pno);
         }
        fclose(st);
    } else {
        printf("Error opening file.");
    }
	
}

//search
void students() {
    struct student s;
    FILE *st;
    int e=16;
    int found = 0;
    char temp[13]; 
	int n;
    st = fopen("student", "r+");

	printf("\nEnter first name to search %c ",e);
	flushall();
	gets(temp);
    if (st) {
	while (fread(&s, sizeof(struct student), 1, st)) {
	    
		n=strcmp(temp, s.fname);
		if(n==0) {
		
		found = 1;
		printf("\nFirst Name: %s", s.fname);
		printf("\nLast Name: %s", s.lname);
		printf("\nGender: %s", s.gd);
		printf("\nDate of Birth: %s", s.dob);
		printf("\nEmail: %s", s.email);
		printf("\nAge: %d", s.age);
		printf("\nYear: %d", s.year);
		printf("\nAddress: %s", s.add);
		printf("\nPhone Number: %s", s.pno);
	    }
	}
	if (found==0) {
	    printf("Record not found\n");
	}
	fclose(st);
    } else {
        printf("Error opening file.");
    }
}

//insert function
void school() {
    struct school s;
    FILE *sc;
    clrscr();
    sc = fopen("school", "a+");
    if (sc) {
	printf("\nEnter school name: ");
	scanf("%s", s.name);
	printf("Enter medium: ");
	scanf("%s", s.type);
	printf("Enter school address: ");
	scanf("%s", s.add);
	printf("Enter school timing: ");
	scanf("%s", s.timing);
	fwrite(&s, sizeof(struct school), 1, sc);
	fclose(sc);
    } else {
	printf("Error opening file.");
    }
}

//view
void schoolv() {
    struct school s;
    FILE *sc;
    sc = fopen("school", "r+");
    if (sc) {
        while (fread(&s, sizeof(struct school), 1, sc)) {
	    printf("\n");
	    printf("\nSchool name: %s", s.name);
	    printf("\nSchool type: %s", s.type);
	    printf("\nSchool address: %s", s.add);
	    printf("\nSchool timing: %s", s.timing);
	}
	fclose(sc);
    } else {
	printf("Error opening file.");
    }
}

//search
void schools() {
    struct school s;
    FILE *sc;
    int e=16;
    int found = 0;
    char temp[20];
	int n; 
    sc = fopen("school", "r+");
	printf("\nEnter school name to search %c",e);
	flushall();
	gets(temp);
    if (sc) {
	while (fread(&s, sizeof(struct school), 1, sc)) {
	    n=strcmp(temp, s.name);
		if(n==0) {
		
		found = 1;
		printf("\nSchool name: %s", s.name);
		printf("\nSchool type: %s", s.type);
		printf("\nSchool address: %s", s.add);
		printf("\nSchool timing: %s", s.timing);
	    }
	}
	if (found==0) {
	    printf("Record not found\n");
	}
	fclose(sc);
    } else {
	printf("Error opening file.");
    }
}

//insert function
void pid() {
    struct payid p;
    FILE *py;
    clrscr();
    py = fopen("payment", "a+");
    if (py) {
	printf("\nEnter payment amount: ");
	flushall();
	gets(p.amount);
	printf("Enter balance: ");
	flushall();
	gets(p.balance);
	printf("Enter mode of payment: ");
	flushall();
	gets(p.mpay);
	printf("Enter receipt id: ");
	flushall();
	gets(p.rp);
	 fwrite(&p, sizeof(struct payid), 1, py);
	fclose(py);
	 } else {
		printf("Error opening file.");
    }
}

//view
void pidv() {
    struct payid p;
    FILE *py;
    py = fopen("payment", "r+");
    if (py) {
        while (fread(&p, sizeof(struct payid), 1, py)) {
	    printf("\n");
	    printf("\nPayment amount: %s", p.amount);
            printf("\nBalance: %s", p.balance);
            printf("\nMode of payment: %s", p.mpay);
            printf("\nReceipt id: %s", p.rp);
        }
        fclose(py);
    } else {
        printf("Error opening file.");
    }
}

//search
void pids() {
    struct payid p;
    FILE *py;
    int e=16;
    int found = 0;
    char temp[18];
	int n; 
    py = fopen("payment", "r+");
	printf("\nEnter receipt id to search %c ",e);
	flushall();
	gets(temp);
    if (py) {
	while (fread(&p, sizeof(struct payid), 1, py)) {
	    n=strcmp(temp, p.rp);
		if(n==0) {
		found = 1;
                printf("\nPayment amount: %s", p.amount);
                printf("\nBalance: %s", p.balance);
                printf("\nMode of payment: %s", p.mpay);
                printf("\nReceipt id: %s", p.rp);
            }
        }
        if (found==0) {
            printf("Record not found\n");
        }
        fclose(py);
    } else {
        printf("Error opening file.");
    }
}

//insert function
void course() {
    struct course c;
    FILE *co;
    clrscr();
    co = fopen("course", "a+");
    if (co) {
        printf("\n enter type: ");
        flushall();
		gets(c.type);
        printf("\n enter student id: ");
        scanf("%d", &c.sid);
        printf("\n enter student name: ");
        flushall();
		gets(c.name);  
        fwrite(&c, sizeof(struct course), 1, co);
    } else {
        printf("Error opening course file.");
        getch();
    }
    fclose(co);
}

//view
void coursev() {
    struct course c;
    FILE *co;
    co = fopen("course", "r+");
    if (co) {
        while (fread(&c, sizeof(struct course), 1, co)) {
	    printf("\n");
	    printf("\ntype: %s", c.type);
            printf("\nstudent id: %d", c.sid);
            printf("\nstudent name: %s", c.name);
        }
        fclose(co);
    } else {
        printf("Error opening course file.");
    }
    getch();
}

//search
void courses() {
    struct course c;
    FILE *co;
    int e=16;
    int found =0;
    char temp[20];
	int n;
    clrscr();
    co = fopen("course", "r+");
    
	printf("\nInput course type to search %c ",e);
	flushall();
	gets(temp);
	if (co) {
	while (fread(&c, sizeof(struct course), 1, co)) {
	    n=strcmp(temp, c.type);
			if(n==0) {
		found = 1;
                printf("\ntype: %s", c.type);
                printf("\nstudent id: %d", c.sid);
                printf("\nstudent name: %s", c.name);
            }
        }
        if (found == 0) {
            printf("Record not found");
        }
        fclose(co);
    } else {
        printf("Error opening course file.");
    }
    getch();
}
