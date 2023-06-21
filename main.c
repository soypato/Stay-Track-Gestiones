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

int main() {
    inicioSesion();
    return 0;
}

void inicioSesion() {
    int tmpClave = 0;
    int loginExitoso = 0;

    limpiarPantalla();

    const char *titulo[] = {
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
    for (int i = 0; i < numLineas; i++) {
        int espaciosInicio = (longitudMaxima - strlen(titulo[i])) / 2;
        int espaciosFin = longitudMaxima - strlen(titulo[i]) - espaciosInicio;

        for (int j = 0; j < espaciosInicio; j++) {
            printf(" ");
        }

        printf("%s%s", colorCeleste, titulo[i]);

        for (int j = 0; j < espaciosFin; j++) {
            printf(" ");
        }

        printf("%s\n", reiniciarColor);
        usleep(80000);
    }

    printf("\n\nIntroduzca la contrasena: ");
    scanf("%d", &tmpClave);
    limpiarPantalla();

    switch (tmpClave) {
        case claveMozo:
            printf(colorAmarillo "=== MENU MOZO ===\n" reiniciarColor);
            menuReservas();
            // Aquí va el código del menú del mozo
            break;
        case claveRecepcionista:
            printf(colorAmarillo "=== MENU RECEPCIONISTA ===\n" reiniciarColor);
            menuComidas();
            break;
        case claveLimpieza:
            printf(colorAmarillo "=== MENU LIMPIEZA ===\n" reiniciarColor);
            menuLimpiar();
            // Aquí va el código del menú de limpieza
            break;
        case claveAdmin:
            printf(colorAmarillo "=== MENU ADMINISTRADOR ===\n" reiniciarColor);
            menuEmpleados();
            // Aquí va el código del menú del administrador
            break;
        default:
            printf(colorRojo "Clave incorrecta, presiona enter para intentar de nuevo\n" reiniciarColor);
            getchar(); // Captura el Enter previo al scanf
            getchar(); // Espera a que el usuario presione Enter para continuar
            inicioSesion();
            break;
    }
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarSeparador() {
    printf("==============================================\n");
}
