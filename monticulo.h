#ifndef _MONTICULO_H_
#define _MONTICULO_H_

//LIBRERIAS USADAS
#include <stdio.h>
#include <stdlib.h>

//VALORES CONSTANTES
#define MONTICULO_MIN 0
#define MONTICULO_MAX 1

#define METODO_FLOTAR 0
#define METODO_HUNDIR 1

//ESTRUCTURAS DE DATOS
typedef struct Monticulo {
    char tipo;
    char metodo;
    int num_elementos;
    int* array;
} Monticulo;

//FUNCIONES
Monticulo* CrearMonticulo(char tipo, char metodo, int num_elementos, int* array);

void FlotarMaximo(int indice_elem, Monticulo* m);
void FlotarMinimo(int indice_elem, Monticulo* m);

void HundirMinimo(int indice_elem, Monticulo* m);
void HundirMaximo(int indice_elem, Monticulo* m);

void Insertar(int elem, Monticulo* m);
int RetirarRaiz(Monticulo* m);
int Eliminar(int indice_elem, Monticulo* m);

void PrintMonticulo(Monticulo* m);

#endif
