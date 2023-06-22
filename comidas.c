#include <stdio.h>
#include <stdlib.h>
#include "comidas.h"
#include <string.h>

const char ArchC[]="NombresAdmins";


int menuComidas()
{
    int op=0;
    char decision;
    char Admins[5][MATRIZ_C];

  do
    {
        printf("|==========================================|\n");
        printf("|              Menu Admins                 |\n");
        printf("|==========================================|\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("|==========================================|\n");
        printf("|   1    | Agregar Nombres                 |\n");
        printf("|   2    | Mostrar Nombres                 |\n");
        printf("|   3    | Verificar Si existe Admin       |\n");
        printf("|   0    | Salir                           |\n");
        printf("|==========================================|\n");
        printf("Su decision: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
       CargarAdminsArchivo(ArchC, Admins, 5);
            break;
        case 2:
           mostrarAdminsArchivo(ArchC, Admins);
            break;
        case 3:
            VerificarSiExisteAdmin(ArchC,Admins);
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

int CargarAdmins(char Admins[][MATRIZ_C], int dimF)
{
  int f=0;
  char control='s';
  for(f=0;f<dimF && control == 's';f++)
  {
    printf("Ingresar los nombres y Apellido de los ADMINS\n");
    fflush(stdin);
    gets(Admins[f]);

    printf("Desea seguir cargando mas Admins?\n");
    fflush(stdin);
    scanf(" %c", &control);
  }
  return f;
}

void mostrarAdmins(char Admins[][MATRIZ_C], int validos)
{
  int f =0;

   puts("|------------------------|");
  for(f=0;f<validos;f++)
  {

    printf("Admins: %s\n", Admins[f]);
  }
   puts("|------------------------|");
}

void CargarAdminsArchivo(char nombre[], char Admins[][MATRIZ_C], int dimF)
{

  FILE* Archi;
  Archi = fopen(nombre, "wb");
  int validos=0;

  if(Archi!=NULL)
  {
     validos = CargarAdmins(Admins, dimF);
    fwrite(&validos, sizeof(int), 1, Archi);
    fwrite(Admins, sizeof(char), validos * MATRIZ_C, Archi);
    fclose(Archi);
  }
}

void mostrarAdminsArchivo(char nombre[], char Admins[][MATRIZ_C])
{
  FILE* Archi;

  Archi = fopen(nombre, "rb");

  int validos=0;

  if(Archi!=NULL)
  {
    fread(&validos, sizeof(int), 1, Archi);
    fread(Admins, sizeof(char), validos * MATRIZ_C, Archi);
    fclose(Archi);

    mostrarAdmins(Admins, validos);
  }

}

void VerificarSiExisteAdmin(char nombre[],char Admins[][MATRIZ_C])
{
  FILE* Archi;

  Archi = fopen(nombre, "rb");

  int flag = 0;
  char NombreBuscar[30];

  printf("Ingrese el nombre que desea buscar\n");
  fflush(stdin);
  gets(NombreBuscar);

  if(Archi!=NULL)
  {
     int validos=0;
     fread(&validos, sizeof(int), 1, Archi);

    for(int i = 0;i < validos && flag == 0; i++)
    {
     fread(Admins[i], sizeof(char), MATRIZ_C, Archi);
       if(strcmp(Admins[i], NombreBuscar) == 0)
       {
         flag=1;
       }
    }
  }
     fclose(Archi);


  if(flag==1)
  {
    printf("El nombre de Administrador %s existe.\n", NombreBuscar);
  }else
  {
    printf("El nombre de Administrador %s NO existe.\n", NombreBuscar);
  }

}



