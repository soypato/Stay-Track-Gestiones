#include <stdio.h>
#include <stdlib.h>
#include "comidas.h"

const char ArchC[]="MenuComidas.dat";


int menuComidas()
{
    int op=0;
    char decision;
    char Alimentoss[5][MATRIZ_C];

  do
    {
        printf("==========================================\n");
        printf("|              Menu comidas                |\n");
        printf("==========================================\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("===========================================\n");
        printf("|   1    | Agregar comidas                 |\n");
        printf("|   2    | Mostrar comidas                 |\n");
        printf("|   3    | Elegir comidas                  |\n");
        printf("|   4    | Cambiar menu                    |\n");
        printf("|   5    | Buscar comida                   |\n");
        printf("|   0    | Salir                           |\n");
        printf("==========================================\n");
        printf("Su decision: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

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

int CargarAlimentos(char Alimentos[][MATRIZ_C], int dimF)
{
  int f=0;
  char control='s';
  for(f=0;f<dimF && control == 's';f++)
  {
    printf("Ingresar los alimentos\n");
    fflush(stdin);
    gets(Alimentos[f]);

    printf("Desea seguir cargando más alimentos?\n");
    fflush(stdin);
    scanf(" %c", &control);
  }
  return f;
}

void mostrarAlimentos(char Alimentos[][MATRIZ_C], int validos)
{
  int f =0;

  for(f=0;f<validos;f++)
  {
    printf("Alimentos: %s", Alimentos[f]);
  }

}

void CargarAlimentosArchivo(char nombre[], char Alimentos[][MATRIZ_C], int dimF)
{
  FILE* Archi;

  Archi = fopen(nombre, "ab");
  int validos=0;

  if(Archi!=NULL)
  {
    validos  =  CargarAlimentos(Alimentos, dimF);
    fwrite(&validos, sizeof(int), 1, Archi);
    fwrite(Alimentos, sizeof(Alimentos[0]), validos, Archi);
    fclose(Archi);
  }
}

void mostrarAlimentosArchivo(char nombre[], char Alimentos[][MATRIZ_C], int dimF)
{
  FILE Archi;

  Archi = fopen(nombre, "rb");
  int validos;
  if(Archi!=NULL)
  {
   while(fread(&validos, sizeof(int), 1, Archi))
   {
    mostrarAlimentos(Alimentos, validos);
   }

   fclose(Archi);
  }





}





