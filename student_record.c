/*
 * Name          : Utsava Kumar Singh
 * Date          : 4th september 2022
 * Discription   : Student Record System for a School
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "interface.h"
#include "function_declaration.h"

/***** Global variable declarion *****/

#define school_name "   MODERN SHANTI CONVENT SCHOOL   "
#define ID_len "10"
#define name_min_len "5"
#define phone_len "10"
#define pin_len "6"

char password[11];

typedef struct
{
    char area_village[20];
    char town_city[20];
    char district[20];
    char state[20];
    char pin[7];
}address;

typedef struct
{
    char ID[20];
    char name[30];
    char father[30];
    char mother[30];
    char birth_date[11];
    address stu_add;
    char class[16];
    char phone[11];
    char gender[16];
} candidate;

candidate student;

/***** main function *****/

int main()
{
    int close_flag = 0, choice0 = 0;
    while(close_flag == 0)
    {
	banner();
	gotoxy(50, 15);printf("1. Sign in");
	gotoxy(50, 17);printf("2. Exit");
	gotoxy(45, 20);printf("Please choose from the above options: ");
	scanf("%d", &choice0);

        switch(choice0)
	{
	    case 1:
		sign_in();
	        break;
	    case 2:
		close_flag = 1;
		printf("\n\n");
		break;
	    default:
		textcolor(IRED);
		gotoxy(45, 22);printf("You have chosen the wrong option.");
		textcolor(CC_CLEAR);
		fflush(stdout);
		sleep(3);
		break;
	}
    }
    return 0;
}

//********************************************************************************************************************************
//                                                    Function Definitions
//********************************************************************************************************************************

//************************************************** banner function definition **************************************************

void banner()
{
    clrscr();
    gotoxy(30, 1);printf("==========================================================================================");
    textcolor(IRED);
    textcolor(BGC_YELLOW);
    gotoxy(56, 2);space(38);
    gotoxy(58, 3);printf(school_name);
    gotoxy(56, 4);space(38);
    textcolor(CC_CLEAR);
    gotoxy(30, 5);printf("==========================================================================================");
    textcolor(IGREEN);
    gotoxy(64, 6);printf("STUDENT RECORD SYSTEM");
    textcolor(CC_CLEAR);
    gotoxy(30, 7);printf("==========================================================================================");
    textcolor(BGC_GREEN);
    gotoxy(35, 3);space(15);
    gotoxy(100, 3);space(15);
    textcolor(CC_CLEAR);
}

//*********************************************** sign_in function definition ****************************************************

void sign_in()
{
    char pass[10];
    int exit = 0, count = 3, msg_flag = 0;
    FILE *pass_file;
    pass_file = fopen("password.txt", "r");
    fscanf(pass_file, "%10[^\n]", password);
    fclose(pass_file);
    while(exit == 0)
    {
	clrscr();
        banner();
	if(msg_flag == 1)
	{
	    gotoxy(45, 12);printf("Wrong Password entered");
	    gotoxy(45, 14);printf("Only %d Chances for entering password remaining", count);
	}
        gotoxy(55, 18);printf("Password : ");
        scanf(" %10s", pass);
        while((getchar()) != '\n');
        gotoxy(66, 18);printf("**********");
        if(strcmp(pass, password) == 0)
	{
	    main_menu_screen();
	    exit = 1;
	}
        else
	{ 
	    msg_flag = 1;
	    count--;
	    if(count == 0)
		exit = 1;
	}   
    }
}

//******************************************* main_menu_screen fuction definition ************************************************

void main_menu_screen()
{
    int choice1 = 0, exit_flag = 0;
    while(exit_flag == 0)
    {
	banner();
        main_menu();

        scanf("%d", &choice1);
        switch(choice1)
	{
	    case 1:
		add_student();
	        break;
	    case 2:
		search_student();
		break;
	    case 3:
		modify_student();
		break;
	    case 4:
		gen_marksheet();
		break;
	    case 5:
		delete_record();
		break;
	    case 6:
		change_pass();
		break;
	    case 7:
		exit_flag = 1;
		break;
	    default:
		textcolor(IRED);
		gotoxy(45, 29);printf("You have chosen the wrong option.");
		textcolor(CC_CLEAR);
		fflush(stdout);
		sleep(3);
		break;
        }
    }
}

//********************************************** main_menu function definition ***************************************************

void main_menu()
{
    short int x = 50;
    textcolor(BLUE);
    gotoxy(x, 12);printf("1. Add Student");
    gotoxy(x, 14);printf("2. Search Student");
    gotoxy(x, 16);printf("3. Modify Student Record");
    gotoxy(x, 18);printf("4. Generate Marksheet");
    gotoxy(x, 20);printf("5. Delete Student Record");
    gotoxy(x, 22);printf("6. Change Password");
    gotoxy(x, 24);printf("7. Sign out");
    textcolor(CC_CLEAR);
    gotoxy(45, 27);printf("Please choose from the above options: ");
}

//********************************************** student_data_clear function definition ***************************************************

void student_data_clear()
{
    strcpy(student.ID, " ");
    strcpy(student.name, " ");
    strcpy(student.father, " ");
    strcpy(student.mother, " ");
    strcpy(student.birth_date, " ");
    strcpy(student.class, " ");
    strcpy(student.phone, " ");
    strcpy(student.gender, " ");
    strcpy(student.stu_add.area_village, " ");
    strcpy(student.stu_add.town_city, " ");
    strcpy(student.stu_add.district, " ");
    strcpy(student.stu_add.state, " ");
    strcpy(student.stu_add.pin, " ");
}

//********************************************** student_data function definition ***************************************************

void student_data(int flag)
{
    int x = 30, y = 90;
    gotoxy(x, 10);printf("1. Student ID    : %s", student.ID);
    gotoxy(x, 12);printf("2. Student Name  : %s", student.name);
    gotoxy(x, 14);printf("3. Father's Name : %s", student.father);
    gotoxy(x, 16);printf("4. Mother's Name : %s", student.mother);
    gotoxy(x, 18);printf("5. Gender        : %s", student.gender);
    gotoxy(x, 20);printf("6. Date of Birth : %s", student.birth_date);
    gotoxy(x, 22);printf("7. Class         : %s", student.class);
    gotoxy(x, 24);printf("8. Phone Number  : %s", student.phone);
    textcolor(BGC_YELLOW);
    gotoxy(92, 10); printf("   9. Current Address    ");
    textcolor(CC_CLEAR);
    gotoxy(y, 12);printf("Area / Village : %s", student.stu_add.area_village);
    gotoxy(y, 14);printf("Town / City    : %s", student.stu_add.town_city);
    gotoxy(y, 16);printf("District       : %s", student.stu_add.district);
    gotoxy(y, 18);printf("State          : %s", student.stu_add.state);
    gotoxy(y, 20);printf("Pin Code       : %s", student.stu_add.pin);
    if(flag == 1)
    {
        textcolor(IGREEN);
        gotoxy(y, 23);printf("10. Save and Exit");
        textcolor(CC_CLEAR);
    }
}

//********************************************** add_student function definition ***************************************************

void add_student()
{
    int choice = 0, exit_flag = 0;
    char stu_id[15];
    FILE *data_file = fopen("student_database.csv", "a+");
    banner();
    gotoxy(34, 27);printf("Please enter Student ID : ");
    scanf(" %10s", stu_id);
    while((getchar()) != '\n');
    while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
    {
	if(strcmp(stu_id, student.ID) == 0)
	{
	    gotoxy(50, 14);printf("Student ID already in use for %s !", student.name);
	    exit_flag = 1;
	    fflush(stdout);
	    sleep(3);
	}
    }
    student_data_clear();
    while(exit_flag == 0)
    {
	strcpy(student.ID, stu_id);
	banner();
        student_data(1);
        gotoxy(34, 27);printf("Please choose the field to be added : ");
        scanf("%d", &choice);
	gotoxy(34, 27);space(50);
        switch(choice)
	{
	    case 1:
		gotoxy(34, 27);printf("Sorry, Student ID is not editable");
		fflush(stdout);
		sleep(3);
	        break;
	    case 2:
		gotoxy(34, 27);printf("Please enter Student's Name : ");
		//The " %[^\n]" scans everything until a '\n'
		//The "%*c" tells scanf to scan a character and discard it. Here my character is '\n'.
		//The "%*c" discard the newline
		scanf(" 29%[^\n]", student.name);
	        while((getchar()) != '\n');
		break;
	    case 3:
		gotoxy(34, 27);printf("Please enter Father's Name : ");
		scanf(" 29%[^\n]", student.father);
	        while((getchar()) != '\n');
		break;
	    case 4:
		gotoxy(34, 27);printf("Please enter Mother's Name : ");
		scanf(" 29%[^\n]", student.mother);
	        while((getchar()) != '\n');
		break;
	    case 5:
		gotoxy(34, 27);printf("Please enter Student's Gender : ");
		scanf(" %10s", student.gender);
	        while((getchar()) != '\n');
		break;
	    case 6:
		gotoxy(34, 27);printf("Please enter Date of Birth in DD/MM/YYYY format : ");
		scanf(" %10s", student.birth_date);
	        while((getchar()) != '\n');
		break;
	    case 7:
		gotoxy(34, 27);printf("Please enter Class : ");
		scanf(" %29s", student.class);
	        while((getchar()) != '\n');
		break;
	    case 8:
		gotoxy(34, 27);printf("Please enter Phone Number : ");
		scanf(" %10s", student.phone);
	        while((getchar()) != '\n');
		break;
	    case 9:
		gotoxy(34, 27);printf("Please enter Area / Village : ");
		scanf(" %29[^\n]", student.stu_add.area_village);
	        while((getchar()) != '\n');
		gotoxy(34, 28);printf("Please enter Town / City    : ");
		scanf(" %29[^\n]", student.stu_add.town_city);
	        while((getchar()) != '\n');
		gotoxy(34, 29);printf("Please enter District       : ");
		scanf(" %29[^\n]", student.stu_add.district);
	        while((getchar()) != '\n');
		gotoxy(34, 30);printf("Please enter State          : ");
		scanf(" %29[^\n]", student.stu_add.state);
	        while((getchar()) != '\n');
		gotoxy(34, 31);printf("Please enter Pin Code       : ");
		scanf(" %6s", student.stu_add.pin);
	        while((getchar()) != '\n');
		break;
	    case 10:
		fprintf(data_file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin);
		gotoxy(34, 29);printf("Student's data is saved to the database");
		fflush(stdout);
		sleep(4);
		fclose(data_file);
		exit_flag = 1;
		break;
	    default:
		textcolor(IRED);
		gotoxy(34, 29);printf("You have chosen the wrong option.");
		textcolor(CC_CLEAR);
		fflush(stdout);
		sleep(3);
		break;
	}
    }
}

//******************************************** id_search function definition ********************************************************

void id_search(char *data)
{
    int found_flag = 0, x, y, a = 15;
    FILE *data_file; 
    data_file = fopen("student_database.csv", "r");
    while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
    {
	if(strcmp(student.ID, data) == 0)
	{	    
	    found_flag++;
	}
    }
    fclose(data_file);
        
    if(found_flag == 0)
    {
	gotoxy(40, 29);printf("No data matched");
	scanf("%d", &y);
    }
    else if(found_flag == 1)
    {
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.ID, data) == 0)
	    {	
		banner();
	        student_data(0);
	        gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		scanf("%d", &y);
	    }
	}
	fclose(data_file);
    }
    else if(found_flag > 1)
    {
	y = 1;
	banner();
	gotoxy(15, 11);printf("===========================================================================================================================");
	gotoxy(20, 12);printf("S. No.");
   	gotoxy(28, 12);printf("Student ID");
   	gotoxy(45, 12);printf("Student Name");
   	gotoxy(80, 12);printf("Father's Name");
   	gotoxy(120, 12);printf("Mother's Name");
   	gotoxy(15, 13);printf("===========================================================================================================================");
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.ID, data) == 0)
       	    {
       	    	gotoxy(20, a);printf("%d", y++);
   			gotoxy(28, a);printf("%s", student.ID);
   			gotoxy(45, a);printf("%s", student.name);
   			gotoxy(80, a);printf("%s", student.father);
   			gotoxy(120, a);printf("%s", student.mother);	
			a++;
	    }	
        }
	fclose(data_file);
	a += 2;
	gotoxy(35, a);printf("Select the student number to be displayed : ");
	scanf("%d", &x);
	
	found_flag = 0;
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.ID, data) == 0)
	    {
		found_flag++;
		if (found_flag == x)
		{
		    banner();
		    student_data(0);
		    gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		    scanf("%d", &y);
		}
	    }
	}
	fclose(data_file);
    }
}

//******************************************** name_search function definition ********************************************************

void name_search(char *data)
{
    int found_flag = 0, x, y, a = 15;
    FILE *data_file; 
    data_file = fopen("student_database.csv", "r");
    while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
    {
	if(strcmp(student.name, data) == 0)
	{	    
	    found_flag++;
	}
    }
    fclose(data_file);
        
    if(found_flag == 0)
    {
	gotoxy(40, 29);printf("No data matched");
	scanf("%d", &y);
    }
    else if(found_flag == 1)
    {
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.name, data) == 0)
	    {	
		banner();
	        student_data(0);
	        gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		scanf("%d", &y);
	    }
	}
	fclose(data_file);
    }
    else if(found_flag > 1)
    {
	y = 1;
	banner();
	gotoxy(15, 11);printf("===========================================================================================================================");
	gotoxy(20, 12);printf("S. No.");
   	gotoxy(28, 12);printf("Student ID");
   	gotoxy(45, 12);printf("Student Name");
   	gotoxy(80, 12);printf("Father's Name");
   	gotoxy(120, 12);printf("Mother's Name");
   	gotoxy(15, 13);printf("===========================================================================================================================");
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.name, data) == 0)
       	    {
       	    	gotoxy(20, a);printf("%d", y++);
   			gotoxy(28, a);printf("%s", student.ID);
   			gotoxy(45, a);printf("%s", student.name);
   			gotoxy(80, a);printf("%s", student.father);
   			gotoxy(120, a);printf("%s", student.mother);		
			a++;
	    }	
        }
	fclose(data_file);
	a += 2;
	gotoxy(35, a);printf("Select the student number to be displayed : ");
	scanf("%d", &x);
	
	found_flag = 0;
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.name, data) == 0)
	    {
		found_flag++;
		if (found_flag == x)
		{
		    banner();
		    student_data(0);
		    gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		    scanf("%d", &y);
		}
	    }
	}
	fclose(data_file);
    }
}

//******************************************** father_search function definition ********************************************************

void father_search(char *data)
{
    int found_flag = 0, x, y, a = 15;
    FILE *data_file; 
    data_file = fopen("student_database.csv", "r");
    while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
    {
	if(strcmp(student.father, data) == 0)
	{	    
	    found_flag++;
	}
    }
    fclose(data_file);
        
    if(found_flag == 0)
    {
	gotoxy(40, 29);printf("No data matched");
	scanf("%d", &y);
    }
    else if(found_flag == 1)
    {
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.father, data) == 0)
	    {	
		banner();
	        student_data(0);
	        gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		scanf("%d", &y);
	    }
	}
	fclose(data_file);
    }
    else if(found_flag > 1)
    {
	y = 1;
	banner();
	gotoxy(15, 11);printf("===========================================================================================================================");
	gotoxy(20, 12);printf("S. No.");
   	gotoxy(28, 12);printf("Student ID");
   	gotoxy(45, 12);printf("Student Name");
   	gotoxy(80, 12);printf("Father's Name");
   	gotoxy(120, 12);printf("Mother's Name");
   	gotoxy(15, 13);printf("===========================================================================================================================");
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.father, data) == 0)
       	    {
       	    	gotoxy(20, a);printf("%d", y++);
   			gotoxy(28, a);printf("%s", student.ID);
   			gotoxy(45, a);printf("%s", student.name);
   			gotoxy(80, a);printf("%s", student.father);
   			gotoxy(120, a);printf("%s", student.mother);		
			a++;
	    }	
        }
	fclose(data_file);
	a += 2;
	gotoxy(35, a);printf("Select the student number to be displayed : ");
	scanf("%d", &x);
	
	found_flag = 0;
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.father, data) == 0)
	    {
		found_flag++;
		if (found_flag == x)
		{
		    banner();
		    student_data(0);
		    gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		    scanf("%d", &y);
		}
	    }
	}
	fclose(data_file);
    }
}

//******************************************** mother_search function definition ********************************************************

void mother_search(char *data)
{
    int found_flag = 0, x, y, a = 15;
    FILE *data_file; 
    data_file = fopen("student_database.csv", "r");
    while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
    {
	if(strcmp(student.mother, data) == 0)
	{	    
	    found_flag++;
	}
    }
    fclose(data_file);
        
    if(found_flag == 0)
    {
	gotoxy(40, 29);printf("No data matched");
	gotoxy(40, 30);printf("Enter any key to go to the previous menu");
	scanf("%d", &y);
    }
    else if(found_flag == 1)
    {
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.mother, data) == 0)
	    {	
		banner();
	        student_data(0);
	        gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		scanf("%d", &y);
	    }
	}
	fclose(data_file);
    }
    else if(found_flag > 1)
    {
	y = 1;
	banner();
	gotoxy(15, 11);printf("===========================================================================================================================");
	gotoxy(20, 12);printf("S. No.");
   	gotoxy(28, 12);printf("Student ID");
   	gotoxy(45, 12);printf("Student Name");
   	gotoxy(80, 12);printf("Father's Name");
   	gotoxy(120, 12);printf("Mother's Name");
   	gotoxy(15, 13);printf("===========================================================================================================================");
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.mother, data) == 0)
       	    {
       	    	gotoxy(20, a);printf("%d", y++);
   			gotoxy(28, a);printf("%s", student.ID);
   			gotoxy(45, a);printf("%s", student.name);
   			gotoxy(80, a);printf("%s", student.father);
   			gotoxy(120, a);printf("%s", student.mother);	
		a++;
	    }	
        }
	fclose(data_file);
	a += 2;
	gotoxy(35, a);printf("Select the student number to be displayed : ");
	scanf("%d", &x);
	
	found_flag = 0;
        data_file = fopen("student_database.csv", "r");
	while(fscanf(data_file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", student.ID, student.name, student.father, student.mother, student.gender, student.birth_date, student.class, student.phone, student.stu_add.area_village, student.stu_add.town_city, student.stu_add.district, student.stu_add.state, student.stu_add.pin) != EOF)
        {
	    if(strcmp(student.mother, data) == 0)
	    {
		found_flag++;
		if (found_flag == x)
		{
		    banner();
		    student_data(0);
		    gotoxy(30, 28);printf("Enter any key to go to the previous menu");
		    scanf("%d", &y);
		}
	    }
	}
	fclose(data_file);
    }
}
        
//********************************************** search_student function definition ***************************************************

void search_student()
{
    int choice = 0, exit_flag = 0, x = 50;
    char stu_id[15], stu_name[30], stu_father[30], stu_mother[30];
    while(exit_flag == 0)
    {
	banner();
        gotoxy(x, 10);printf("Please choose the below option :");
        gotoxy(x, 12);printf("Search by :");
        gotoxy(x, 16);printf("1. Student ID");
        gotoxy(x, 18);printf("2. Student Name");
        gotoxy(x, 20);printf("3. Father's Name");
        gotoxy(x, 22);printf("4. Mother's Name");
        gotoxy(x, 24);printf("5. Go to previous menu");
        gotoxy(x, 27);printf("Please choose the field to be searched: ");
	scanf("%d", &choice);
	gotoxy(x, 27);space(50);
        switch(choice)
	{
	    case 1:
		gotoxy(34, 27);printf("Please enter Student's ID : ");
		scanf(" %10s", stu_id);
		while((getchar()) != '\n');
                id_search(stu_id);
	        break;
	    case 2:
		gotoxy(34, 27);printf("Please enter Student's Name : ");
		scanf(" %29[^\n]", stu_name);
		while((getchar()) != '\n');
		name_search(stu_name);
		break;
	    case 3:
		gotoxy(34, 27);printf("Please enter Father's Name : ");
		scanf(" %29[^\n]", stu_father);
		while((getchar()) != '\n');
		father_search(stu_father);
		break;
	    case 4:
		gotoxy(34, 27);printf("Please enter Mother's Name : ");
		scanf(" %29[^\n]", stu_mother);
		while((getchar()) != '\n');
		mother_search(stu_mother);
		break;
	    case 5:
		exit_flag = 1;
		break;
	    default:
		textcolor(IRED);
		gotoxy(34, 29);printf("You have chosen the wrong option.");
		textcolor(CC_CLEAR);
		fflush(stdout);
		sleep(3);
		break;
	}

    }
}

//********************************************** modify_student function definition ***************************************************

void modify_student()
{
    printf("hello");
}

//********************************************** gen_marksheet function definition ***************************************************

void gen_marksheet()
{
    printf("hello");
}

//********************************************** delete_record function definition ***************************************************

void delete_record()
{
    printf("hello");
}

//********************************************** change_pass function definition ***************************************************

void change_pass()
{
    banner();
    char pass[11], pass1[11], pass2[11];
    int exit = 0, msg_flag = 0, y;
    FILE *old, *new;
    old = fopen("password.txt", "r");
    new = fopen("new.txt", "w");
    fscanf(old, "%10[^\n]", password);
    fclose(old);
    while(exit == 0)
    {
        banner();
	if(msg_flag == 1)
	{
	    gotoxy(45, 12);printf("Wrong Password entered!");
	    gotoxy(45, 13);printf("Try again!");
	}
        gotoxy(50, 16);printf("Please enter the present password : ");
        scanf(" %10s", pass);
        while((getchar()) != '\n');
        if(strcmp(pass, password) == 0)
	{
	    gotoxy(45, 18);printf("Please enter the new password : ");
	    scanf(" %10s", pass1);
	    gotoxy(45, 20);printf("Please re-enter the new password : ");
	    scanf(" %10s", pass2);
	    if(strcmp(pass1, pass2) == 0)
	    {
	         fprintf(new, "%s", pass1);
		 fclose(new);
		 remove("password.txt");
		 rename("new.txt", "password.txt");
	         gotoxy(45, 23);printf("Password changed successfully!");
	         gotoxy(45, 28);printf("Enter any key to go to the previous menu");
		 scanf("%d", &y);
		 exit = 1;
	    }
	}
        else
	    msg_flag = 1;
    }
}
