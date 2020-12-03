#include <stdio.h>
#include <string.h>
int main()
{
    char nombre[];
    system("clear");
    printf("dame tu nombre \n");
    gets(nombre);
    printf("hola %s",nombre);
    getchar();
    return 0;
}
