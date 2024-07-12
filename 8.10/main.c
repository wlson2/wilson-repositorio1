#include <stdio.h>
#include <string.h>

/* Definición de las estructuras */
typedef struct {
    char noba[10]; /* Nombre del banco. */
    char nucu[10]; /* Número de cuenta. */
} banco;

typedef union {
    banco che; /* Cheque. Campo de tipo estructura banco. */
    banco nomi; /* Cómina. Campo de tipo estructura banco. */
    char venta; /* Ventanilla. */
} fpago;

typedef struct {
    char cnu[20]; /* Calle y número. */
    char col[20]; /* Colonia. */
    char cp[5]; /* Código Postal. */
    char ciu[15]; /* Ciudad. */
} domicilio;

typedef struct {
    int num; /* Número de vendedor. */
    char nom[20]; /* Nombre del vendedor. */
    float ven[12]; /* Ventas del año. Arreglo unidimensional de tipo real. */
    domicilio domi; /* domi es de tipo estructura domicilio. */
    float sal; /* Salario mensual. */
    fpago pago; /* pago es de tipo unión fpago. */
    int cla; /* Clave forma de pago. */
} vendedor;

/* Prototipos de funciones */
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

void main(void) {
    vendedor VENDEDORES[100]; /* Arreglo unidimensional de tipo estructura vendedor. */
    int TAM;

    /* Solicitar al usuario el número de vendedores */
    do {
        printf("Ingrese el número de vendedores (máximo 100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    /* Verificar que el número de elementos del arreglo sea correcto */
    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);
    printf("\n\tFIN DEL PROGRAMA\n");
}

void Lectura(vendedor A[], int T) {
    int I, J;

    /* Leer la información de cada vendedor */
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos del vendedor %d", I + 1);
        printf("\nNúmero de vendedor: ");
        scanf("%d", &A[I].num);
        printf("Nombre del vendedor: ");
        fflush(stdin);
        gets(A[I].nom);
        printf("Ventas del año: \n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }
        printf("Domicilio del vendedor: \n");
        printf("\tCalle y número: ");
        fflush(stdin);
        gets(A[I].domi.cnu);
        printf("\tColonia: ");
        fflush(stdin);
        gets(A[I].domi.col);
        printf("\tCódigo Postal: ");
        fflush(stdin);
        gets(A[I].domi.cp);
        printf("\tCiudad: ");
        fflush(stdin);
        gets(A[I].domi.ciu);
        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);
        printf("Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        switch (A[I].cla) {
            case 1:
                printf("\tNombre del banco: ");
                fflush(stdin);
                gets(A[I].pago.che.noba);
                printf("\tNúmero de cuenta: ");
                fflush(stdin);
                gets(A[I].pago.che.nucu);
                break;
            case 2:
                printf("\tNombre del banco: ");
                fflush(stdin);
                gets(A[I].pago.nomi.noba);
                printf("\tNúmero de cuenta: ");
                fflush(stdin);
                gets(A[I].pago.nomi.nucu);
                break;
            case 3:
                A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T) {
    int I, J;
    float SUM;

    printf("\n\t\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++) {
        printf("\nVendedor: %d", A[I].num);
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        printf("\nVentas: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T) {
    int I, J;
    float SUM;

    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM > 1500000.00) {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNúmero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f",
                   A[I].num, SUM, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T) {
    int I, J;
    float SUM;

    printf("\n\t\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM < 300000.00)
            printf("\nNúmero de empleado: %d\nNombre: %s\nVentas: %.2f",
                   A[I].num, A[I].nom, SUM);
    }
}

void F4(vendedor A[], int T) {
    int I;

    printf("\n\t\tVendedores con Cuenta en el Banco");
    for (I = 0; I < T; I++) {
        if (A[I].cla == 1)
            printf("\nNúmero de vendedor: %d\nBanco: %s\nCuenta: %s",
                   A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
    }
}
