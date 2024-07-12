#include <stdio.h>

/* Prototipo de función para calcular la longitud de la cadena de manera recursiva. */
int cuenta(char *cadena);

int main(void)
{
    int longitud;
    char cad[50];
    printf("Ingrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Elimina el salto de línea al final de la cadena si existe
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    longitud = cuenta(cad);
    printf("Longitud de la cadena: %d\n", longitud);

    return 0;
}

int cuenta(char *cadena)
{
    if (cadena[0] == '\0')
        return 0;
    else
        return 1 + cuenta(&cadena[1]);
}
