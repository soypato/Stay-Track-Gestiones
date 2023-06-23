#include <stdlib.h>
#include <stdio.h>
// Función que sirve en varias libs de preguntar el DNI
// Decidimos apartarla para que se conecte con varias libs
int preguntarDNI()
{
    int dniTmp;
    printf("Introduce el DNI de la persona: ");

    while (scanf("%i", &dniTmp) != 1)
    {
        printf("Por favor, introduza números. Intente nuevamente: ");
        fflush(stdin);
    }

    return dniTmp;
}

