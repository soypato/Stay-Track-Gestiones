#include <stdio.h>
#include <stdlib.h>
#include "comidas.h"

const char ArchC[]="MenuComidas.dat";


int menuComidas()
{
    int op=0;
    char decision;

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
             CargarAlimentosArchivo(ArchC, MATRIZ_F );
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;

        case 0:
            printf("Opción inválida. Por favor, ingrese nuevamente.\n");
            break;

        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's');


    return 0;
}


int CargarAlimentos(Alimento Alimentos[][MATRIZ_S], int dimF)
{
   int f=0;
   char op='s';

    while (f < dimF && op == 's')
    {
        printf("Ingrese la comida: ");
        fflush(stdin);
        gets(Alimentos.comida[]);

        printf("Ingrese el postre: ");
        fflush(stdin);
        gets(Alimentos.postre[f]);

        printf("Ingrese la fruta: ");
        fflush(stdin);
        gets(Alimentos.fruta[f]);

        printf("Deseas seguir cargando alimentos (s/n)? ");
        fflush(stdin);
        scanf(" %c", &op);

        f++;
    }

    return f;
}

void mostrarAlimentos(Alimento Alimentos, int validos)
{
  int f=0;

  for(f=0;f<validos;f++)
  {
    puts("|-------------------------------|");
    printf("Comida: %s\n", Alimentos.comida[f]);
    printf("Postre: %s\n", Alimentos.postre[f]);
    printf("Fruta:  %s\n", Alimentos.fruta[f]);
    puts("|-------------------------------|");
  }
}

void CargarAlimentosArchivo(char nombre[], int dimF)
{
  FILE* Archi;

  Archi = fopen(nombre, "ab");
  Alimento Temp;
  int validos = 0;

  if(Archi!=NULL)
  {
  /*
   validos = CargarAlimentos(Temp, dimF);
   fwrite(&Temp, sizeof(Alimento), 1, Archi);
   fclose(Archi);
   printf("Se cargo correctamente\n");
   */
  }
}

void mostrarAlimentosArchivo(char nombre[])
{
 FILE* Archi;

 Archi = fopen(nombre, "rb");
 Alimento Temp;
 if(Archi!=NULL)
 {
   fread(&Temp, sizeof(Alimento), 1, Archi);
   {

   }

   fclose(Archi);
 }





}



