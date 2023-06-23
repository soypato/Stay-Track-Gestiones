#include <stdio.h>
#include <string.h>
#include "tipoUsuario.h"
#include "comidas.h"
#include <ctype.h>

const char ArchC[] = "Comidas.dat";
const int DIM_F = 15;

int op = 0;
char decision;
char Comidas[15][MATRIZ_C];
char comidaEliminar[MATRIZ_C];
char comidaModificar[MATRIZ_C];
char nuevaComida[MATRIZ_C];

int menuComidas()
{
    do
    {
        printf("============================================\n");
        printf("|              Menu                        |\n");
        printf("|==========================================|\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("|==========================================|\n");
        printf("|   1    | Cargar comidas                  |\n");
        printf("|   2    | Mostrar comidas                 |\n");
        printf("|   3    | Verificar si existe comida      |\n");
        printf("|   4    | Modificar comidas               |\n");
        printf("|   5    | Borrar TODAS las comidas        |\n");
        printf("|   6    | Borrar una comida específica    |\n");
        printf("|   0    | Salir                           |\n");
        printf("============================================\n");
        printf("Su decision: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            CargarComidasArchivo(ArchC, Comidas, DIM_F);
            break;
        case 2:
            mostrarComidasArchivo(ArchC, Comidas);
            break;
        case 3:
            VerificarSiExisteComidas(ArchC, Comidas);
            break;
        case 4:
            printf("Ingrese el nombre de la comida a modificar: ");
            fflush(stdin);
            gets(comidaModificar);

            printf("Ingrese el nuevo nombre de la comida: ");
            fflush(stdin);
            gets(nuevaComida);

            modificarComida(Comidas, DIM_F, comidaModificar, nuevaComida);
            break;
        case 5:
            BorrarTodasLasComidas(Comidas, DIM_F);
            printf("Todas las comidas han sido eliminadas.\n");
            break;
        case 6:
            printf("Ingrese el nombre de la comida a eliminar: ");
            fflush(stdin);
            gets(comidaEliminar);

            BorrarComidaEspecifica(Comidas, DIM_F, comidaEliminar);
            break;
        case 0:
            inicioSesion();
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    } while (decision == 's');

    return 0;
}

int CargarComidas(char Comidas[][MATRIZ_C], int dimF)
{
    int f = 0;
    printf("Vamos a cargar TODAS las comidas.\n");

    if (Comidas != 0)
    {
        for (f = 0; f < dimF; f++)
        {
            printf("Ingrese la comida numero %i de %i: ", f + 1, dimF);
            fflush(stdin);
            gets(Comidas[f]);

            int len = strlen(Comidas[f]);
            int esPalabra = 1;

            for (int i = 0; i < len; i++)
            {
                if (!isalpha(Comidas[f][i]) && Comidas[f][i] != ' ')
                {
                    esPalabra = 0;
                    break;
                }
            }

            if (!esPalabra)
            {
                printf("Error: La carga debe ser una palabra. Inténtelo de nuevo.\n");
                f--;
            }
        }
    }
    else
    {
        printf("Hubo un error con la matriz, contacte con el administrador.\n");
    }

    return f;
}

void mostrarComidas(char Comidas[][MATRIZ_C], int validos)
{
    puts("|------------------------|");
    for (int f = 0; f < validos; f++)
    {
        printf("Comidas: %s\n", Comidas[f]);
    }
    puts("|------------------------|");
}

void CargarComidasArchivo(char nombre[], char Comidas[][MATRIZ_C], int dimF)
{
    FILE *Archi;
    Archi = fopen(nombre, "wb");
    int validos = 0;

    if (Archi != NULL)
    {
        validos = CargarComidas(Comidas, dimF);
        fwrite(&validos, sizeof(int), 1, Archi);
        fwrite(Comidas, sizeof(char), validos * MATRIZ_C, Archi);
        fclose(Archi);
    }
}

void mostrarComidasArchivo(char nombre[], char Comidas[][MATRIZ_C])
{
    FILE *Archi;
    Archi = fopen(nombre, "rb");

    int validos = 0;

    if (Archi != NULL)
    {
        fread(&validos, sizeof(int), 1, Archi);
        fread(Comidas, sizeof(char), validos * MATRIZ_C, Archi);
        fclose(Archi);

        mostrarComidas(Comidas, validos);
    }
}

char VerificarSiExisteComidas(char nombreArchivo[], char Comidas[][MATRIZ_C])
{
    FILE *Archi;
    Archi = fopen(nombreArchivo, "rb");

    int flag = 0;
    char NombreBuscar[30];

    printf("Ingrese el nombre de la comida: ");
    fflush(stdin);
    gets(NombreBuscar);

    if (Archi != NULL)
    {
        int validos = 0;
        fread(&validos, sizeof(int), 1, Archi);

        for (int i = 0; i < validos && flag == 0; i++)
        {
            fread(Comidas[i], sizeof(char), MATRIZ_C, Archi);
            if (strcmp(Comidas[i], NombreBuscar) == 0)
            {
                flag = 1;
            }
        }
        fclose(Archi);
    }

    if (flag == 1)
    {
        printf("El nombre de la comida '%s' existe.\n", NombreBuscar);
        return NombreBuscar;
    }
    else
    {
        printf("El nombre de la comida '%s' NO existe.\n", NombreBuscar);
        return 0;
    }
}

void BorrarComidaEspecifica(char Comidas[][MATRIZ_C], int dimF, char comida[])
{
    int encontrada = 0;
    for (int f = 0; f < dimF; f++)
    {
        if (strcmp(Comidas[f], comida) == 0)
        {
            strcpy(Comidas[f], "");
            printf("Comida '%s' eliminada correctamente.\n", comida);
            encontrada = 1;
            break;
        }
    }

    if (!encontrada)
    {
        printf("No se encontró la comida '%s' en la lista.\n", comida);
    }
    GuardarCambiosArchivo("Comidas.dat", Comidas, dimF);
}


void modificarComida(char Comidas[][MATRIZ_C], int dimF, char comida[], char nuevaComida[])
{
    int encontrada = 0;
    for (int f = 0; f < dimF; f++)
    {
        if (strcmp(Comidas[f], comida) == 0)
        {
            strcpy(Comidas[f], nuevaComida);
            printf("Comida '%s' modificada correctamente.\n", comida);
            encontrada = 1;
            break;
        }
    }

    if (!encontrada)
    {
        printf("No se encontró la comida '%s' en la lista.\n", comida);
    }

    GuardarCambiosArchivo(ArchC, Comidas, dimF);
}

void BorrarTodasLasComidas(char Comidas[][MATRIZ_C], int dimF)
{
    for (int f = 0; f < dimF; f++)
    {
        strcpy(Comidas[f], "");
    }
    GuardarCambiosArchivo(ArchC, Comidas, dimF);
}

void GuardarCambiosArchivo(char nombre[], char Comidas[][MATRIZ_C], int dimF)
{
    FILE* Archi;
    Archi = fopen(nombre, "wb"); //
    int validos = 0;

    if (Archi != NULL)
    {
        for (int f = 0; f < dimF; f++)
        {
            if (strlen(Comidas[f]) > 0)
            {
                validos++;
            }
        }

        fwrite(&validos, sizeof(int), 1, Archi);
        fwrite(Comidas, sizeof(char), validos * MATRIZ_C, Archi);
        fclose(Archi);
    }
}
