#include <stdio.h>
#include <string.h>

/* Prototipo de función para invertir una cadena. */
char *inverso(char *cadena);

int main(void)
{
    char fra[50];
    printf("Ingrese la linea de texto: ");
    fgets(fra, sizeof(fra), stdin);

    // Elimina el salto de línea al final de la cadena si existe
    size_t len = strlen(fra);
    if (len > 0 && fra[len - 1] == '\n') {
        fra[len - 1] = '\0';
    }

    // Invertir la cadena
    inverso(fra);

    printf("La línea de texto en forma inversa es: %s\n", fra);

    return 0;
}

char *inverso(char *cadena)
{
    int i, j;
    char temp;
    int lon = strlen(cadena);

    for (i = 0, j = lon - 1; i < j; i++, j--) {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
    }

    return cadena;
}
