#include <stdlib.h>
#include <stdio.h>

int tipoUsuario; //Con esto lo que hicimos fue exportar una variable de forma externa al resto del codigo
void volverDependiendoTipoUsuario (int tipoUsuario)
{
    limpiarPantalla();
    // dependiendo el ID del usuario (no la pass)
    if (tipoUsuario == 1)
    {
        controlMozo();
    }else if (tipoUsuario == 2)
    {
        controlRecepcionista();
    }else if (tipoUsuario == 3)
    {
        controlLimpieza();
    }else if (tipoUsuario == 4)
    {
        controlAdmin();
    }
}
