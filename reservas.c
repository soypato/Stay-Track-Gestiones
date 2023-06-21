#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include "reservas.h"
#include "preguntarDNI.h"

const char arHuespedes[] = "datosPersonas.dat";

int menuReservas()
{
    int op = 0;
    char decision = 's';
    int dniTmp = 0;
    int decisionDeBusqueda = 0;
    huesped temporalDeDNI;

    do
    {
        printf("==========================================\n");
        printf("|              Menu reservas               |\n");
        printf("==========================================\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("===========================================\n");
        printf("|   1    | Nuevo cliente y reserva         |\n");
        printf("|   2    | Activar reserva (check-in)      |\n");
        printf("|   3    | Cerrar reserva (check-out)      |\n");
        printf("|   4    | Buscar cliente por DNI          |\n");
        printf("|   5    | Mostrar todos los clientes      |\n");
        printf("|   6    | Eliminar cliente                |\n");
        printf("|   7    | Restaurar cliente eliminado     |\n");
        printf("|   8    | Filtrar clientes en alta        |\n");
        printf("|   9    | Filtrar clientes dados de baja  |\n");
        printf("|   10   | Filtrar clientes en el hotel    |\n");
        printf("|   11   | Filtrar fuera del hotel         |\n");
        printf("|   12   | Modificar cliente               |\n");
        printf("|   13   | Filtrar por nombre              |\n"); // INSERCION
        printf("|   14   | Filtrar por edad                |\n"); // SELECCION
        printf("|   0    | Cerrar sesion                   |\n");
        printf("==========================================\n");
        printf("Su decision: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            reservarCliente();
            break;
        case 2:
            cambiarReservaCliente(1);
            break;
        case 3:
            cambiarReservaCliente(0);
            break;
        case 4:
            buscarCliente();
            break;
        case 5:
            mostrarTodasLasReservas();
            break;
        case 6:
            eliminarCliente();
            break;
        case 7:
            restaurarCliente();
            break;
        case 8:
            mostrarReservasSegunEliminacion(0);
            break;
        case 9:
            mostrarReservasSegunEliminacion(1);
            break;
        case 10:
            mostrarPresenciaHotel(1);
            break;
        case 11:
            mostrarPresenciaHotel(0);
            break;
        case 12:
            modificarCliente();
            break;
        case 13:
            filtrarPorNombreAlfabetico();
            printf("Ordenado por nombre correctamente. Marque 5 en el menu para verlo.\n");
            break;
        case 14:
            filtrarPorEdad();
            printf("Ordenado por edad correctamente. Marque 5 en el menu para verlo.\n");
            break;
        case 0:
            inicioSesion();
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's');


    return 0;
}


void reservarCliente()
{
    char decision = 's';
    do
    {
        int dniTmp = preguntarDNI();
        huesped temporalDeDNI = buscarPorDni(dniTmp, arHuespedes);
        if (temporalDeDNI.dni != -1)
        {
            printf("El cliente ya se encuentra en nuestra base de datos:\n");
            mostrarHuesped(temporalDeDNI);
            printf("---\n");
            printf("1- Check-in | 2- Check-out | 3- Eliminar | 4- Restaurar | 0- Atras\n");
            printf("Su decision: \n");
            int decisionDeBusqueda;
            scanf("%i", &decisionDeBusqueda);
            if (decisionDeBusqueda >= 0 && decisionDeBusqueda <= 4)
            {
                opcionesDeBusqueda(decisionDeBusqueda, temporalDeDNI);
            }
        }
        else
        {
            huespedArchi(dniTmp);
        }
        printf("Cargar mas? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);

    }
    while (decision == 's');
    /* Hacemos el while acá y no después en la función porque nos pide el DNI,
    entonces comprobamos siempre ese dato, de forma anterior */
}



void cambiarReservaCliente(int nuevoEstadoReserva)
{
    if(nuevoEstadoReserva == 0)
    {
        printf("\n- CHECK OUT-\n");
    }
    else if(nuevoEstadoReserva == 1)
    {
        printf("\n- CHECK IN-\n");
    }
    int dniTmp = preguntarDNI();
    cambiarReserva(nuevoEstadoReserva, dniTmp);
}

void buscarCliente()
{
    printf("\n- BUSCAR CLIENTE -\n");
    int dniTmp = preguntarDNI();
    huesped temporalDeDNI = buscarPorDni(dniTmp, arHuespedes);
    if (temporalDeDNI.dni != -1)
    {
        mostrarHuesped(temporalDeDNI);
        printf("---\n");
        printf("1- Check-in | 2- Check-out | 3- Eliminar | 4- Restaurar | 0- Atras\n");
        printf("Su decisión: \n");
        int decisionDeBusqueda;
        scanf("%i", &decisionDeBusqueda);
        if (decisionDeBusqueda >= 0 && decisionDeBusqueda <= 4)
        {
            opcionesDeBusqueda(decisionDeBusqueda, temporalDeDNI);
        }
    }
    else
    {
        printf("No hemos encontrado personas registradas con dicho DNI.\n");
    }
}

void eliminarCliente()
{
    printf("\n- ELIMINAR CLIENTE -\n");
    int dniTmp = preguntarDNI();
    eliminarRestaurarCliente(1, dniTmp);
}

void restaurarCliente()
{
    printf("\n- RESTAURAR CLIENTE -\n");
    int dniTmp = preguntarDNI();
    eliminarRestaurarCliente(0, dniTmp);
}

void modificarCliente()
{
    printf("\n- MODIFICAR CLIENTE -\n");
    int dniTmp = preguntarDNI();
    int decisionDeModificarArchivo = 0;
    huesped huespedAModificar = buscarPorDni(dniTmp, arHuespedes);

    if (huespedAModificar.dni == -1)
    {
        printf("La persona no se encontro.\n");
        return; // Regresar al menu principal
    }

    printf("==========================================\n");
    printf("|              Menu modificacion           |\n");
    printf("==========================================\n");
    printf("| Opcion |           Descripcion           |\n");
    printf("==========================================\n");
    printf("|   1    | Cambiar nombre                  |\n");
    printf("|   2    | Cambiar edad                    |\n");
    printf("|   3    | Cambiar telefono                |\n");
    printf("|   4    | Cambiar DNI                     |\n");
    printf("|   5    | Cambiar numero de habitacion    |\n");
    printf("|   6    | Cambiar fecha de entrada        |\n");
    printf("|   7    | Cambiar fecha de salida         |\n");
    printf("|   0    | Volver                          |\n");
    printf("==========================================|\n");
    printf("Para hacer check-in y check-out, \nvuelva al menu anterior.\n");
    printf("Su decision: ");
    scanf("%i", &decisionDeModificarArchivo);
    if(decisionDeModificarArchivo != 0)
    {
        modificacionDeDatos(huespedAModificar, decisionDeModificarArchivo, dniTmp);
    }
}


void mostrarReservasSegunEliminacion(int tipoAMostrar)
{
    mostrarSegunEliminacion(tipoAMostrar);
}

void mostrarPresenciaHotel(int tipoAMostrar)
{
    presenciaHotel(tipoAMostrar);
}

void opcionesDeBusqueda(int decisionDeBusqueda, huesped huespedAManipular)
{
    switch (decisionDeBusqueda)
    {
    case 1: // check-in
        cambiarReserva(1, huespedAManipular.dni);
        break;
    case 2: // check-out
        cambiarReserva(0, huespedAManipular.dni);
        break;
    case 3: // eliminar
        eliminarRestaurarCliente(1, huespedAManipular.dni);
        break;
    case 4: // restaurar
        eliminarRestaurarCliente(0, huespedAManipular.dni);
        break;
    case 0:
        return;
    }
}

huesped cargaDeHuesped(int dniTmp)
// En el caso de que no queramos pasarle por la funcion de DNI, en dniTMP poner = 0;
{
    huesped A;

    printf("Introduzca nombre y apellido: ");
    fflush(stdin);
    gets(A.nombreApellido);

    printf("Ahora la edad: ");
    while (scanf("%i", &A.edad) != 1 || A.edad < 18)
    {
        printf("Edad incorrecta, intente de nuevo (debe ser mayor a 18): ");
        while (getchar() != '\n');  // Limpiar el buffer de entrada
    }

    printf("Introduzca el genero (0 para masculino / 1 para femenino / 2 no especifica): ");
    while (scanf("%i", &A.genero) != 1 || A.genero < 0 || A.genero > 2)
    {
        printf("Opcion incorrecta, intente de nuevo: ");
        while (getchar() != '\n');  // Limpiar el buffer de entrada
    }

    printf("Telefono: ");
    scanf("%i", &A.telefono);

    if(dniTmp == 0) // En el caso de que no tengamos el DNI de una busqueda.
    {
        preguntarDNI();
    }
    else // En el caso de que hayamos preguntado con anterioridad el DNI.
    {
        A.dni = dniTmp;
    }
    printf("Introduzca el numero de habitacion: ");
    scanf("%i", &A.numeroDeHabitacion);

    printf("-- Ahora, cuando va a ingresar al hotel? --\n");
    cargaDeFechas(&A.llegada);
    mostrarFecha(A.llegada);

    printf("-- Ahora, cuando va a salir del hotel? --\n");
    cargaDeFechas(&A.salida);
    mostrarFecha(A.salida);

    A.bajaPasiva = 0; // Cuando se borre, bajaPasiva será 1.
    A.estadoReserva = 0; // Cuando haga check-in, estadoReserva será 1.

    mostrarHuesped(A);
    printf("Cargado correctamente\n");

    return A;
}

void huespedArchi(int dniTmp)
{
    FILE *buffer = fopen(arHuespedes, "ab");
    huesped A;

    if (buffer)
    {
        A = cargaDeHuesped(dniTmp);
        fwrite(&A, sizeof(huesped), 1, buffer);
        fclose(buffer);

    }
    else
    {
        printf("Ocurrio un error con la apertura del archivo.\n");
    }
}

void mostrarHuesped(huesped A)
{
    char impresionGenero[30];
    char impresionBaja[100];
    char impresionReserva[100];

    // Comprobación del género
    if (A.genero == 0)
    {
        strcpy(impresionGenero, "masculino");
    }
    else if (A.genero == 1)
    {
        strcpy(impresionGenero, "femenino");
    }
    else if (A.genero == 2)
    {
        strcpy(impresionGenero, "no especifica");
    }
    else
    {
        strcpy(impresionGenero, "no valido");// Imprimir el valor del género si es inválido
    }

    // Comprobación de la baja pasiva
    if (A.bajaPasiva == 0)
    {
        strcpy(impresionBaja, "el cliente esta activo en la base de datos");
    }
    else if (A.bajaPasiva == 1)
    {
        strcpy(impresionBaja, "el cliente fue eliminado de la base de datos");
    }
    else
    {
        printf("Dato de baja invalido\n");
        return; // Salir de la función si el dato de baja es inválido
    }

    // Comprobación del estado de reserva
    if (A.estadoReserva == 0)
    {
        strcpy(impresionReserva, "no hay check-in activo, no esta en el hotel");
    }
    else if (A.estadoReserva == 1)
    {
        strcpy(impresionReserva, "el cliente tiene check-in, esta en el hotel");
    }
    else
    {
        printf("Dato de reserva invalido\n");
        return; // Salir de la función si el dato de reserva es inválido
    }

    printf("------------------\n");
    printf("Nombre y apellido: %s\n", A.nombreApellido);
    printf("- Genero: %s\n", impresionGenero);
    printf("- Telefono: %i\n", A.telefono);
    printf("- Edad: %i\n", A.edad);
    printf("- DNI: %i\n", A.dni);
    printf("- Habitacion: %i\n", A.numeroDeHabitacion);
    printf("- Fecha de llegada: ");
    mostrarFecha(A.llegada);
    printf("- Fecha de salida: ");
    mostrarFecha(A.salida);
    printf("- Estado de los datos: %s\n", impresionBaja);
    printf("- Estado de reserva: %s\n", impresionReserva);
}

void cambiarReserva(int nuevoEstadoDeReserva, int dniTmp)
{
    // 0 para inactivo, 1 para activo
    FILE *archivo;
    huesped Persona;
    char decision = 's';
    int encontrado = 0;

    archivo = fopen(arHuespedes, "rb+");

    if (archivo)
    {
        while (fread(&Persona, sizeof(huesped), 1, archivo) > 0 && encontrado == 0)
        {

            if (!encontrado)
            {
                printf("No hemos encontrado a la persona.\n");
            }
            if (Persona.dni == dniTmp)
            {
                encontrado = 1;
                mostrarHuesped(Persona);
                printf("\nDesea cambiar el estado de la reserva de esta persona? (s/n): ");
                fflush(stdin);
                scanf(" %c", &decision);

                if (decision == 's')
                {
                    Persona.estadoReserva = nuevoEstadoDeReserva;
                    // Cuando hagamos check-out, se borran los datos de fechas
                    if(nuevoEstadoDeReserva == 0)
                    {
                        Persona.llegada.anio = NULL;
                        Persona.llegada.mes = NULL;
                        Persona.llegada.dia = NULL;
                        Persona.llegada.hora = NULL;
                        Persona.llegada.minuto = NULL;

                        Persona.salida.anio = NULL;
                        Persona.salida.mes = NULL;
                        Persona.salida.dia = NULL;
                        Persona.salida.hora = NULL;
                        Persona.salida.minuto = NULL;

                    }
                    // Retrocedo N cant. de bytes para poder modificar
                    fseek(archivo, -sizeof(huesped), SEEK_CUR);
                    fwrite(&Persona, sizeof(huesped), 1, archivo);
                    printf("El estado de la reserva ha sido cambiado exitosamente.\n");
                }
                break;
            }
        }

        fclose(archivo);

    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

void eliminarRestaurarCliente(int nuevoEstadoDeEliminacion, int dniTmp)
{
    // 0 para inactivo, 1 para activo
    FILE *archivo;
    huesped Persona;
    char decision = 's';
    int encontrado = 0;

    archivo = fopen(arHuespedes, "rb+");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fread(&Persona, sizeof(huesped), 1, archivo) == 1)
    {
        if (Persona.dni == dniTmp)
        {
            encontrado = 1;
            mostrarHuesped(Persona);
            printf("\nDesea cambiar el estado de la eliminacion de esta persona? (s/n): ");
            fflush(stdin);
            scanf(" %c", &decision);

            if (decision == 's')
            {
                Persona.bajaPasiva = nuevoEstadoDeEliminacion;
                // Cuando hagamos check-out, se borran los datos de fechas
                fseek(archivo, -sizeof(huesped), SEEK_CUR);
                fwrite(&Persona, sizeof(huesped), 1, archivo);
                printf("El estado de la eliminacion ha sido cambiado exitosamente.\n");
            }
            break;
        }
    }

    fclose(archivo);

    if (!encontrado)
    {
        printf("No hemos encontrado a la persona.\n");
    }
}

huesped buscarPorDni(int dniOrigen, const char archivo[])
{
    huesped Encontrado;
    Encontrado.dni = -1; // Valor inicial para indicar que no se encontró ningún huésped
    int flag = 0;
    huesped A;

    FILE *buffer = fopen(archivo, "rb");

    if (buffer)
    {
        while (fread(&A, sizeof(huesped), 1, buffer) > 0 && flag == 0)
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

void mostrarTodasLasReservas()
{
    huesped A;
    FILE *buffer = fopen(arHuespedes, "rb");
    int contador = 0;
    if(buffer)
    {
        printf("Se muestran todas las reservas:\n");
        while(fread(&A, sizeof(huesped), 1, buffer) > 0)
        {
            mostrarHuesped(A);
            contador++;
        }
        fclose(buffer);
        printf("(%i elemento/s)\n", contador);
    }
}

void mostrarSegunEliminacion(int tipoAMostrar)
{
    huesped A;
    FILE *buffer = fopen(arHuespedes, "rb");
    int contador = 0;
    if(buffer)
    {
        printf("Se muestran todas las reservas:\n");
        while(fread(&A, sizeof(huesped), 1, buffer) > 0)
        {
            if ((tipoAMostrar == 0 && A.bajaPasiva == 0) ||
                    (tipoAMostrar == 1 && A.bajaPasiva == 1))
            {
                mostrarHuesped(A);
            }
            contador++;
        }
        fclose(buffer);
        printf("(%i elemento/s)\n", contador);
    }
}

void presenciaHotel(int tipoAMostrar)
{
    huesped A;
    FILE *buffer = fopen(arHuespedes, "rb");
    int contador = 0;
    if (buffer)
    {
        printf("Se muestran todas las reservas:\n");
        while (fread(&A, sizeof(huesped), 1, buffer) > 0)
        {
            if ((tipoAMostrar == 0 && A.estadoReserva == 0) ||
                    (tipoAMostrar == 1 && A.estadoReserva == 1))
            {
                mostrarHuesped(A);
            }
        }
        contador++;
        fclose(buffer);
        printf("(%i elemento/s)\n", contador);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

#include <stdio.h>
#include <string.h>

void modificacionDeDatos(huesped huespedAModificar, int eleccionDeCampoAModificar, int dniTmp)
{
    FILE* archivo;
    huesped Persona;
    char decision = 's';
    int encontrado = 0;
    char nombreTemporal[50];
    int numeroTemporal;

    archivo = fopen(arHuespedes, "r+b");

    if (archivo != NULL)
    {
        while (fread(&Persona, sizeof(huesped), 1, archivo) > 0 && encontrado == 0)
        {
            if (Persona.dni == dniTmp)
            {
                encontrado = 1;
                mostrarHuesped(Persona);

                switch (eleccionDeCampoAModificar)
                {
                case 1:
                    printf("Introduce el nuevo nombre y apellido: ");
                    fflush(stdin);
                    fgets(nombreTemporal, sizeof(nombreTemporal), stdin);
                    nombreTemporal[strcspn(nombreTemporal, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                    strncpy(Persona.nombreApellido, nombreTemporal, sizeof(Persona.nombreApellido) - 1);
                    break;

                case 2:
                    printf("Introduce la nueva edad de la persona: ");
                    scanf("%i", &numeroTemporal);
                    Persona.edad = numeroTemporal;
                    break;

                case 3:
                    printf("Introduce el nuevo telefono de la persona: ");
                    scanf("%i", &numeroTemporal);
                    Persona.telefono = numeroTemporal;
                    break;

                case 4:
                    numeroTemporal = preguntarDNI();
                    Persona.dni = numeroTemporal;
                    break;

                case 5:
                    printf("Introduce el numero de habitacion nuevamente: ");
                    scanf("%i", &numeroTemporal);
                    Persona.numeroDeHabitacion = numeroTemporal;
                    break;

                case 6:
                    printf("Fecha de entrada: ");
                    cargaDeFechas(&Persona.llegada);
                    break;

                case 7:
                    printf("Fecha de salida: ");
                    cargaDeFechas(&Persona.salida);
                    break;

                default:
                    printf("Opción no válida.\n");
                    break;
                }

                fseek(archivo, -sizeof(huesped), SEEK_CUR); // Mover el puntero de archivo justo después del registro leído
                fwrite(&Persona, sizeof(huesped), 1, archivo); // Escribir el registro modificado
                fflush(archivo); // Guardar los cambios en el archivo de inmediato
                printf("El estado del cliente ha sido cambiado exitosamente.\n");
            }
        }

        if (encontrado == 0)
        {
            printf("No hemos encontrado a la persona.\n");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}



void intercambio(huesped *a, huesped *b)
{
    huesped temp = *a;
    *a = *b;
    *b = temp;
}

/* Es mucho más óptimo usar con malloc(), realloc() y free() por un tema de que estamos moviendo
estructuras individuales */

void ordenarPorNombreAlfabetico(FILE *archivo)
{
    huesped *huespedes = NULL;
    int numHuespedes = 0;

    huesped registro;
    while (fread(&registro, sizeof(huesped), 1, archivo) == 1)
    {
        numHuespedes++;
        huespedes = realloc(huespedes, numHuespedes * sizeof(huesped));
        huespedes[numHuespedes - 1] = registro;
    }

    for (int i = 1; i < numHuespedes; i++)
    {
        int j = i;
        while (j > 0 && strcmp(huespedes[j].nombreApellido, huespedes[j - 1].nombreApellido) < 0)
        {
            intercambio(&huespedes[j], &huespedes[j - 1]);
            j--;
        }
    }

    fseek(archivo, 0, SEEK_SET);
    for (int i = 0; i < numHuespedes; i++)
    {
        fwrite(&huespedes[i], sizeof(huesped), 1, archivo);
    }

    free(huespedes);
}

void ordenarPorEdad(FILE *archivo)
{
    huesped *huespedes = NULL;
    int numHuespedes = 0;

    huesped registro;
    while (fread(&registro, sizeof(huesped), 1, archivo) == 1)
    {
        numHuespedes++;
        huespedes = realloc(huespedes, numHuespedes * sizeof(huesped));
        huespedes[numHuespedes - 1] = registro;
    }

    for (int i = 0; i < numHuespedes - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < numHuespedes; j++)
        {
            if (huespedes[j].edad < huespedes[minIndex].edad)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            intercambio(&huespedes[i], &huespedes[minIndex]);
        }
    }

    fseek(archivo, 0, SEEK_SET);
    for (int i = 0; i < numHuespedes; i++)
    {
        fwrite(&huespedes[i], sizeof(huesped), 1, archivo);
    }

    free(huespedes);
}

void filtrarPorNombreAlfabetico()
{
    FILE *buffer = fopen(arHuespedes, "rb+");
    if (buffer)
    {
        ordenarPorNombreAlfabetico(buffer);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

int obtenerNumeroHuespedes(FILE* archivo)
{
    int numHuespedes = 0;
    fseek(archivo, 0, SEEK_END);
    long fileSize = ftell(archivo);
    numHuespedes = fileSize / sizeof(huesped);
    return numHuespedes;
}

void filtrarPorEdad()
{
    FILE* archivo = fopen(arHuespedes, "r+b");
    int numHuespedes = obtenerNumeroHuespedes(archivo);

    for (int i = 0; i < numHuespedes - 1; i++)
    {
        int minIndex = i;
        huesped huespedMin;
        fseek(archivo, sizeof(huesped) * minIndex, SEEK_SET);
        fread(&huespedMin, sizeof(huesped), 1, archivo);

        for (int j = i + 1; j < numHuespedes; j++)
        {
            huesped huespedActual;
            fseek(archivo, sizeof(huesped) * j, SEEK_SET);
            fread(&huespedActual, sizeof(huesped), 1, archivo);

            if (huespedActual.edad < huespedMin.edad)
            {
                minIndex = j;
                huespedMin = huespedActual;
            }
        }

        if (minIndex != i)
        {
            huesped huespedActual;
            fseek(archivo, sizeof(huesped) * i, SEEK_SET);
            fread(&huespedActual, sizeof(huesped), 1, archivo);

            fseek(archivo, sizeof(huesped) * minIndex, SEEK_SET);
            fwrite(&huespedActual, sizeof(huesped), 1, archivo);
            fseek(archivo, sizeof(huesped) * i, SEEK_SET);
            fwrite(&huespedMin, sizeof(huesped), 1, archivo);
        }
    }

    fclose(archivo);
}
