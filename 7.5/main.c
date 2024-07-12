#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
    int i;
    double d;
    long l;
    char cad0[20], cad1[20];

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cad0, sizeof(cad0), stdin);
    cad0[strcspn(cad0, "\n")] = '\0';  // Elimina el salto de línea al final de cad0

    i = atoi(cad0);
    printf("\n%s \t %d", cad0, i + 3);

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cad0, sizeof(cad0), stdin);
    cad0[strcspn(cad0, "\n")] = '\0';  // Elimina el salto de línea al final de cad0

    d = atof(cad0);
    printf("\n%s \t %.2lf", cad0, d + 1.50);

    d = strtod(cad0, &cad1);
    printf("\n%s \t %.2lf", cad0, d + 1.50);
    printf("\nResto de la cadena: %s", cad1);

    l = atol(cad0);
    printf("\n%s \t %ld", cad0, l + 10);

    l = strtol(cad0, &cad1, 0);
    printf("\n%s \t %ld", cad0, l + 10);
    printf("\nResto de la cadena: %s\n", cad1);
}
