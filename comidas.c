#include <stdio.h>
#include <string.h>
#include "tipoUsuario.h"
#include "comidas.h"

const char ArchC[]="Comidas.dat";

int op=0;
char decision;
char Comidas[15][MATRIZ_C];

int menuComidas()
{
    do
    {
        printf("|==========================================|\n");
        printf("|              Menu                        |\n");
        printf("|==========================================|\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("|==========================================|\n");
        printf("|   1    | Cargar  comidas                 |\n");
        printf("|   2    | Mostrar comidas                 |\n");
        printf("|   3    | Verificar Si existe comida      |\n");
        printf("|   0    | Salir                           |\n");
        printf("|==========================================|\n");
        printf("Su decision: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            CargarComidasArchivo(ArchC, Comidas, 5);
            break;
        case 2:
             mostrarComidasArchivo(ArchC, Comidas);
            break;
        case 3:
            VerificarSiExisteComidas(ArchC, Comidas);
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

int CargarComidas(char Comidas[][MATRIZ_C], int dimF)
{
    int f=0;

    for(f=0; f<dimF; f++)
    {
        printf("Ingresar las comidas\n");
        fflush(stdin);
        gets(Comidas[f]);
    }
    return f;
}


void mostrarComidas(char Comidas[][MATRIZ_C], int validos)
{
    int f =0;

    puts("|------------------------|");
    for(f=0; f<validos; f++)
    {

        printf("Comidas: %s\n", Comidas[f]);
    }
    puts("|------------------------|");
}

void CargarComidasArchivo(char nombre[], char Comidas[][MATRIZ_C], int dimF )
{
    FILE* Archi;
    Archi = fopen(nombre, "wb");
    int validos=0;

    if(Archi!=NULL)
    {
        validos = CargarComidas(Comidas, dimF);
        fwrite(&validos, sizeof(int), 1, Archi);
        fwrite(Comidas, sizeof(char), validos * MATRIZ_C, Archi);
        fclose(Archi);
    }
}

void mostrarComidasArchivo(char nombre[], char Comidas[][MATRIZ_C])
{
    FILE* Archi;

    Archi = fopen(nombre, "rb");

    int validos=0;

    if(Archi!=NULL)
    {
        fread(&validos, sizeof(int), 1, Archi);
        fread(Comidas, sizeof(char), validos * MATRIZ_C, Archi);
        fclose(Archi);

        mostrarComidas(Comidas, validos);
    }
}


void VerificarSiExisteComidas(char nombre[], char Comidas[][MATRIZ_C])
{

    FILE* Archi;

    Archi = fopen(nombre, "rb");

    int flag = 0;
    char NombreBuscar[30];

    printf("Ingrese la comida que desea buscar\n");
    fflush(stdin);
    gets(NombreBuscar);

    if(Archi!=NULL)
    {
        int validos=0;
        fread(&validos, sizeof(int), 1, Archi);

        for(int i = 0; i < validos && flag == 0; i++)
        {
            fread(Comidas[i], sizeof(char), MATRIZ_C, Archi);
            if(strcmp(Comidas[i], NombreBuscar) == 0)
            {
                flag=1;
            }
        }
         fclose(Archi);
    }

    if(flag==1)
    {
        printf("El nombre de la comida %s existe.\n", NombreBuscar);
    }
    else
    {
        printf("El nombre de la comida %s NO existe.\n", NombreBuscar);
    }
}




























/*
void imprimirMatriz(char menu[][MAX_LONGITUD], char descripcion[][MAX_DESCRIPCION], int numComidas)
{
    printf("MENU DE COMIDAS\n");
    printf("---------------\n");
    for (int i = 0; i < numComidas; i++)
    {
        printf("Comida: %s\n", menu[i]);
        printf("Descripcion: %s\n", descripcion[i]);
        printf("\n");
    }
}



int menuComidas()
{
    int flag;
    copiarComidas();
    printf("Presione 0 para volver al menu");
    scanf("%i", &flag);
    if (flag == 0) {
    volverDependiendoTipoUsuario(tipoUsuario);
    }
    return 0;
}
*/
