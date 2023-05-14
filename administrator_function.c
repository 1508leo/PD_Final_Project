/*目前遇到幾個問題，看到這段話的請回覆我
1.return_book 跟 lend_book這兩個函數的功能是不是重複了？
2.total.h中能不能幫我添加管理員編號？modify_ad_information 這個函數中需要用到。
3.account是否有存在的必要？我覺得只要有讀者名字跟密碼就夠了，account 的功能看起來只是像另一組密碼。
4.delete_book這個函數中需要呼叫review_library跟自己，但編譯不過，可能的原因是什麼?
*/
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

void review_library(int option_ad, int option_sort){ //印出所有的書
    for (int i = 0; i < MAX_BUF; i++)
    {
        if(book[i].book_name == 'deleted') continue;//已被刪除的書書名會是deleted，若遇到，跳過
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

void add_book(char book_name[], char aurthor[], char translator[],char publisher[], int publish_year, float call_number, char isbn[]){
    int i=5;//i暫時代表有幾本書
    printf("enter the book_name:");
    scanf(" %s",book[i].book_name);

    printf("enter the aurthor:");
    scanf(" %s",book[i].author);

    printf("enter the translator:");
    scanf(" %s",book[i].translator);

    printf("enter the publisher:");
    scanf(" %s",book[i].publisher);

    printf("enter the publish_year:");
    scanf("%d",&book[i].publish_year);

    printf("enter the call_number:");
    scanf("%f",&book[i].call_number);

    printf("enter the isbn:");
    scanf(" %s",book[i].isbn);
}

void delete_book(char book_name[], int optiont_shure){ //show every book first(use search_book_name()). To make sure whether the book you want to delete
    review_library();//先印出所有的書
    printf("enter the book name which book you want to delete");
    char tmp_book_name[30];
    scanf(" %s",tmp_book_name);
    for (int i = 0; i < MAX_BUF; i++)
    {
        if(strcmp(book[i].book_name,tmp_book_name)==0){
            gotolable://輸入錯誤訊息時跳至這裡
            printf("Warning! Are you sure you want to deleted this book? y/n");
            char oper[2];
            scanf("%c",oper);
            if(oper == 'y'){
                book[i].book_name = 'deleted';//將書籍名稱設為已被刪除
                break;
            }
            else if(oper == 'n'){
                delete_book();//重新開啟這個function
            }
            else{
                printf("wrong operation!\n");
                goto gotolable;
            }
        }
    }
}
/* While checking borrowing, you can return book */
void check_borrowing(int option_ad, int number_book){//印出所有已被借出的書
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && book[i].accession_number != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("%s|%s|%s|%d|%d|%.2f|%s|%d|%d|\n", book[i].book_name, book[i].author,book[i].publisher, book[i].publish_year,
                    book[i].amount,book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
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
    struct readers *current;
    current = first;
    while(current != NULL){
        printf("=================================================================================================\n");
        printf("| Reader name | student_id | grade | email | re_account | re_password | borrow_history | credit |\n");
        printf("================================================================================================= \n");
        printf(" %s | %d | %s | %s | %s | %s | %s | %d",current->re_name,current->student_id,current->grade,current->email,
               current->re_account,current->re_password,current->borrow_history,current->credit);
        current = current->next;
    }
}

void modify_re_information(int option_number){//這個函數目前還缺刪除讀者的功能
    struct readers *current;
    current = first;

    printf("enter the reader name which you want to modify:\n");
    char *temp_reader_name;
    scanf(" %s",temp_reader_name);//輸入想查找的名稱

    int oper = 1;//預設一選擇器為1
    while(current != NULL){
        if(strcmp(current->re_name,temp_reader_name)==0){//若有找到，則進行修改
            scanf(" %s %d %s %s %s %s %s %d",current->re_name,&current->student_id,current->grade,current->email,
                  current->re_account,current->re_password,current->borrow_history,&current->credit);//輸入資料
            oper = 1;
            break;
        }
        else oper = 0;//找不到目標名字就把選擇器改為0
    }
    if(oper == 0){//若整個迴圈跑完都沒找到目標名字
        printf("no this reader!");
    }
} // modify or delete reader information

void check_ad_information(int option_ad){
    for (int i = 0; i < number_ad; i++)
    {
        printf("======================================\n");
        printf("| ad_name | ad_account | ad_password |\n");
        printf("======================================\n");
        printf("%s|%s|%s", administrator[i].ad_name, administrator[i].ad_account, administrator[i].ad_password);
    }
}

void modify_ad_information(int number, int option_number){ // 這個函數目前還缺刪除管理員的功能
    int id;//管理員編號
    scanf("%d",&id);
    printf("information of this administrator\n");
    printf("======================================\n");
    printf("| ad_name | ad_account | ad_password |\n");
    printf("======================================\n");
    printf(" %s %s %s",administrator[id].ad_name,administrator[id].ad_account,administrator[id].ad_password);
    printf("new name:");
    scanf(" %s",administrator[id].ad_name);
    printf("new account:");
    scanf(" %s",administrator[id].ad_account);
    printf("new password:");
    scanf(" %s",administrator[id].ad_password);
}

//void interface_set_administrator(int option_ad, char name[], char account[], char password[]); //按鈕

void set_check_account_ad(char account[]); // need to print error message

void set_check_password_ad(char password[]); // need to print error message

void lend_book(int option_ad, char book_name[], char name[]); // change the status of book

void add_administrator(char name[], char account[],char password[]){//number_ad的初始值在total.h中設為4，代表陣列中的第五格
    printf("enter your name:");
    scanf(" %s",administrator[number_ad].ad_name);

    printf("enter your account:");
    scanf(" %s",administrator[number_ad].ad_account);

    printf("enter your password:");
    scanf(" %s",administrator[number_ad].ad_password);

    number_ad++;
}
