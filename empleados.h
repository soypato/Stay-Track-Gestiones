#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "tiempo.h"

typedef struct {
    char nombreyApellido[35];
    int edad;
    char genero[20];
    int telefono;
    int dni;
    char correo[30];
    char nacionalidad[20];
    char oficio[20];
    tiempo fechaAlta;
    tiempo fechaBaja;
    int bajaPasiva;
} stEmpleado;



///PROTOTIPADOS///
stEmpleado alta1Empleado();
int altaEmpleados(stEmpleado A[], int dimension, int DNITemporal);
void listar1Empleado (stEmpleado A);
void listarEmpleados(stEmpleado A[], int validos);
void cargar1EmpleadoEnArchivo(stEmpleado A, const char *nombreArchivo);
void mostrarArchivo(char nombreArchivo[], int validos);
void modificarEmpleadoEnArchivo (char nombreArchivo[]);
void bajaEmpleado (char nombreArchivo[], int validos);
void buscarEmpleadoPorDNI(char nombreArchivo[], int dniBuscado);
void mostrarEmpleadosDadosDeBaja(const char* nombreArchivo);
void reactivarEmpleado(const char* nombreArchivo);
void mostrarEmpleadosOrdenadosPorEdad(const char* nombreArchivo);
void mostrarEmpleadosOrdenadosPorNombre(const char* nombreArchivo);
stEmpleado buscarEnDni(int dniOrigen, const char archivo[]);

#endif // EMPLEADOS_H_INCLUDED
