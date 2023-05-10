#include "total.h"

/* Checking whether the account has been registed */
int set_check_account_re(char account[])
{
    struct readers *check;
    check = first;
    while(check != NULL)
    {
        if(strcmp(check -> re_account, account) == 0)
        {
            printf("The account has been registered!\n");
            printf("Please enter another one.\n");
            return NO;
        }
        check = check -> link;
    }

    return YES;
}

/* Add a node for new reader */
void add_reader(char name[], int id, char grade[], char email[], char account[],char password[])
{
    struct readers *new_reader;

    new_reader = malloc(sizeof(struct readers));

    /* The type in linked list is pointer */
    new_reader -> re_name = name;
    new_reader -> student_id = id;
    new_reader -> grade = grade;
    new_reader -> email = email;
    new_reader -> re_account = account;
    new_reader -> re_password = password;
    new_reader -> credit = 100; // initailize
    new_reader -> next = NULL;
    new_reader -> link = NULL;
    
    if(first == NULL)
    {
        first = new_reader;
    }
    else
    {
        /* Push back */
        struct readers *cur;
        cur = first;
        while(cur -> link != NULL)
        {
            cur = cur -> link;
        }
        cur -> next = new_reader;
        cur -> link = new_reader;
    } 
}