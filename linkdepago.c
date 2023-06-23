#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "const.h"

#define MAX_LONGITUD 6

char *generarCadenaAleatoria(int longitud);
char *randomMercadoPago();
char *randomPayPal();

// Llama a generar los respectivos generadores aleatorios y lo imprime

int linkDePago()
{
    char *mercadoLink = randomMercadoPago();
    char *payLink = randomPayPal();

    printf("%s", colorCeleste);
    printf("MercadoPago: %s\n", mercadoLink);
    printf("PayPal: %s\n", payLink);
    printf("%s", reiniciarColor);

    free(mercadoLink);
    free(payLink);

    return 0;
}

// Esta cadena genera datos aleatorios, a partir de los caractéres válidos
/* Esto se hace para asegurarse de asignar la cantidad correcta de memoria para la cadena,
independientemente del tamaño del tipo de datos char de MP en la función anterior */

char *generarCadenaAleatoria(int longitud)
{
    static const char caracteresValidos[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    char *cadena = malloc((longitud + 1) * sizeof(char)); // +1 para el carácter nulo

    for (i = 0; i < longitud; i++)
    {
        int indice = rand() % (sizeof(caracteresValidos) - 1);
        cadena[i] = caracteresValidos[indice];
    }

    cadena[longitud] = '\0';
    return cadena;
}

// Las funciones donde se copian y concatenan las cadenas de caractéres
char *randomMercadoPago()
{
    srand(time(NULL));
    char mercadoPago[] = "mpago.la/";
    char *cadena = generarCadenaAleatoria(MAX_LONGITUD);
    char *mercadoLink = malloc(strlen(mercadoPago) + strlen(cadena) + 1);
    strcpy(mercadoLink, mercadoPago);
    strcat(mercadoLink, cadena);
    free(cadena);
    return mercadoLink;
}

char *randomPayPal()
{
    srand(time(NULL));
    char payPal[] = "pay.pal/";
    char *cadena = generarCadenaAleatoria(MAX_LONGITUD);
    char *payLink = malloc(strlen(payPal) + strlen(cadena) + 1);
    strcpy(payLink, payPal);
    strcat(payLink, cadena);
    free(cadena);
    return payLink;
}
