#include <stdio.h>
#include <ctype.h>

/* Cuenta letras minúsculas y mayúsculas.
El programa, al recibir como dato una frase, determina el número de letras
minúsculas y mayúsculas que existen en la frase. */
int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("Ingrese la cadena de caracteres (maximo 50 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Elimina el salto de línea al final de la cadena si existe
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    while (cad[i] != '\0') {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }

    printf("\nNúmero de letras minúsculas: %d\n", mi);
    printf("Número de letras mayúsculas: %d\n", ma);

    return 0;
}
