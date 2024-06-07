#include <stdio.h>
#include <stdlib.h>

void main(void)
{
int OP, T;
float RES;
printf("Ingrese la opcion del calculo y el valor entero: ");
scanf("%d %d", &OP, &T);
switch(OP)
{
case 1: RES = T / 5;
break;
case 2: RES = pow(T,T);

break;
case 3:
case 4: RES = 6 * T/2;
break;
default: RES = 1;
break;
}
printf("\nResultado: %7.2f", RES);
}
