#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para isdigit()

#define MAX_CADENAS 10
#define MAX_STR_LEN 10

int main(void)
{
    char respuesta;
    char cadenas[MAX_CADENAS][MAX_STR_LEN + 1]; // Arreglo para almacenar las cadenas de máximo 10 caracteres
    int num_cadenas = 0;
    float suma = 0.0;

    printf("Desea ingresar una cadena de caracteres (S/N)? ");
    respuesta = getchar();
    while (toupper(respuesta) == 'S' && num_cadenas < MAX_CADENAS) {
        printf("\nIngrese la cadena de caracteres (máximo %d caracteres): ", MAX_STR_LEN);
        fflush(stdin); // Limpiar el buffer de entrada
        fgets(cadenas[num_cadenas], sizeof(cadenas[num_cadenas]), stdin);

        // Convertir la cadena a un número flotante y sumarlo
        suma += atof(cadenas[num_cadenas]);

        num_cadenas++;

        if (num_cadenas < MAX_CADENAS) {
            printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
            respuesta = getchar();
        }
    }

    // Calcular el promedio
    float promedio = suma / num_cadenas;

    // Mostrar resultados
    printf("\nSuma de los números reales ingresados: %.2f\n", suma);
    printf("Promedio de los números reales ingresados: %.2f\n", promedio);

    return 0;
}
