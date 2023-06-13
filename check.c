#include "total.h"

int position = 0;
char name_re[SPACE];
char name_ad[SPACE];
jmp_buf	emailbuffer;

void check_email(char email[]) 
{
    int error = 0;
    int counter = 0;
    char* cptr;
    char* temp;

    printf("\n===================================================\n");

    if ((cptr = strchr(email, '@')) == NULL) {
        printf("| Email format error: at least one @              |\n");
        printf("===================================================\n");
        error++;
    }
    else
    {
        temp = cptr;
        while ((cptr = strchr(temp, '@')) != NULL) {
            counter++;
            temp = cptr + 1;
        }

        if (counter > 1) {
            printf("Email format error: more than one @               |\n");
            printf("===================================================\n");
            error++;
        }
    }

    char* sharp;
    sharp = strchr(email, '#');
    while (sharp != NULL) {
        printf("| Email format error: can't exist #               |\n");
        printf("===================================================\n");
        error++;
        sharp = strchr(sharp + 1, '#');
    }

    char* asterisk;
    asterisk = strchr(email, '*');
    while (asterisk != NULL) {
        printf("| Email format error: can't exist *               |\n");
        printf("===================================================\n");
        error++;
        asterisk = strchr(asterisk + 1, '*');
    }

    char* doubledot;
    doubledot = strstr(email, "..");
    while (doubledot != NULL) {
        printf("| Email format error: can't exist ..              |\n");
        printf("===================================================\n");
        error++;
        doubledot = strstr(doubledot + 1, "..");
    }

    char* at = NULL;
    char* dot = NULL;
    if ((at = strchr(email, '@')) != NULL) {
        dot = strchr(at + 1, '.');
        if (dot == NULL) {
            printf("| Email format error: at least one . behind the @ |\n");
            printf("===================================================\n");
            error++;
        }
    }

    if (error != 0)
        longjmp(emailbuffer, 1);
    printf("| Email format correct!                           |\n");
    printf("===================================================\n\n");
}

int set_check_account_re(char name[], int id, char email[], char account[])
{
    struct readers *check;
    check = first;
    while(check != NULL)
    {
        if(strcmp(check -> re_account, account) == 0)
        {
            CLEARSCREAN; // clear the screen
            printf("The account had been registered!\n");
            printf("Please enter another one.\n\n");
            printf("Your name: %s\n", name);
            printf("Your student id: %d\n", id);
            printf("Your email: %s\n", email);
            return NO;
        }
        check = check -> next;
    }

    return YES;
}

/* Add a node for new reader */
void add_reader()
{
    int success=0;
    char name[SPACE], email[SPACE], account[SPACE], password[SPACE];
    struct readers *new_reader;

    new_reader = malloc(sizeof(struct readers));

    CLEARSCREAN; // clear the screen
    printf("Please enter your name: ");
    fgets(name, SPACE, stdin);
    if(name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';

    printf("Please enter your student id: ");
    scanf("%d", &new_reader -> student_id);

    fflush(stdin);

    int detect=0;

    detect = setjmp(emailbuffer);
    if(detect == 1)
        printf("\n");

    printf("Please enter your email: ");
    fgets(email, SPACE, stdin);
    if(email[strlen(email) - 1] == '\n')
        email[strlen(email) - 1] = '\0';

    check_email(email);

    while (1)
    {
        printf("Please enter your account: ");
        fgets(account, SPACE, stdin);
        if(account[strlen(account) - 1] == '\n')
            account[strlen(account) - 1] = '\0';

        success = set_check_account_re(name, new_reader -> student_id, email, account);
        if(success == YES)
            break;
    }
    strcpy(new_reader -> re_account, account);

    printf("Please enter your password: ");
    fgets(password, SPACE, stdin);
    if(password[strlen(password) - 1] == '\n')
        password[strlen(password) - 1] = '\0';

    /* Store it */
    strcpy(new_reader -> re_name, name);
    strcpy(new_reader -> email, email);
    strcpy(new_reader -> re_account, account);
    strcpy(new_reader -> re_password, password);

    new_reader -> next = NULL;
    amount_re++;
    
    if(first == NULL)
    {
        first = new_reader;
    }
    else
    {
        /* Push back */
        struct readers *cur;
        cur = first;
        while(cur -> next != NULL)
        {
            cur = cur -> next;
        }
        cur -> next = new_reader;
    } 
}

/* Check whether the account is existent */
int in_check_account_ad(char account[])
{
    for(int i = 0; i < number_ad; i++)
    {
        if(strcmp(administrator[i].ad_account, account) == 0) // the account exist
            return YES;
    }
    /* Account doesn't exist */
    CLEARSCREAN; // clear the screen
    printf("==============================\n");
    printf("| The account doesn't exist! |\n");
    printf("==============================\n\n");

    return NO; // ask to enter again
}

/* Check whether the password is correct */
int in_check_password_ad(char account[], char password[])
{
    for(int i = 0; i < number_ad; i++)
    {
        if(strcmp(administrator[i].ad_account, account) == 0 && strcmp(administrator[i].ad_password, password) == 0) // the password is correct
        {
            strcpy(name_ad, administrator[i].ad_name); // user name
            return YES;
        }
    }
    /* Password isn't correct */
    CLEARSCREAN; // clear the screen
    printf("================================\n");
    printf("| Your password isn't correct! |\n");
    printf("================================\n\n");
    printf("Account: %s\n", account);
    
    return NO; // ask to enter again
}

/* Option_entry = BUTTON_SIGN_IN */
void sign_in_administrator()
{
    char account[MAX_BUF], password[MAX_BUF];
    int success=0; // to store the return value of checking function
    while(1)
    {
        printf("Please enter your account: ");
        fgets(account, SPACE, stdin);
        if(account[strlen(account) - 1] == '\n')
            account[strlen(account) - 1] = '\0';
        
        success = in_check_account_ad(account); // check

        if(success == NO) // "No" means the account doesn't exist
            continue;
        else
            break; // account exist
    }
    
    while(1)
    {
        
        printf("Please enter your password: ");
        fgets(password, SPACE, stdin);
        if(password[strlen(password) - 1] == '\n')
            password[strlen(password) - 1] = '\0';
        
        success = in_check_password_ad(account, password);

        if(success == NO) // "No" means the password isn't correct
            continue;
        else
            break; // password is correct
    }
}

/* Check whether the account is existent */
int in_check_account_re(char account[])
{
    struct readers *cur;
    cur = first;
    while(cur != NULL)
    {
        if(strcmp(cur -> re_account, account) == 0) // the account exist
            return YES;
        cur = cur -> next;
    }
    /* Account doesn't exist */
    CLEARSCREAN; // clear the screen
    printf("==============================\n");
    printf("| The account doesn't exist! |\n");
    printf("==============================\n\n");

    return NO;
}

int in_check_password_re(char account[], char password[])
{
    struct readers *cur;
    cur = first;
    while(cur != NULL)
    {
        if(strcmp(cur -> re_account, account) == 0 && strcmp(cur -> re_password, password) == 0) // password correct
        {
            strcpy(name_re, cur -> re_name); // user name
            return YES;
        }
        cur = cur -> next;
    }
    /* Password isn't correct */
    CLEARSCREAN; // clear the screen
    printf("================================\n");
    printf("| Your password isn't correct! |\n");
    printf("================================\n\n");
    printf("Account: %s\n", account);
    
    return NO; // ask to enter again
}

void sign_in_reader()
{
    char account[MAX_BUF], password[MAX_BUF];
    int success = 0;
    while(1)
    {
        printf("Please enter your account: ");
        fgets(account, SPACE, stdin);
        if(account[strlen(account) - 1] == '\n')
            account[strlen(account) - 1] = '\0';

        success = in_check_account_re(account);

        if(success == NO) // "No" means the account doesn't exist
            continue;
        else
            break; // account exist
    }

    while(1)
    {
        printf("Please enter your password: ");
        fgets(password, SPACE, stdin);
        if(password[strlen(password) - 1] == '\n')
            password[strlen(password) - 1] = '\0';
        
        success = in_check_password_re(account, password);

        if(success == NO) // "No" means the account doesn't exist
            continue;
        else
            break; // account exist
    }
}

int set_check_account_ad(char name[], char account[])
{
    for(int i = 0; i < number_ad; i++)
    {
        if(strcmp(administrator[i].ad_account, account) == 0) // compare
        {
            CLEARSCREAN; // clear the screen
            printf("The account has been reginsted!\n");
            printf("Please enter another one.\n\n");
            printf("Name: %s\n", name);
            return NO;
        }
    }
    return YES;
}