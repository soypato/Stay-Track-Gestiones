#include <stdio.h>
#include <stdlib.h>

#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED

typedef struct
{
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
} tiempo;

int validarFechas();
void mostrarFecha(tiempo fecha);

#endif // TIEMPO_H_INCLUDED
