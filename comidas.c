#include <stdio.h>
#include <string.h>
#include "tipoUsuario.h"

#define MAX_COMIDAS 10
#define MAX_LONGITUD 50
#define MAX_DESCRIPCION 200

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

void copiarComidas()
{
    char menu[MAX_COMIDAS][MAX_LONGITUD] = {""};
    char descripcion[MAX_COMIDAS][MAX_DESCRIPCION] = {""};


    strcpy(menu[0], "Pizza");
    strcpy(descripcion[0], "Deliciosa pizza recién horneada con una variedad de ingredientes.");
    strcpy(menu[1], "Hamburguesa");
    strcpy(descripcion[1], "Sabrosa hamburguesa jugosa con carne a la parrilla y acompañamientos.");
    strcpy(menu[2], "Ensalada");
    strcpy(descripcion[2], "Ensalada fresca y saludable con una mezcla de vegetales y aderezo.");
    strcpy(menu[3], "Sushi");
    strcpy(descripcion[3], "Rollos de sushi elaborados con pescado fresco y arroz aderezado.");
    strcpy(menu[4], "Pasta");
    strcpy(descripcion[4], "Plato de pasta al dente con salsa de tomate o crema, acompañado de queso.");
    strcpy(menu[5], "Tacos");
    strcpy(descripcion[5], "Tortillas de maíz rellenas de carne, pollo, o vegetales, con salsa y guarniciones.");
    strcpy(menu[6], "Pollo asado");
    strcpy(descripcion[6], "Pollo jugoso asado con especias y acompañado de papas o ensalada.");
    strcpy(menu[7], "Sopa");
    strcpy(descripcion[7], "Sopa caliente y reconfortante con una mezcla de ingredientes y caldo.");
    strcpy(menu[8], "Sandwich");
    strcpy(descripcion[8], "Sándwich hecho con pan fresco y relleno de ingredientes variados.");
    strcpy(menu[9], "Ramen");
    strcpy(descripcion[9], "Plato de fideos japoneses en caldo sabroso con carne, huevo y vegetales.");
    strcpy(menu[9], "Huevo");
    strcpy(descripcion[9], "Desayuna con huevo!!.");

    imprimirMatriz(menu, descripcion, MAX_COMIDAS);
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
