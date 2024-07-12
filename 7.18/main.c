#include <stdio.h>

/* Prototipo de función para invertir la cadena de forma recursiva. */
void inverso(char *cadena);

int main(void)
{
    char fra[50];
    printf("Ingrese la línea de texto: ");
    fgets(fra, sizeof(fra), stdin);

    // Elimina el salto de línea al final de la cadena si existe
    size_t len = strlen(fra);
    if (len > 0 && fra[len - 1] == '\n') {
        fra[len - 1] = '\0';
    }

    printf("Escribe la línea de texto en forma inversa: ");
    inverso(fra);
    printf("\n");

    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0') {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
