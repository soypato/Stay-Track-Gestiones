#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "const.h"

#define MAX_LONGITUD 6

char *generarCadenaAleatoria(int longitud);
char *randomMercadoPago();
char *randomPayPal();

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
