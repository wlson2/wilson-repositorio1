#include <stdio.h>

void main(void)
{
    char *cad0 = "Buenos días"; // Cadena asignada de forma directa
    char cad1[20] = "Hola";     // Cadena con espacio reservado
    char cad2[] = "México";     // Cadena sin tamaño explícito
    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'}; // Cadena inicializada con caracteres individuales
    char cad4[50];              // Cadena leída con gets
    char cad5[20];              // Cadena leída con scanf
    char cad6[50];              // Cadena leída con getchar

    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    printf("\nLa cadena cad1 es: ");
    printf("%s", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una línea de texto (se lee con gets): ");
    gets(cad4);
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    fflush(stdin); // Limpiar el buffer de entrada para scanf

    printf("\nIngrese una línea de texto (se lee con scanf): ");
    scanf("%s", cad5);
    printf("\nLa cadena cad5 es: ");
    printf("%s", cad5);

    fflush(stdin); // Limpiar el buffer de entrada para getchar

    printf("\nIngrese una línea de texto (se lee con getchar): ");
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && i < 49) // Leer caracteres hasta encontrar salto de línea o llenar el arreglo
    {
        cad6[i++] = ch;
    }
    cad6[i] = '\0'; // Agregar terminador nulo al final de la cadena cad6

    printf("\nLa cadena cad6 es: ");
    puts(cad6);
}
