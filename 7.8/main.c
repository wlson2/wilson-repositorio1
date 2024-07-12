#include <stdio.h>
#include <ctype.h>

#define N 20
#define M 50

/* Funci�n para contar min�sculas y may�sculas en una cadena */
void minymay(char *cadena) {
    int i = 0, minusc = 0, mayusc = 0;

    while (cadena[i] != '\0') {
        if (islower(cadena[i])) {
            minusc++;
        } else if (isupper(cadena[i])) {
            mayusc++;
        }
        i++;
    }

    printf("\nN�mero de letras min�sculas en la cadena \"%s\": %d", cadena, minusc);
    printf("\nN�mero de letras may�sculas en la cadena \"%s\": %d\n", cadena, mayusc);
}

int main(void) {
    char FRA[N][M];
    int n, i;

    printf("Ingrese el n�mero de filas del arreglo (1 <= N <= 20): ");
    scanf("%d", &n);

    if (n < 1 || n > N) {
        printf("N�mero de filas fuera del rango permitido.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Ingrese la l�nea %d de texto (m�ximo %d caracteres): ", i + 1, M - 1);
        fflush(stdin); // Limpiar el buffer de entrada
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Reemplazar el salto de l�nea al final de la cadena con terminador nulo
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\nResultados:\n");

    for (i = 0; i < n; i++) {
        minymay(FRA[i]);
    }

    return 0;
}
