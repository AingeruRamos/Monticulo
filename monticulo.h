#ifndef _MONTICULO_H_
#define _MONTICULO_H_

#define MONTICULO_MIN 0
#define MONTICULO_MAX 1

typedef struct Monticulo {
    char tipo;
    int num_elementos;
    int* array;
} Monticulo;

Monticulo* CrearMonticulo(char tipo, int num_elementos, int* array);

void FlotarMaximo(int indice_elem, Monticulo* m);

void FlotarMinimo(int indice_elem, Monticulo* m);

void Insertar(int elem, Monticulo* m);

void Eliminar(int indice_elem, Monticulo* m);

void PrintMonticulo(Monticulo* m);

#endif
