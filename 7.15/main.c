#include <stdio.h>
#include <ctype.h>

/* Prototipo de funci�n para decodificar la cadena de caracteres. */
void interpreta(char *cadena);

int main(void)
{
    char cad[50];
    printf("Ingrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Elimina el salto de l�nea al final de la cadena si existe
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    interpreta(cad);

    return 0;
}

void interpreta(char *cadena)
{
    int i = 0, j, k;

    while (cadena[i] != '\0') {
        if (isdigit(cadena[i]) && isalpha(cadena[i + 1])) {
            k = cadena[i] - '0';  // Convertir el car�cter n�mero a entero
            for (j = 0; j < k; j++) {
                putchar(cadena[i + 1]);
            }
            i += 2;  // Saltar el n�mero y la letra
        } else {
            i++;
        }
    }
    printf("\n");
}
