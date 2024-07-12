#include <stdio.h>
#include <string.h>

/* Prototipo de función para contar las ocurrencias de una cadena dentro de otra. */
int contar_ocurrencias(char *cadena1, char *cadena2);

int main(void)
{
    char cad1[50], cad2[50];

    printf("Ingrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);
    // Elimina el salto de línea al final de la cadena si existe
    size_t len1 = strlen(cad1);
    if (len1 > 0 && cad1[len1 - 1] == '\n') {
        cad1[len1 - 1] = '\0';
    }

    printf("Ingrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin);
    // Elimina el salto de línea al final de la cadena si existe
    size_t len2 = strlen(cad2);
    if (len2 > 0 && cad2[len2 - 1] == '\n') {
        cad2[len2 - 1] = '\0';
    }

    int ocurrencias = contar_ocurrencias(cad1, cad2);

    printf("\nEl número de veces que aparece la segunda cadena es: %d\n", ocurrencias);

    return 0;
}

int contar_ocurrencias(char *cadena1, char *cadena2)
{
    int contador = 0;
    char *posicion = cadena1;

    while ((posicion = strstr(posicion, cadena2)) != NULL) {
        contador++;
        posicion++;
    }

    return contador;
}
