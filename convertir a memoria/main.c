#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a;
    char c;
    float f;
} AL;

void grabarDatos(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    AL *pal;
    char otraEntrada;

    do {
        pal = (AL *) malloc(sizeof(AL));
        if (pal == NULL) {
            perror("Error al asignar memoria");
            fclose(file);
            return;
        }

        printf("\nIngresa un entero: ");
        scanf("%d", &pal->a);
        printf("Ingresa un char: ");
        fflush(stdin);
        pal->c = (char)getchar();
        printf("Ingresa un float: ");
        scanf("%f", &pal->f);

        fwrite(pal, sizeof(AL), 1, file);
        free(pal);

        printf("¿Desea ingresar otro dato? (s/n): ");
        fflush(stdin);
        otraEntrada = getchar();
    } while (otraEntrada == 's' || otraEntrada == 'S');

    fclose(file);
}

void leerDatos(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    AL *pal;
    while (!feof(file)) {
        pal = (AL *) malloc(sizeof(AL));
        if (pal == NULL) {
            perror("Error al asignar memoria");
            fclose(file);
            return;
        }

        if (fread(pal, sizeof(AL), 1, file) == 1) {
            printf("\nValor de a: %d", pal->a);
            printf("\nValor de c: %c", pal->c);
            printf("\nValor de f: %f", pal->f);
        }
        free(pal);
    }

    fclose(file);
}

int main() {
    int opcion;
    const char *filename = "datos.bin";

    do {
        printf("\nMenu:");
        printf("\n0. Salir");
        printf("\n1. Grabar Dato");
        printf("\n2. Leer archivo");
        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 0:
                printf("Saliendo...\n");
                break;
            case 1:
                grabarDatos(filename);
                break;
            case 2:
                leerDatos(filename);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while(opcion != 0);

    return 0;
}

