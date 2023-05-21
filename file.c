#include "total.h"

FILE *fp_amount, *fp_administrator, *fp_book, *fp_reader;

void input_file()
{
    /* Open the amount.txt. Which store the amount of administrators, books, accession number, and readers */
    if((fp_amount = fopen("amount.txt", "r+")) == NULL) // r+ can read and write.  
    {
        printf("Open amount.txt fail\n"); // Error message
        exit(0);
    } 

    /* Get the information from amount.txt. Store the value into variable */
    fscanf(fp_amount ,"%d %d %d %d", &number_ad, &amount_books, &accession_numer, &number_ad);

    /* Open administrator.txt. Which store the information of every administrator */
    if((fp_administrator = fopen("administrator.txt", "r+")) == NULL) // r+ can read and write
    {
        printf("Open administrator.txt fail\n"); // Error message
        exit(0);
    } 

    /* Get the information from administrator.txt. Store into administrator */
    fread(administrator, sizeof(struct administrators), number_ad, fp_administrator);

    /* Open book.txt. Which store the information of every book */
    if((fp_book = fopen("book.txt", "r+")) == NULL) // r+ can read and write
    {
        printf("Open book.txt fail\n"); // Error message
        exit(0);
    } 

    /* Get the information from book.txt. Store into book */
    fread(book, sizeof(struct books), amount_books, fp_book); 

    /* Open reader.txt. Which store the information of every reader */
    if((fp_reader = fopen("reader.txt", "r+")) == NULL) // r+ can read and write
    {
        printf("Open reader.txt fail\n"); // Error message
    }

    /* Readers' information is store in linked list */
    struct readers *cur;
    struct readers *new_node;
    cur = first;

    for(int i = 0; i < amount_re; i++)
    {
        new_node = malloc(sizeof(struct readers));
        fread(new_node, sizeof(struct readers) - sizeof(struct readers *), 1, fp_reader); // store into new_node
        new_node -> next = NULL; // Let next point to NULL
        
        /* Put into linked list*/
        if(first == NULL)
        {
            first = new_node;
            cur = first;
        }
        else
        {
            while(cur -> next != NULL)
                cur = cur -> next;
            cur -> next = new_node; // push back
        }
        
    }

    /* Back to the beginning of the file */
    rewind(fp_amount);
    rewind(fp_administrator);
    rewind(fp_book);
    rewind(fp_book);
}

void output_file()
{
    /* Use fprintf to write into file */
    fprintf(fp_amount, "%d %d %d %d\n", number_ad, amount_books, accession_numer, amount_re);

    /* Use fwrite to write into file. Which is binary I/O */
    fwrite(administrator, sizeof(struct administrators), number_ad, fp_administrator); 

    /* Use fwrite to write into file. Which is binary I/O */
    fwrite(book, sizeof(struct books), amount_books, fp_book); 

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
    fclose(fp_amount);
    fclose(fp_administrator);
    fclose(fp_book);
    fclose(fp_book);
}