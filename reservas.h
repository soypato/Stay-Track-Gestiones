#ifndef RESERVAS_H_INCLUDED
#define RESERVAS_H_INCLUDED


typedef struct
{
    char nombreApellido[50];
    int edad;
    int genero; // 0 para masculino, 1 para femenino, 2 no quiere especificar
    int telefono;
    int dni;
    int numeroDeHabitacion;
    int bajaPasiva;
    int estadoReserva;
    tiempo llegada;
    tiempo salida;
} huesped;


int preguntarDNI();
huesped cargaDeHuesped();
void mostrarHuesped(huesped A);
huesped cargaDeHuesped(int dniTmp);
void cambiarReserva(int nuevoEstadoDeReserva, int dniTmp);
huesped buscarPorDni(int dniOrigen, const char archivo[]);
void mostrarTodasLasReservas();
void clienteConBajaActiva();
void clienteSinBajaActiva();
void mostrarSegunEliminacion(int tipoAMostrar);
void presenciaHotel(int tipoAMostrar);
void opcionesDeBusqueda(int decisionDeBusqueda, huesped huespedAManipular);
void modificarCliente();
void intercambio(huesped *a, huesped *b);
void ordenarPorNombreAlfabetico(FILE *archivo);
void filtrarPorNombreAlfabetico();
void ordenarPorEdad();
int obtenerNumeroHuespedes(FILE* archivo);
const char *obtenerNombreMes(int mes);
int validarFechas();
void mostrarFecha(tiempo fecha);

#endif // RESERVAS_H_INCLUDED
