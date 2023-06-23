#ifndef BOTELLAS_H_INCLUDED
#define BOTELLAS_H_INCLUDED
#include "pila.h"


// struct de botellas
typedef struct {
    char marca[50];
    int retornable; // 0 para retornables, 1 para no retornables
    int id; // código de barras para después usarlo en la pila
} botellita;

#define MAX_BOTELLAS 10
// PROTOTIPADO
botellita cargarBotellas(botellita);
void cargarBotellasArchivo(char nombre[]);
void mostrarBotella(botellita deMuestra);
void mostrarTodoElArchivoDeBotellas(char nombre[]);
void ordenarBotellasPorMarca(char nombre[]);
void ordenarBotellasPorID(char nombre[]);
void buscarBotellasPorMarca(char nombre[], const char* marcaBuscada);
int verificarIDExistente(char nombre[], int id);
void ModificarSegunUsuario(char[], int);






#endif // BOTELLAS_H_INCLUDED
