#include <stdio.h>
#include <string.h>

/* Declaración de la estructura producto */
typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

/* Prototipos de funciones */
void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

void main(void) {
    producto INV[100];  // Arreglo unidimensional de tipo estructura producto
    int TAM, OPE;

    // Solicitar al usuario el número de productos (entre 1 y 100)
    do {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    // Llenar el inventario con los datos de los productos
    Lectura(INV, TAM);

    // Menú de operaciones
    printf("\nIngrese operación a realizar:\n");
    printf("\t1 – Ventas\n");
    printf("\t2 – Reabastecimiento\n");
    printf("\t3 - Nuevos Productos\n");
    printf("\t4 – Inventario\n");
    printf("\t0 - Salir\n");
    scanf("%d", &OPE);

    while (OPE != 0) {
        switch (OPE) {
            case 1:
                Ventas(INV, TAM);
                break;
            case 2:
                Reabastecimiento(INV, TAM);
                break;
            case 3:
                Nuevos_Productos(INV, &TAM);
                break;
            case 4:
                Inventario(INV, TAM);
                break;
            default:
                printf("Opción no válida.\n");
        }

        // Solicitar nueva operación al usuario
        printf("\nIngrese operación a realizar:\n");
        printf("\t1 – Ventas\n");
        printf("\t2 – Reabastecimiento\n");
        printf("\t3 - Nuevos Productos\n");
        printf("\t4 – Inventario\n");
        printf("\t0 - Salir\n");
        scanf("%d", &OPE);
    }
}

void Lectura(producto A[], int T) {
    // Leer los datos de cada producto
    for (int i = 0; i < T; i++) {
        printf("\nIngrese información del producto %d\n", i + 1);
        printf("\tClave: ");
        scanf("%d", &A[i].clave);
        fflush(stdin);

        printf("\tNombre: ");
        gets(A[i].nombre);
        fflush(stdin);

        printf("\tPrecio: ");
        scanf("%f", &A[i].precio);

        printf("\tExistencia: ");
        scanf("%d", &A[i].existencia);
    }
}

void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;

    // Iniciar proceso de ventas
    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);

    while (CLA != 0) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);

        // Buscar el producto por su clave
        I = 0;
        while (I < T && A[I].clave != CLA) {
            I++;
        }

        if (I == T) {
            printf("\nLa clave del producto es incorrecta\n");
        } else if (A[I].existencia >= CAN) {
            // Procesar la venta si hay suficiente existencia
            A[I].existencia -= CAN;
            PAR = A[I].precio * CAN;
            TOT += PAR;
        } else {
            // Si no hay suficiente existencia, preguntar al usuario
            printf("\nNo hay suficiente existencia. Solo hay %d unidades.\n", A[I].existencia);
            printf("¿Desea llevar las %d unidades disponibles? (1 - Sí, 0 - No): ", A[I].existencia);
            scanf("%d", &RES);

            if (RES == 1) {
                PAR = A[I].precio * A[I].existencia;
                TOT += PAR;
                A[I].existencia = 0;
            }
        }

        // Solicitar siguiente producto a vender
        printf("\nIngrese clave del producto (0 para salir): ");
        scanf("%d", &CLA);
    }

    // Mostrar total de la venta
    printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I;

    // Iniciar proceso de reabastecimiento
    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);

    while (CLA != 0) {
        // Buscar el producto por su clave
        I = 0;
        while (I < T && A[I].clave != CLA) {
            I++;
        }

        if (I == T) {
            printf("\nLa clave del producto es incorrecta\n");
        } else {
            // Incrementar la existencia del producto
            printf("\tCantidad a reabastecer: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }

        // Solicitar siguiente producto para reabastecer
        printf("\nIngrese clave del producto (0 para salir): ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T) {
    int CLA, I, J;

    // Iniciar proceso de ingreso de nuevos productos
    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);

    while (*T < 100 && CLA != 0) {
        // Buscar posición para insertar el nuevo producto
        I = 0;
        while (I < *T && A[I].clave < CLA) {
            I++;
        }

        if (I < *T && A[I].clave == CLA) {
            printf("\nEl producto ya existe en el inventario\n");
        } else {
            // Desplazar elementos para insertar el nuevo producto
            for (J = *T; J > I; J--) {
                A[J] = A[J - 1];
            }

            // Ingresar los datos del nuevo producto
            A[I].clave = CLA;
            printf("\tNombre: ");
            fflush(stdin);
            gets(A[I].nombre);

            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);

            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);

            (*T)++;
        }

        // Solicitar siguiente clave de producto para ingresar
        printf("\nIngrese clave del producto (0 para salir): ");
        scanf("%d", &CLA);
    }

    if (*T == 100) {
        printf("\nNo hay espacio para ingresar nuevos productos\n");
    }
}

void Inventario(producto A[], int T) {
    // Mostrar el inventario completo
    printf("\nInventario:\n");
    for (int i = 0; i < T; i++) {
        printf("Clave: %d, Nombre: %s, Precio: %.2f, Existencia: %d\n",
                A[i].clave, A[i].nombre, A[i].precio, A[i].existencia);
    }
}
