#include "total.h"


void reader_mode()
{
    int option_re=0; // ???裡�??�???��?��?��????��??�????�?麼�????????
    while(1)
    {
        CLEARSCREAN;
        printf("==================================\n");
        printf("| What would you like to do?     |\n");
        printf("| 1. Search by book name         |\n");
        printf("| 2. Search by author            |\n");
        printf("| 3. Search by publisher         |\n");
        printf("| 4. Search by call number       |\n");
        printf("| 5. Search by ISBN              |\n");
        printf("| 6. Search by viewer count      |\n");
        printf("| 7. Reserve a book              |\n");
        printf("| 8. Show every book             |\n");
        printf("| 9. Sorting                     |\n");
        printf("| 10. Check personal information |\n");
        printf("| 11. Exit                       |\n");
        printf("==================================\n");
        printf("Please enter an option: ");
        scanf("%d", &option_re); // 輸�?��?????�?麼�?????

        fflush(stdin);

        if(option_re == 1)
        {
            search_book_name();
            waiting();
            continue;
        }
        else if(option_re == 2)
        {
            search_author();
            waiting();
            continue;
        }
        else if(option_re == 3)
        {
            search_publisher();
            waiting();
            continue;
        }
        else if(option_re == 4)
        {
            search_call_number();
            waiting();
            continue;
        }
        else if(option_re == 5)
        {
            search_isbn();
            waiting();
            continue;
        }
        else if(option_re == 6)
        {
            search_popular();
            waiting();
            continue;
        }
        else if(option_re == 7)
        {
            reserve_book();
            continue;
        }
        else if(option_re == 8)
        {
            show_book();
            waiting();
            continue;
        }
        else if(option_re == 9)
        {
            int sort=0;
            while(1)
            {
                CLEARSCREAN;
                printf("===================================\n");
                printf("| Which kind of sorting you want? |\n");
                printf("| 1. Publish year                 |\n");
                printf("| 2. Viewer number                |\n");
                printf("| 3. Accession number             |\n");
                printf("| 4. Exit                         |\n");
                printf("===================================\n");
                printf("Enter: ");
                scanf(" %d", &sort);

                fflush(stdin);

                if(sort == 1)
                {
                    sort_publish_year();
                    break;
                }
                else if(sort == 2)
                {
                    sort_viewer_count();
                    break;
                }
                else if(sort == 3)
                {
                    sort_accession_number();
                    break;
                }
                else if(sort == 4)
                    break;
                else
                    continue;
            }
            
        }
        else if(option_re == 10)
        {
            check_personal_information();
            waiting();
            continue;
        }
        else if(option_re == 11)
        {
            break;
        }
        else
            continue;
    }
    

}

void waiting()
{
    char temp[SPACE];
    printf("\n=====================================\n");
    printf("| Enter any key to back to the menu |\n");
    printf("=====================================\n");
    printf("Enter: ");
    scanf("%s", temp);
    fflush(stdin);
}

void lowwer(char string[])
{
    int i=0;
    while(string[i] != '\0')
    {
        string[i] = tolower(string[i]);
        i++;
    }
}

void search_book_name()
{
    char temporary_book_name[SPACE];
    char book_name[SPACE];
    int found=0;
    CLEARSCREAN; // clear screen
    printf("Please enter the name of the book: ");
    fgets(book_name, sizeof(book_name), stdin);
    if(book_name[strlen(book_name) - 1] == '\n')
        book_name[strlen(book_name) - 1] = '\0';
    lowwer(book_name); // to lower case
    CLEARSCREAN; // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_book_name, book[i].book_name);
        lowwer(temporary_book_name); // to lower case
        
        if (strstr(temporary_book_name, book_name) != NULL)
        {
            if(found == 0)
            {
                printf("=============================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("=============================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            if(book[i].status == 0)
            printf("    %s   |\n", "*");
            else
                printf("        |\n");
            printf("=============================================================================================================================================================================================\n");
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("===================================\n");
        printf("| Sorry, There is no book found. |\n");
        printf("===================================\n");
    }
}

void search_popular()
{
    sort_viewer_count(); // here will show the error message. Cause the function is in sort.c
    if(book[0].viewer_count < book[amount_books - 1].viewer_count)
        sort_viewer_count();

    CLEARSCREAN; // clear screen
    printf("=============================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("=============================================================================================================================================================================================\n");

    for (int i = 0; i < amount_books; i++)
    {
        if (book[i].viewer_count > 0)
        {
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
}

void check_personal_information()
{
    struct readers *current;
    current = first;
    CLEARSCREAN; // clear screen
    printf("=========================================================================================================\n");
    printf("| %2s%-12s | %10s | %10s%-15s | %5s%-15s | %5s%-15s |\n", " ","Reader name", "student_id", " ", "email", " ", "re_account", " ", "re_password");
    printf("========================================================================================================= \n");
    while (current != NULL)
    {
        if(strcmp(name_re, current -> re_name) == 0)
        {
            printf("| %-14s | %-10d | %-25s | %-20s | %-20s |\n", current->re_name, current->student_id, current->email,
               current->re_account, current->re_password);
            printf("=========================================================================================================\n");

            printf("\n======================================================\n");
            printf("|                   Borrowing History                |\n");
            printf("======================================================\n");
            struct history *currentNode = queue->front;

            while (currentNode != NULL) 
            {
                if (strcmp(currentNode -> re_name, name_re) == 0) 
                {
                    printf("| %-50s |\n", currentNode -> book_name);
                    printf("======================================================\n");
                }
                currentNode = currentNode->next;
            }
            break;
        }
        current = current->next;
        
    }
}

void search_author()
{
    char temporary_author[SPACE];
    char author[SPACE];
    int found=0;

    CLEARSCREAN; // clear screen
    printf("Please enter the name of the author: ");
    fgets(author, sizeof(author), stdin);
    if(author[strlen(author) - 1] == '\n')
        author[strlen(author) - 1] = '\0';
    lowwer(author); // to lower case

    CLEARSCREAN; // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_author, book[i].author);
        lowwer(temporary_author); // to lower case
        
        if (strstr(temporary_author, author) != NULL)
        {
            if(found == 0)
            {
                printf("=============================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("=============================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            if(book[i].status == 0)
            printf("    %s   |\n", "*");
            else
                printf("        |\n");
            printf("============================================================================================================================================================================================\n");
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("===================================\n");
        printf("| Sorry, There is no book found. |\n");
        printf("===================================\n");
    }
}

void search_publisher()
{
    char temporary_publisher[SPACE];
    int found=0;
    char publisher[SPACE];

    CLEARSCREAN; // clear screen
    printf("Please enter the name of the publisher: ");
    fgets(publisher, sizeof(publisher), stdin);
    if(publisher[strlen(publisher) - 1] == '\n')
        publisher[strlen(publisher) - 1] = '\0';
    lowwer(publisher); // to lower case

    CLEARSCREAN; // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_publisher, book[i].publisher);
        lowwer(temporary_publisher); // to lower case
        
        if (strstr(temporary_publisher, publisher) != NULL)
        {
            if(found == 0)
            {
                printf("=============================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("=============================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            if(book[i].status == 0)
            printf("    %s   |\n", "*");
            else
                printf("        |\n");
            printf("=============================================================================================================================================================================================\n");
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("===================================\n");
        printf("| Sorry, There is no book found. |\n");
        printf("===================================\n");
    }
}

void search_call_number()
{
   char temporary_call_number[SPACE];
    int found=0;
    char call_number[SPACE];

    CLEARSCREAN; // clear screen
    printf("Please enter the call number of the book: ");
    fgets(call_number, sizeof(call_number), stdin);
    if(call_number[strlen(call_number) - 1] == '\n')
        call_number[strlen(call_number) - 1] = '\0';
    lowwer(call_number); // to lower case

    CLEARSCREAN; // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_call_number, book[i].call_number);
        lowwer(temporary_call_number); // to lower case
        
        if (strstr(temporary_call_number, call_number) != NULL)
        {
            if(found == 0)
            {
                printf("=============================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("=============================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            if(book[i].status == 0)
            printf("    %s   |\n", "*");
            else
                printf("        |\n");
            printf("=============================================================================================================================================================================================\n");
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("===================================\n");
        printf("| Sorry, There is no book found. |\n");
        printf("===================================\n");
    }
}

void search_isbn()
{
   char temporary_isbn[SPACE];
    int found=0;
    char isbn[SPACE];

    CLEARSCREAN; // clear screen
    printf("Please enter the isbn of the book: ");
    fgets(isbn, sizeof(isbn), stdin);
    if(isbn[strlen(isbn) - 1] == '\n')
        isbn[strlen(isbn) - 1] = '\0';
    lowwer(isbn); // to lower case

    CLEARSCREAN; // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_isbn, book[i].isbn);
        lowwer(temporary_isbn); // to lower case
        
        if (strstr(temporary_isbn, isbn) != NULL)
        {
            if(found == 0)
            {
                printf("=============================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("=============================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            if(book[i].status == 0)
            printf("    %s   |\n", "*");
            else
                printf("        |\n");
            printf("=====================================================================================================================================================================================\n");
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("===================================\n");
        printf("| Sorry, There is no book found. |\n");
        printf("===================================\n");
    }
}

void show_book()
{
    int num_books = 0;

    CLEARSCREAN; // clear screen
    // show every books
    printf("=============================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s| Status |\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("=============================================================================================================================================================================================\n");
    for (int i = 0; i < amount_books; i++)
    {
        printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|", 
                book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                book[i].isbn, book[i].viewer_count, book[i].accession_number);
        if(book[i].status == 0)
            printf("    %s   |\n", "*");
        else
            printf("        |\n");
        printf("=============================================================================================================================================================================================\n");
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

void reserve_book()
{
   int number_book=0, option_reserve=0;
   CLEARSCREAN; // clear screen
   while(1)
   {
        printf("======================================================================\n");
        printf("| Please enter the accession number of the book you want to reserve. |\n");
        printf("| Enter -1 to go back.                                               |\n");
        printf("======================================================================\n");
        printf("Enter the accession number: ");
        scanf(" %d", &number_book);
   
        if(number_book == -1)
            return;
        else
        {
            int find=0;
            for (int i = 0; i < amount_books; i++)
            {
                if (book[i].accession_number == number_book)
                {
                    find = 1;
                    CLEARSCREAN; // clear screen
                    printf("====================================================================================================================================================================================\n");
                    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                    printf("====================================================================================================================================================================================\n");
                    printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                        book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                        book[i].isbn, book[i].viewer_count, book[i].accession_number);
                    printf("====================================================================================================================================================================================\n");
                    if(book[i].status == 1)
                    {
                        CLEARSCREAN; // clear screen
                        printf("==============================================\n");
                        printf("| Sorry, the book has already been borrowed. |\n");
                        printf("==============================================\n");
                        break;
                    }

                    printf("======================================\n");
                    printf("| Do you want to reserved the book ? |\n");
                    printf("| 1. YES                             |\n");
                    printf("| 2. NO                              |\n");
                    printf("======================================\n");
                    printf("Enter: ");
                    scanf(" %d", &option_reserve); // Use buttom

                    fflush(stdin);

                    if (option_reserve == 1)
                    {
                        book[i].viewer_count++;
                        CLEARSCREAN; // clear screen
                        printf("==========================\n");
                        printf("| Reserved successfully. |\n");
                        printf("==========================\n");
                        book[i].status = 1;
                        if(amount_history == 100)
                        {
                            dequeue(queue);
                        }
                        else
                        {
                            amount_history++;
                        }
                        enqueue(queue, name_re, book[i].book_name);
                        break;
                    }
                    else if (option_reserve == 2)
                    {
                        CLEARSCREAN; // clear screen
                        break;
                    }
                    else if (option_reserve < 1 || option_reserve > 2)
                    {
                        CLEARSCREAN; // clear screen
                        printf("===================\n");
                        printf("| Invalid option! |\n");
                        printf("===================\n");
                        break;
                    }
                }
            }
            if(find == 0)
            {
                CLEARSCREAN; // clear screen
                printf("Sorry, there is no book with accession number %d in the library!\n", number_book);
            }
        }   
   }
}
