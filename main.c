#include "total.h"

int main()
{
    input_file();
    int iden=0;
    jmp_buf startbuffer;
    setjmp(startbuffer);

    CLEARSCREAN;
    printf("================================\n");
    printf("| Please select the identity:  |\n");
    printf("| 1. Administrator             |\n");
    printf("| 2. Reader                    |\n");
    printf("| 3. Exit the system           |\n");
    printf("================================\n");
    printf("Enter: ");

    scanf(" %d", &iden);

    fflush(stdin);

    if(iden == 1)
    {
        CLEARSCREAN;
        
        sign_in_administrator();

        administrator_mode();

        longjmp(startbuffer, 1); // back to start
    }
    else if(iden == 2)
    {
        int sign=0;
        jmp_buf signbuffer;
        setjmp(signbuffer);
        CLEARSCREAN;
        printf("=========================================\n");
        printf("| Please desing to sign in or sign up:  |\n");
        printf("| 1. Sign in                            |\n");
        printf("| 2. Sign up                            |\n");
        printf("| 3. Exit                               |\n");
        printf("=========================================\n");
        printf("Enter: ");

        scanf(" %d", &sign);

        fflush(stdin);

        if(sign == 1)
        {
            CLEARSCREAN;

            sign_in_reader();

            reader_mode();

            longjmp(signbuffer, 1); // back to sign
        }
        else if(sign == 2)
        {
            add_reader();

            longjmp(signbuffer, 2); // back to sign
        }
        else if(sign == 3)
        {
            longjmp(startbuffer, 2); // back to start
        }
    }
    else if(iden == 3)
    {
        output_file();
        return 0;
    }
    else
        longjmp(startbuffer, 3); // back to start
}
/*

strcpy(book[0].book_name, "The Lightning Thief");
    strcpy(book[0].author, "Rick Riordan");
    strcpy(book[0].publisher, "Hyperion Boooks");
    book[0].publish_year = 2005;
    strcpy(book[0].call_number, "874.57 2727");
    strcpy(book[0].isbn, "9789573264354");
    book[0].viewer_count = 0;
    book[0].accession_number = 1;
    book[0].status = 0;


    strcpy(book[1].book_name, "The Sea of Monsters");
    strcpy(book[1].author, "Rick Riordan");
    strcpy(book[1].publisher, "Hyperion Boooks");
    book[1].publish_year = 2006;
    strcpy(book[1].call_number, "874.57 2727");
    strcpy(book[1].isbn, "9789573264743");
    book[1].viewer_count = 0;
    book[1].accession_number = 2;
    book[1].status = 0;


    strcpy(book[2].book_name, "The Tian's Curse");
    strcpy(book[2].author, "Rick Riordan");
    strcpy(book[2].publisher, "Hyperion Boooks");
    book[2].publish_year = 2007;
    strcpy(book[2].call_number, "874.57 2727");
    strcpy(book[2].isbn, "9789573265061");
    book[2].viewer_count = 0;
    book[2].accession_number = 3;
    book[2].status = 0;

    strcpy(book[3].book_name, "The Battle of the Labyrinth");
    strcpy(book[3].author, "Rick Riordan");
    strcpy(book[3].publisher, "Hyperion Boooks");
    book[3].publish_year = 2008;
    strcpy(book[3].call_number, "874.57 2727");
    strcpy(book[3].isbn, "9789573265467");
    book[3].viewer_count = 0;
    book[3].accession_number = 4;
    book[3].status = 0;

    strcpy(book[4].book_name, "The Last Olympian");
    strcpy(book[4].author, "Rick Riordan");
    strcpy(book[4].publisher, "Hyperion Boooks");
    book[4].publish_year = 2009;
    strcpy(book[4].call_number, "874.57 2727");
    strcpy(book[4].isbn, "9789573265955");
    book[4].viewer_count = 0;
    book[4].accession_number = 5;
    book[4].status = 0;
    amount_books = 5;
*/

/*
strcpy(administrator[0].ad_name, "Leo Hsu");
    strcpy(administrator[0].ad_account, "leohsu");
    strcpy(administrator[0].ad_password, "leo930228");
    */