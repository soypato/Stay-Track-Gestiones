#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "botellas.h"
#include "tipoUsuario.h"

///Nombre del archivo
const char Arch[]="BotellasFrigo.dat";



// Arrancamos el menu de botellas que se invoca desde el main
int menuBotellas()
{
    int op = 0;
    char decision = 's';
    char marcaTemporal[50]; ///Case 5. String  temporal que busca el nombre de la botella
    int idTemporal; ///Case 6. Variable temporal para buscar el ID de la botella y luego modificarlo

    do
    {
        printf("==========================================\n");
        printf("|              Menu botellas               |\n");
        printf("==========================================\n");
        printf("| Opcion |           Descripcion           |\n");
        printf("===========================================\n");
        printf("|   1    | Agregar botella                 |\n");
        printf("|   2    | Mostrar botellas                |\n");
        printf("|   3    | Ordenar botellas por marca      |\n"); // INSERCION
        printf("|   4    | Ordenar botellas por ID         |\n"); // SELECCION
        printf("|   5    | Buscar  Marca                   |\n");
        printf("|   6    | Modificar Segun usuario         |\n");
        printf("|   0    | Volver                          |\n");
        printf("==========================================\n");
        printf("Su decision: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            cargarBotellasArchivo(Arch);
            break;
        case 2:
            mostrarTodoElArchivoDeBotellas(Arch);
            break;
        case 3:
            ordenarBotellasPorMarca(Arch);
            break;
        case 4:
            ordenarBotellasPorID(Arch);
            break;
        case 5:
            printf("Ingrese la marca a buscar: ");
            fflush(stdin);
            gets(marcaTemporal);
            buscarBotellasPorMarca(Arch, marcaTemporal);
            break;
        case 6:
            printf("Ingrese la id para modificar\n");
            scanf("%d", &idTemporal);
            ModificarSegunUsuario(Arch, idTemporal);
            break;
        case 0:
            volverDependiendoTipoUsuario(tipoUsuario);
            break;
        }

        printf("Seguir ejecutando? (s/n): ");
        fflush(stdin);
        scanf(" %c", &decision);
    }
    while (decision == 's');


    return 0;
}

///Funcion que carga una botella


// Carga de botellas

botellita cargarBotellas(botellita botellaTemporal)
{
    printf("Ingrese la marca de la botella: ");
    fflush(stdin);
    gets(botellaTemporal.marca);

    printf("Es retornable? (0 para si / 1 para no): ");
    scanf("%i", &botellaTemporal.retornable);

    // omitimos la toma de la id porque la pedimos anteriormente

    return botellaTemporal;
}

///Función que verifica si ya existe el ID de una botella


// Comprobación de ID existente

int verificarIDExistente(char nombre[], int id)
{
    FILE* archivo = fopen(nombre, "rb");
    int idExistente = 0;

    if (archivo)
    {
        botellita botella;
        while (fread(&botella, sizeof(botellita), 1, archivo) > 0)
        {
            if (botella.id == id)
            {
                idExistente = 1; // ID existe
                break;
            }
        }
        fclose(archivo);
    }

    return idExistente; // 0 si el ID no existe, 1 si existe
}


///Funcion que carga en el archivo y verifica al momento de cargar si ya existe un ID

// Carga de botellas de archivo

void cargarBotellasArchivo(char nombre[])
{
    FILE* Archi = fopen(nombre, "wb");
    char decision = 's';
    int idExistente = 0;
    botellita temp;
    if (Archi != NULL)
    {
        while (decision == 's')
        {
            printf("Ingrese el ID de la botella: ");
            scanf("%d", &temp.id);

            // Verificar si el ID ya existe en el archivo
            idExistente = verificarIDExistente(nombre, temp.id);

            if (idExistente) ///Si retorna 1, existe el ID
            {
                printf("El ID de botella ya existe. No se puede agregar.\n");
            }
            else ///Sino, carga normalmente
            {
                temp = cargarBotellas(temp);
                fwrite(&temp, sizeof(botellita), 1, Archi);
            }

            printf("Desea seguir cargando? (s/n): ");
            scanf(" %c", &decision);
        }
        fclose(Archi);
    }
    else
    {
        printf("Error en la carga del archivo.\n");
    }
}

///Función que muestra la botella


// Impresión de una botellas

void mostrarBotella(botellita deMuestra)
{
    char textoRetornable[50];

    if(deMuestra.retornable == 0)
    {
        strcpy(textoRetornable, "si, es retornable");
    }
    else if(deMuestra.retornable == 1)
    {
        strcpy(textoRetornable, "no, no es retornable");
    }
    else
    {
        strcpy(textoRetornable, "no se proporcionarodn datos");
    }
    printf("-----------\n");
    printf("Marca: %s\n", deMuestra.marca);
    printf("ID o codigo de barras: %i\n", deMuestra.id);
    printf("Es retornable? %s\n", textoRetornable);
    printf("-----------\n");

}

///Función que muestra las botellas en un archivo


// Muestreo de todo el archivo de todas las botellas

void mostrarTodoElArchivoDeBotellas(char nombre[])
{
    FILE* buffer = fopen(nombre, "rb");
    botellita temp;
    if(buffer)
    {
        while(fread(&temp, sizeof(botellita), 1, buffer) > 0)
        {
            mostrarBotella(temp);
        }
    }
    else
    {
        printf("Error en la apertura del archivo.\n");
    }

}

///Ordena por inserccion La marca de las botellas


// Ordenamiento por inserción

void ordenarBotellasPorMarca(char nombre[])
{
    FILE* archivo = fopen(nombre, "rb+");
    if (archivo)
    {
        fseek(archivo, 0, SEEK_END);
        int totalBotellas = ftell(archivo) / sizeof(botellita);
        rewind(archivo);

        botellita* botellas = (botellita*)malloc(totalBotellas * sizeof(botellita));
        if (botellas)
        {
            fread(botellas, sizeof(botellita), totalBotellas, archivo);

            for (int i = 1; i < totalBotellas; i++)
            {
                botellita temp = botellas[i];
                int j = i - 1;
                while (j >= 0 && strcmp(botellas[j].marca, temp.marca) > 0)
                {
                    botellas[j + 1] = botellas[j];
                    j--;
                }
                botellas[j + 1] = temp;
            }

            rewind(archivo);
            fwrite(botellas, sizeof(botellita), totalBotellas, archivo);

            free(botellas); ///Liberamos memoria que usaba botellas
            fclose(archivo);
            printf("Botellas ordenadas por marca.\n");
        }
        else
        {
            printf("Error: no se pudo asignar memoria.\n");
        }
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
}

///Función que ordena por selección el ID de las botellas


// Ordenamiento por selección

void ordenarBotellasPorID(char nombre[])
{
    FILE* archivo = fopen(nombre, "rb+");
    if (archivo)
    {
        fseek(archivo, 0, SEEK_END);
        int totalBotellas = ftell(archivo) / sizeof(botellita);
        rewind(archivo);

        botellita* botellas = (botellita*)malloc(totalBotellas * sizeof(botellita));
        if (botellas)
        {
            fread(botellas, sizeof(botellita), totalBotellas, archivo);

            for (int i = 0; i < totalBotellas - 1; i++)
            {
                int minIdx = i;
                for (int j = i + 1; j < totalBotellas; j++)
                {
                    if (botellas[j].id < botellas[minIdx].id)
                    {
                        minIdx = j;
                    }
                }
                if (minIdx != i)
                {
                    botellita temp = botellas[i];
                    botellas[i] = botellas[minIdx];
                    botellas[minIdx] = temp;
                }
            }

            rewind(archivo);
            fwrite(botellas, sizeof(botellita), totalBotellas, archivo);

            free(botellas);
            fclose(archivo);
            printf("Botellas ordenadas por ID.\n");
        }
        else
        {
            printf("Error: no se pudo asignar memoria.\n");
        }
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
}


///Función que busca una botella según la marca

// Búsqueda de las botellas por marca

void buscarBotellasPorMarca(char nombre[], const char* marcaBuscada)
{
    FILE* archivo = fopen(nombre, "rb");
    if (archivo)
    {
        botellita botella;
        int encontradas = 0;

        while (fread(&botella, sizeof(botellita), 1, archivo) > 0)
        {
            if (strcmp(botella.marca, marcaBuscada) == 0)
            {
                mostrarBotella(botella);
                encontradas++;
            }
        }

        if (encontradas == 0)
        {
            printf("No se encontraron botellas con la marca '%s'.\n", marcaBuscada);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
}

///Función que permite modificar Algún campo de la botella


// Modificación según el usuario, modifica pidiendo el ID

void ModificarSegunUsuario(char nombre[], int id)
{
    FILE* Archi;
    Archi = fopen(nombre, "r+b");
    int nuevaId;
    char nuevaMarca[10];
    botellita temp;
    int nuevaRetorn;
    int decision = 1;

    if (Archi != NULL)
    {
        fseek(Archi, sizeof(botellita) * (id - 1), SEEK_SET);
        fread(&temp, sizeof(botellita), 1, Archi);

        do
        {
            // Dependiendo el case modifica uno u otro
            printf("¿Qué desea modificar de la botella?\n");
            printf("==========================================\n");
            printf("|              Cambios               |\n");
            printf("==========================================\n");
            printf("| Opcion |           Descripcion           |\n");
            printf("==========================================\n");
            printf("|   1    | Modificar id                    |\n");
            printf("|   2    | Modificar Marca                 |\n");
            printf("|   3    | Modificar Retornabilidad        |\n");
            printf("|   0    | Salir                           |\n");
            printf("==========================================\n");
            scanf("%d", &decision);

            switch (decision)
            {
            case 1:
                printf("Ingrese el nuevo id a modificar: ");
                scanf("%d", &nuevaId);
                temp.id = nuevaId;
                printf("Se realizó con éxito la modificación!\n");
                break;

            case 2:
                printf("Ingrese la marca a modificar: ");
                scanf("%9s", nuevaMarca);
                strcpy(temp.marca, nuevaMarca);
                printf("Se realizó con éxito la modificación!\n");
                break;

            case 3:
                printf("Ingrese la nueva retornabilidad (0 o 1): ");
                while (scanf("%d", &nuevaRetorn) != 1 || (nuevaRetorn != 0 && nuevaRetorn != 1))
                {
                    printf("El dato ingresado no es válido. Intente nuevamente (0 o 1): ");
                    fflush(stdin);
                }
                temp.retornable = nuevaRetorn;
                printf("Se realizó con éxito la modificación!\n");
                break;

            case 0:
                fclose(Archi);
                return;
            }
            // Lo guardamos en el archivo
            fseek(Archi, sizeof(botellita) * (id - 1), SEEK_SET);
            fwrite(&temp, sizeof(botellita), 1, Archi);
            fflush(Archi);

            printf("¿Quiere seguir modificando? (1: Sí / 0: No): ");
            scanf("%d", &decision);

        }
        while (decision == 1);

        fclose(Archi);
    }
}

