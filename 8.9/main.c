#include <stdio.h>
#include <string.h>

/* Definición de las estructuras */
typedef struct {
    char zona[20];
    char calle[20];
    char colo[20];   // Colonia
} ubicacion;

typedef struct {
    char clave[5];
    float scu;       // Superficie cubierta
    float ste;       // Superficie terreno
    char car[50];    // Características
    ubicacion ubi;   // Ubicación
    float precio;
    char dispo;      // Disponibilidad (V para venta, R para renta)
} propiedades;

/* Prototipos de funciones */
void Lectura(propiedades *, int);
void F1(propiedades *, int);
void F2(propiedades *, int);

void main(void) {
    propiedades PROPIE[100];  // Arreglo de propiedades
    int TAM;

    // Solicitar al usuario el número de propiedades
    do {
        printf("Ingrese el número de propiedades (máximo 100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    // Llenar el arreglo de propiedades con la información ingresada por el usuario
    Lectura(PROPIE, TAM);

    // Llamar a las funciones para realizar las operaciones requeridas
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}

void Lectura(propiedades A[], int T) {
    int I;

    // Leer la información de cada propiedad
    for (I = 0; I < T; I++) {
        printf("\nIngrese datos de la propiedad %d", I + 1);
        printf("\nClave: ");
        fflush(stdin);
        gets(A[I].clave);
        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        printf("Características: ");
        fflush(stdin);
        gets(A[I].car);
        printf("\tZona: ");
        fflush(stdin);
        gets(A[I].ubi.zona);
        printf("\tCalle: ");
        fflush(stdin);
        gets(A[I].ubi.calle);
        printf("\tColonia: ");
        fflush(stdin);
        gets(A[I].ubi.colo);
        printf("Precio: ");
        scanf("%f", &A[I].precio);
        printf("Disponibilidad (Venta-V Renta-R): ");
        fflush(stdin);
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T) {
    int I;

    printf("\nListado de Propiedades para Venta en Miraflores");
    printf("\n------------------------------------------------");

    // Mostrar propiedades disponibles para venta en Miraflores entre 450,000 y 650,000 soles
    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0)) {
            if ((A[I].precio >= 450000) && (A[I].precio <= 650000)) {
                printf("\nClave de la propiedad: %s", A[I].clave);
                printf("\nSuperficie cubierta: %.2f", A[I].scu);
                printf("\nSuperficie terreno: %.2f", A[I].ste);
                printf("\nCaracterísticas: %s", A[I].car);
                printf("\nCalle: %s", A[I].ubi.calle);
                printf("\nColonia: %s", A[I].ubi.colo);
                printf("\nPrecio: %.2f\n", A[I].precio);
            }
        }
    }
}

void F2(propiedades A[], int T) {
    int I;
    float li, ls;
    char zon[20];

    printf("\nListado de Propiedades para Renta");
    printf("\n--------------------------------");

    // Solicitar la zona geográfica y el rango de precio para las propiedades en renta
    printf("\nIngrese zona geográfica: ");
    fflush(stdin);
    gets(zon);
    printf("Ingrese el límite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el límite superior del precio: ");
    scanf("%f", &ls);

    // Mostrar propiedades disponibles para renta en la zona y rango de precio especificados
    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0)) {
            if ((A[I].precio >= li) && (A[I].precio <= ls)) {
                printf("\nClave de la propiedad: %s", A[I].clave);
                printf("\nSuperficie cubierta: %.2f", A[I].scu);
                printf("\nSuperficie terreno: %.2f", A[I].ste);
                printf("\nCaracterísticas: %s", A[I].car);
                printf("\nCalle: %s", A[I].ubi.calle);
                printf("\nColonia: %s", A[I].ubi.colo);
                printf("\nPrecio: %.2f\n", A[I].precio);
            }
        }
    }
}
