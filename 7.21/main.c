#include <stdio.h>

int longitud(char *cadena); /* Prototipo de funci�n. */

int main(void)
{
    int i, n, l = -1, p, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el n�mero de filas del arreglo: ");
    scanf("%d", &n);
    getchar();  // Consumir el salto de l�nea residual del scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la l�nea %d de texto. M�ximo 50 caracteres: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Remover el salto de l�nea si es que se qued� en el buffer
        size_t len = longitud(FRA[i]);
        if (FRA[i][len - 1] == '\n')
            FRA[i][len - 1] = '\0';
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        t = longitud(FRA[i]);
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("\nLongitud: %d\n", l);

    return 0;
}

int longitud(char *cadena)
{
    int cue = 0;
    while (cadena[cue] != '\0')
        cue++;
    return cue;
}
