#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Prototipo de funci�n. */
int cuentaPalabras(char *cadena);

int main(void)
{
    char fra[50];
    printf("Ingrese la l�nea de texto: ");
    fgets(fra, sizeof(fra), stdin);

    // Elimina el salto de l�nea al final de la cadena si existe
    size_t len = strlen(fra);
    if (len > 0 && fra[len - 1] == '\n') {
        fra[len - 1] = '\0';
    }

    int numPalabras = cuentaPalabras(fra);
    printf("\nLa l�nea de texto tiene %d palabras\n", numPalabras);

    return 0;
}

int cuentaPalabras(char *cadena)
{
    int enPalabra = 0;
    int contadorPalabras = 0;

    while (*cadena != '\0') {
        if (isspace((unsigned char)*cadena)) {
            enPalabra = 0;
        } else if (!enPalabra) {
            enPalabra = 1;
            contadorPalabras++;
        }
        cadena++;
    }

    return contadorPalabras;
}
