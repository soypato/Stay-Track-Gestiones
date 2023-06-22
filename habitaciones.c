#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "habitaciones.h"
#include "empleados.h"

///HARCHIVOS
const char arcHabitaciones[30] = {"archivoHabitaciones.dat"};

const int numHabitaciones = 15;
//////////////////////////////////////////////////////////////////////////////////






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
    int numPunto3;
    int auxPunto3;
    int subMenuPunto4;
    int opcPunto4;
    int validosPunto4;
    int valorPunto4;
    int subMenuPunto5;
    int opcPunto5;
    int habBuscarPunto5;
    int auxPunto5;






    char decision = 's';


    do
    {
        printf("=======================================================\n");
        printf("|             Menu habitaciones                      |\n");
        printf("=======================================================\n");
        printf("| Opcion |          Descripcion                      |\n");
        printf("=======================================================\n");
        printf("|   1    |  Cargar habitacion archivo                |\n");
        printf("|   2    |  Mostrar habitacion archivo               |\n");
        printf("|   3    |  Mostrar habitacion por numero            |\n");
        printf("|   4    |  Mostrar por criterio de ocupacion/reserva|\n");
        printf("|   5    |  Modificar un campo a eleccion            |\n");
        printf("|   6    |  Mostrar habitaciones deshabilitadas      |\n");
        printf("|   0    |  Volver al menu de recepcionista          |\n");
        printf("=======================================================\n");

        printf("Su decision: ");
        fflush(stdin);
        scanf("%i", &ejercicio);
        switch(ejercicio)
        {
        case 1:
            arcCargarHabitaciones(arcHabitaciones, opcion);
            break;
        case 2:
            arcMostrarHabitaciones(arcHabitaciones);//PUNTO 4
            break;
        case 3:
            numPunto3=auxBuscarConEntero();
            auxPunto3=arcBuscarHabitacionPorNumero(arcHabitaciones, numPunto3);
            break;
        case 4:
            do
            {
                printf("================================================\n");
                printf("|             Buscar habitacion               |\n");
                printf("================================================\n");
                printf("| Opcion |          Descripcion               |\n");
                printf("================================================\n");
                printf("|   1    |  Mostrar habitaciones no ocupadas  |\n");
                printf("|   2    |  Mostrar habitaciones no reservadas|\n");
                printf("|   3    |  Mostrar habitaciones ocupadas     |\n");
                printf("|   4    |  Mostrar habitaciones reservadas   |\n");
                printf("|   0    |  Volver al menu de habitaciones    |\n");
                printf("================================================\n");
                fflush(stdin);
                scanf("%i", &subMenuPunto4);
                switch(subMenuPunto4)
                {
                case 1:
                    opcPunto4=1;
                    valorPunto4=0;
                    validosPunto4=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesSinOcupar, opcPunto4, valorPunto4);
                    printf("Las habitaciones sin ocupar son:\n");
                    mostrarArregloDeStructs(habitacionesSinOcupar, validosPunto4);
                    break;
                case 2:
                    opcPunto4=2;
                    valorPunto4=0;
                    validosPunto4=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesSinReservas, opcPunto4, valorPunto4);
                    printf("Las habitaciones sin reservar son:\n");
                    mostrarArregloDeStructs(habitacionesSinReservas, validosPunto4);
                    break;
                case 3:
                    opcPunto4=1;
                    valorPunto4=1;
                    validosPunto4=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesOcupadas, opcPunto4, valorPunto4);
                    printf("Las habitaciones ocupadas son:\n");
                    mostrarArregloDeStructs(habitacionesOcupadas, validosPunto4);
                    break;
                case 4:
                    opcPunto4=2;
                    valorPunto4=1;
                    validosPunto4=arcBuscarHabitacionesNoOcupadasONoReservadas(arcHabitaciones, habitacionesReservadas, opcPunto4, valorPunto4);
                    printf("Las habitaciones reservadas son:\n");
                    mostrarArregloDeStructs(habitacionesReservadas, validosPunto4);
                    break;

                }


            }
            while(subMenuPunto4!=0);
            break;
        case 5:
            habBuscarPunto5=auxBuscarConEntero();
            auxPunto5=arcBuscarHabitacionPorNumero(arcHabitaciones, habBuscarPunto5);
            if(auxPunto5==1)
            {
                do
                {
                    printf("================================================\n");
                    printf("|             Menu de modificaciones          |\n");
                    printf("================================================\n");
                    printf("| Opcion |          Descripcion               |\n");
                    printf("================================================\n");
                    printf("|   1    |  Ocupadas                          |\n");
                    printf("|   2    |  Reservadas                        |\n");
                    printf("|   3    |  Habilitadas                       |\n");
                    printf("|   4    |  Cantidad de huespedes             |\n");
                    printf("|   5    |  Numero de habitacion              |\n");
                    printf("|   6    |  Cantidad de ba�os                 |\n");
                    printf("|   7    |  Aire acondicionado                |\n");
                    printf("|   8    |  Frigobar                          |\n");
                    printf("|   0    |  Volver al menu de habitaciones    |\n");
                    printf("================================================\n");
                    fflush(stdin);
                    scanf("%i", &subMenuPunto5);
                    switch(subMenuPunto5)
                    {
                    case 1:
                        opcPunto5=1;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 2:
                        opcPunto5=2;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 3:
                        opcPunto5=3;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 4:
                        opcPunto5=4;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 5:
                        opcPunto5=5;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 6:
                        opcPunto5=6;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 7:
                        opcPunto5=7;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;
                    case 8:
                        opcPunto5=8;
                        arcModificarUnCampoDeUnaHabitacion(habBuscarPunto5, arcHabitaciones, opcPunto5);
                        break;

                    }
                }
                while(subMenuPunto5!=0);
            }
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

strHabitacion strCargarHabitacion() // PUNTO 1: CARGAR UNA HABITACION
{
    strHabitacion aux;

    printf("�La habitacion est� ocupada? (0 = No, 1 = Si): ");
    fflush(stdin);
    scanf("%i", &aux.ocupado);

    printf("�La habitacion est� reservada? (0 = No, 1 = Si): ");
    fflush(stdin);
    scanf("%i", &aux.reservado);

    printf("Ingrese el n�mero de la habitacion: ");
    fflush(stdin);
    scanf("%i", &aux.numeroDeHabitacion);

    printf("Ingrese la capacidad de hu�spedes: ");
    fflush(stdin);
    scanf("%i", &aux.capacidadDeHuespedes);

    printf("Ingrese la cantidad de banios de la habitacion: ");
    fflush(stdin);
    scanf("%i", &aux.cantBanios);

    printf("�Tiene frigobar? (0 = No, 1 = Si) ");
    fflush(stdin);
    scanf("%i", &aux.frigobar);

    printf("�Tiene aire acondicionado? (0 = No, 1 = Si) ");
    fflush(stdin);
    scanf("%i", &aux.aireAcondicionado);

    aux.habilitada = 1;

    printf("La habitacion fue cargada satisfactoriamente. ");

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




void auxPrecioHabitaciones(strHabitacion aux) // Correcci�n: agregar asterisco para pasar por referencia
{
    int precioPorPersona = 2500;
    int precioFrigobar = 2000;
    int precioPorBanio = 700;
    int precioAireAcondicionado = 1500;

    int precioHabitacionNoche;

    precioHabitacionNoche = aux.cantBanios * precioPorBanio + aux.capacidadDeHuespedes * precioPorPersona; // Correcci�n: utilizar los campos correctos del struct

    if (aux.aireAcondicionado == 1)
    {
        precioHabitacionNoche += precioAireAcondicionado;
    }
    if (aux.frigobar == 1)
    {
        precioHabitacionNoche += precioFrigobar;
    }

    printf("Precio por noche: %i\n", precioHabitacionNoche); // Correcci�n: imprimir el precio calculado

    aux.precio = precioHabitacionNoche;
    printf("aux.precio: %i\n", aux.precio); // Correcci�n: imprimir el precio asignado a aux.precio
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
    auxPrecioHabitaciones(aux); // Correcci�n: pasar la estructura por referencia

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
        long fileSize = ftell(buffer); // Obtener el tama�o del archivo
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

void arcMostrarHabitaciones(char nombreArchivo[])
{
    strHabitacion aux;
    FILE* buffer = fopen(nombreArchivo, "rb");

    if (buffer)
    {
        printf("Abierto\n");
        fseek(buffer, 0, SEEK_END); // Mover el puntero de archivo al final
        long fileSize = ftell(buffer); // Obtener el tama�o del archivo
        if (fileSize == 0)
        {
            printf("El archivo no tiene datos cargados\n");
        }
        else
        {
            printf("Entra\n");
            fseek(buffer, 0, SEEK_SET);

            while((fread(&aux, sizeof(strHabitacion), 1, buffer)>0)&&(aux.habilitada==1))



            {
                strMostrarUnaHabitacion(aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
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

int arcBuscarHabitacionPorNumero(const char nombreArchi[], int num)
{
    strHabitacion aux;
    FILE* buffer = fopen(nombreArchi, "rb");
    int i = 0;
    if(buffer)
    {
        printf("Abierto\n");


        while((fread(&aux, sizeof(strHabitacion), 1, buffer))>0)
        {
            if(aux.numeroDeHabitacion==num && aux.habilitada==1)
            {

                strMostrarUnaHabitacion(aux);
                i=1;

                // Se encontr� la habitaci�n, no es necesario seguir buscando
            }
        }

        if(i==0)
        {
            printf("No se encontro la habitacion o no esta habilitada.\n");




        }

        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return i;
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
        resultado.opcionPunto4=aux.ocupado;
    }
    else if(num==2)
    {
        resultado = aux;
        resultado.opcionPunto4=aux.reservado;
    }

    return resultado;
}

int arcBuscarHabitacionesNoOcupadasONoReservadas(char nombreArchi[], strHabitacion A[], int num, int numero)
{
    int i = 0;
    strHabitacion aux;
    FILE* buffer = fopen(nombreArchi, "rb");

    if (buffer)
    {
        printf("Abierto\n");

        while (fread(&aux, sizeof(strHabitacion), 1, buffer) > 0)
        {
            strHabitacion resultado = auxBuscarHabitacionesNoOcupadasONoReservadas(aux, num);

            if(resultado.opcionPunto4==numero && resultado.habilitada==1)
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

void arcModificarUnCampoDeUnaHabitacion(int num, char nombreArchi[], int opc)//FUNCION MODIFICAR UN CAMPO DENTRO DE LA HABITACION
{
    FILE* buffer = fopen(nombreArchi, "r+b");
    int flag=0;
    strHabitacion aux;
    if (buffer)
    {

        while(flag==0 && (fread(&aux, sizeof(strHabitacion), 1, buffer)>0))
        {
            if(num==aux.numeroDeHabitacion)
            {
                flag==1;
            }
        }
        if(flag==1)
        {

            if(opc==1)
            {
                printf("La habitacion esta ocupada?0=no,1=si.\n");
                fflush(stdin);
                scanf("%i", &aux.ocupado);
            }

            else if(opc==2)
            {
                printf("La habitacion esta reservada?0=no,1=si.\n");
                fflush(stdin);
                scanf("%i", &aux.reservado);
            }
            else if(opc==3)
            {
                printf("La habitacion esta habilitada?0=no, 1=si.\n");
                fflush(stdin);
                scanf("%i", &aux.habilitada);

            }


            else if(opc==4)
            {
                printf("Ingrese la capacidad de huespedes.\n");
                fflush(stdin);
                scanf("%i", &aux.capacidadDeHuespedes);
            }

            else if(opc==5)
            {
                printf("Ingrese el numero de la habitacion.\n");
                fflush(stdin);
                scanf("%i", &aux.numeroDeHabitacion);

            }

            else if(opc==6)
            {
                printf("Ingrese la cantidad de ba�os de la habitacion.\n");
                fflush(stdin);
                scanf("%i", &aux.cantBanios);
            }

            else if(opc==7)
            {
                printf("Tiene aire acondicionado?0=no,1=si.\n");
                fflush(stdin);
                scanf("%i", &aux.aireAcondicionado);
            }
            else if(opc==8)
            {
                printf("Tiene frigobar?0=no,1=si.\n");
                fflush(stdin);
                scanf("%i", &aux.frigobar);
            }

            else
            {
                printf("Error\n");
            }

            fseek(buffer,sizeof(strHabitacion)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(strHabitacion),1, buffer);

        }
        else
        {
            printf("Error alumno no encontrado.\n");
        }
        fclose(buffer);
    }

}


void arcMostrarHabitacionesNoHabilitadas(char nombreArchi[])
{
    FILE* buffer = fopen(nombreArchi, "rb");

    strHabitacion aux;

    if(buffer)
    {
        printf("Abierto\n");

        while(((fread(&aux, sizeof(strHabitacion), 1, buffer))>0) && (aux.habilitada==0))
        {
            strMostrarUnaHabitacion(aux);
        }

        fclose(buffer);
    }
    else
    {
        printf("Error\n");
    }
}






