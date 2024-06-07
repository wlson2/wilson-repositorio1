#include <stdio.h>
#include <math.h>

void main(void)
{
float RES;
int R, T, Q;
printf("Ingrese el valor de R: ");
scanf("%d", &R, &T, &Q);
printf("Ingrese el valor de T: ");
scanf("%d", &R, &T, &Q);
printf("Ingrese el valor de Q: ");
scanf("%d", &R, &T, &Q);
RES = pow(R, 4) - pow(T, 3) + 4 * pow(Q, 2);
if (RES < 820)
printf("\nR = %d\tT = %d\t Q = %d", R, T, Q);
}
