#ifndef COMIDAS_H
#define COMIDAS_H

#define MATRIZ_C 70

int CargarComidas(char[][MATRIZ_C], int);
void mostrarComidas(char[][MATRIZ_C], int);
void CargarComidasArchivo(char[], char[][MATRIZ_C], int);
void mostrarComidasArchivo(char[], char[][MATRIZ_C]);
void VerificarSiExisteComidas(char[], char[][MATRIZ_C]);


int menuComidas();

#endif
