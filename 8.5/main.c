#include <stdio.h>
#include <string.h>

// Declaración de la unión datos
union datos {
    char celular[15];
    char correo[20];
};

// Declaración de la estructura alumno utilizando typedef
typedef struct {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales; // Campo de la estructura que es una unión
} alumno;

// Prototipo de la función para leer los datos de un alumno
void Lectura(alumno *a);

int main(void) {
    // Declaración e inicialización de alumnos
    alumno a1 = {120, "María", "Contabilidad", 8.9, {"5-158-40-50"}};
    alumno a2, a3;

    // Ingreso de datos para el alumno a2 desde el usuario
    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electrónico: ");
    gets(a2.personales.correo); // Asignación al campo correo de la unión datos

    // Llamada a función para ingresar datos del alumno a3
    printf("Alumno 3\n");
    Lectura(&a3);

    // Impresión de resultados
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); // Imprime el contenido del campo celular
    // puts(a1.personales.correo); // Intentar imprimir correo causa basura

    // Modificación del campo correo de la unión datos en a1
    strcpy(a1.personales.correo, "hgimenez@hotmail.com");

    // Imprimir después de asignar un valor al campo correo
    puts(a1.personales.celular); // Imprime basura
    puts(a1.personales.correo);  // Imprime el nuevo correo asignado

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular); // Imprime basura
    puts(a2.personales.correo);  // Imprime el contenido del campo correo

    // Ingresar teléfono celular para a2
    printf("Ingrese el teléfono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular); // Asignación al campo celular de la unión datos
    puts(a2.personales.celular); // Imprime el celular ingresado
    // puts(a2.personales.correo); // Intentar imprimir correo causa basura

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular); // Imprime basura
    puts(a3.personales.correo);  // Imprime basura

    return 0;
}

// Implementación de la función Lectura para ingresar datos de un alumno
void Lectura(alumno *a) {
    printf("Ingrese la matrícula del alumno: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera del alumno: ");
    gets(a->carrera);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese el teléfono celular del alumno: ");
    gets(a->personales.celular); // Asignación al campo celular de la unión datos
}
