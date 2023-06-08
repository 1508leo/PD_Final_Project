/*5/20更新問題
要求:書籍新曾status(借閱狀態)
未完成:
*/
#include "total.h"
void administrator_mode()
{
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

void review_library() // print every book
{
    int num_books = 0;

    printf("\033[H\033[2J"); // clear screen
    // show every books
    printf("====================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("====================================================================================================================================================================================\n");
    for (int i = 0; i < amount_books; i++)
    {
        printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                book[i].isbn, book[i].viewer_count, book[i].accession_number);
        printf("====================================================================================================================================================================================\n");
        num_books = 1;
    }

    // If there is no book in library
    if(num_books == 0)
    {
        printf("=======================================\n");
        printf("|     There is no book in library.    |\n");
        printf("=======================================\n");
    }
}

//void interface_add_delete(int option_ad, int option_crease); //按鈕

void add_book()
{
    char book_name[SPACE], author[SPACE], publisher[SPACE], call_number[SPACE], isbn[SPACE];
    if (amount_books == MAX_BUF)
    { // The capacity of the library is full
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("\033[H\033[2J"); // clear screen
    printf("Please enter the book_name: ");
    fgets(book_name, SPACE, stdin);
    if(book_name[strlen(book_name) - 1] == '\n')
        book_name[strlen(book_name) - 1] = '\0';

    printf("Please enter the aurthor: ");
    fgets(author,  SPACE, stdin);
    if(author[strlen(author) - 1] == '\n')
        author[strlen(author) - 1] = '\0';

    printf("Please enter the publisher: ");
    fgets(publisher,  SPACE, stdin);
    if(publisher[strlen(publisher) - 1] == '\n')
        publisher[strlen(publisher) - 1] = '\0';

    printf("Please enter the publish_year: ");
    scanf("%d",&book[amount_books].publish_year);

    fflush(stdin);

    printf("Please enter the call_number: ");
    fgets(call_number,  SPACE, stdin);
    if(call_number[strlen(call_number) - 1] == '\n')
        call_number[strlen(call_number) - 1] = '\0';

    printf("Please enter the isbn: ");
    fgets(isbn,  SPACE, stdin);
    if(isbn[strlen(isbn) - 1] == '\n')
        isbn[strlen(isbn) - 1] = '\0';

    strcpy(book[amount_books].book_name, book_name);
    strcpy(book[amount_books].author, author);
    strcpy(book[amount_books].publisher, publisher);
    strcpy(book[amount_books].call_number, call_number);
    strcpy(book[amount_books].isbn, isbn);
    book[amount_books].accession_number = accession_numer;

    printf("\nThe book addition is complete.\n");

    accession_numer++;
    amount_books++;
}

void delete_book( )//show every book first(use search_book_name()). To make sure whether the book you want to delete
{
    int delete_number=0, find=0;
    review_library(); // print every book first
    printf("Please enter the accession number of book you want to delete: ");
    scanf(" %d", &delete_number);

    for (int i = 0; i < amount_books; i++)
    {
        if(book[i].accession_number == delete_number)
        {
            int confirm=0;
            find = 1;
            while(1)
            {
                printf("========================================================\n");
                printf("| Are you sure you want to delete %-20s |\n", book[i].book_name);
                printf("| 1. Yes%46s |\n", " ");
                printf("| 2. No%47s |\n", " ");
                printf("========================================================\n");
                printf("Please enter your option: ");
                scanf(" %d", &confirm);
                if(confirm > 2 || confirm < 1)
                {
                    printf("\033[H\033[2J"); // clear screen
                    printf("Error Option\n\n");
                    continue;
                }
                else if(confirm == 1)
                {
                    if(i == MAX_BUF - 1)
                    {
                        strcpy(book[i].book_name, "\0");
                        strcpy(book[i].author, "\0");
                        strcpy(book[i].publisher, "\0");
                        book[i].publish_year = 0;
                        strcpy(book[i].call_number, "\0");
                        strcpy(book[i].isbn, "\0");
                        book[i].viewer_count = 0;
                        book[i].accession_number = 0;
                        book[i].status = 0;
                    }
                    else
                    {
                        for(int j = i; j < amount_books; j++)
                        book[j] = book[j + 1];
                    }

                    printf("\nThe deletion of book is complete.\n");
                    amount_books--;
                    break;
                }
                else // confirm = 2
                    break;
            }
            break;
            
        }
    }

    if(find == 0)
        printf("\nThere is no book with accession number %d in the library.\n", delete_number);

    return;
}

void check_borrowing() // print every book which is borrowed
{
    int find=0;
    printf("\033[H\033[2J"); // clear screen
    
    for (int i = 0; i < amount_books; i++)
    {
        if (book[i].status != 0)
        {
            if(find == 0)
            {
                printf("====================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("====================================================================================================================================================================================\n");
            }
            find = 1;
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
        }
    }

    if(find == 0)
        printf("Every book in the library is not borrowed.\n");
}

void return_book()
{
    check_borrowing(); // show the borrowing books
    printf("\nWhich book do you want to return?\n");
    printf("Please enter the accession number of the book: ");
    int return_book=0, find=0;
    scanf("%d",&return_book);
    for(int i = 0; i < amount_books; i++)
    {
        if (book[i].accession_number == return_book)
        {
            find = 1;
            if(book[i].status == 0)
            {
                printf("\nThe book is in the library.\n");
                return;
            }
            else // status = 1
            {
                printf("\nReturn %s successfully.\n", book[i].book_name);
                book[i].status = 0;
            }
        }
    }

    if(find == 0)
        printf("\nThere is no book with the accession number %d in the library.\n", return_book);
} 


void check_re_information()
{
    printf("\033[H\033[2J"); // clear screen
    struct readers *current = first;

    printf("=========================================================================================================\n");
    printf("| %2s%-12s | %10s | %10s%-15s | %5s%-15s | %5s%-15s |\n", " ","Reader name", "student_id", " ", "email", " ", "re_account", " ", "re_password");
    printf("========================================================================================================= \n");

    while(current != NULL){
        printf("| %-14s | %-10d | %-25s | %-20s | %-20s |\n", current->re_name, current->student_id, current->email,
               current->re_account, current->re_password);
        printf("=========================================================================================================\n");

        current = current->next;
    }
}

void modify_re_information() // Modify or delete reader information
{
    struct readers *current = first;
    struct readers *prev = NULL;
    check_re_information();
    printf("Please enter the reader name which you want to modify: ");
    char temp_reader_name[30];
    fgets(temp_reader_name,  sizeof(temp_reader_name), stdin); // The reader name that is going to be modified
    if(temp_reader_name[strlen(temp_reader_name) - 1] == '\n')
        temp_reader_name[strlen(temp_reader_name) - 1] = '\0';

    int oper = 0; // Represent whether tje name is exist
    while (current != NULL)
    {
        if (strcmp(current->re_name, temp_reader_name) == 0) // reader_name exist
        {
            oper = 1; // Find the reader
            jmp_buf	jmpbuffer;
            int error=0;
            error = setjmp(jmpbuffer);
            if(error == 1) // If user enter wrong option
            {
                printf("\033[H\033[2J"); // clear screan
                printf("Wrong operation!\n\n");
            }

            printf("================================\n");
            printf("| What do you prefer to do?    |\n");
            printf("| 1. Modify reader information |\n");
            printf("| 2. Delete reader             |\n");
            printf("================================\n");
            printf("Please enter your option: ");

            int operation=0; // Decide operation
            scanf("%d",&operation);
            if(operation == 1) // Modify reader information
            {
                
                char name[SPACE], email[SPACE], account[SPACE], password[SPACE];
                int id=0;
                printf("\033[H\033[2J"); // clear screan
                printf("============================================\n");
                printf("| Enter the new information for the reader |\n");
                printf("============================================\n\n");

                fflush(stdin);

                printf("Old name: %s\n", current -> re_name);
                printf("Please enter the new reader name: ");
                fgets(name,  sizeof(name), stdin);
                if(name[strlen(name) - 1] == '\n')
                    name[strlen(name) - 1] = '\0';

                printf("Old student id: %d\n", current -> student_id);
                printf("Please enter the new student id: ");
                scanf(" %d", &id);

                fflush(stdin);

                printf("Old email: %s\n", current -> email);
                printf("Please enter the new email: ");
                fgets(email,  sizeof(email), stdin);
                if(email[strlen(email) - 1] == '\n')
                    email[strlen(email) - 1] = '\0';

                printf("Old account: %s\n", current -> re_account);
                printf("Please enter the new reader account: ");
                fgets(account,  sizeof(account), stdin);
                if(account[strlen(account) - 1] == '\n')
                    account[strlen(account) - 1] = '\0';

                printf("Old password: %s\n", current -> re_password);
                printf("Please enter reader password: ");
                fgets(password,  sizeof(password), stdin);
                if(password[strlen(password) - 1] == '\n')
                    password[strlen(password) - 1] = '\0';

                strcpy(current -> re_name, name);
                current -> student_id = id;
                strcpy(current -> email, email);
                strcpy(current -> re_account, account);
                strcpy(current -> re_password, password);

                printf("\033[H\033[2J"); // clear screan
                printf("Update successful!\n");

                break;
            }
            else if(operation == 2) // Delete reader
            {
                if (prev == NULL)  // Remove the first reader
                    first = current->next;
                else 
                    prev->next = current->next; // Remove the reader that is not the first
                free(current);

                printf("\033[H\033[2J"); // clear screan
                printf("Deletion successful!\n");
                break;
            }
            else // error option
            {
                longjmp(jmpbuffer, 1); // to the error message
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    if (oper == 0)  
        printf("No such reader!\n"); //Can't find the reader
}

void check_ad_information()
{
    printf("======================================\n");
    printf("| ad_name | ad_account | ad_password |\n");
    printf("======================================\n");
    for (int i = 0; i < number_ad; i++)
    {
        printf("%s | %s | %s\n", administrator[i].ad_name, administrator[i].ad_account, administrator[i].ad_password);
        printf("======================================\n");
    }
}

void modify_ad_information(int number, int option_number)
{ // 這個函數目前還缺刪除管理員的功能
    int id;//管理員編號
    printf("Enter the administrator ID: ");
    scanf("%d",&id);

    if (id >= 0 && id < number_ad)
    {
        printf("information of this administrator\n");//列出資料
        printf("======================================\n");
        printf("| ad_name | ad_account | ad_password |\n");
        printf("======================================\n");
        printf("%s | %s | %s\n", administrator[id].ad_name, administrator[id].ad_account, administrator[id].ad_password);


        printf("Enter 1 if you want to modify information for the administrator\n");//選擇修改or刪除
        printf("Enter 2 if you want to delete information for the administrator: ");

        int operation;//選擇器 選擇要修該資料還刪除資料
        scanf("%d",&operation);
        if(operation == 1)
        {//修該資料
            printf("Enter the new information for the administrator:\n");
            printf("New name: ");

            fgets(administrator[id].ad_name,  SPACE, stdin);

            printf("New account: ");
            fgets(administrator[id].ad_account,  SPACE, stdin);

            printf("New password: ");
            fgets(administrator[id].ad_password,  SPACE, stdin);
            return;
        }
        else if(operation == 2)//刪除資料
        {
            number_ad--;//管理員總人數減1
            for (int i = id; i < number_ad - 1; i++) // 往前移一格
            {
                strcpy(administrator[i].ad_name, administrator[i + 1].ad_name);
                strcpy(administrator[i].ad_account, administrator[i + 1].ad_account);
                strcpy(administrator[i].ad_password, administrator[i + 1].ad_password);
            }
            strcpy(administrator[number_ad].ad_name, "");
            strcpy(administrator[number_ad].ad_account, "");
            strcpy(administrator[number_ad].ad_password, "");
            return;
        }
        else //錯誤輸入
        {
            printf("wrong operation!\n");
            return;
        }
    }
    else  printf("Invalid administrator ID!\n");
}

//void interface_set_administrator(int option_ad, char name[], char account[], char password[]); //按鈕

void lend_book()
{
    check_borrowing();
    printf("Which book do you want to lend?\n");
    int number_book;
    scanf("%d",&number_book);
    for(int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name[0] != '\0' && book[i].status != 1)
        {
            if(number_book == book[i].call_number)
            {
                book[i].status = 1;
                printf("Lend successful.\n");
                return;
            }
        }
    }
} // change the status of book

/* Add new administrator */
void add_administrator()
{
    char name[SPACE], account[SPACE], password[SPACE];
    int success=0;

    printf("Please enter the name: ");
    fgets(name, SPACE, stdin);
    if(name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';

    while(1)
    {
        printf("Please enter the account: ");
        fgets(account, SPACE, stdin);
        if(account[strlen(account) - 1] == '\n')
            account[strlen(account) - 1] = '\0';
        success = set_check_account_ad(administrator[number_ad].ad_name, account); // check whether the account has been registed
        if(success == YES)
            break;
    }

    printf("Please enter the password: ");
    fgets(password, SPACE, stdin);
    if(password[strlen(password) - 1] == '\n')
        password[strlen(password) - 1] = '\0';

    /* Store into database */
    strcpy(administrator[number_ad].ad_name, name);
    strcpy(administrator[number_ad].ad_account, account);
    strcpy(administrator[number_ad].ad_password, password);

    number_ad++;

}
