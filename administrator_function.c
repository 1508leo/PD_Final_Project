#include "total.h"
void administrator_mode(){
    int option_ad; // 這裡的變數是用來選擇要做什麼事情的
    printf("=====================================");
    printf("|What would you like to do?         |\n");
    printf("|1. review_library                  |\n");
    printf("|2. add book or delete book         |\n");
    printf("|3. check_borrowing                 |\n");
    printf("|4. check reader information        |\n");
    printf("|5. check administrator information |\n");
    printf("|6. lend book                       |\n");
    printf("|7. add administrator               |\n");
    printf("|8. Exit                            |\n");
    printf("=====================================");
    printf("Please enter an option: ");
    scanf("%d", &option_ad); // 輸入要做什麼事情
    interface_re(option_ad); // 請開始做事情
}

//void interface_ad(int option_ad); //按鈕

void review_library(int option_ad, int option_sort){ //印出所有的書
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("%s|%s|%s|%d|%d|%.2f|%s|%d|%d|\n", book[i].book_name, book[i].author,book[i].publisher, book[i].publish_year,
                    book[i].amount,book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
        }
    }
}

//void interface_add_delete(int option_ad, int option_crease); //按鈕

void add_book(char book_name[], char aurthor[], char translator[],char publisher[], int publish_year, float call_number, char isbn[]);

void delete_book(char book_name[], int optiont_shure); //show every book first(use search_book_name()). To make sure whether the book you want to delete

/* While checking borrowing, you can return book */
void check_borrowing(int option_ad, int number_book){
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && book[i].borrower != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("%s|%s|%s|%d|%d|%.2f|%s|%d|%d|\n", book[i].book_name, book[i].author,book[i].publisher, book[i].publish_year,
                    book[i].amount,book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
        }
    }
} //印出所有已被借出的書

void return_book(int number, int number_book); // use number to choose the book to return

void check_re_information(int option_ad) ;

void modify_re_information(int option_number); // modify or delete reader information

void check_ad_information(int option_ad){
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (administrator[i].ad_name != NULL)
        {
            printf("======================================\n");
            printf("| ad_name | ad_account | ad_password |\n");
            printf("======================================\n");
            printf("%s|%s|%s", administrator[i].ad_name, administrator[i].ad_account, administrator[i].ad_password);
        }
    }
}

void modify_ad_information(int number, int option_number); // delete administrator information

//void interface_set_administrator(int option_ad, char name[], char account[], char password[]); //按鈕

void set_check_account_ad(char account[]); // need to print error message

void set_check_password_ad(char password[]); // need to print error message

void lend_book(int option_ad, char book_name[], char name[]); // change the status of book

void add_administrator(char name[], char account[],char password[]); // add into structure
