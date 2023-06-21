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
    inicioSesion();
    return 0;
}

void inicioSesion()
{
    int tmpClave = 0;
    int loginExitoso = 0;

    limpiarPantalla();

    const char *titulo[] =
    {
        " _______  _______  _______  _______  ___   _______  __    _  __   __  _______  _______  _______  ___     ",
        "|       ||       ||       ||       ||   | |       | |  |  | ||  | |  ||       ||       ||       ||   |    ",
        "|    ___||    ___||  _____||_     _||   | |   _   | |   |_| ||  |_|  ||   _   ||_     _||    ___||   |    ",
        "|   | __ |   |___ | |_____   |   |  |   | |  | |  | |       ||       ||  | |  |  |   |  |   |___ |   |    ",
        "|   ||  ||    ___||_____  |  |   |  |   | |  |_|  | |  _    ||       ||  |_|  |  |   |  |    ___||   |___ ",
        "|   |_| ||   |___  _____| |  |   |  |   | |       | | | |   ||   _   ||       |  |   |  |   |___ |       |",
        "|_______||_______||_______|  |___|  |___| |_______| |_|  |__||__| |__||_______|  |___|  |_______||_______|",
        "__________________________________________________________________________________________________________"
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

        printf("%s%s", colorCeleste, titulo[i]);

        for (int j = 0; j < espaciosFin; j++)
        {
            printf(" ");
        }

        printf("%s\n", reiniciarColor);
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
        // Aquí va el código del menú del mozo
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
        printf("|         Menú Mozo                 |\n");
        printf("=====================================\n");
        printf("| Opción | Descripción              |\n");
        printf("=====================================\n");
        printf("|   1    | Menú de Limpieza         |\n");
        printf("|   2    | Menú de Comida           |\n");
        printf("|   0    | Salir                    |\n");
        printf("=====================================\n");


        printf("Su decisión: ");
        fflush(stdin);
        scanf(" %c", &decision);

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
            printf("La opción es incorrecta.\n");
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's' || decision == 'S');
}


void controlRecepcionista()
{
    int decision;
    do
    {
        printf("=====================================\n");
        printf("|    Control recepcionista          |\n");
        printf("=====================================\n");
        printf("| Opción | Descripción              |\n");
        printf("=====================================\n");
        printf("|   1    | Menú de habitaciones     |\n");
        printf("|   2    | Menú de reserva          |\n");
        printf("|   3    | Generar link de pago     |\n");
        printf("|   0    | Salir                    |\n");
        printf("=====================================\n");

        printf("Su decisión: ");
        fflush(stdin);
        scanf(" %c", &decision);

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

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's' || decision == 'S');
}

void controlLimpieza()
{
    int decision;
    do
    {
        printf("========================================\n");
        printf("|        Control limpieza              |\n");
        printf("========================================\n");
        printf("| Opción | Descripción                 |\n");
        printf("========================================\n");
        printf("|   1    | Menú de botellas            |\n");
        printf("|   2    | Menú de habitaciones        |\n");
        printf("|   0    | Salir                       |\n");
        printf("========================================\n");

        printf("Su decisión: ");
        fflush(stdin);
        scanf(" %c", &decision);

        switch (decision)
        {
        case 1:
            menuBotellas();
            break;
        case 2:
            menuHabitaciones();
            break;
        case 3:
            return 0;
        default:
            printf("La opción es incorrecta.\n");
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's' || decision == 'S');
}

void controlAdmin()
{
    int decision;
    do
    {
        printf("=============================================\n");
        printf("|           Control admin.                  |\n");
        printf("=============================================\n");
        printf("| Opción | Descripción                      |\n");
        printf("=============================================\n");
        printf("|   1    | Menú de botellas                 |\n");
        printf("|   2    | Menú de comidas                  |\n");
        printf("|   3    | Menú de empleados                |\n");
        printf("|   4    | Menú de limpieza                 |\n");
        printf("|   5    | Menú de reservas                 |\n");
        printf("|   6    | Generar link de pago             |\n");
        printf("|   0    | Salir                            |\n");
        printf("=============================================\n");

        printf("Su decisión: ");
        fflush(stdin);
        scanf(" %c", &decision);

        switch (decision)
        {
        case 1:
            menuBotellas();
            break;
        case 2:
            menuHabitaciones();
            break;
        case 3:
            return 0;
        default:
            printf("La opción es incorrecta.\n");
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's' || decision == 'S');
}
