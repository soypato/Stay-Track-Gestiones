#include <stdlib.h>
#include <stdio.h>

int preguntarDNI()
{
    int dniTmp;
    printf("Introduce el DNI de la persona: ");

    while (scanf("%i", &dniTmp) != 1)
    {
        printf("Por favor, introduza n�meros. Intente nuevamente: ");
        fflush(stdin);
    }

    return dniTmp;
}

