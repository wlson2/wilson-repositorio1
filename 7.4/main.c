#include <stdio.h>
#include <string.h>

void main(void)
{
    char *cad0;
    cad0 = "Argentina";
    puts(cad0);  // Imprime "Argentina"

    cad0 = "Brasil";
    puts(cad0);  // Imprime "Brasil"

    char cad1[50];  // Se declara cad1 como un arreglo de caracteres
    gets(cad1);  // Se lee una cadena de caracteres en cad1
    printf("Cadena leída en cad1: %s\n", cad1);

    char cad2[20] = "México";  // Se inicializa cad2 con "México"
    puts(cad2);  // Imprime "México"

    gets(cad2);  // Se lee una nueva cadena en cad2
    printf("Nueva cadena en cad2: %s\n", cad2);

    // Intento de asignación incorrecta, que debería ser corregido
    // cad2[10] = "Guatemala";  // Esto causaría un error en la compilación

    // Para asignar "Guatemala" en la posición 10 de cad2, se usa strcpy
    strcpy(&cad2[10], "Guatemala");
    puts(cad2);  // Imprime "MéxicoGuatemala"

    // Otra forma de hacerlo sería usando strncpy
    strncpy(&cad2[10], "Honduras", 8);  // Copiar solo los primeros 8 caracteres de "Honduras"
    cad2[18] = '\0';  // Asegurar que cad2 tenga un terminador nulo al final
    puts(cad2);  // Imprime "MéxicoHonduras"
}

