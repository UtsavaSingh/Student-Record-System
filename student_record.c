#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "function_declaration.h"

int main()
{
    short unsigned int choice, exit_flag = 0;
    while(exit_flag == 0)
    {
	banner();
        main_menu();

        scanf("%hu", &choice);
        switch(choice)
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
		printf("You have chosen the wrong option.");
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
    gotoxy(30, 1);printf("==============================================================================================");
    textcolor(IRED);
    textcolor(BGC_YELLOW);
    gotoxy(56, 2);printf("                                      ");
    gotoxy(56, 3);printf("     MODERN SHANTI CONVENT SCHOOL     ");
    gotoxy(56, 4);printf("                                      ");
    textcolor(CC_CLEAR);
    gotoxy(30, 5);printf("==============================================================================================");
    textcolor(IGREEN);
    gotoxy(64, 6);printf("STUDENT RECORD SYSTEM");
    textcolor(CC_CLEAR);
    gotoxy(30, 7);printf("==============================================================================================");
}

//********************************************** main_menu function definition ***************************************************

void main_menu()
{
    short int x = 50;
    textcolor(BLUE);
    gotoxy(x, 10);printf("1. Add Student");
    gotoxy(x, 12);printf("2. Search Student");
    gotoxy(x, 14);printf("3. Modify Student Record");
    gotoxy(x, 16);printf("4. Generate Marksheet");
    gotoxy(x, 18);printf("5. Delete Student Record");
    gotoxy(x, 20);printf("6. Change Password");
    gotoxy(x, 22);printf("7. Exit");
    textcolor(CC_CLEAR);
    gotoxy(45, 25);printf("Please choose from the above options: ");
}

//********************************************** main_menu function definition ***************************************************

void add_student()
{
    printf("Hello");
}

//********************************************** main_menu function definition ***************************************************

void search_student()
{
    printf("hello");
}

//********************************************** main_menu function definition ***************************************************

void modify_student()
{
    printf("hello");
}

//********************************************** main_menu function definition ***************************************************

void gen_marksheet()
{
    printf("hello");
}

//********************************************** main_menu function definition ***************************************************

void delete_record()
{
    printf("hello");
}

//********************************************** main_menu function definition ***************************************************

void change_pass()
{
    printf("hello");
}
