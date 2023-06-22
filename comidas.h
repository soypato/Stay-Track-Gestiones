#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

#define MATRIZ_C 70

int CargarAdmins(char[][MATRIZ_C], int);
void mostrarAdmins(char[][MATRIZ_C], int);
void CargarAdminsArchivo(char[], char[][MATRIZ_C], int );
void mostrarAdminsArchivo(char[], char[][MATRIZ_C]);
void VerificarSiExisteAdmin(char[], char[][MATRIZ_C]);





#endif // COMIDAS_H_INCLUDED
