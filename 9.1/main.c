#include <stdio.h>
#include <stdlib.h>

void escribirArchivo(const char *nombreArchivo) {
    // Abrir el archivo para escritura
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        exit(EXIT_FAILURE);
    }

    // Escribir caracteres en el archivo
    const char *texto = "Hola, mundo!";
    const char *ptr = texto;
    while (*ptr != '\0') {
        // Usar fputc para escribir el carácter en el archivo
        fputc(*ptr, archivo);
        ptr++;
    }

    // Cerrar el archivo
    fclose(archivo);
}

void leerArchivo(const char *nombreArchivo) {
    // Abrir el archivo para lectura
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para lectura");
        exit(EXIT_FAILURE);
    }

    // Leer caracteres del archivo y mostrarlos en pantalla
    int caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
        // Usar putc para escribir el carácter en la salida estándar
        putc(caracter, stdout);
    }

    // Cerrar el archivo
    fclose(archivo);
}

int main() {
    const char *nombreArchivo = "archivo.txt";

    // Escribir en el archivo
    escribirArchivo(nombreArchivo);

    // Leer del archivo
    printf("Contenido del archivo:\n");
    leerArchivo(nombreArchivo);

    return 0;
}
