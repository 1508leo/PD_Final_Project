#include "total.h"
void administrator_mode(){
    int option_ad; // 這裡的變數是用來選擇要做什麼事情的
    printf("=====================================\n");
    printf("|What would you like to do?         |\n");
    printf("|1. review_library                  |\n");
    printf("|2. add book or delete book         |\n");
    printf("|3. check_borrowing                 |\n");
    printf("|4. check reader information        |\n");
    printf("|5. check administrator information |\n");
    printf("|6. lend book                       |\n");
    printf("|7. add administrator               |\n");
    printf("|8. Exit                            |\n");
    printf("=====================================\n");
    printf("Please enter an option: ");
    scanf("%d", &option_ad); // 輸入要做什麼事情
    interface_re(option_ad); // 請開始做事情
}

//void interface_ad(int option_ad); //按鈕

void review_library(){ //印出所有的書
    printf("=================================================================================================================\n");
    printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
    printf("=================================================================================================================\n");

    for (int i = 0; i < MAX_BUF; i++)
    {
        if(book[i].book_name[0] == '\0') continue;//已被刪除的書書名會是'\0'
        else
        {
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
        }
    }
}

//void interface_add_delete(int option_ad, int option_crease); //按鈕

void add_book(){
    int i=5;//i暫時代表有幾本書

    if (i == MAX_BUF) { //已達最大值時拒絕添加
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("enter the book_name: ");
    scanf(" %s",book[i].book_name);

    printf("enter the aurthor: ");
    scanf(" %s",book[i].author);

    printf("enter the translator: ");
    scanf(" %s",book[i].translator);

    printf("enter the publisher: ");
    scanf(" %s",book[i].publisher);

    printf("enter the publish_year: ");
    scanf("%d",&book[i].publish_year);

    printf("enter the call_number: ");
    scanf("%f",&book[i].call_number);

    printf("enter the isbn: ");
    scanf(" %s",book[i].isbn);
}

void delete_book( ){ //show every book first(use search_book_name()). To make sure whether the book you want to delete
    review_library();//先印出所有的書
    printf("enter the book name which book you want to delete");
    char tmp_book_name[30];
    scanf(" %s",tmp_book_name);
    for (int i = 0; i < MAX_BUF; i++)
    {
        if(strcmp(book[i].book_name,tmp_book_name)==0){
            gotolable://輸入錯誤訊息時跳至這裡
            printf("Warning! Are you sure you want to deleted this book? y/n");
            char oper;//再次確認是否要刪
            scanf(" %c",&oper);
            if(oper == 'y'){
                book[i].book_name[0] = '\0';//將書籍名稱設為已被刪除
                printf("Delete OK\n");
                break;
            }
            else if(oper == 'n'){
                printf("Delete failed\n");
                break;
            }
            else{
                printf("wrong operation!\n");
                goto gotolable;
            }
        }
    }
}
/* While checking borrowing, you can return book */
void check_borrowing( int number_book){//印出所有已被借出的書
    printf("=================================================================================================================\n");
    printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
    printf("=================================================================================================================\n");
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name[0] != '\0' && book[i].accession_number != 0)
        {
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
        }
    }
}

void return_book(int number, int number_book); // use number to choose the book to return

void check_re_information(int option_ad){
    /*char *re_name;
        int student_id;
        char *grade;
        char *email;
        char *re_account;
        char *re_password;
        char **borrow_history;
        int credit;*/
    struct readers *current = first;

    printf("=================================================================================================\n");
    printf("| Reader name | student_id | grade | email | re_account | re_password | borrow_history | credit |\n");
    printf("================================================================================================= \n");

    while(current != NULL){
        printf(" %s | %d | %s | %s | %s | %s | %s | %d\n",
               current->re_name, current->student_id, current->grade, current->email,
               current->re_account, current->re_password, current->borrow_history, current->credit);

        current = current->next;
    }
}

void modify_re_information(int option_number){//這個函數目前還缺刪除讀者的功能
    struct readers *current = first;

    printf("enter the reader name which you want to modify:\n");
    char temp_reader_name[30];
    scanf(" %s",temp_reader_name);//輸入想查找的名稱

    int oper = 0; // 選擇器，0 表示找不到目標名字
    while (current != NULL) {
        if (strcmp(current->re_name, temp_reader_name) == 0) { // 若找到，則進行修改
            printf("Enter the new information for the reader:\n");
            printf("please enter re_name: ");
            scanf(" %s",current->re_name);

            printf("please enter student_id: ");
            scanf(" %d",&(current->student_id));

            printf("please enter grade: ");
            scanf(" %s",current->grade);

            printf("please enter email: ");
            scanf(" %s",current->email);

            printf("please enter re_account: ");
            scanf(" %s",current->re_account);

            printf("please enter re_password: ");
            scanf(" %s",current->re_password);

            printf("please enter borrow_history: ");
            scanf(" %s",current->borrow_history);

            printf("please enter credit: ");
            scanf("%d",&(current->credit));

            oper = 1; // 找到目標名字
            break;
        }
        else  current = current->next;
    }

    if (oper == 0)  printf("No such reader!\n"); //若整個迴圈跑完都沒找到目標名字
} // modify or delete reader information

void check_ad_information(int option_ad){
    printf("======================================\n");
    printf("| ad_name | ad_account | ad_password |\n");
    printf("======================================\n");
    for (int i = 0; i < number_ad; i++)
    {
        printf("%s | %s | %s\n", administrator[i].ad_name, administrator[i].ad_account, administrator[i].ad_password);
        printf("======================================\n");
    }
}

void modify_ad_information(int number, int option_number){ // 這個函數目前還缺刪除管理員的功能
    int id;//管理員編號
    printf("Enter the administrator ID: ");
    scanf("%d",&id);

    if (id >= 0 && id < number_ad) {
        printf("information of this administrator\n");
        printf("======================================\n");
        printf("| ad_name | ad_account | ad_password |\n");
        printf("======================================\n");
        printf("%s | %s | %s\n", administrator[id].ad_name, administrator[id].ad_account, administrator[id].ad_password);

        printf("Enter the new information for the administrator:\n");
        printf("New name: ");
        scanf(" %s", administrator[id].ad_name);

        printf("New account: ");
        scanf(" %s", administrator[id].ad_account);

        printf("New password: ");
        scanf(" %s", administrator[id].ad_password);
    }
    else  printf("Invalid administrator ID!\n");
}

//void interface_set_administrator(int option_ad, char name[], char account[], char password[]); //按鈕

void set_check_account_ad(char account[]); // need to print error message

void set_check_password_ad(char password[]); // need to print error message

void lend_book(char book_name[], char name[]); // change the status of book

void add_administrator( ){//number_ad的初始值在total.h中設為4，代表陣列中的第五格
    printf("enter your name: ");
    scanf(" %s",administrator[number_ad].ad_name);

    printf("enter your account: ");
    scanf(" %s",administrator[number_ad].ad_account);

    printf("enter your password: ");
    scanf(" %s",administrator[number_ad].ad_password);

    number_ad++;
}
