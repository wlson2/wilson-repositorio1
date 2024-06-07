#include <stdio.h>
#include <math.h>

void main(void)
{
int T, P, N;
printf("Ingrese el valor de T: ");
scanf("%d", &T);
printf("Ingrese el valor de  P: ");
scanf("%d", &P);
printf("Ingrese el valor de N: ");
scanf("%d", &N);
if (P != 0)
{
if (pow(T / P, N) == (pow(T, N) / pow(P, N)))
printf("\nSe comprueba la igualdad");
else
printf("\nNo se comprueba la igualdad");
}
else
printf("\nP tiene que ser diferente de cero");
}
