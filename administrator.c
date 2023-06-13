#include "total.h"

int number_ad = 4; //trace the amount of administrator initialize 4 administrator
int amount_books = 0; // trace the amount of books
int accession_numer = 1; //record accession_number
int amount_re = 0; // trace the amount of reader
int amount_history = 0;


void administrator_mode()
{
    int option_ad=0; //
    while(1)
    {
        CLEARSCREAN;
        printf("=======================================\n");
        printf("| What would you like to do?          |\n");
        printf("| 1. Browse the library               |\n");
        printf("| 2. Add book or delete book          |\n");
        printf("| 3. Check borrowing                  |\n");
        printf("| 4. Check reader information         |\n");
        printf("| 5. Modify reader information        |\n");
        printf("| 6. Check administrator information  |\n");
        printf("| 7. Modify administrator information |\n");
        printf("| 8. Lend book                        |\n");
        printf("| 9. Return book                      |\n");
        printf("| 10. Add administrator               |\n");
        printf("| 11. Exit                            |\n");
        printf("=======================================\n");
        printf("Please enter an option: ");
        scanf("%d", &option_ad); // 輸入要做什麼事情

        fflush(stdin);

        if(option_ad == 1)
        {
            review_library();
            waiting();
            continue;
        }
        else if(option_ad == 2)
        {
            int ad_de=0;
            CLEARSCREAN;
            printf("========================================\n");
            printf("| Please decide to add or delete book. |\n");
            printf("| 1. Add book                          |\n");
            printf("| 2. Delete book                       |\n");
            printf("| 3. Exit                              |\n");
            printf("========================================\n");
            printf("Enter: ");
            scanf(" %d", &ad_de);

            fflush(stdin);

            if(ad_de == 1)
            {
                add_book();
                continue;
            }
            else if(ad_de == 2)
            {
                delete_book();
                continue;
            }
            else if(ad_de == 3)
            {
                break;
            }
            else
                continue;
        }
        else if(option_ad == 3)
        {
            check_borrowing();
            waiting();
            continue;
        }
        else if(option_ad == 4)
        {
            check_re_information();
            waiting();
            continue;
        }
        else if(option_ad == 5)
        {
            modify_re_information();
            sleep(1);
            continue;
        }
        else if(option_ad == 6)
        {
            check_ad_information();
            waiting();
            continue;
        }
        else if(option_ad == 7)
        {
            modify_ad_information();
            sleep(1);
            continue;
        }
        else if(option_ad == 8)
        {
            lend_book();
            sleep(1);
            continue;
        }
        else if(option_ad == 9)
        {
            return_book();
            continue;
        }
        else if(option_ad == 10)
        {
            add_administrator();
            sleep(1);
            continue;
        }
        else if(option_ad == 11)
        {
            break;
        }
        else
            continue;
        
    }
    
}

void review_library() // print every book
{
    int num_books = 0;

    CLEARSCREAN; // clear screen
    // show every books
    printf("============================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("============================================================================================================================================================================================\n");
    for (int i = 0; i < amount_books; i++)
    {
        printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                book[i].isbn, book[i].viewer_count, book[i].accession_number);
        if(book[i].status == 0)
            printf("    %s   |\n", "*");
        else
            printf("        |\n");
        printf("============================================================================================================================================================================================\n");
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

void add_book()
{
    char book_name[SPACE], author[SPACE], publisher[SPACE], call_number[SPACE], isbn[SPACE];
    if (amount_books == MAX_BUF)
    { // The capacity of the library is full
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    CLEARSCREAN; // clear screen
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

    CLEARSCREAN;
    printf("==================================\n");
    printf("| The book addition is complete. |\n");
    printf("==================================\n");
    sleep(2);

    accession_numer++;
    amount_books++;
}

void delete_book( )//show every book first(use search_book_name()). To make sure whether the book you want to delete
{
    
    while(1)
    {
        int delete_number=0, find=0;
        review_library(); // print every book first
        printf("================================================================\n");
        printf("| Please enter the accession number of book you want to delete |\n");
        printf("| Enter -1 to back to menu                                     |\n");
        printf("================================================================\n");
        printf("Enter: ");
        scanf(" %d", &delete_number);

        if(delete_number == -1)
        {
            break;
        }
        else
        {
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
                            CLEARSCREAN; // clear screen
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
                            CLEARSCREAN;
                            printf("The deletion of book is complete.\n");
                            amount_books--;
                            sleep(2);
                            break;
                        }
                        else // confirm = 2
                            break;
                    }
                    break;
                    
                }
            }

            if(find == 0)
            {
                CLEARSCREAN;
                printf("There is no book with accession number %d in the library.\n", delete_number);
                sleep(2);
            }
                
            }
        }
        
        

    return;
}

void check_borrowing() // print every book which is borrowed
{
    int find=0;
    CLEARSCREAN; // clear screen
    
    for (int i = 0; i < amount_books; i++)
    {
        if (book[i].status != 0)
        {
            if(find == 0)
            {
                printf("=============================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("=============================================================================================================================================================================================\n");
            }
            find = 1;
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            if(book[i].status == 0)
                printf("    %s   |\n", "*");
            else
                printf("        |\n");
            printf("=============================================================================================================================================================================================\n");
        }
    }

    if(find == 0)
    {
        CLEARSCREAN;
        printf("==============================================\n");
        printf("| Every book in the library is not borrowed. |\n");
        printf("==============================================\n");
    }
        
}

void return_book()
{
    while(1)
    {
        check_borrowing(); // show the borrowing books
        printf("\n==================================================\n");
        printf("| Which book do you want to return?              |\n");
        printf("| Please enter the accession number of the book. |\n");
        printf("| Enter -1 to back to menu.                      |\n");
        printf("==================================================\n");
        printf("Enter: ");
        int return_book=0, find=0;
        scanf("%d",&return_book);
        if(return_book == -1)
        {
            break;
        }
        else
        {
            for(int i = 0; i < amount_books; i++)
            {
                if (book[i].accession_number == return_book)
                {
                    find = 1;
                    if(book[i].status == 0)
                    {
                        CLEARSCREAN;
                        printf("===============================\n");
                        printf("| The book is in the library. |\n");
                        printf("===============================\n");
                        sleep(2);
                        continue;
                    }
                    else // status = 1
                    {
                        CLEARSCREAN;
                        printf("Return %s successfully.\n", book[i].book_name);
                        book[i].status = 0;
                        sleep(2);
                        continue;
                    }
                }
            }

            if(find == 0)
            {
                CLEARSCREAN;
                printf("There is no book with the accession number %d in the library.\n", return_book);
                sleep(2);
            }
                
        }
        
    }
    
} 


void check_re_information()
{
    CLEARSCREAN; // clear screen
    struct readers *current = first;

    printf("===============================================================================================================\n");
    printf("| %5s%-15s | %10s | %10s%-15s | %5s%-15s | %5s%-15s |\n", " ","Reader Name", "Student_id", " ", "Email", " ", "Re_account", " ", "Re_password");
    printf("=============================================================================================================== \n");

    while(current != NULL){
        printf("| %-20s | %-10d | %-25s | %-20s | %-20s |\n", current->re_name, current->student_id, current->email,
               current->re_account, current->re_password);
        printf("===============================================================================================================\n");

        current = current->next;
    }
}

void modify_re_information() // Modify or delete reader information
{
    struct readers *current = first;
    struct readers *prev = NULL;
    check_re_information();
    printf("Please enter the name of the reader which you want to modify: ");


    char temp_reader_name[30];
    fgets(temp_reader_name,  sizeof(temp_reader_name), stdin); // The reader name that is going to be modified
    if(temp_reader_name[strlen(temp_reader_name) - 1] == '\n')
        temp_reader_name[strlen(temp_reader_name) - 1] = '\0';

    int oper = 0; // Represent whether the name is exist
    while (current != NULL)
    {
        if (strcmp(current->re_name, temp_reader_name) == 0) // reader_name exist
        {
            oper = 1; // Find the reader
            jmp_buf	rebuffer;
            int error=0;
            error = setjmp(rebuffer);
            if(error == 1) // If user enter wrong option
            {
                CLEARSCREAN; // clear screan
                printf("Wrong operation!\n\n");
            }

            printf("================================\n");
            printf("| What do you prefer to do?    |\n");
            printf("| 1. Modify reader information |\n");
            printf("| 2. Delete reader             |\n");
            printf("| 3. Exit                      |\n");
            printf("================================\n");
            printf("Please enter your option: ");

            int operation=0; // Decide operation
            scanf("%d",&operation);
            fflush(stdin);
            if(operation == 1) // Modify reader information
            {
                
                char name[SPACE], email[SPACE], account[SPACE], password[SPACE];
                int id=0;
                CLEARSCREAN; // clear screan
                printf("============================================\n");
                printf("| Enter the new information for the reader |\n");
                printf("============================================\n\n");

                fflush(stdin);

                printf("Old name: %s\n", current -> re_name);
                printf("Please enter the new reader name: ");
                fgets(name,  sizeof(name), stdin);
                if(name[strlen(name) - 1] == '\n')
                    name[strlen(name) - 1] = '\0';

                printf("\nOld student id: %d\n", current -> student_id);
                printf("Please enter the new student id: ");
                scanf(" %d", &id);

                fflush(stdin);
                
                int success=0;
                while(1)
                {
                    printf("\nOld account: %s\n", current -> re_account);
                    printf("Please enter the new reader account: ");
                    fgets(account,  sizeof(account), stdin);
                    if(account[strlen(account) - 1] == '\n')
                        account[strlen(account) - 1] = '\0';

                    success = set_check_account_re(name, id, email, account);

                    if(success == YES)
                        break;
                }
                

                printf("\nOld password: %s\n", current -> re_password);
                printf("Please enter reader password: ");
                fgets(password,  sizeof(password), stdin);
                if(password[strlen(password) - 1] == '\n')
                    password[strlen(password) - 1] = '\0';

                strcpy(current -> re_name, name);
                current -> student_id = id;
                //strcpy(current -> email, email);
                strcpy(current -> re_account, account);
                strcpy(current -> re_password, password);

                CLEARSCREAN; // clear screan
                printf("======================\n");
                printf("| Update successful! |\n");
                printf("======================\n");

                break;
            }
            else if(operation == 2) // Delete reader
            {
                if (prev == NULL)  // Remove the first reader
                    first = current->next;
                else 
                    prev->next = current->next; // Remove the reader that is not the first
                free(current);

                CLEARSCREAN; // clear screan
                printf("========================\n");
                printf("| Deletion successful! |\n");
                printf("========================\n");
                amount_re--;
                break;
            }
            else if(operation == 3)
            {
                break;
            }
            else // error option
            {
                longjmp(rebuffer, 1); // jump to the error message
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    if (oper == 0)  
    {
        CLEARSCREAN; // clear screan
        printf("===================\n");
        printf("| No such reader! |\n"); //Can't find the reader
        printf("===================\n");
    }
        
}

void check_ad_information()
{
    CLEARSCREAN; // clear screen
    printf("======================================================================\n");
    printf("| %1s%-19s | %5s%-15s | %5s%-15s |\n", " ", "Administrator Name", " ", "ad_account", " ", "ad_password");
    printf("======================================================================\n");
    for (int i = 0; i < number_ad; i++)
    {
        printf("| %-20s | %-20s | %-20s |\n", administrator[i].ad_name, administrator[i].ad_account, administrator[i].ad_password);
        printf("======================================================================\n");
    }
}

void modify_ad_information()
{ 
    check_ad_information();
    char temp_ad_name[30];
    printf("Please enter the administrator name which you want to modify: ");
    fgets(temp_ad_name,  sizeof(temp_ad_name), stdin); // The reader name that is going to be modified
    if(temp_ad_name[strlen(temp_ad_name) - 1] == '\n')
        temp_ad_name[strlen(temp_ad_name) - 1] = '\0';

    int oper = 0; // Represent whether tje name is exist
    for(int i = 0; i < number_ad; i++)
    {
        if(strcmp(administrator[i].ad_name, temp_ad_name) == 0) // Find administrator
        {
            oper = 1;
            jmp_buf	adbuffer;
            int error=0;
            error = setjmp(adbuffer);
            if(error == 1) // If user enter wrong option
            {
                CLEARSCREAN; // clear screan
                printf("Wrong operation!\n\n");
            }

            printf("=======================================\n");
            printf("| What do you prefer to do?           |\n");
            printf("| 1. Modify administrator information |\n");
            printf("| 2. Delete administrator             |\n");
            printf("| 3. Exit                             |\n");
            printf("=======================================\n");
            printf("Please enter your option: ");

            int operation=0; // Decide operation
            scanf("%d",&operation);

            if(operation == 1)
            {
                char name[SPACE], account[SPACE], password[SPACE];
                CLEARSCREAN; // clear screan
                printf("===================================================\n");
                printf("| Enter the new information for the administrator |\n");
                printf("===================================================\n\n");

                fflush(stdin);

                printf("Old name: %s\n", administrator[i].ad_name);
                printf("Please enter the new administrator name: ");
                fgets(name,  sizeof(name), stdin);
                if(name[strlen(name) - 1] == '\n')
                    name[strlen(name) - 1] = '\0';

                printf("\nOld account: %s\n", administrator[i].ad_account);
                printf("Please enter the new administrator account: ");
                fgets(account,  sizeof(account), stdin);
                if(account[strlen(account) - 1] == '\n')
                    account[strlen(account) - 1] = '\0';

                printf("\nOld password: %s\n", administrator[i].ad_password);
                printf("Please enter administrator password: ");
                fgets(password,  sizeof(password), stdin);
                if(password[strlen(password) - 1] == '\n')
                    password[strlen(password) - 1] = '\0';

                strcpy(administrator[i].ad_name, name);
                strcpy(administrator[i].ad_account, account);
                strcpy(administrator[i].ad_password, password);

                CLEARSCREAN; // clear screan
                printf("======================\n");
                printf("| Update successful! |\n");
                printf("======================\n");

                break;
            }
            else if(operation == 2) // Delete reader
            {
                for(int j = i; j < number_ad; j++)
                {
                    administrator[j] = administrator[j + 1];
                }

                number_ad--;
                CLEARSCREAN; // clear screan
                printf("========================\n");
                printf("| Deletion successful! |\n");
                printf("========================\n");
                break;
            }
            else if(operation == 3)
            {
                break;
            }
            else
            {
                longjmp(adbuffer, 1); // jump to the error message
            }
        }
    }
    if (oper == 0)  
    {
        CLEARSCREAN; // clear screen
        printf("==========================\n");
        printf("| No such administrator! |\n"); //Can't find the administrator
        printf("==========================\n");
    }
        
}

void lend_book()
{
    review_library();
    printf("\n===================================================================\n");
    printf("| Please enter the accession number of the book you want to lend. |\n");
    printf("| Enter -1 to go back.                                            |\n");
    printf("===================================================================\n");
    printf("Enter the accession number: ");
    int number_book=0; // the accession number of the book you want lend
    scanf(" %d",&number_book);
    if(number_book == -1)
        return;
    else
    {
        for(int i = 0; i < amount_books; i++)
    {
        if (book[i].accession_number == number_book)
        {
            fflush(stdin);
            
            jmp_buf	lendbuffer;
            char reader_name[SPACE];
            int error=0;
            error = setjmp(lendbuffer);
            if(error == 1)
            {
                CLEARSCREAN; // clear screan
                printf("The reader doesn't exist!\n");
            }

            printf("Please enter the borrower name: ");
            fgets(reader_name, sizeof(reader_name), stdin);
            if(reader_name[strlen(reader_name) - 1] == '\n')
                reader_name[strlen(reader_name) - 1] = '\0';

            struct readers *current;
            current = first;
            while(current != NULL) // find whether the reader is exist
            {
                if(strcmp(current -> re_name, reader_name) == 0)
                    break;
                else
                    current = current -> next;
            }
            if(current == NULL)
            {
                longjmp(lendbuffer, 1); // jump to the error message
            }
            if(book[i].status == 0)
            {
                book[i].status = 1;
                CLEARSCREAN; // clear screan
                printf("Lend %s successfully.\n", book[i].book_name);
                book[i].viewer_count++; // viewer plus 1
                if(amount_history == 100)
                {
                    dequeue(queue);
                }
                else
                {
                    amount_history++;
                }
                enqueue(queue, reader_name, book[i].book_name);
                sleep(2);
                return;
            }
            else if(book[i].status == 1)
            {
                CLEARSCREAN; // clear screen
                printf("The book has been borrowed!\n");
                return;
            }
        }
    }
        // Doesn't find the book in library
        printf("The book with %d accession number doesn't exist.\n", number_book);
    }
    
}

/* Add new administrator */
void add_administrator()
{
    char name[SPACE], account[SPACE], password[SPACE];
    int success=0;

    CLEARSCREAN; // clear screan
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

    printf("\nThe book addition is complete.\n");

    number_ad++;

}
