#include "total.h"

void sort_publish_year()
{
    static int order = SMALL;

    /* Large first */
    for(int i = 0; i < amount_books - 1; i++)
    {
        for(int j = 0; j < amount_books - i; j++)
        {
            if(book[j].publish_year < book[j + 1].publish_year)
            {
                struct books temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }

    if(order == SMALL)
        order = LARGE;
    else if(order == LARGE)
    {
        order = SMALL;
        /* Small first, reverse the structure */
        for(int i = 0; i < (amount_books / 2); i++)
        {
            struct books temp = book[i];
            book[i] = book[amount_books - i - 1];
            book[amount_books - i - 1] = temp;
        }
    }
    
}