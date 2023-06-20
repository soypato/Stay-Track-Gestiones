#ifndef HABITACIONES_H_INCLUDED
#define HABITACIONES_H_INCLUDED





///ESTRUCTURAS
typedef struct
{

    int ocupado;
    int reservado;
    int numeroDeHabitacion;
    int capacidadDeHuespedes;
    int figobar;
    int cantBanios;
    int aireAcondicionado;
    int precio;
    int opcionPunto6;
    int habilitada;



} strHabitacion;
///////////////////////////////////////////////////////////////////////////////


///PROTOTIPADOS
strHabitacion strCargarHabitacion();//CARGAR HABITACIONES
void auxOcupado(strHabitacion aux);//AUX OCUPADO
void auxReservado(strHabitacion aux);//AUX RESERVADO
void auxHabilitada(strHabitacion aux);//AUX PARA SABER SI LA HABITACION SE ENCUENTRA HABILITADA
void auxFrigobar(strHabitacion aux);//AUX FRIGOBAR
void auxAireAcondicionado(strHabitacion aux);//AUX AIRE ACONDICIONADO
void auxPrecioHabitaciones(strHabitacion aux);//AUX PRECIO HABITACIONES
void strMostrarUnaHabitacion();//PUNTO 2
int auxCargaHabitaciones(char nombreArchi[]);//AUX CARGAR HABITACIONES
int otroAuxDeCargarHabitaciones(int opc, char opcion[]);//OTRO AUX PARA CARGAR HABITACIONES
void arcCargarHabitaciones(char nombreArchi[], char opcion[]);//PUNTO 3
void arcMostrarHabitaciones(char nombreArchivo[]);//PUNTO 4
int auxBuscarConEntero();//AUX CARGAR UN ENTERO PARA USAR COMO PARAMETRO
void arcBuscarHabitacionPorNumero(char nombreArchi[], int num);//MOSTRAR UNA HABITACION BUSCADA POR NUMERO DE HABITACION
int arcBuscarHabitacionesNoOcupadasONoReservadas(char nombreArchi[], strHabitacion A[], int num, int numero);//PASAR LAS HABITACIONES QUE SE SOLICITEN A UN ARREGLO
void mostrarArregloDeStructs(strHabitacion A[], int validos);//MOSTRAR ARREGLO DE STRUCTS
strHabitacion auxBuscarHabitacionesNoOcupadasONoReservadas(strHabitacion aux, int num);



///////////////////////////////////////////////////////////////////////////////


#endif // HABITACIONES_H_INCLUDED