#include <stdio.h>
#include <string.h>

/* Definición de las estructuras */
typedef struct {
    char mat[20];  // Materia
    int pro;       // Promedio
} matpro;

typedef struct {
    int matri;        // Matrícula
    char nom[20];     // Nombre del alumno
    matpro cal[5];    // Calificaciones de hasta 5 materias
} alumno;

/* Prototipos de funciones */
void Lectura(alumno *, int);
void F1(alumno *, int);
void F2(alumno *, int);
void F3(alumno *, int);

void main(void) {
    alumno ALU[50];  // Arreglo de alumnos
    int TAM;

    // Solicitar al usuario el tamaño del arreglo de alumnos
    do {
        printf("Ingrese el tamano del arreglo (maximo 50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    // Llenar el arreglo de alumnos con la información ingresada por el usuario
    Lectura(ALU, TAM);

    // Llamar a las funciones para realizar las operaciones requeridas
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);
}

void Lectura(alumno A[], int T) {
    int I, J;

    // Leer la información de cada alumno y sus materias
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d:\n", I + 1);
        printf("Matrícula del alumno: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);

        printf("Nombre del alumno: ");
        gets(A[I].nom);
        fflush(stdin);

        for (J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            fflush(stdin);
            gets(A[I].cal[J].mat);

            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T) {
    int I, J;
    float SUM;

    // Calcular el promedio general de cada alumno
    for (I = 0; I < T; I++) {
        printf("\nMatrícula del alumno: %d", A[I].matri);
        SUM = 0.0;

        for (J = 0; J < 5; J++) {
            SUM += A[I].cal[J].pro;
        }

        SUM /= 5; // Calcular el promedio dividiendo entre el número de materias
        printf("\tPromedio: %.2f", SUM);
    }
}

void F2(alumno A[], int T) {
    int I;

    // Mostrar las matrículas de los alumnos con calificación mayor a 9 en la tercera materia
    printf("\nAlumnos con calificación mayor a 9 en la tercera materia:\n");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9) {
            printf("Matrícula del alumno: %d\n", A[I].matri);
        }
    }
}

void F3(alumno A[], int T) {
    int I;
    float SUM = 0.0;

    // Calcular el promedio general de la cuarta materia
    for (I = 0; I < T; I++) {
        SUM += A[I].cal[3].pro;
    }

    SUM /= T; // Calcular el promedio dividiendo entre el número de alumnos
    printf("\nPromedio de la cuarta materia: %.2f", SUM);
}
