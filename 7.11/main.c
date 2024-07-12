#include <stdio.h>
#include <ctype.h>

/* Verifica si el car�cter en la posici�n dada es una letra min�scula.
El programa, al recibir como datos una cadena de caracteres y una posici�n espec�fica en la cadena,
determina si el caracter correspondiente es una letra min�scula. */
int main(void)
{
    char p, cad[50];
    int n;

    printf("Ingrese la cadena de caracteres (maximo 50): ");
    fgets(cad, sizeof(cad), stdin);

    printf("Ingrese la posici�n en la cadena que desea verificar: ");
    scanf("%d", &n);

    if (n >= 0 && n < 50 && cad[n] != '\0') {
        p = cad[n];
        if (islower(p)) {
            printf("%c es una letra min�scula\n", p);
        } else {
            printf("%c no es una letra min�scula\n", p);
        }
    } else {
        printf("El valor ingresado de n es incorrecto o la cadena no tiene suficientes caracteres.\n");
    }

    return 0;
}
