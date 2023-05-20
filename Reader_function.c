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
    int option_re; // 這裡的變數是用來選擇要做什麼事情的
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
    scanf("%d", &option_re); // 輸入要做什麼事情
    interface_re(option_re); // 請開始做事情
}

void search_book_name(char book_name[])
{
    int a = 0;
    char temporary_book_name[SPACE][SPACE];
    for (int i = 0; i < SPACE; i++)
    {
        strcpy(temporary_book_name[i], book[i].book_name);
    }
    for (int i = 0; i < SPACE; i++)
    {
        for (int j = 0; j < SPACE; j++)
        {
            if (temporary_book_name[i][j] >= 'A' && temporary_book_name[i][j] <= 'Z')
            {
                temporary_book_name[i][j] += 32;
            }
        }
    }
    for (int i = 0; i < SPACE; i++)
    {
        if (strstr(temporary_book_name[i], book_name) != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
            a = 1; // 有找到書
        }
    }
    if (a == 0)
    { // 沒找到書
        printf("===================================\n");
        printf("| Sorry, There is no books found. |\n");
        printf("===================================\n");
    }
}

void search_viewer_count(void)
{
    int most_viewer_count;
    scanf("%d", &most_viewer_count);
    int most_viewer_count_index;
    scanf("%d", &most_viewer_count_index);
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].viewer_count > most_viewer_count)
        {
            most_viewer_count = book[i].viewer_count;
            most_viewer_count_index = i;
        }
    }
    printf("========================================================================\n");
    printf("| The most viewer count is %d, and the book name is %s! |\n", most_viewer_count, book[most_viewer_count_index].book_name);
    printf("========================================================================\n");
    return;
}

void check_personal_information(void)
{
    struct readers *current;
    current = first;
    while (current != NULL)
    {
        printf("=================================================================================================\n");
        printf("| Reader name | student_id | grade | email | re_account | re_password | borrow_history | credit |\n");
        printf("================================================================================================= \n");
        printf("| %s | %d | %s | %s | %s | %s | %s | %d |", current->re_name, current->student_id, current->grade, current->email,
               current->re_account, current->re_password, current->borrow_history, current->credit);
        current = current->next;
        printf("=================================================================================================\n");
    }
}

void interface_re(int option_re)
{
    if (option_re == BUTTON_BOOK_NAME)
    { // 410是用來判斷是否為搜尋書籍的選項
        printf("Enter book name: ");
        char search[MAX_BUF];
        fflush(stdin);
        while (fgets(search, MAX_BUF, stdin) != NULL)
        { // 預防空格
            if (search[strlen(search) - 1] == '\n')
                search[strlen(search) - 1] = '\0';
            break;
        }

        for (int i = 0; i < MAX_BUF; i++)
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
        char author[MAX_BUF];
        fflush(stdin);
        while (fgets(author, MAX_BUF, stdin) != NULL)
        { // 預防空格
            if (author[strlen(author) - 1] == '\n')
                author[strlen(author) - 1] = '\0';
            break;
        }
        for (int i = 0; i < MAX_BUF; i++)
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
        char publisher[MAX_BUF];
        fflush(stdin);
        while (fgets(publisher, MAX_BUF, stdin) != NULL)
        { // 預防空格
            if (publisher[strlen(publisher) - 1] == '\n')
                publisher[strlen(publisher) - 1] = '\0';
            break;
        }
        for (int i = 0; i < MAX_BUF; i++)
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
        while (fgets(call_number, MAX_BUF, stdin) != NULL)
        { // 預防空格
            if (call_number[strlen(call_number) - 1] == '\n')
                call_number[strlen(call_number) - 1] = '\0';
            break;
        }
        for (int i = 0; i < MAX_BUF; i++)
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
        char isbn[MAX_BUF];
        while (fgets(isbn, MAX_BUF, stdin) != NULL)
        { // 預防空格
            if (isbn[strlen(isbn) - 1] == '\n')
                isbn[strlen(isbn) - 1] = '\0';
            break;
        }
        for (int i = 0; i < MAX_BUF; i++)
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
        printf("Enter viewer count: ");
        fflush(stdin);
        int viewer_count;
        scanf("%d", &viewer_count);
        search_viewer_count();
    }
    if (option_re == BUTTON_RESERVE)
    {
        printf("Enter book name: ");
        fflush(stdin);
        char book_name_reserve[MAX_BUF];
        while (fgets(book_name_reserve, MAX_BUF, stdin) != NULL)
        { // 預防空格
            if (book_name_reserve[strlen(book_name_reserve) - 1] == '\n')
                book_name_reserve[strlen(book_name_reserve) - 1] = '\0';
            break;
        }
        for (int i = 0; i < MAX_BUF; i++)
        {
            if (book_name_reserve[i] >= 'A' && book_name_reserve[i] <= 'Z')
            {
                book_name_reserve[i] = book_name_reserve[i] + 32;
            }
        }
        int option_reserve;
        printf("Enter 1 to reserve book, 2 to cancel reservation: ");
        scanf("%d", &option_reserve);
        reserve_book(book_name_reserve, option_reserve);
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
    char temporary_author[SPACE][SPACE];
    for (int i = 0; i < SPACE; i++)
    {
        strcpy(temporary_author[i], book[i].author);
    }
    for (int i = 0; i < SPACE; i++)
    {
        for (int j = 0; j < SPACE; j++)
        {
            if (temporary_author[i][j] >= 'A' && temporary_author[i][j] <= 'Z')
            {
                temporary_author[i][j] += 32;
            }
        }
    }
    int error = 0;
    // search for books with matching authors

    for (int i = 0; i < SPACE; i++)
    {
        if (strstr(temporary_author[i], author) != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
            error = 1;
        }
    }
    // print message if no matches found
    if (error == 0)
    {
        printf("============================\n");
        printf("| No matching books found. |\n");
        printf("============================\n");
    }
}

void search_publisher(char publisher[])
{
    char temporary_publisher[SPACE][SPACE];
    for (int i = 0; i < SPACE; i++)
    {
        strcpy(temporary_publisher[i], book[i].publisher);
    }
    for (int i = 0; i < SPACE; i++)
    {
        for (int j = 0; j < SPACE; j++)
        {
            if (temporary_publisher[i][j] >= 'A' && temporary_publisher[i][j] <= 'Z')
            {
                temporary_publisher[i][j] += 32;
            }
        }
    }
    int error = 0;
    // count the number of books that match the search criteria
    for (int i = 0; i < SPACE; i++)
    {
        if (strstr(temporary_publisher[i], publisher) != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
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

void search_call_number(char call_number[])
{
    char temporary_call[SPACE][SPACE];
    for (int i = 0; i < SPACE; i++)
    {
        strcpy(temporary_call[i], book[i].call_number);
    }
    for (int i = 0; i < SPACE; i++)
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
    for (int i = 0; i < SPACE; i++)
    {
        if (strstr(temporary_call[i], call_number) != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("|%s|%s|%s|%d|%d|%s|%s|%d|%d|\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
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
    char temporary_isbn[SPACE][SPACE];
    for (int i = 0; i < SPACE; i++)
    {
        strcpy(temporary_isbn[i], book[i].isbn);
    }
    for (int i = 0; i < SPACE; i++)
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
    for (int i = 0; i < SPACE; i++)
    {
        if (strstr(temporary_isbn[i], isbn) != NULL)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
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
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (strlen(book[i].book_name) > 0)
        {
            printf("=================================================================================================================\n");
            printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
            printf("=================================================================================================================\n");
            printf("| %s | %s | %s | %d | %d | %s | %s | %d | %d |\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
            printf("=================================================================================================================\n");
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

void reserve_book(char number_book[], int option_reserve)
{
    char temporary_number_book[SPACE][SPACE];
    for (int i = 0; i < SPACE; i++)
    {
        strcpy(temporary_number_book[i], number_book);
    }
    // reserve book 1:要做 2:不要做
    //  search for the book to be reserved
    for (int i = 0; i < SPACE; i++)
    {
        if (option_reserve == 1)
        {
            if (book[i].amount > 0)
            {
                book[i].amount--;
                printf("==================================================================\n");
                printf("| Book  %s  reserved successfully. |\n", book[i].book_name);
                printf("==================================================================\n");
            }
            else
            {
                printf("===========================================================================\n");
                printf("| Error: Book %s is currently unavailable. |\n", book[i].book_name);
                printf("===========================================================================\n");
            }
        }
        else if (option_reserve == 2)
        {
            book[i].amount++;
            printf("===================================================================\n");
            printf("| Book %s unreserved successfully. |\n", book[i].book_name);
            printf("===================================================================\n");
        }
        else if (option_reserve > 2 || option_reserve < 1)
        {
            printf("=================================\n");
            printf("| Your option is not available. |\n");
            printf("=================================\n");
        }
        else
        {
            printf("=====================================\n");
            printf("| Error: Book %s not found. |\n", temporary_number_book[i]);
            printf("=====================================\n");
        }
    }
}
