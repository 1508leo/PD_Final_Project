#ifndef TOTAL_H
#define TOTAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int number_ad = 4; //trace the amount of administrator initialize 4 administrator
int index_books = 0; // trace the amount of books
int accession_numer = 0; //record accession_number
int amount_re = 0; // trace the amount of reader

#define NO -1
#define YES 1

#define MAX_BUF 4096
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
    char *book_name;
    char *author;
    char *translator;
    char *publisher;
    int publish_year;
    int amount;        //amount might larger than 1
    float call_number;
    char *isbn;
    int viewer_count;
    int accession_number;
    char **borrower;
    int expiry_date[MAX_BUF];

}book[MAX_BUF];

struct administrators
{
    char *ad_name;
    char *ad_account;
    char *ad_password;
} administrator[MAX_BUF];


struct readers
{
    char *re_name;
    int student_id;
    char *grade; 
    char *email;
    char *re_account;
    char *re_password;
    char **borrow_history;
    int credit;
    struct readers *next;
    struct readers *link;
};

struct readers *first = NULL;

void sort_publish_year();

//void sort_amount();

void sort_call_number();

void sort_viewer_count();

void sort_accession_number();

void input_file();

void output_file();

/* Decide the mode */
void interface_choose_identity(int option_mode); //

void interface_ad_entry();

void interface_re_entry(int option_entry); //sign in or sign up

/* Explain and fill in information */
void interface_set_reader(int option_entry, char name[], int id, char grade[], char email[], char account[],char password[]); //get the information

int set_check_account_re(char account[]); //need to print error message

//int set_check_password_re(char password[]); //need to print error message

void add_reader(char name[], int id, char grade[], char email[], char account[],char password[]); //add into linked list

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

void interface_ad(int option_ad); // contain 8 buttons ( include exit button )

void review_library(int option_ad, int option_sort); //show every book, can decide the way to 

void interface_add_delete(int option_ad, int option_crease); //add or delete

void add_book(char book_name[], char aurthor[], char translator[],char publisher[], int publish_year, float call_number, char isbn[]);

void delete_book(char book_name[], int optiont_shure); //show every book first(use search_book_name()). To make sure whether the book you want to delete

/* While checking borrowing, you can return book */
void check_borrowing(int option_ad, int number_book); //show every borrowed books

void return_book(int number, int number_book); // use number to choose the book to return

void check_re_information(int option_ad);

void modify_re_information(int option_number); // modify or delete reader information

void check_ad_information(int option_ad); 

void modify_ad_information(int number, int option_number); // delete administrator information

void interface_set_administrator(int option_ad, char name[], char account[], char password[]); //get the information

void set_check_account_ad(char account[]); // need to print error message

//void set_check_password_ad(char password[]); // need to print error message

void add_administrator(char name[], char account[],char password[]); // add into structure

void lend_book(int option_ad, char book_name[], char name[]); // change the status of book

/* Reader mode*/
void reader_mode(); // if mode == READER_MODE

void interface_re(int option_re); // contain 9 buttons ( include exit button )

void check_personal_information(int option_re);

/* Search every book which contain the same string in searching */
/* Decided by option_re */
void search_book_name(char book_name[]);

void search_author(char author[]);

void search_publisher(char publisher[]);

void search_call_number(float call_number[]);

void search_isbn(char isbn[]);

void search_viewer_count(); // print every book that amount of viewer is greater than 0 from the most popular

void show_book(); // print the result into table. If doesn't search the books return the message

void reserve_book(int number_book, int option_reserve); // change the status of book

#endif /* TOTAL_H */