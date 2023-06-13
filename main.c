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
        CLEARSCREAN;
        printf("===================\n");
        printf("| Exit successful |\n");
        printf("===================\n");
        return 0;
    }
    else
        longjmp(startbuffer, 3); // back to start
}