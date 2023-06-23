#ifndef COMIDAS_H
#define COMIDAS_H

#define MATRIZ_C 30
// PROTOTIPADO
int menuComidas();
int CargarComidas(char Comidas[][MATRIZ_C], int dimF);
void mostrarComidas(char Comidas[][MATRIZ_C], int validos);
void CargarComidasArchivo(char nombre[], char Comidas[][MATRIZ_C], int dimF);
void mostrarComidasArchivo(char nombre[], char Comidas[][MATRIZ_C]);
char VerificarSiExisteComidas(char nombreArchivo[], char Comidas[][MATRIZ_C]);
void BorrarComidaEspecifica(char Comidas[][MATRIZ_C], int dimF, char comida[]);
void modificarComida(char Comidas[][MATRIZ_C], int dimF, char comidaModificar[], char nuevaComida[]);
void BorrarTodasLasComidas(char Comidas[][MATRIZ_C], int dimF);
void GuardarCambiosArchivo(char nombre[], char Comidas[][MATRIZ_C], int dimF);

#endif /* COMIDAS_H */
