#include "total.h"

void output_file()
{
    FILE *fp_amount, *fp_administrator, *fp_book, *fp_reader;

    /* Open the amount.txt. Which store the amount of administrators, books, accession number, and readers */
    if((fp_amount = fopen("amount.txt", "r+")) == NULL) // r+ can read and write.  
    {
        printf("Open amount.txt fail\n"); // Error message
        exit(0);
    } 

    fprintf(fp_amount, "%d %d %d %d\n", number_ad, amount_books, accession_numer, amount_re); // Use fprintf to write into file

    /* Open administrator.txt. Which store the information of every administrator */
    if((fp_administrator = fopen("administrator.txt", "r+")) == NULL) // r+ can read and write
    {
        printf("Open administrator.txt fail\n"); // Error message
        exit(0);
    } 

    fwrite(administrator, sizeof(struct administrators), number_ad, fp_administrator); // Use fwrite to write into file. Which is binary I/O

    /* Open book.txt. Which store the information of every book */
    if((fp_book = fopen("book.txt", "r+")) == NULL) // r+ can read and write
    {
        printf("Open book.txt fail\n"); // Error message
        exit(0);
    } 

    fwrite(book, sizeof(struct books), amount_books, fp_book);  // Use fwrite to write into file. Which is binary I/O

    /* Open reader.txt. Which store the information of every reader */
    if((fp_reader = fopen("reader.txt", "r+")) == NULL) // r+ can read and write
    {
        printf("Open reader.txt fail\n"); // Error message
    }

    /* Readers' information is store in linked list */
    struct readers *cur;
    cur = first;

    while(cur != NULL) // Run every node
    {
        /* Don't store the pointer information into file. It might point to weird place */
        fwrite(cur, sizeof(struct readers) - sizeof(struct readers *), 1, fp_reader);
        cur = cur -> next; // To next node
    }

    /* Back to the beginning of the file */
    rewind(fp_amount);
    rewind(fp_administrator);
    rewind(fp_book);
    rewind(fp_book);
}