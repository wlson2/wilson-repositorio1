#include <stdio.h>
#include <ctype.h>

void main(void)
{
    char p1;

    printf("\nIngrese un caracter para analizar si este es un digito: ");
    p1 = getchar();
    if (isdigit(p1))
        printf("%c es un d�gito\n", p1);
    else
        printf("%c no es un d�gito\n", p1);

    fflush(stdin);

    printf("\nIngrese un caracter para examinar si �ste es una letra: ");
    p1 = getchar();
    if (isalpha(p1))
        printf("%c es una letra\n", p1);
    else
        printf("%c no es una letra\n", p1);

    fflush(stdin);

    printf("\nIngrese un caracter para examinar si �ste es una letra min�scula: ");
    p1 = getchar();
    if (isalpha(p1))
    {
        if (islower(p1))
            printf("%c es una letra min�scula\n", p1);
        else
            printf("%c no es una letra min�scula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }

    fflush(stdin);

    printf("\nIngrese una letra para convertirla de mayuscula a minuscula: ");
    p1 = getchar();
    if (isalpha(p1))
    {
        if (isupper(p1))
            printf("%c fue convertida de may�scula a minuscula: %c\n", p1, tolower(p1));
        else
            printf("%c es una letra minuscula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }

    fflush(stdin);

    printf("\nIngrese una letra para convertirla de min�scula a mayuscula: ");
    p1 = getchar();
    if (isalpha(p1))
    {
        if (islower(p1))
            printf("%c fue convertida de minuscula a mayuscula: %c\n", p1, toupper(p1));
        else
            printf("%c es una letra mayuscula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }
}
