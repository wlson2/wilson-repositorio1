#include <stdio.h>
#include <string.h>

// Definici�n de la estructura alumno utilizando typedef
typedef struct {
    int matricula;
    char nombre[30];
    float cal[5]; // Arreglo para almacenar 5 calificaciones
} alumno;

// Prototipos de funciones
void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno A[], int T);

int main(void) {
    alumno ARRE[50]; // Arreglo de alumnos con tama�o m�ximo de 50
    int TAM;

    // Solicitar al usuario el tama�o del arreglo, validando entre 1 y 50
    do {
        printf("Ingrese el tamano del arreglo (entre 1 y 50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    // Llamada a la funci�n para leer los datos de los alumnos
    Lectura(ARRE, TAM);

    // Llamadas a las funciones para realizar operaciones estad�sticas
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);

    return 0;
}

// Funci�n para leer los datos de los alumnos
void Lectura(alumno A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d\n", I + 1);
        printf("Ingrese la matr�cula del alumno: ");
        scanf("%d", &A[I].matricula);
        fflush(stdin);

        printf("Ingrese el nombre del alumno: ");
        fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
        A[I].nombre[strlen(A[I].nombre) - 1] = '\0'; // Eliminar el salto de l�nea

        for (J = 0; J < 5; J++) {
            printf("\tIngrese la calificaci�n %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I].cal[J]);
        }
        fflush(stdin);
    }
}

// Funci�n para obtener la matr�cula y el promedio de cada alumno
void F1(alumno A[], int T) {
    int I, J;
    float SUM, PRO;
    printf("\nMatr�cula del alumno\tPromedio");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 5; J++) {
            SUM += A[I].cal[J];
        }
        PRO = SUM / 5;
        printf("\n%d\t\t\t%.2f", A[I].matricula, PRO);
    }
    printf("\n");
}

// Funci�n para obtener las matr�culas de los alumnos con calificaci�n > 9 en la tercera materia
void F2(alumno A[], int T) {
    int I;
    printf("\nAlumnos con calificaci�n en la tercera materia > 9");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2] > 9) {
            printf("\nMatr�cula del alumno: %d", A[I].matricula);
        }
    }
    printf("\n");
}

// Funci�n para obtener el promedio general del grupo en la materia 4
void F3(alumno A[], int T) {
    int I;
    float SUM = 0.0, PRO;
    for (I = 0; I < T; I++) {
        SUM += A[I].cal[3];
    }
    PRO = SUM / T;
    printf("\nPromedio de la materia 4: %.2f\n", PRO);
}
