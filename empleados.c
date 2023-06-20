#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include "empleados.h"
#include <time.h>
#include <unistd.h>
#include "const.h"
#include "preguntarDNI.h"

///ARCHIVOS///
const char empleadosArchivo[]="arEmpleados.dat";




int menuEmpleados()
{
    int opcion;
    stEmpleado A[30];
    stEmpleado temp;
    int validos;
    int DNI;
    int DNITemporal;

    do
    {
        printf("=============================================\n");
        printf(colorAmarillo"|              Menu empleados              |\n"reiniciarColor);
        printf("=============================================\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("=============================================\n");
        printf("|   1    | Alta empleados                  |\n");
        printf("|   2    | Listar empleados                |\n");
        printf("|   3    | Modificar datos                 |\n");
        printf("|   4    | Dar de baja un empleado         |\n");
        printf("|   5    | Buscar empleado por DNI         |\n");
        printf("|   6    | Listar empleados dados de baja  |\n");
        printf("|   7    | Restaurar empleado dado de baja |\n");
        printf("|   8    | Mostrar empleados por edad      |\n");
        printf("|   9    | Mostrar empleados por Nombre    |\n");
        printf("|   0    | Salir                           |\n");
        printf("=============================================\n");
        printf("Su decision: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("\n=== Alta de empleado ===\n");
            DNITemporal = preguntarDNI();
            temp = buscarEnDni(DNITemporal, empleadosArchivo);
            if (temp.dni == -1)
            {
                validos = altaEmpleados(A, 30, DNITemporal);
            }else
            {
                printf("El DNI que ingresaste ya esta cargado en el sistema\n");
                listar1Empleado(temp);
            }
            break;
        case 2:
            printf("\n=== Listar empleados ===\n");
            mostrarArchivo(empleadosArchivo, validos);
            break;
        case 3:
            printf("\n=== Modificar empleado ===\n");
            modificarEmpleadoEnArchivo(empleadosArchivo);
            break;
        case 4:
            printf("\n=== Dar de baja empleado ===\n");
            bajaEmpleado(empleadosArchivo);
            break;
        case 5:
            printf("\n=== Filtrar por DNI ===\n");
            printf("\nIngrese el DNI a filtrar: ");
            scanf("%i", &DNI);
            buscarEmpleadoPorDNI(empleadosArchivo, DNI);
            break;
        case 6:
            printf("\n=== Listar empleados dados de baja ===\n");
            mostrarEmpleadosDadosDeBaja(empleadosArchivo);
            break;
        case 7:
            printf("\n=== Reactivar un empleado dado de baja ===\n");
            reactivarEmpleado(empleadosArchivo);
            break;
        case 8:
            printf("\n=== Filtrar empleados por edad, de menor a mayor ===\n");
            mostrarEmpleadosOrdenadosPorEdad(empleadosArchivo);
            break;
        case 9:
            mostrarEmpleadosOrdenadosPorNombre(empleadosArchivo);
            break;
        case 0:
            printf("\nCerrando programa...\n");
            break;
        default:
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
            break;
        }
    }
    while (opcion != 0);

    return 0;
}


/// FUNCIONES ///
// [Funcion de alta de empleado] //
stEmpleado alta1Empleado(int DNITemporal)
{

    stEmpleado A;
    printf("\n=== Alta Empleado ===\n");
    printf("Ingrese nombre y apellido: \n");
    fflush(stdin);
    gets(A.nombreyApellido);

    printf("\nIngrese la edad: \n");
    scanf("%i", &A.edad);

    printf("\nIngrese el genero: \n");
    fflush(stdin);
    gets(A.genero);

    printf("\nIngrese Numero de telefono: \n");
    scanf("%i", &A.telefono);

    if (DNITemporal == 0)
    {
        printf("\nIngrese Numero de DNI: \n");
        scanf("%i", &A.dni);
    }else
    {
        A.dni = DNITemporal;
    }
    printf("\nIngrese correo electronico: \n");
    fflush(stdin);
    gets(A.correo);

    printf("\nIngrese la nacionalidad: \n");
    fflush(stdin);
    gets(A.nacionalidad);

    printf("\nPuesto de trabajo: \n");
    fflush(stdin);
    gets(A.oficio);

    printf("\nIngrese fecha inicio: \n");
    cargaDeFechas(&A.fechaAlta);
    mostrarFecha(A.fechaAlta);

    A.bajaPasiva = 0;
    return A;
}

// [Carga un empleado en un archivo] //
void cargar1EmpleadoEnArchivo(stEmpleado A, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "ab");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fwrite(&A, sizeof(stEmpleado), 1, archivo);
    fclose(archivo);
}

//[Carga varios empleados en el archivo]//
int altaEmpleados(stEmpleado A[], int dimension, int DNITemporal)
{
    int i = 0;
    char control = 's';

    while (control == 's' && i < dimension)
    {
        A[i] = alta1Empleado(DNITemporal);
        i++;

        printf("\nEmpleado cargado. ¿Quiere cargar otro empleado al sistema? Presione (s/n)\n");
        getchar();

        scanf("%c", &control);

        // Llama a la función cargar1EmpleadoEnArchivo para guardar el empleado en el archivo
        cargar1EmpleadoEnArchivo(A[i-1], "arEmpleados.dat");
    }

    return i;
}


// [Funcion que muestra un empleado] //
void listar1Empleado (stEmpleado A)
{
    printf("\n=== Empleado ===\n");
    printf("Nombre y Apellido: %s\n", A.nombreyApellido);
    printf("Edad: %d\n", A.edad);
    printf("Genero: %s\n", A.genero);
    printf("Telefono: %d\n", A.telefono);
    printf("DNI: %d\n", A.dni);
    printf("Correo electronico: %s\n", A.correo);
    printf("Nacionalidad: %s\n", A.nacionalidad);
    printf("Puesto trabajo: %s\n", A.oficio);
    mostrarFecha(A.fechaAlta);
    printf("\n");

}

// [Funcion de listado de Empleados] //
void listarEmpleados(stEmpleado A[], int validos)
{
    int i;

    for(i=0; i<validos; i++)
    {
        printf("\n=== Listado de Empleados ===\n");
        printf("\n------------ %i ------------\n", i+1);
        listar1Empleado(A[i]);
    }
}


// [Funcion listar empleados desde el archivo] //
void mostrarArchivo(char nombreArchivo[], int validos)
{
    FILE* buffer;
    buffer = fopen(nombreArchivo, "rb");
    stEmpleado aux;
    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            if (aux.bajaPasiva != 1)
            {
                listar1Empleado(aux);
            }
        }
        fclose(buffer);
    }
}


// [Funcion para modificar un empleado del archivo] //
void modificarEmpleadoEnArchivo(char nombreArchivo[]) {
    char nombreBuscado[35];
    int eleccion;
    int decision = 1;
    stEmpleado aux;
    int flag = 0;
    FILE* buffer;
    buffer = fopen(nombreArchivo, "r+b");
    if (buffer != NULL) {
        printf("\n\n Ingrese nombre y apellido a buscar: ");
        fflush(stdin);
        gets(nombreBuscado);
        while (flag == 0 && decision == 1 && fread(&aux, sizeof(stEmpleado), 1, buffer) > 0) {
            if (strcmp(aux.nombreyApellido, nombreBuscado) == 0) {
                flag = 1;
                listar1Empleado(aux);
                printf("=============================================\n");
                printf("|              Menu modificacion           |\n");
                printf("=============================================\n");
                printf("| Opcion |           Descripcion           |\n");
                printf("=============================================\n");
                printf("|   1    | Edad                            |\n");
                printf("|   2    | Genero                          |\n");
                printf("|   3    | Telefono                        |\n");
                printf("|   4    | DNI                             |\n");
                printf("|   5    | Correo Electronico              |\n");
                printf("|   6    | Nacionalidad                    |\n");
                printf("|   7    | Puesto de trabajo               |\n");
                printf("|   8    | Fecha de inicio                 |\n");
                printf("|   0    | Salir                           |\n");
                printf("=============================================\n");
                printf("Su decision: ");
                scanf("%d", &eleccion);
                switch (eleccion) {
                    case 1:
                        printf("Ingrese la nueva edad:\n");
                        scanf("%d", &aux.edad);
                        break;
                    case 2:
                        printf("Ingrese el nuevo genero:\n");
                        fflush(stdin);
                        gets(aux.genero);
                        break;
                    case 3:
                        printf("Ingrese el nuevo telefono:\n");
                        scanf("%d", &aux.telefono);
                        break;
                    case 4:
                        printf("Ingrese el nuevo DNI:\n");
                        scanf("%d", &aux.dni);
                        break;
                    case 5:
                        printf("Ingrese el nuevo correo electronico:\n");
                        fflush(stdin);
                        gets(aux.correo);
                        break;
                    case 6:
                        printf("Ingrese la nueva nacionalidad:\n");
                        fflush(stdin);
                        gets(aux.nacionalidad);
                        break;
                    case 7:
                        printf("Ingrese el nuevo puesto de trabajo:\n");
                        fflush(stdin);
                        gets(aux.oficio);
                        break;
                    case 8:
                        printf("Ingrese la nueva fecha de inicio:\n");
                        cargaDeFechas(&aux.fechaAlta);
                        break;
                    case 0:
                        return;
                    default:
                        printf("La opción es incorrecta.\n");
                        break;
                }
                fseek(buffer, sizeof(stEmpleado) * (-1), SEEK_CUR);
                fwrite(&aux, sizeof(stEmpleado), 1, buffer);
                printf("Empleado actualizado\n");
            }
        }
        if (strcmp(aux.nombreyApellido, nombreBuscado) != 0) {
            printf("El nombre que ingreso no se encuentra en el sistema\n");
        }
        rewind(buffer);
        printf("Quiere modificar otro empleado?\n");
        printf("1- Si\n");
        printf("2- No\n");
        scanf("%d", &decision);
        fclose(buffer);
    }
}


// [Funcion para dar de baja un empleado] //
void bajaEmpleado(char nombreArchivo[])
{
    char nombreBuscado[35];
    int flag = 0;
    int decision = 1;
    stEmpleado aux;
    FILE *buffer;
    buffer = fopen(nombreArchivo, "r+b");
    if (buffer != NULL)
    {
        while (flag == 0 && decision == 1 && fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            printf("\n\nIngrese nombre y apellido a buscar: ");
            fflush(stdin);
            gets(nombreBuscado);
            if (strcmp(aux.nombreyApellido, nombreBuscado) == 0)
            {
                flag = 1;
            }
        }

        if (flag == 1)
        {
            aux.bajaPasiva = 1;
            printf("Ingrese la fecha de baja\n");
            cargaDeFechas(&aux.fechaBaja);
            fseek(buffer, sizeof(stEmpleado) * (-1), SEEK_CUR);
            fwrite(&aux, sizeof(stEmpleado), 1, buffer);
            printf("Empleado dado de baja.\n");
        }
        else
        {
            printf("No se encontró el empleado.\n");
        }

        rewind(buffer);
        printf("Quiere dar de baja otro empleado?\n");
        printf("1- Si\n");
        printf("2- No\n");
        scanf("%d", &decision);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

// [Funcion para buscar un empleado por DNI] //
void buscarEmpleadoPorDNI(char nombreArchivo[], int dniBuscado)
{
    stEmpleado aux;
    FILE* buffer;
    buffer = fopen(nombreArchivo, "rb");
    int encontrado = 0;

    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            if (aux.dni == dniBuscado)
            {
                listar1Empleado(aux);
                encontrado = 1;
                break;
            }
        }

        fclose(buffer);

        if (!encontrado)
        {
            printf("No se encontro ningun empleado con el DNI especificado.\n");
        }
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

// [Funcion para mostrar empleados dados de baja] //
void mostrarEmpleadosDadosDeBaja(const char* nombreArchivo)
{
    FILE* buffer;
    buffer = fopen(nombreArchivo, "rb");
    stEmpleado aux;

    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            if (aux.bajaPasiva == 1)
            {
                listar1Empleado(aux);
            }
        }

        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

// [Funcion para reactivar un exempleado] //
void reactivarEmpleado(const char* nombreArchivo)
{
    mostrarEmpleadosDadosDeBaja(nombreArchivo);

    char nombreBuscado[35];
    int flag = 0;
    int decision = 1;
    stEmpleado aux;
    FILE* buffer;
    buffer = fopen(nombreArchivo, "r+b");

    if (buffer != NULL)
    {
        while (flag == 0 && decision == 1 && fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            printf("\n\nIngrese nombre y apellido a buscar: ");
            fflush(stdin);
            gets(nombreBuscado);
            if (strcmp(aux.nombreyApellido, nombreBuscado) == 0)
            {
                flag = 1;
            }
        }

        if (flag == 1)
        {
            aux.bajaPasiva = 0;
            fseek(buffer, sizeof(stEmpleado) * (-1), SEEK_CUR);
            fwrite(&aux, sizeof(stEmpleado), 1, buffer);
            printf("Empleado reactivado.\n");
        }
        else
        {
            printf("No se encontró el empleado.\n");
        }

        rewind(buffer);
        printf("Quiere reactivar a otro empleado?\n");
        printf("1- Si\n");
        printf("2- No\n");
        scanf("%d", &decision);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

// [Funcion para mostrar empleados por edad] //
void mostrarEmpleadosOrdenadosPorEdad(const char* nombreArchivo)
{
    FILE* buffer;
    buffer = fopen(nombreArchivo, "rb");
    stEmpleado aux;
    stEmpleado empleados[30]; // Array para almacenar los empleados

    int encontrados = 0;

    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            if (aux.bajaPasiva == 0)
            {
                empleados[encontrados] = aux;
                encontrados++;
            }
        }

        fclose(buffer);

        if (encontrados == 0)
        {
            printf("No se encontraron empleados.\n");
        }
        else
        {
            // Ordenar los empleados por edad utilizando el método de inserción
            for (int i = 1; i < encontrados; i++)
            {
                stEmpleado temp = empleados[i];
                int j = i - 1;
                while (j >= 0 && empleados[j].edad > temp.edad)
                {
                    empleados[j + 1] = empleados[j];
                    j--;
                }
                empleados[j + 1] = temp;
            }

            // Mostrar los empleados ordenados por edad
            printf("\n=== Empleados Ordenados por Edad ===\n");
            for (int i = 0; i < encontrados; i++)
            {
                printf("\n------------ %i ------------\n", i + 1);
                listar1Empleado(empleados[i]);
            }
        }
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

// [Funcion para mostrar empleados por N y A] //
void mostrarEmpleadosOrdenadosPorNombre(const char* nombreArchivo)
{
    FILE* buffer;
    buffer = fopen(nombreArchivo, "rb");
    stEmpleado aux;
    stEmpleado empleados[30]; // Array para almacenar los empleados

    int encontrados = 0;

    if (buffer != NULL)
    {
        while (fread(&aux, sizeof(stEmpleado), 1, buffer) > 0)
        {
            if (aux.bajaPasiva == 0)
            {
                // Utilizar el método de inserción para ordenar por nombre y apellido
                int i = encontrados - 1;
                while (i >= 0 && (strcmp(empleados[i].nombreyApellido, aux.nombreyApellido) > 0 ))
                {
                    empleados[i + 1] = empleados[i];
                    i--;
                }
                empleados[i + 1] = aux;

                encontrados++;
            }
        }

        fclose(buffer);

        if (encontrados == 0)
        {
            printf("No se encontraron empleados.\n");
        }
        else
        {
            // Mostrar los empleados ordenados por nombre y apellido
            printf("\n=== Empleados Ordenados por Nombre y Apellido ===\n");
            for (int i = 0; i < encontrados; i++)
            {
                printf("\n------------ %i ------------\n", i + 1);
                listar1Empleado(empleados[i]);
            }
        }
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}


stEmpleado buscarEnDni(int dniOrigen, const char archivo[])
{
    stEmpleado Encontrado;
    Encontrado.dni = -1; // Valor inicial para indicar que no se encontró ningún empleado
    int flag = 0;
    stEmpleado A;

    FILE *buffer = fopen(archivo, "rb");

    if (buffer)
    {
        while (fread(&A, sizeof(stEmpleado), 1, buffer) > 0 && flag == 0)
        {
            if (A.dni == dniOrigen)
            {
                Encontrado = A;
                flag = 1;
            }
        }

        fclose(buffer);
    }
    else
    {
        printf("Ocurrio un error con la apertura del archivo.\n");
    }

    return Encontrado;
}
