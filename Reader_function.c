#include "fp_headerfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void search_book_name(int option_re, char book_name[])
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
        for (int j = 0; j < count; j++)
        {
            printf("%d. %s by %s, %s\n", j + 1, book[results[j]].book_name,
                   book[results[j]].author, book[results[j]].publisher);
        }
        if (option_re == 1)
        {
            // prompt user to reserve a book
            int number, option_reserve;
            printf("Enter book number to reserve: ");
            scanf("%d", &number);
            printf("Enter 1 to reserve, 2 to unreserve: ");
            scanf("%d", &option_reserve);
            reserve_book(number, count, option_reserve);
        }
    }
    else
    {
        printf("No books found.\n");
    }
}

void search_author(int option_re, char author[])
{
    int match_count = 0;

    // search for books with matching authors
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL && strstr(book[i].author, author) != NULL)
        {
            if (match_count == 0)
            {
                printf("\nMatching books:\n");
            }
            printf("%d. %s\n", match_count + 1, book[i].book_name);
            match_count++;
        }
    }

    // print message if no matches found
    if (match_count == 0)
    {
        printf("\nNo matching books found.\n");
        return;
    }

    // ask user to reserve a book
    if (option_re == 1)
    {
        int book_num;
        printf("\nEnter the number of the book you want to reserve: ");
        scanf("%d", &book_num);
        if (book_num < 1 || book_num > match_count)
        {
            printf("Invalid book number.\n");
            return;
        }
        //  reserve_book(book_num, match_count, 1);
    }
}

void search_publisher(int option_re, char publisher[])
{
    int num_books = 0;
    int match = 0;

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

    // print the header for the search results
    printf("Search results for \"%s\" in the publisher field:\n\n", publisher);
    printf("  %-30s %-20s %-20s %-15s %-15s\n", "Book Title", "Author", "Publisher", "Publication Year", "ISBN");

    // print the search results
    for (int i = 0; i < MAX_BUF && match < num_books; i++)
    {
        if (book[i].book_name != NULL && strstr(book[i].publisher, publisher) != NULL)
        {
            match++;
            if (option_re == 1)
            {
                printf("%2d. %-30s %-20s %-20s %-15d %-15s\n", match, book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].isbn);
            }
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
    printf("\n%-5s %-30s %-20s %-20s %-15s %-15s\n", "No.", "Book Title", "Author", "Publisher", "Publication Year", "ISBN");

    // print the search results
    int count = 0;
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (book[i].book_name != NULL)
        {
            count++;
            printf("%-5d %-30s %-20s %-20s %-15d %-15s\n", count, book[i].book_name, book[i].author, book[i].publisher, book[i].publish_year, book[i].isbn);
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


int main(int argc, char *argv[])
{
    char query[MAX_BUF];
    int option;
    int option_re;
    float call_number;
    int number;
    int number_book;
    int option_reserve;
    char search_term[MAX_BUF];
    printf("===========================");
    printf("Welcome to the library!\n");
    printf("===========================");
    while (1)
    {
        printf("===========================");
        printf("What would you like to do?\n");
        printf("1. Search by book name\n");
        printf("2. Search by author\n");
        printf("3. Search by publisher\n");
        printf("4. Search by call number\n");
        printf("5. Search by ISBN\n");
        printf("6. Search by viewer count\n");
        printf("7. Reserve a book\n");
        printf("8. Show all books\n");
        printf("9. Exit\n");
        printf("===========================");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter a book name to search for: ");
            scanf("%s", query);
            printf("Do you want to search for an exact match or a partial match? (1 for exact, 2 for partial): ");
            scanf("%d", &option_re);
            search_book_name(option_re, query);
            break;
        case 2:
            printf("Enter author: ");
            scanf("%s", search_term);
            printf("Enter 1 to reserve, 0 to search only: ");
            scanf("%d", &option_re);
            search_author(option_re, search_term);
            break;
        case 3:
            // TODO: call search_publisher function
            printf("Enter publisher: ");
            scanf("%s", search_term);
            printf("Enter 1 to reserve, 0 to search only: ");
            scanf("%d", &option_re);
            search_publisher(option_re, search_term);
            break;
        case 4:
            printf("Enter a call number to search for: ");
            scanf("%f", &call_number);
            printf("Do you want to search for an exact match or a partial match? (1 for exact, 2 for partial): ");
            scanf("%d", &option_re);
            search_call_number(option_re, &call_number);
            break;
        case 5:
            // TODO: call search_isbn function
            printf("Enter ISBN: ");
            scanf("%s", search_term);
            printf("Enter 1 to reserve, 0 to search only: ");
            scanf("%d", &option_re);
            search_ISBN(option_re, search_term);
            break;
        case 6:
            printf("Do you want to see the most popular books or all books with at least one viewer? (1 for most popular, 2 for all): ");
            scanf("%d", &option_re);
            search_viewer_count(option_re);
            break;
        case 7:
            printf("Enter your student ID: ");
            scanf("%d", &number);
            printf("Enter the accession number of the book you want to reserve: ");
            scanf("%d", &number_book);
            printf("Do you want to reserve or unreserve the book? (1 for reserve, 2 for unreserve): ");
            scanf("%d", &option_reserve);
            reserve_book(number, number_book, option_reserve);
            break;
        case 8:
            show_book();
            break;
        case 9:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }
}
