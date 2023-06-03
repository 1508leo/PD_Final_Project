/*
=========================================================
| TODO: Ensuring without "ANY" bugs  and errors appear. |
=========================================================
-----------------------------------------------
| WISHING Due date: 5.28.2023 Sunday (Myself) |
-----------------------------------------------
*/
#include "total.h"

void reader_mode()
{
    int option_re; // ???裡�??�???��?��?��????��??�????�?麼�????????
    printf("=============================\n");
    printf("| What would you like to do?|\n");
    printf("| 1. Search by book name    |\n");
    printf("| 2. Search by author       |\n");
    printf("| 3. Search by publisher    |\n");
    printf("| 4. Search by call number  |\n");
    printf("| 5. Search by ISBN         |\n");
    printf("| 6. Search by viewer count |\n");
    printf("| 7. Reserve a book         |\n");
    printf("| 8. Show all books         |\n");
    printf("| 9. Exit                   |\n");
    printf("=============================\n");
    printf("Please enter an option: ");
    scanf("%d", &option_re); // 輸�?��?????�?麼�?????
    interface_re(option_re); // �????�????�????
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

void search_book_name(char book_name[])
{
    char temporary_book_name[SPACE];
    int found=0;
    lowwer(book_name); // to lower case
    printf("\033[H\033[2J"); // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_book_name, book[i].book_name);
        lowwer(temporary_book_name); // to lower case
        
        if (strstr(temporary_book_name, book_name) != NULL)
        {
            if(found == 0)
            {
                printf("====================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("====================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
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

void search_popular(void)
{
    sort_viewer_number(); // here will show the error message. Cause the function is in sort.c
    if(book[0].viewer_count < book[amount_books - 1].viewer_count)
        sort_viewer_number();

    printf("\033[H\033[2J"); // clear screen
    printf("====================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("====================================================================================================================================================================================\n");

    for (int i = 0; i < amount_books; i++)
    {
        if (book[i].viewer_count > 0)
        {
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
        }
    }
}

void check_personal_information(void)
{
    struct readers *current;
    current = first;
    printf("=================================================================================================\n");
    printf("| Reader name | student_id | grade | email | re_account | re_password | borrow_history | credit |\n");
    printf("================================================================================================= \n");
    while (current != NULL)
    {
        if(strcmp(name_re, current -> re_name) == 0)
        {
            printf("| %s | %d | %s | %s | %s | %s | %s | %d |", current->re_name, current->student_id, current->grade, current->email,
               current->re_account, current->re_password, current->borrow_history, current->credit);
            printf("=================================================================================================\n");
            break;
        }
        current = current->next;
        
    }
}

void interface_re(int option_re)
{
    if (option_re == BUTTON_BOOK_NAME)
    { // 410??��?��????��?��?��?��?��??�???��???????��??
        printf("Enter book name: ");
        char search[SPACE];
        fflush(stdin);
        while (fgets(search, SPACE, stdin) != NULL)
        { // ?????�空???
            if (search[strlen(search) - 1] == '\n')
                search[strlen(search) - 1] = '\0';
            break;
        }

        for (int i = 0; i < SPACE; i++)
        {
            if (search[i] >= 'A' && search[i] <= 'Z')
            {
                search[i] = search[i] + 32;
            }
        }
        search_book_name(search);
    }
    if (option_re == BUTTON_AUTHOR)
    {
        printf("Enter author: ");
        char author[SPACE];
        fflush(stdin);
        while (fgets(author, SPACE, stdin) != NULL)
        { // ?????�空???
            if (author[strlen(author) - 1] == '\n')
                author[strlen(author) - 1] = '\0';
            break;
        }
        for (int i = 0; i < SPACE; i++)
        {
            if (author[i] >= 'A' && author[i] <= 'Z')
            {
                author[i] = author[i] + 32;
            }
        }
        search_author(author);
    }
    if (option_re == BUTTON_PUBLISHER)
    {
        printf("Enter publisher: ");
        char publisher[SPACE];
        fflush(stdin);
        while (fgets(publisher, SPACE, stdin) != NULL)
        { // ?????�空???
            if (publisher[strlen(publisher) - 1] == '\n')
                publisher[strlen(publisher) - 1] = '\0';
            break;
        }
        for (int i = 0; i < SPACE; i++)
        {
            if (publisher[i] >= 'A' && publisher[i] <= 'Z')
            {
                publisher[i] = publisher[i] + 32;
            }
        }
        search_publisher(publisher);
    }
    if (option_re == BUTTON_CALL_NUMBER)
    {
        printf("Enter call number: ");
        char call_number[SPACE];
        fflush(stdin);
        while (fgets(call_number, SPACE, stdin) != NULL)
        { // ?????�空???
            if (call_number[strlen(call_number) - 1] == '\n')
                call_number[strlen(call_number) - 1] = '\0';
            break;
        }
        for (int i = 0; i < SPACE; i++)
        {
            if (call_number[i] >= 'A' && call_number[i] <= 'Z')
            {
                call_number[i] = call_number[i] + 32;
            }
        }
        search_call_number(call_number);
    }
    if (option_re == BUTTON_ISBN)
    {
        printf("Enter ISBN: ");
        fflush(stdin);
        char isbn[SPACE];
        while (fgets(isbn, SPACE, stdin) != NULL)
        { // ?????�空???
            if (isbn[strlen(isbn) - 1] == '\n')
                isbn[strlen(isbn) - 1] = '\0';
            break;
        }
        for (int i = 0; i < SPACE; i++)
        {
            if (isbn[i] >= 'A' && isbn[i] <= 'Z')
            {
                isbn[i] = isbn[i] + 32;
            }
        }
        search_isbn(isbn);
    }
    if (option_re == BUTTON_POPULAR)
    {
        search_popular();
    }
    if (option_re == BUTTON_RESERVE)
    {
        show_book();
        fflush(stdin);
        int number;
        printf("Enter the accession number of the book you want to reserve: ");
        scanf("%d", &number);
        int option_reserve;
        printf("Enter 1 to reserve book, 2 to cancel reservation: ");
        scanf("%d", &option_reserve);
        reserve_book(&number, option_reserve);
    }
    if (option_re == BUTTON_EXIT)
    {
        printf("  ==============  \n");
        printf("  | Exiting... |  \n");
        printf("  ==============  \n");
        exit(0);
    }
    if (option_re != BUTTON_BOOK_NAME && option_re != BUTTON_AUTHOR && option_re != BUTTON_PUBLISHER && option_re != BUTTON_CALL_NUMBER && option_re != BUTTON_ISBN && option_re != BUTTON_POPULAR && option_re != BUTTON_RESERVE && option_re != BUTTON_EXIT)
    {
        printf("Invalid option.\n");
    }
    reader_mode();
}

void search_author(char author[])
{
    char temporary_author[SPACE];
    int found=0;
    lowwer(author); // to lower case

    printf("\033[H\033[2J"); // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_author, book[i].author);
        lowwer(temporary_author);
        
        if (strstr(temporary_author, author) != NULL)
        {
            if(found == 0)
            {
                printf("====================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("====================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
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

void search_publisher(char publisher[])
{
    char temporary_publisher[SPACE];
    int found=0;
    lowwer(publisher); // to lower case

    printf("\033[H\033[2J"); // clear screen
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_publisher, book[i].publisher);
        lowwer(temporary_publisher); // to lower case
        
        if (strstr(temporary_publisher, publisher) != NULL)
        {
            if(found == 0)
            {
                printf("====================================================================================================================================================================================\n");
                printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
                printf("====================================================================================================================================================================================\n");
            }
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
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

void search_call_number(char call_number[])
{
    char temporary_call[amount_books][SPACE];
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_call[i], book[i].call_number);
    }
    for (int i = 0; i < amount_books; i++)
    {
        for (int j = 0; j < SPACE; j++)
        {
            if (temporary_call[i][j] >= 'A' && temporary_call[i][j] <= 'Z')
            {
                temporary_call[i][j] += 32;
            }
        }
    }
    int num_books = 0;
    // count the number of books that match the search criteria
    printf("====================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("====================================================================================================================================================================================\n");
    for (int i = 0; i < amount_books; i++)
    {
        if (strstr(temporary_call[i], call_number) != NULL)
        {
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
            num_books = 1;
        }
    }
    // check if any books were found
    if (num_books == 0)
    {
        printf("============================\n");
        printf("|      No books found.     |\n");
        printf("============================\n");
    }
}

void search_isbn(char isbn[])
{
    char temporary_isbn[amount_books][SPACE];
    for (int i = 0; i < amount_books; i++)
    {
        strcpy(temporary_isbn[i], book[i].isbn);
    }
    for (int i = 0; i < amount_books; i++)
    {
        for (int j = 0; j < SPACE; j++)
        {
            if (temporary_isbn[i][j] >= 'A' && temporary_isbn[i][j] <= 'Z')
            {
                temporary_isbn[i][j] += 32;
            }
        }
    }
    int error = 0;
    // count the number of books that match the search criteria
    printf("====================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("====================================================================================================================================================================================\n");
    for (int i = 0; i < amount_books; i++)
    {
        if (strstr(temporary_isbn[i], isbn) != NULL){
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
            error = 1;
        }
    }
    // check if any books were found
    if (error == 0)
    {
        printf("============================\n");
        printf("|      No books found.     |\n");
        printf("============================\n");
    }
}

void show_book()
{
    int num_books = 0;

    // count the number of books
    for (int i = 0; i < amount_books; i++)
    {
        if (strlen(book[i].book_name) > 0)
        {
            printf("====================================================================================================================================================================================\n");
    printf("| %20s%-30s| %6s%-14s| %5s%-15s| %-13s| %2s%-13s| %4s%-10s| %-14s| %-17s|\n", " ", "Book name", " ", "Author", " ", "Publisher", "Publish year", " ", "Call number", " ", "ISBN", "Viewer amount", "Accession number");
    printf("====================================================================================================================================================================================\n");
            printf("| %-50s| %-20s| %-20s| %-13d| %-15s| %-14s| %-14.0f| %-17d|\n", 
                    book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].call_number,
                    book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("====================================================================================================================================================================================\n");
            num_books = 1;
        }
    }

    // check if any books were found
    if (num_books == 0)
    {
        printf("============================\n");
        printf("|      No books found.     |\n");
        printf("============================\n");
    }
}

void reserve_book(int *number_book, int option_reserve)
{
   for (int i = 0; i < amount_books; i++)
    {
        if (book[i].accession_number == *number_book)
        {
            if (option_reserve == 1)
            {
                if (book[i].amount == 0)
                {
                    book[i].viewer_count++;
                    printf("==================================================================\n");
                    printf("| Book  %s  reserved successfully. |\n", book[i].book_name);
                    printf("==================================================================\n");
                    book[i].amount = 1;
                }
                else
                {
                    printf("==================================================================\n");
                    printf("| Book  %s  is already reserved. |\n", book[i].book_name);
                    printf("==================================================================\n");
                }
            }
            else if (option_reserve == 2)
            {
                if (book[i].amount == 1)
                {
                    printf("==================================================================\n");
                    printf("| Book  %s  returned successfully. |\n", book[i].book_name);
                    printf("==================================================================\n");
                    book[i].amount = 0;
                }
                else
                {
                    printf("==================================================================\n");
                    printf("| Book  %s  is already returned. |\n", book[i].book_name);
                    printf("==================================================================\n");
                }
            }
        }
    }
    if (option_reserve < 1 || option_reserve > 2)
    {
        printf("===================\n");
        printf("| Invalid option! |\n");
        printf("===================\n");
    }
    if (*number_book < 1 || *number_book > 100)
    {
        printf("===================\n");
        printf("| Invalid option! |\n");
        printf("===================\n");
    }
}
