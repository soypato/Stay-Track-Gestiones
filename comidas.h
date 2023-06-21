#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

#define MATRIZ_S 30
#define MATRIZ_F 3



typedef struct ///Arreglo de palabras/strings
{
    char comida[MATRIZ_F][MATRIZ_S];
    char postre[MATRIZ_F][MATRIZ_S];
    char fruta[MATRIZ_F][MATRIZ_S];

} Alimento;




int CargarAlimentos(Alimento[][MATRIZ_S], int);
void mostrarAlimentos(Alimento, int);
void CargarAlimentosArchivo(char[], int );
void mostrarAlimentosArchivo(char[]);





#endif // COMIDAS_H_INCLUDED
