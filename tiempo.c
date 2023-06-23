#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

const char *obtenerNombreMes(int mes)
{
    const char *nombresMeses[] = {
        "ene", "feb", "mar", "abr", "may", "jun",
        "jul", "ago", "sep", "oct", "nov", "dic"};

    if (mes >= 1 && mes <= 12)
    {
        return nombresMeses[mes - 1];
    }
    if (mes == NULL)
    {
        return ", no hay fecha definida"; // cuando se hace, por ejemplo, check-out
    }
    else
    {
        return "mes invalido";
    }
}

void cargaDeFechas(tiempo *A)
{
    printf("Introduzca el dia: ");
    scanf("%i", &(A->dia));

    printf("Introduzca el mes: ");
    scanf("%i", &(A->mes));

    while (A->mes < 1 || A->mes > 12)
    {
        printf("Mes incorrecto, intente de nuevo: ");
        scanf("%i", &(A->mes));
    }

    int maxDias;

    if (A->mes == 2) // Febrero
    {
        maxDias = 28;
    }
    else if (A->mes == 4 || A->mes == 6 || A->mes == 9 || A->mes == 11) // Abril, junio, septiembre, noviembre
    {
        maxDias = 30;
    }
    else // Resto de los meses
    {
        maxDias = 31;
    }

    while (A->dia < 1 || A->dia > maxDias) // calcula los días según el mes
    {
        printf("Dia incorrecto, intente de nuevo (1-%d): ", maxDias);
        scanf("%i", &(A->dia));
    }

    printf("Introduzca el anio: ");
    scanf("%i", &(A->anio));

    const char *nombreMes = obtenerNombreMes(A->mes);
}


void mostrarFecha(tiempo fecha)
{
    printf("Fecha: %d %s. %d\n", fecha.dia, obtenerNombreMes(fecha.mes), fecha.anio);
}
