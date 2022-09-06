/*
 * Name          : Utsava Kumar Singh
 * Date          : 4th september 2022
 * Discription   : Student Record Syatem for a School
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

char password[] = "utsava";

typedef struct
{
    char area_village[20];
    char town_city[20];
    char district[20];
    char state[20];
    char pin[8];
}address;

typedef struct
{
    char ID[20];
    char name[20];
    char father[20];
    char mother[20];
    address stu_add;
    char class[10];
    char phone[11];
    char gender[10];
} student;

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
        scanf("%s", pass);
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

//********************************************** main_menu function definition ***************************************************

void add_student()
{
    banner();
    fflush(stdout);
    sleep(5);
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
