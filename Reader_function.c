#include "fp_headerfile.h"

void reader_mode()
{
    int option_re; // 這裡的變數是用來選擇要做什麼事情的
    printf("===========================");
    printf("|What would you like to do?|\n");
    printf("|1. Search by book name    |\n");
    printf("|2. Search by author       |\n");
    printf("|3. Search by publisher    |\n");
    printf("|4. Search by call number  |\n");
    printf("|5. Search by ISBN         |\n");
    printf("|6. Search by viewer count |\n");
    printf("|7. Reserve a book         |\n");
    printf("|8. Show all books         |\n");
    printf("|9. Exit                   |\n");
    printf("===========================");
    printf("Please enter an option: ");
    scanf("%d", &option_re); // 輸入要做什麼事情
    interface_re(option_re); // 請開始做事情
}

void search_book_name(char book_name[])
{
    int count = 0;
    int results[MAX_BUF]; // array to store matching book indices

    // search for matching books
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL)
        {
            if (strstr(book[i].book_name, book_name) != NULL)
            {
                // book name contains the search term
                results[count] = i;
                count++;
            }
        }
    }

    // display search results
    if (count > 0)
    {
        printf("%d books found:\n", count);
        printf("=================================================================================================================\n");
        printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
        printf("=================================================================================================================\n");
        for (int j = 0; j < count; j++)
        {
            printf("%s|%s|%s|%d|%d|%.2f|%s|%d|%d|\n", book[results[j]].book_name, book[results[j]].author,
                   book[results[j]].publisher, book[results[j]].publish_year, book[results[j]].amount,
                   book[results[j]].call_number, book[results[j]].isbn, book[results[j]].viewer_count, book[results[j]].accession_number);
        }
    }
    else
    {
        printf("===================================\n");
        printf("| Sorry, There is no books found. |\n");
        printf("===================================\n");
    }
}

void search_viewer_count(void)
{
    return;
}

void interface_re(int option_re)
{
    if (option_re == BUTTON_BOOK_NAME)
    { // 410是用來判斷是否為搜尋書籍的選項
        printf("Enter book name: ");
        char book_name[MAX_BUF];
        while (fgets(book_name, MAX_BUF, stdin) != NULL)
        { // 預防空格
            int len = strlen(book_name);
            if (*(book_name + len - 1) == '\n')
            {
                *(book_name + len - 1) = '\0';
            }
            break;
        }
        search_book_name(book_name);
    }
    if (option_re == BUTTON_AUTHOR)
    {
        printf("Enter author: ");
        char author[MAX_BUF];
        while (fgets(author, MAX_BUF, stdin) != NULL)
        { // 預防空格
            int len = strlen(author);
            if (*(author + len - 1) == '\n')
            {
                *(author + len - 1) = '\0';
            }
            break;
        }
        search_author(author);
    }
    if (option_re == BUTTON_PUBLISHER)
    {
        printf("Enter publisher: ");
        char publisher[MAX_BUF];
        while (fgets(publisher, MAX_BUF, stdin) != NULL)
        { // 預防空格
            int len = strlen(publisher);
            if (*(publisher + len - 1) == '\n')
            {
                *(publisher + len - 1) = '\0';
            }
            break;
        }
        search_publisher(publisher);
    }
    if (option_re == BUTTON_CALL_NUMBER)
    {
        printf("Enter call number: ");
        float call_number;
        scanf("%f", &call_number);
        search_call_number(&call_number);
    }
    if (option_re == BUTTON_ISBN)
    {
        printf("Enter ISBN: ");
        char isbn[MAX_BUF];
        scanf("%s", isbn);
        search_isbn(isbn);
    }
    if (option_re == BUTTON_POPULAR)
    {
        printf("Enter viewer count: ");
        int viewer_count;
        scanf("%d", &viewer_count);
        search_viewer_count();
    }
    if (option_re == BUTTON_RESERVE)
    {
        printf("Enter book name: ");
        char book_name_reserve[MAX_BUF];
        while (fgets(book_name_reserve, MAX_BUF, stdin) != NULL)
        { // 預防空格
            int len = strlen(book_name_reserve);
            if (*(book_name_reserve + len - 1) == '\n')
            {
                *(book_name_reserve + len - 1) = '\0';
            }
            break;
        }
    }
    if (option_re == BUTTON_RESERVE)
    {
        review_library(1, 0);
    }
    if (option_re == BUTTON_EXIT)
    {
        printf("Exiting...\n");
        exit(0);
    }
    else
    {
        printf("Invalid option.\n");
    }
}

void search_author(char author[])
{
    int match_count = 0;
    // search for books with matching authors

    printf("=================================================================================================================\n");
    printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
    printf("=================================================================================================================\n");
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && strstr(book[i].author, author) != NULL)
        {
            // book name contains the search term

            if (match_count == 0)
            {
                printf(" Matching books... \n");
            }
            printf("%s|%s|%s|%d|%d|%.2f|%s|%d|%d|\n", book[i].book_name, book[i].author,
                   book[i].publisher, book[i].publish_year, book[i].amount,
                   book[i].call_number, book[i].isbn, book[i].viewer_count, book[i].accession_number);
        }
    }

    // print message if no matches found
    if (match_count == 0)
    {
        printf("\nNo matching books found.\n");
        return;
    }
}

void search_publisher(char publisher[])
{
    int num_books = 0;
    printf("=================================================================================================================\n");
    printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
    printf("=================================================================================================================\n");
    // count the number of books that match the search criteria
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && strstr(book[i].publisher, publisher) != NULL)
        {
            num_books++;
        }
    }

    // check if any books were found
    if (num_books == 0)
    {
        printf("No books found.\n");
        return;
    }
    // print the search results
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && strstr(book[i].publisher, publisher) != NULL)
        {
            printf("%-30s %-20s %-20s %-15d %-15s\n", book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].isbn);
        }
    }
}

void search_call_number(float *call_number)
{
    int num_books = 0;
    // count the number of books that match the search criteria
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && book[i].call_number == *call_number)
        {
            num_books++;
        }
    }

    // check if any books were found
    if (num_books == 0)
    {
        printf("No books found.\n");
        return;
    }

    // print the header for the search results
    printf("Search results for \"%f\" in the call number field:\n\n", *call_number);
    printf("  %-30s %-20s %-20s %-15s %-15s\n", "Book Title", "Author", "Publisher", "Publication Year", "ISBN");

    // print the search results
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && book[i].call_number == *call_number)
        {
            printf("%-30s %-20s %-20s %-15d %-15s\n", book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].isbn);
        }
    }
}

void search_ISBN(char isbn[])
{
    int num_books = 0;
    // count the number of books that match the search criteria
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && strcmp(book[i].isbn, isbn) == 0)
        {
            num_books++;
        }
    }

    // check if any books were found
    if (num_books == 0)
    {
        printf("No books found.\n");
        return;
    }

    // print the header for the search results
    printf("Search results for \"%s\" in the ISBN field:\n\n", isbn);
    printf("  %-30s %-20s %-20s %-15s %-15s\n", "Book Title", "Author", "Publisher", "Publication Year", "ISBN");

    // print the search results
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && strcmp(book[i].isbn, isbn) == 0)
        {
            printf("%-30s %-20s %-20s %-15d %-15s\n", book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].isbn);
        }
    }
}

void show_book()
{
    int num_books = 0;

    // count the number of books
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL)
        {
            num_books++;
        }
    }

    // check if any books were found
    if (num_books == 0)
    {
        printf("No books found.\n");
        return;
    }

    // print the header for the search results

    printf("=================================================================================================================\n");
    printf("| Book name | Author | Publisher | Publish year | Amount | Call number | ISBN | Viewer count | Accession number |\n");
    printf("=================================================================================================================\n");
    // print the search results
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL)
        {
            printf("|%s|%s|%s|%d|%s|\n", book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].isbn);
        }
    }
}

void reserve_book(int number, int number_book, int option_reserve)
{
    int count = 0;

    // search for the book to be reserved
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL)
        {
            count++;
            if (count == number_book)
            {
                // book found, update its status
                if (option_reserve == 1)
                {
                    if (book[i].amount > 0)
                    {
                        book[i].amount--;
                        printf("Book %d: \"%s\" reserved successfully.\n", number, book[i].book_name);
                        // TODO: add the user's name to the book's borrower list
                        // TODO: set the book's expiry date
                    }
                    else
                    {
                        printf("Error: Book %d: \"%s\" is currently unavailable.\n", number, book[i].book_name);
                    }
                }
                else if (option_reserve == 2)
                {
                    book[i].amount++;
                    printf("Book %d: \"%s\" unreserved successfully.\n", number, book[i].book_name);
                    // TODO: remove the user's name from the book's borrower list
                }
                return;
            }
        }
    }

    // book not found
    printf("Error: Book %d not found.\n", number);
}
