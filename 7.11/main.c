#include <stdio.h>
#include <ctype.h>

/* Verifica si el carácter en la posición dada es una letra minúscula.
El programa, al recibir como datos una cadena de caracteres y una posición específica en la cadena,
determina si el caracter correspondiente es una letra minúscula. */
int main(void)
{
    char p, cad[50];
    int n;

    printf("Ingrese la cadena de caracteres (maximo 50): ");
    fgets(cad, sizeof(cad), stdin);

    printf("Ingrese la posición en la cadena que desea verificar: ");
    scanf("%d", &n);

    if (n >= 0 && n < 50 && cad[n] != '\0') {
        p = cad[n];
        if (islower(p)) {
            printf("%c es una letra minúscula\n", p);
        } else {
            printf("%c no es una letra minúscula\n", p);
        }
    } else {
        printf("El valor ingresado de n es incorrecto o la cadena no tiene suficientes caracteres.\n");
    }

    return 0;
}
