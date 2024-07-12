#include <stdio.h>

void main(void)
{
    char p1, p2, p3 = '$';

    printf("\nIngrese un caracter: ");
    p1 = getchar(); // Leer un caracter usando getchar
    putchar(p1);    // Escribir el caracter usando putchar
    printf("\n");

    fflush(stdin); // Limpiar el buffer de entrada

    printf("\nEl caracter p3 es: ");
    putchar(p3); // Escribir el caracter almacenado en p3
    printf("\n");

    printf("\nIngrese otro caracter: ");
    fflush(stdin); // Limpiar el buffer de entrada antes de usar scanf
    scanf("%c", &p2); // Leer un caracter usando scanf
    printf("%c", p2); // Escribir el caracter usando printf
}
