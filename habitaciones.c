#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "habitaciones.h"
#include "empleados.h"

///HARCHIVOS
const char arcHabitaciones[30] = {"archivoHabitaciones.dat"};
const int numHabitaciones = 2;

//////////////////////////////////////////////////////////////////////////////

///FUNCIONES

void menuHabitaciones()//MENU
{
    int ejercicio;
    strHabitacion hab;
    strHabitacion habitacionesSinOcupar[20];
    strHabitacion habitacionesSinReservas[20];
    strHabitacion habitacionesOcupadas[20];
    strHabitacion habitacionesReservadas[20];
    char opcion[3];
    int numPunto5;
    int subMenuPunto6;
    int opcPunto6;
    int validosPunto6;
    int valorPunto6;
    char decision = 's';

    do
    {
    printf("================================================\n");
    printf("|             Menu habitaciones               |\n");
    printf("================================================\n");
    printf("| Opcion |          Descripcion               |\n");
    printf("================================================\n");
    printf("|   1    |  Cargar una habitacion             |\n");
    printf("|   2    |  Mostrar una habitacion            |\n");
    printf("|   3    |  Cargar habitacion archivo         |\n");
    printf("|   4    |  Mostrar habitacion archivo        |\n");
    printf("|   5    |  Mostrar habitacion por numero     |\n");
    printf("|   6    |  Mostrar no ocupadas/no reservadas |\n");
    printf("|   0    |  Volver al menu administrador      |\n");
    printf("================================================\n");

        printf("Su decision: ");
        fflush(stdin);
        scanf("%i", &ejercicio);
        switch(ejercicio)
        {
        case 1:
            hab=strCargarHabitacion();
            break;
        case 2:
            strMostrarUnaHabitacion(hab);//PUNTO 2
            break;
        case 3:
            arcCargarHabitaciones(arcHabitaciones, opcion);
            break;
        case 4:
            arcMostrarHabitaciones(arcHabitaciones);//PUNTO 4
            break;
        case 5:
            numPunto5=auxBuscarConEntero();
            arcBuscarHabitacionPorNumero(arcHabitaciones, numPunto5);
            break;
        case 6:

            do
            {
                printf("Que desea realizar?\n 1 = mostrar habitaciones no ocupadas.\n 2 = mostrar habitaciones no reservadas.\n 3 = mostrar habitaciones ocupadas.\n 4 = mostrar habitaciones reservadas.\n 0 = volver para atras.\n");
                fflush(stdin);
                scanf("%i", &subMenuPunto6);
                switch(subMenuPunto6)
                {
                case 1:
                    opcPunto6=1;
                    valorPunto6=0;
                    validosPunto6=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesSinOcupar, opcPunto6, valorPunto6);
                    printf("Las habitaciones sin ocupar son:\n");
                    mostrarArregloDeStructs(habitacionesSinOcupar, validosPunto6);
                    break;
                case 2:
                    opcPunto6=2;
                    valorPunto6=0;
                    validosPunto6=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesSinReservas, opcPunto6, valorPunto6);
                    printf("Las habitaciones sin reservar son:\n");
                    mostrarArregloDeStructs(habitacionesSinReservas, validosPunto6);
                    break;
                case 3:
                    opcPunto6=1;
                    valorPunto6=1;
                    validosPunto6=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesOcupadas, opcPunto6, valorPunto6);
                    printf("Las habitaciones ocupadas son:\n");
                    mostrarArregloDeStructs(habitacionesOcupadas, validosPunto6);
                    break;
                case 4:
                    opcPunto6=2;
                    valorPunto6=1;
                    validosPunto6=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesReservadas, opcPunto6, valorPunto6);
                    printf("Las habitaciones reservadas son:\n");
                    mostrarArregloDeStructs(habitacionesReservadas, validosPunto6);
                    break;

                }


            }
            while(subMenuPunto6!=0);
            break;
        case 0:
            menuEmpleados();
            break;
        }
    printf("Seguir ejecutando? (s/n): ");
    fflush(stdin);
    scanf("%c", &decision);
    }
    while(ejercicio!=0);
}


strHabitacion strCargarHabitacion()//PUNTO 1 CARGAR UNA HABITACION
{
    strHabitacion aux;

    printf("La habitacion esta ocupada?0=no,1=si.\n");
    fflush(stdin);
    scanf("%i", &aux.ocupado);

    printf("La habitacion esta reservada?0=no,1=si.\n");
    fflush(stdin);
    scanf("%i", &aux.reservado);


    printf("Ingrese el numero de la habitacion.\n");
    fflush(stdin);
    scanf("%i", &aux.numeroDeHabitacion);

    printf("Ingrese la capacidad de huespedes.\n");
    fflush(stdin);
    scanf("%i", &aux.capacidadDeHuespedes);

    printf("Ingrese la cantidad de baños de la habitacion.\n");
    fflush(stdin);
    scanf("%i", &aux.cantBanios);


    printf("Tiene frigobar?0=no,1=si.\n");
    fflush(stdin);
    scanf("%i", &aux.frigobar);

    printf("Tiene aire acondicionado?0=no,1=si.\n");
    fflush(stdin);
    scanf("%i", &aux.aireAcondicionado);

    aux.habilitada=1;

    return aux;

}
void auxOcupado(strHabitacion aux)//AUX OCUPADO PARA MOSTRAR HABITACIONES
{
    if(aux.ocupado==0)
    {
        printf("La habitacion no esta ocupada.\n");

    }
    else if(aux.ocupado==1)
    {
        printf("La habitacion esta ocupada.\n");
    }
    else
    {
        printf("Error con el estado de la habitacion.\n");
    }
}
void auxHabilitada(strHabitacion aux)//AUX PARA SABER SI LA HABITACION SE ENCUENTRA HABILITADA
{
    if(aux.habilitada==1)
    {
        printf("La habitacion esta habilitada.\n");

    }
    else if(aux.habilitada==0)
    {
        printf("La habitacion no esta habilitada.\n");
    }
    else
    {
        printf("Error con el estado de la habilitacion.\n");
    }
}

void auxReservado(strHabitacion aux)//AUX RESERVADO PARA MOSTRAR HABITACIONES
{
    if(aux.reservado==0)
    {
        printf("La habitacion no esta reservada.\n");

    }
    else if(aux.reservado==1)
    {
        printf("La habitacion esta reservada.\n");
    }
    else
    {
        printf("Error con el estado de la reserva.\n");
    }
}

void auxFrigobar(strHabitacion aux)//AUX FRIGOBAR
{
    if(aux.frigobar==0)
    {
        printf("La habitacion no tiene frigobar.\n");

    }
    else if(aux.frigobar==1)
    {
        printf("La habitacion tiene frigobar.\n");
    }
    else
    {
        printf("Error con la informacion del frigobar.\n");
    }
}

void auxAireAcondicionado(strHabitacion aux)//AUX AIRE ACONDICIONADO PARA MOSTRAR AIRE ACONDICIONADO
{
    if(aux.aireAcondicionado==0)
    {
        printf("La habitacion no tiene aire acondicionado.\n");

    }
    else if(aux.aireAcondicionado==1)
    {
        printf("La habitacion tiene aire acondicionado.\n");
    }
    else
    {
        printf("Error con la informacion del aire acondicionado.\n");
    }
}

/*void auxPrecioHabitaciones(strHabitacion aux)//AUX PRECIO HABITACIONES PARA CALCULAR EL PRECIO DE LAS HABITACIONES
{

    int precioPorPersona= 2500;
    int precioFrigobar=2000;
    int precioPorBanio=700;
    int precioAireAcondicionado=1500;

    int precioHabitacionNoche;

    precioHabitacionNoche=aux.cantBanios*precioPorBanio+aux.capacidadDeHuespedes*precioPorPersona;

    if(aux.aireAcondicionado==1)
    {
        precioHabitacionNoche+=precioAireAcondicionado;
    }
    if(aux.figobar==1)
    {
        precioHabitacionNoche+=precioFrigobar;
    }
printf("precio por noche%i\n", precioHabitacionNoche);
    aux.precio=precioHabitacionNoche;
    printf("aux.precio %i\n",aux.precio);

}



void strMostrarUnaHabitacion(strHabitacion aux)//PUNTO 2 MOSTRAR UNA HABITACION
{


    printf("---------\n");
    printf("La habitacion numero %i\n", aux.numeroDeHabitacion);

    auxOcupado(aux);
    auxReservado(aux);
    auxHabilitada(aux);

    printf("La capacidad de huespedes es: %i\n", aux.capacidadDeHuespedes);

    printf("La cantidad de baños es: %i\n", aux.cantBanios);

    auxFrigobar(aux);

    auxAireAcondicionado(aux);
    auxPrecioHabitaciones(aux);
    printf("El precio de la habitacion por noche es de $%i.\n", aux.precio);




}*/


void auxPrecioHabitaciones(strHabitacion aux) // Corrección: agregar asterisco para pasar por referencia
{
    int precioPorPersona = 2500;
    int precioFrigobar = 2000;
    int precioPorBanio = 700;
    int precioAireAcondicionado = 1500;

    int precioHabitacionNoche;

    precioHabitacionNoche = aux.cantBanios * precioPorBanio + aux.capacidadDeHuespedes * precioPorPersona; // Corrección: utilizar los campos correctos del struct

    if (aux.aireAcondicionado == 1)
    {
        precioHabitacionNoche += precioAireAcondicionado;
    }
    if (aux.frigobar == 1)
    {
        precioHabitacionNoche += precioFrigobar;
    }

    printf("Precio por noche: %i\n", precioHabitacionNoche); // Corrección: imprimir el precio calculado

    aux.precio = precioHabitacionNoche;
    printf("aux.precio: %i\n", aux.precio); // Corrección: imprimir el precio asignado a aux.precio
}

void strMostrarUnaHabitacion(strHabitacion aux)
{
    printf("---------\n");
    printf("La habitacion numero %i\n", aux.numeroDeHabitacion);

    auxOcupado(aux);
    auxReservado(aux);
    auxHabilitada(aux);

    printf("La capacidad de huespedes es: %i\n", aux.capacidadDeHuespedes);

    printf("La cantidad de banios es: %i\n", aux.cantBanios);

    auxFrigobar(aux);

    auxAireAcondicionado(aux);
    auxPrecioHabitaciones(aux); // Corrección: pasar la estructura por referencia

    printf("El precio de la habitacion por noche es de $%i.\n", aux.precio);
}


int auxCargaHabitaciones(char nombreArchi[]) //AUX PARA VERIFICAR SI EL ARCHIVO ESTA CARGADO ANTES DE CARGARLO Y EN BASE A ESO RETORNA QUE HACER CON EL ARCHIVO
{
    int opc;
    FILE* buffer = fopen(nombreArchi, "rb");
    if (buffer)
    {
        printf("Archivo abierto correctamente\n");
        fseek(buffer, 0, SEEK_END); // Mover el puntero de archivo al final
        long fileSize = ftell(buffer); // Obtener el tamaño del archivo
        if(fileSize == 0)
        {

            printf("EL archivo no tiene datos cargados\n");
            opc=0;
        }
        else
        {
            printf("El archivo tiene datos cargados que quiere hacer?\n 0=sobreescribirlo, 1=agregar datos, otro=no hacer nada\n");
            fflush(stdin);
            scanf("%i", &opc);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error abriendo el archivo\n");
    }
    printf("La opcion antes de ir al aux %i\n", opc);
    return opc;
}

int otroAuxDeCargarHabitaciones(int opc, char opcion[])//AUX PARA CARGAR UN ARREGLO CON EL MODO DE ESCRITURA EN EL QUE SE VA A ABRIR EL ARCHIVO
{
    int i;

    if(opc==0)
    {
        strcpy(opcion, "wb");
        i=1;
    }
    else if(opc==1)
    {
        strcpy(opcion, "ab");
        i=1;
    }
    else
    {
        i=0;
    }
    printf("La i: %i\n", i);
    printf("El char es: ");
    puts(opcion);
    return i;
}



void arcCargarHabitaciones(char nombreArchi[], char opcion[])//PUNTO 3 CARGAR HABITACIONES EN ARCHIVO
{
    int opcionCarga;
    int opcionSegundaCarga;

    opcionCarga=auxCargaHabitaciones(nombreArchi);
    opcionSegundaCarga=otroAuxDeCargarHabitaciones(opcionCarga, opcion);


    int i;
    strHabitacion aux;

    if(opcionSegundaCarga==1)
    {
        FILE* buffer = fopen(nombreArchi, opcion);

        if (buffer)
        {
            printf("Abierto\n");

            for(i=0; i<numHabitaciones; i++)
            {

                aux=strCargarHabitacion();
                printf("---------\n");
                fwrite(&aux, sizeof(strHabitacion),1, buffer);
            }
            fclose(buffer);
        }
        else
        {
            printf("Error\n");
        }


    }
    else
    {
        printf("Usted eligio no hacer nada con el archivo\n");
    }



}

void arcMostrarHabitaciones(char nombreArchivo[])//PUNTO 4 MOSTRAR LAS HABITACIONES DE UN ARCHIVO
{
    strHabitacion aux;
    FILE* buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {


        printf("Abierto\n");
        fseek(buffer, 0, SEEK_END); // Mover el puntero de archivo al final
        long fileSize = ftell(buffer); // Obtener el tamaño del archivo
        if(fileSize == 0)
        {
            printf("El archivo no tiene datos cargados\n");
        }
        else
        {
            printf("Entra\n");
            fseek(buffer, 0, SEEK_SET);
            while(fread(&aux, sizeof(strHabitacion), 1, buffer)>0)


            {
                strMostrarUnaHabitacion(aux);
            }


        }




        fclose(buffer);

    }
    else
    {
        printf("Error\n");
    }
}


int auxBuscarConEntero()//AUX CARGAR UN ENTERO PARA USAR COMO PARAMETRO
{
    int num;
    printf("Ingrese el numero de la habitacion.\n");
    fflush(stdin);
    scanf("%i", &num);
    return num;
}

void arcBuscarHabitacionPorNumero(char nombreArchi[], int num)//MOSTRAR UNA HABITACION BUSCADA POR NUMERO DE HABITACION
{
    strHabitacion aux;
    FILE* buffer = fopen(nombreArchi, "rb");
    if (buffer)
    {

        printf("Abierto\n");


        while((fread(&aux, sizeof(strHabitacion), 1, buffer))>0)
        {
            if(aux.numeroDeHabitacion==num)
            {
                strMostrarUnaHabitacion(aux);
            }
        }
        if(feof(buffer)!=0)
        {
            printf("No se encontro la habitacion.\n");
        }



        fclose(buffer);
    }
    else
    {
        printf("Error\n");
    }
}


void mostrarArregloDeStructs(strHabitacion A[], int validos)//MOSTRAR ARREGLO DE STRUCTS
{

    for(int i=0; i<validos; i++)
    {
        strMostrarUnaHabitacion(A[i]);
    }

}

strHabitacion auxBuscarHabitacionesNoOcupadasONoReservadas(strHabitacion aux, int num)//AUX PARA ASIGNAR UN VALOR AL CAMPO PARA PODER PASAR UN ARREGLO SEGUN LO SOLICITADO
{
    strHabitacion resultado;
    if(num==1)
    {
        resultado = aux;
        resultado.opcionPunto6=aux.ocupado;
    }
    else if(num==2)
    {
        resultado = aux;
        resultado.opcionPunto6=aux.reservado;
    }

    return resultado;
}


int arcBuscarHabitacionesNoOcupadasONoReservadas(char nombreArchi[], strHabitacion A[], int num, int numero)//PASAR LAS HABITACIONES QUE SE SOLICITEN A UN ARREGLO
{
    int i=0;
    strHabitacion aux;
    FILE* buffer = fopen(nombreArchi, "rb");
    if(buffer)
    {

        printf("Abierto\n");



        while((fread(&aux, sizeof(strHabitacion), 1, buffer))>0)
        {
            strHabitacion resultado = auxBuscarHabitacionesNoOcupadasONoReservadas(aux, num);
            if(resultado.opcionPunto6==numero)
            {
                A[i]=resultado;
                i++;

            }
        }

        fclose(buffer);
    }
    else
    {
        printf("Error\n");
    }



    return i;
}

void arcModificarUnCampoDeUnaHabitacion(int num, char nombreArchi[])
{




}




