#include <stdio.h>

/* Prototipo de funci�n para calcular la longitud de la cadena. */
int cuenta(char *cadena);

int main(void)
{
    int longitud;
    char cad[50];
    printf("Ingrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Elimina el salto de l�nea al final de la cadena si existe
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
    int c = 0;
    while (cadena[c] != '\0') {
        c++;
    }
    return c;
}
