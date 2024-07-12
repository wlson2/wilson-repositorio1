#include <stdio.h>

/* Función para contar el número de veces que aparece un caracter en una cadena */
int cuenta(char *cad, char car) {
    int i = 0, contador = 0;
    while (cad[i] != '\0') {
        if (cad[i] == car) {
            contador++;
        }
        i++;
    }
    return contador;
}

int main(void) {
    char car, cad[50];
    int resultado;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    printf("Ingrese el caracter que desea contar: ");
    scanf(" %c", &car);

    resultado = cuenta(cad, car);

    printf("\nEl caracter '%c' se encuentra %d veces en la cadena \"%s\"", car, resultado, cad);

    return 0;
}
