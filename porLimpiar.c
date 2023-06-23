#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
#include "porLimpiar.h"
#include "tipoUsuario.h"
// MENU DE LIMPIEZA
void menuLimpieza()
{
    int numAeliminar;
    Pila habitacionesPorLimpiar;
    inicpila(&habitacionesPorLimpiar);
    Pila completadas;
    inicpila(&completadas);
    char decision;
    int eleccion;
    do
    {
        printf("Advertencia: al final del dia, los datos seran borrados.\n");
        printf("=======================================================|\n");
        printf("|                   Menu limpieza                      |\n");
        printf("=======================================================|\n");
        printf("| Opcion |            Descripcion                      |\n");
        printf("=======================================================|\n");
        printf("|   1    | Agregar habitacion                          |\n");
        printf("|   2    | Eliminar habitacion                         |\n");
        printf("|   3    | Mostrar habitaciones (menos a mas reciente) |\n");
        printf("|   4    | Mostrar habitaciones (mas a menos reciente) |\n");
        printf("|   5    | Ordenar habitaciones numericamente          |\n");
        printf("|   6    | Completar el dia borrando todas las hab.    |\n");
        printf("|   7    | Ver todas las completadas.                  |\n");
        printf("|   0    | Volver                                      |\n");
        printf("=======================================================|\n");

        printf("Su decision: ");
        scanf("%i", &eleccion);
        switch (eleccion)
        {
        case 1:
            agregarDatosALaPila(&habitacionesPorLimpiar);
            break;
        case 2:
            printf("Introduzca la habitacion que ya se completo: ");
            scanf("%i", &numAeliminar);
            busquedaYEliminacion(&habitacionesPorLimpiar, numAeliminar, &completadas);
            break;
        case 3:
            mostrarHabitacionesEnFormatoFIFO(habitacionesPorLimpiar);
            break;
        case 4:
            mostrarHabitacionesEnFormatoLIFO(habitacionesPorLimpiar);
            break;
        case 5:
            ordenarHabitacionesNumericamente(&habitacionesPorLimpiar);
            printf("Pila ordenada numéricamente:");
            mostrar(&habitacionesPorLimpiar);
            break;
        case 6:
            borrarTodasLasHabitaciones(&habitacionesPorLimpiar, &completadas);
            printf("Hemos borrado todas las habitaciones.\n");
            break;
        case 7:
            mostrar(&completadas);
            break;
        case 0:
            volverDependiendoTipoUsuario(tipoUsuario);
            break;
        default:
            printf("La opción es incorrecta.\n");
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's');
}

// AGREGAMOS DATOS A LA PILA
void agregarDatosALaPila(Pila *habitacionesPorLimpiar)
{
    printf("Vamos a cargar una nueva habitación.\n");
    leer(habitacionesPorLimpiar);
    printf("La habitación se ha cargado correctamente.\n");
}
/* función de mostrar habitaciones en first in first out, invertimos los datos pasando a una pila
dada vuelta */
/* no usamos punteros porque no interesa que los datos de invertida se
pierdan si solo son para muestreo */
void mostrarHabitacionesEnFormatoFIFO(Pila habitacionesPorLimpiar)
{
    Pila pilaInvertida;
    inicpila(&pilaInvertida);

    while (!pilavacia(&habitacionesPorLimpiar))
    {
        apilar(&pilaInvertida, desapilar(&habitacionesPorLimpiar));
    }

    printf("Mas recientes - Menos recientes");
    mostrar(&pilaInvertida);
}
// mostramos en formato predeterminado de pila.h la pila
void mostrarHabitacionesEnFormatoLIFO(Pila habitacionesPorLimpiar)
{
    printf("Menos recientes - Mas recientes");
    mostrar(&habitacionesPorLimpiar);
}
// buscamos y eliminamos alguna habitación, función basada en la teoría de la unidad 1
void busquedaYEliminacion(Pila *habitacionesPorLimpiar, int numAeliminar, Pila *completadas)
{
    Pila aux, descarte;
    inicpila(&descarte);
    inicpila(&aux);

    while (!pilavacia(habitacionesPorLimpiar))
    {
        if (tope(habitacionesPorLimpiar) == numAeliminar)
        {
            apilar(&descarte, desapilar(habitacionesPorLimpiar));
        }
        else
        {
            apilar(&aux, desapilar(habitacionesPorLimpiar));
        }
    }

    while (!pilavacia(&aux))
    {
        apilar(habitacionesPorLimpiar, desapilar(&aux));
    }

    printf("\nAsí ha quedado la pila:");
    mostrar(habitacionesPorLimpiar);
    printf("\nEsta fue eliminada:");
    mostrar(&descarte);
    apilar(completadas, desapilar(&descarte));
}
// ordenamiento de pilas numéricamente
void ordenarHabitacionesNumericamente(Pila *habitacionesPorLimpiar)
{
    Pila pilaAux;
    inicpila(&pilaAux);

    while (!pilavacia(habitacionesPorLimpiar))
    {
        int menor = tope(habitacionesPorLimpiar);
        Pila pilaMenores;
        inicpila(&pilaMenores);

        while (!pilavacia(habitacionesPorLimpiar))
        {
            int valor = desapilar(habitacionesPorLimpiar);
            if (valor < menor)
            {
                apilar(&pilaMenores, menor);
                menor = valor;
            }
            else
            {
                apilar(&pilaMenores, valor);
            }
        }

        apilar(&pilaAux, menor);

        while (!pilavacia(&pilaMenores))
        {
            apilar(habitacionesPorLimpiar, desapilar(&pilaMenores));
        }
    }

    while (!pilavacia(&pilaAux))
    {
        apilar(habitacionesPorLimpiar, desapilar(&pilaAux));
    }

    printf("\nPila ordenada numéricamente:");
    mostrar(habitacionesPorLimpiar);
}
// borramos todas desapilandolas
// no hace falta mandarla a una pila diferente
void borrarTodasLasHabitaciones(Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

