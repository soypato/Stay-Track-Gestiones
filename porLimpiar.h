#ifndef PORLIMPIAR_H_INCLUDED
#define PORLIMPIAR_H_INCLUDED
// PROTOTIPADO
void menuLimpiar();
void agregarDatosALaPila(Pila *habitacionesPorLimpiar);
void mostrarHabitacionesEnFormatoFIFO(Pila habitacionesPorLimpiar);
void mostrarHabitacionesEnFormatoLIFO(Pila habitacionesPorLimpiar);
void busquedaYEliminacion(Pila *habitacionesPorLimpiar, int numAeliminar, Pila *completadas);
void ordenarHabitacionesNumericamente(Pila *habitacionesPorLimpiar);
void borrarTodasLasHabitaciones(Pila *origen, Pila *destino);


#endif // PORLIMPIAR_H_INCLUDED
