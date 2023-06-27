#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_AUTOS 10

 char codigo[MAX_AUTOS][20];
    char nombre[MAX_AUTOS][50];
    char marca[MAX_AUTOS][50];
    int cantidad[MAX_AUTOS];
    float precio[MAX_AUTOS];
    int numAutos = 0;
    int opcion;

// funcion ver menu
int menuPrincipal(){
    int opcion1;
     printf("----- INVENTARIO UDLACAR -----\n");
        printf("1. Ver autos\n");
        printf("2. Ingresar auto\n");
        printf("3. Modificar auto\n");
        printf("4. Eliminar auto\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion1);
         return opcion1;
}
    
// Función para mostrar los autos
void verAutos(char codigo[][20], char nombre[][50], char marca[][50], int cantidad[], float precio[], int numAutos) {
    if (numAutos == 0) {
        printf("No hay autos en el inventario.\n");
        return;
    }

    printf("----- Autos -----\n");
    for (int i = 0; i < numAutos; i++) {
        printf("Codigo: %s\n", codigo[i]);
        printf("Nombre: %s\n", nombre[i]);
        printf("Marca: %s\n", marca[i]);
        printf("Cantidad: %d\n", cantidad[i]);
        printf("Precio: %.2f\n", precio[i]);
        printf("-----------------\n");
    }
}

// Función para ingresar un nuevo auto
void ingresarAuto(char codigo[][20], char nombre[][50], char marca[][50], int cantidad[], float precio[], int* numAutos) {
    if (*numAutos == MAX_AUTOS) {
        printf("No se pueden ingresar mas autos. El inventario esta lleno.\n");
        return;
    }

    printf("Ingrese el codigo del auto: ");
    scanf("%s", codigo[*numAutos]);
    printf("Ingrese el nombre del auto: ");
    scanf("%s", nombre[*numAutos]);
    printf("Ingrese la marca del auto: ");
    scanf("%s", marca[*numAutos]);
    printf("Ingrese la cantidad de autos: ");
    scanf("%d", &cantidad[*numAutos]);
    printf("Ingrese el precio del auto: ");
    scanf("%f", &precio[*numAutos]);

    (*numAutos)++;
    printf("Auto ingresado correctamente.\n");
}

// Función para modificar un auto existente
void modificarAuto(char codigo[][20], char nombre[][50], char marca[][50], int cantidad[], float precio[], int numAutos) {
    if (numAutos == 0) {
        printf("No hay autos en el inventario.\n");
        return;
    }

    char codigoBuscar[20];
    printf("Ingrese el codigo del auto a modificar: ");
    scanf("%s", codigoBuscar);

    int encontrado = 0;
    for (int i = 0; i < numAutos; i++) {
        if (strcmp(codigo[i], codigoBuscar) == 0) {
            printf("Ingrese el nuevo nombre del auto: ");
            scanf("%s", nombre[i]);
            printf("Ingrese la nueva marca del auto: ");
            scanf("%s", marca[i]);
            printf("Ingrese la nueva cantidad de autos: ");
            scanf("%d", &cantidad[i]);
            printf("Ingrese el nuevo precio del auto: ");
            scanf("%f", &precio[i]);
            printf("Auto modificado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro ningun auto con ese codigo.\n");
    }
}

// Función para eliminar un auto
void eliminarAuto(char codigo[][20], char nombre[][50], char marca[][50], int cantidad[], float precio[], int* numAutos) {
    if (*numAutos == 0) {
        printf("No hay autos en el inventario.\n");
        return;
    }

    char codigoBuscar[20];
    printf("Ingrese el codigo del auto a eliminar: ");
    scanf("%s", codigoBuscar);

    int encontrado = 0;
    for (int i = 0; i < *numAutos; i++) {
        if (strcmp(codigo[i], codigoBuscar) == 0) {
            for (int j = i; j < (*numAutos) - 1; j++) {
                strcpy(codigo[j], codigo[j + 1]);
                strcpy(nombre[j], nombre[j + 1]);
                strcpy(marca[j], marca[j + 1]);
                cantidad[j] = cantidad[j + 1];
                precio[j] = precio[j + 1];
            }
            (*numAutos)--;
            printf("Auto eliminado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro ningun auto con ese codigo.\n");
    }
}