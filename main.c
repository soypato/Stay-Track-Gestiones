#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
#include "reservas.h"
#include "const.h"
#include <time.h>
#include <unistd.h> // Libreria  para usleep (retraso en microsegundos)
#include "linkdepago.h"
#include "botellas.h"
#include "comidas.h"
#include "empleados.h"
#include "porLimpiar.h"
#include "preguntarDNI.h"

void inicioSesion();
void limpiarPantalla();
void mostrarSeparador();
void controlMozo();
void controlReservas();
void controlAdmin();

int main()
{
    int continuar = 1;

    while (continuar)
    {
        inicioSesion();
        printf("¿Desea volver al inicio de sesion? (1: Sí / 0: No): ");
        scanf("%d", &continuar);
        limpiarPantalla();
    }

    return 0;
}

void inicioSesion()
{
    int tmpClave = 0;
    int loginExitoso = 0;

    limpiarPantalla();

    const char *titulo[] =
    {
        "   ____ _____ ____ _____ ___ ___  _   _               ",
        "  / ___| ____/ ___|_   _|_ _/ _ \\| \\ | |              ",
        " | |  _|  _| \\___ \\ | |  | | | | |  \\| |              ",
        " | |_| | |___ ___) || |  | | |_| | |\\  |              ",
        "  \\____|_____|____/ |_| |___\\___/|_| \\_|_ _____ _     ",
        "                        | | | |/ _ \\_   _| ____| |    ",
        "                        | |_| | | | || | |  _| | |    ",
        "                        |  _  | |_| || | | |___| |___ ",
        "                        |_| |_|\\___/ |_| |_____|_____|",
        "                                                      "
    };

    int numLineas = sizeof(titulo) / sizeof(titulo[0]);
    int longitudMaxima = strlen(titulo[0]);

    limpiarPantalla();
    for (int i = 0; i < numLineas; i++)
    {
        int espaciosInicio = (longitudMaxima - strlen(titulo[i])) / 2;
        int espaciosFin = longitudMaxima - strlen(titulo[i]) - espaciosInicio;

        for (int j = 0; j < espaciosInicio; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < strlen(titulo[i]); j++)
        {
<<<<<<< HEAD
            // Calcula el valor de azul y violeta en funcion de la posicion j
            int azul = 255 - j * (255 / strlen(titulo[i]));
            int violeta = j * (255 / strlen(titulo[i]));

            // Establece el color utilizando codigos de escape ANSI
=======
            // Calcula el valor de azul y violeta en función de la posición j
            int azul = 255 - j * (255 / strlen(titulo[i]));
            int violeta = j * (255 / strlen(titulo[i]));

            // Establece el color utilizando códigos de escape ANSI
>>>>>>> 0d5249ac126c105145a55d02a824d5edd1ac057f
            printf("\033[48;2;%d;0;%dm%c\033[0m", violeta, azul, titulo[i][j]);
        }

        for (int j = 0; j < espaciosFin; j++)
        {
            printf(" ");
        }

        printf("\n");
        usleep(80000);
    }

    printf("\n\nIntroduzca la contrasena: ");
    scanf("%d", &tmpClave);
    limpiarPantalla();

    switch (tmpClave)
    {
    case claveMozo:
        printf(colorAmarillo "=== MENU MOZO ===\n" reiniciarColor);
        controlMozo();
        break;
    case claveRecepcionista:
        printf(colorAmarillo "=== MENU RECEPCIONISTA ===\n" reiniciarColor);
        controlRecepcionista();
        break;
    case claveLimpieza:
        printf(colorAmarillo "=== MENU LIMPIEZA ===\n" reiniciarColor);
        controlLimpieza();
        break;
    case claveAdmin:
        printf(colorAmarillo "=== MENU ADMINISTRADOR ===\n" reiniciarColor);
        controlAdmin();
        break;
    default:
        printf(colorRojo "Clave incorrecta, presiona enter para intentar de nuevo\n" reiniciarColor);
        getchar(); // Captura el Enter previo al scanf
        getchar(); // Espera a que el usuario presione Enter para continuar
        inicioSesion();
        break;
    }
}


void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarSeparador()
{
    printf("==============================================\n");
}

void controlMozo()
{
    int decision;
    do
    {
        printf("=====================================\n");
        printf("|         Menu Mozo                 |\n");
        printf("=====================================\n");
        printf("| Opcion | Descripcion              |\n");
        printf("=====================================\n");
        printf("|   1    | Menu de Limpieza         |\n");
        printf("|   2    | Menu de Comida           |\n");
        printf("|   0    | Salir                    |\n");
        printf("=====================================\n");


        printf("Su decision: ");
        fflush(stdin);
        scanf(" %d", &decision);

        switch (decision)
        {
        case 1:
            menuLimpieza();
            break;
        case 2:
            menuComidas();
            break;
        case 0:
            return;
        default:
            printf("La opcion es incorrecta.\n");
            break;
        }

        printf("Seguir ejecutando? (1: Sí / 0: No): ");
        scanf("%d", &decision);
    }
    while (decision == 1);
}


void controlRecepcionista()
{
    int decision;
    do
    {
        printf("=====================================\n");
        printf("|    Control recepcionista          |\n");
        printf("=====================================\n");
        printf("| Opcion | Descripcion              |\n");
        printf("=====================================\n");
        printf("|   1    | Menu de Habitaciones     |\n");
        printf("|   2    | Menu de Reserva          |\n");
        printf("|   3    | Generar pagos            |\n");
        printf("|   0    | Salir                    |\n");
        printf("=====================================\n");

        printf("Su decision: ");
        fflush(stdin);
        scanf(" %d", &decision);

        switch (decision)
        {
        case 1:
            menuHabitaciones();
            break;
        case 2:
            menuReservas();
            break;
        case 3:
            linkDePago();
            break;
        case 0:
            return;
        }
        printf("Seguir ejecutando? (1: Sí / 0: No): ");
        scanf("%d", &decision);
    }
    while (decision == 1);
}

void controlLimpieza()
{
    int decision;
    do
    {
        printf("=====================================\n");
        printf("|         Menu Limpieza             |\n");
        printf("=====================================\n");
        printf("| Opcion | Descripcion              |\n");
        printf("=====================================\n");
        printf("|   1    | Menu Limpieza            |\n");
        printf("|   2    | Menu Botellas            |\n");
        printf("|   3    | Menu Habitaciones        |\n");
        printf("|   0    | Salir                    |\n");
        printf("=====================================\n");

        printf("Su decision: ");
        fflush(stdin);
        scanf(" %d", &decision);

        switch (decision)
        {
        case 1:
            menuLimpieza();
            break;
        case 2:
            menuBotellas();
            break;
        case 3:
            menuHabitaciones();
            break;
        case 0:
            return;
        }

        printf("Seguir ejecutando? (1: Sí / 0: No): ");
        scanf("%d", &decision);
    }
    while (decision == 1);
}

void controlAdmin()
{
    int decision;
    do
    {
        printf("=====================================\n");
        printf("|         Menu Administrador        |\n");
        printf("=====================================\n");
        printf("| Opcion | Descripcion              |\n");
        printf("=====================================\n");
        printf("|   1    | Menu de Botellas         |\n");
        printf("|   2    | Menu de Comidas          |\n");
        printf("|   2    | Menu de Empleados        |\n");
        printf("|   2    | Menu de Limpieza         |\n");
        printf("|   2    | Menu de Reserva          |\n");
        printf("|   2    | Generar pagos            |\n");
        printf("|   0    | Salir                    |\n");
        printf("=====================================\n");

        printf("Su decision: ");
        fflush(stdin);
        scanf(" %d", &decision);

        switch (decision)
        {
        case 1:
            menuEmpleados();
            break;
        case 2:
            menuBotellas();
            break;
        case 0:
            return;
        }

        printf("Seguir ejecutando? (1: Sí / 0: No): ");
        scanf("%d", &decision);
    }
    while (decision == 1);
}
