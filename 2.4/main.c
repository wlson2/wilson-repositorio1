#include <stdio.h>
#include <stdlib.h>

void main(void)
{
float PRE, NPR;

printf("Ingrese el precio del producto: ");
scanf("%f", &PRE);
if (PRE < 1500)
NPR = PRE * 2;
else
NPR = PRE * 1.08;
printf("\nNuevo precio del producto: %8.2f", NPR);
}
