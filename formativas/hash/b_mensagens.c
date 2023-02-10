#include <stdlib.h>
#include <stdio.h>

typedef struct letra
{
    long int code;
    char carac;
} letra;

int main()
{
    long int code;
    char carac;
    while (scanf("%ld %c", &code, &carac) != EOF)
    {
        printf("Leitura -> code: %ld, carac: %c\n", code, carac);
    }
    return 0;
}