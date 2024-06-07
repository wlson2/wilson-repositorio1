#include <stdio.h>
#include <stdlib.h>

void main(void)
{
float SAL;
int NIV;
printf("Ingrese el nivel academico del profesor: ");
scanf("%d", &NIV);
printf("Ingrese el salario: ");
scanf("%f", &SAL);
switch(NIV)

{
case 1: SAL = SAL * 1.0100; break;
case 2: SAL = SAL * 1.0150; break;
case 3: SAL = SAL * 1.0200; break;
case 4: SAL = SAL * 1.0300; break;
}
printf("\n\nNivel: %d \tNuevo salario: %8.2f",NIV, SAL);
}
