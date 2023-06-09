#ifndef TOTAL_H
#define TOTAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>

#define SPACE 100
#define MAX_BUF 4096

/* To execute in different system */
#if _WIN32
    #define CLEARSCEARN system("cls")
#elif (__APPLE__)
    #define CLEARSCREAN system("clear")
#endif

extern int number_ad; //trace the amount of administrator initialize 4 administrator
extern int amount_books; // trace the amount of books
extern int accession_numer; //record accession_number
extern int amount_re; // trace the amount of reader
extern char name_re[SPACE]; // current user
extern char name_ad[SPACE]; // current user
extern int amount_history;


extern FILE *fp_amount, *fp_administrator, *fp_book, *fp_reader, *fp_history;
extern jmp_buf	emailbuffer;

#define NO -1
#define YES 1

#define LARGE 10
#define SMALL 11

#define ADMINISTRATOR_MODE 2
#define READER_MODE 3

#define ADD 4
#define DELETE 5

#define BUTTON_EXIT 0

/* Option_mode */
#define BUTTON_AD_MODE 110
#define BUTTON_RE_MODE 120

/* Option_entry */
#define BUTTON_SIGN_IN 210
#define BUTTON_SIGN_UP 220

/* Option_ad */
#define BUTTON_REVIEW 310
#define BUTTON_ADD_DELETE 320 //choose add or delete book, this will create two child buttom
#define BUTTON_ADD 321 // add book
#define BUTTON_DELETE 322 // delete book
#define BUTTON_CHECK_BORROWING 330
#define BUTTON_CHECK_RE 340
#define BUTTON_CHECK_AD 350
#define BUTTON_ADD_AD 360
#define BUTTON_LEND 370

/* Option_re */
#define BUTTON_SEARCH 410
#define BUTTON_INFORMATION 420
#define BUTTON_BOOK_NAME 430
#define BUTTON_AUTHOR 440
#define BUTTON_PUBLISHER 450
#define BUTTON_CALL_NUMBER 460
#define BUTTON_ISBN 470
#define BUTTON_POPULAR 480
#define BUTTON_RESERVE 400

#define BUTTON_SORT_YEAR 510
#define BUTTON_SORT_CALL 520
#define BUTTON_SORT_VIEWER 530
#define BUTTON_SORT_ACCESSION 540

struct books 
{
    char book_name[SPACE];
    char author[SPACE];
    char publisher[SPACE];
    int publish_year;
    int amount;        //amount 
    char call_number[SPACE];
    char isbn[SPACE];
    float viewer_count;
    int accession_number;
    int status; // to know whether the book is borrowed
}book[MAX_BUF];

struct administrators
{
    char ad_name[SPACE];
    char ad_account[SPACE];
    char ad_password[SPACE];
} administrator[SPACE];


struct readers
{
    char re_name[SPACE];
    int student_id;
    char email[SPACE];
    char re_account[SPACE];
    char re_password[SPACE];
    struct readers *next;
};

struct readers *first = NULL;

struct history // Queue
{
    char re_name[SPACE];
    char book_name[SPACE];
    struct history *next;
};

struct Queue
{
    struct history *front; // Points to the front of the queue
    struct history *rear; // Points to the rear of the queue
};

struct Queue *queue;

int empty(struct Queue *queue);

struct Queue *createQueue();

void enqueue(struct Queue *queue, char re_name[], char book_name[]);

void dequeue(struct Queue* queue);

void sort_publish_year();

//void sort_call_number();

void sort_viewer_count();

void sort_accession_number();

void free_reader(struct readers *list);

void input_file();

void output_file();

/* Decide the mode */
void interface_choose_identity(int option_mode); //

void interface_ad_entry();

void interface_re_entry(int option_entry); //sign in or sign up

/* Explain and fill in information */
void interface_set_reader(int option_entry, char name[], int id, char grade[], char email[], char account[],char password[]); //get the information

int set_check_account_re(char name[], int id, char email[], char account[]); //need to print error message

void check_email(char email[]);

void add_reader(); //add into linked list

void sign_in_administrator();

/* Check account first. If account doeasn't exist will not check password */
int in_check_account_ad(char account[]); //need to print error message

int in_check_password_ad(char account[], char password[]); //need to print error message

void sign_in_reader();

/* Check account first. If account doeasn't exist will not check password */
int in_check_account_re(char account[]); //need to print error message

int in_check_password_re(char account[], char password[]); //need to print error message

/* Administrator mode */
void administrator_mode(); //if mode == ADMINISTRATOR_MODE

void interface_ad(); // contain 8 buttons ( include exit button )

void review_library(); //show every book, can decide the way to 

void interface_add_delete(); //add or delete

void add_book();

void delete_book(); //show every book first(use search_book_name()). To make sure whether the book you want to delete

/* While checking borrowing, you can return book */
void check_borrowing(); //show every borrowed books

void return_book(); // use number to choose the book to return

void check_re_information();

void modify_re_information(); // modify or delete reader information

void check_ad_information(); 

void modify_ad_information(); // delete administrator information

void interface_set_administrator(char name[], char account[], char password[]); //get the information

int set_check_account_ad(char name[], char account[]); // need to print error message

//void set_check_password_ad(char password[]); // need to print error message

void add_administrator(); // add into structure

void lend_book(); // change the status of book

/* Reader mode*/
void reader_mode(); // if mode == READER_MODE

void interface_re(int option_re); // contain 9 buttons ( include exit button )

void check_personal_information();

void lowwer(char string[]);

/* Search every book which contain the same string in searching */
/* Decided by option_re */
void search_book_name();

void search_author();

void search_publisher();

void search_call_number();

void search_isbn();

void search_viewer_count(); // print every book that amount of viewer is greater than 0 from the most popular

void show_book(); // print the result into table. If doesn't search the books return the message

void reserve_book(); // change the status of book

#endif /* TOTAL_H */
