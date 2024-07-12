#include <stdio.h>
#include <string.h>

void main(void)
{
    char cad0[] = "Hola M�xico";
    char cad1[20], cad2[20], cad3[] = ", buenos d�as!!!";
    char *c;

    // Copia cad0 a cad1
    strcpy(cad1, cad0);
    printf("\nPrueba de la funci�n strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

    // Copia cad3 a cad1
    strcpy(cad1, cad3);
    printf("\nPrueba de la funci�n strcpy. Se copia la cadena cad3 a cad1: %s\n", cad1);

    // Copia "XX" a cad1
    strcpy(cad1, "XX");
    printf("\nPrueba de la funci�n strcpy. Se copia la cadena XX a cad1: %s\n", cad1);

    // Copia los primeros 4 caracteres de cad0 a cad2
    strncpy(cad2, cad0, 4);
    cad2[4] = '\0'; // A�ade el terminador nulo
    printf("\nPrueba de la funci�n strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    // Copia los primeros 3 caracteres de cad3 a cad2
    strncpy(cad2, cad3, 3);
    cad2[3] = '\0'; // A�ade el terminador nulo
    printf("\nPrueba de la funci�n strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    // Concatena cad3 a cad0
    strcat(cad0, cad3);
    printf("\nPrueba de la funci�n strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);

    // Concatena " YY" a cad1
    strcat(cad1, " YY");
    printf("\nPrueba de la funci�n strcat. Se incorpora la cadena YY a cad1: %s\n", cad1);

    // Concatena los primeros 4 caracteres de cad0 a cad2
    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba de la funci�n strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);

    // Busca "M�xico" en cad0
    c = strstr(cad0, "M�xico");
    if (c != NULL)
    {
        printf("\nPrueba de la funci�n strstr. Se encuentra 'M�xico' dentro de cad0: %s\n", c);
    }
    else
    {
        printf("\nPrueba de la funci�n strstr. 'M�xico' no se encuentra dentro de cad0.\n");
    }

    // Intenta buscar "Guatemala" en cad0
    c = strstr(cad0, "Guatemala");
    if (c != NULL)
    {
        printf("\nPrueba de la funci�n strstr. Se encuentra 'Guatemala' dentro de cad0: %s\n", c);
    }
    else
    {
        printf("\nPrueba de la funci�n strstr. 'Guatemala' no se encuentra dentro de cad0.\n");
    }
}
