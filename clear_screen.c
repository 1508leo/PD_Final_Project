#include <stdio.h>
#include <stdlib.h>

int main()
{
    //system("cls"); // for windows
    //system("clear"); // for mac
    printf("\033[H\033[2J");
    printf("hello world\n");
}