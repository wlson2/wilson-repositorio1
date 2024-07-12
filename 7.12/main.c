#include <stdio.h>
#include <ctype.h>

/* Cuenta letras min�sculas y may�sculas.
El programa, al recibir como dato una frase, determina el n�mero de letras
min�sculas y may�sculas que existen en la frase. */
int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("Ingrese la cadena de caracteres (maximo 50 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Elimina el salto de l�nea al final de la cadena si existe
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

    printf("\nN�mero de letras min�sculas: %d\n", mi);
    printf("N�mero de letras may�sculas: %d\n", ma);

    return 0;
}
