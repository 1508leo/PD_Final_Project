#include "total.h"

int set_check_account_re(char account[])
{
    struct readers *check;
    check = first;
    while(check != NULL)
    {
        if(strcmp(check -> re_account, account) == 0)
        {
            printf("The account had been registered!\n");
            printf("Please enter another one.\n");
            return NO;
        }
        check = check -> link;
    }

    return YES;
}