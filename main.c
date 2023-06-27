#include <stdio.h>
#include <string.h>
#include "funciones.h"

// maximo de autos (se lo puede cambiar)
#define MAX_AUTOS 10

int main()
{
    char codigo[MAX_AUTOS][20];
    char nombre[MAX_AUTOS][50];
    char marca[MAX_AUTOS][50];
    int cantidad[MAX_AUTOS];
    float precio[MAX_AUTOS];
    int numAutos = 0;
    int opcion;

    while (1)
    {

        opcion = menuPrincipal();

        switch (opcion)
        {
        case 1:
            verAutos(codigo, nombre, marca, cantidad, precio, numAutos);
            break;
        case 2:
            ingresarAuto(codigo, nombre, marca, cantidad, precio, &numAutos);
            break;
        case 3:
            modificarAuto(codigo, nombre, marca, cantidad, precio, numAutos);
            break;
        case 4:
            eliminarAuto(codigo, nombre, marca, cantidad, precio, &numAutos);
            break;
        case 5:
            printf("Saliendo del programa.\n");
            return 0;
        default:
            printf("Opción inválida. Por favor, intente nuevamente.\n");
            break;
        }
    }

    return 0;
}
