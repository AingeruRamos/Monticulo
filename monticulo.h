#ifndef _MONTICULO_H_
#define _MONTICULO_H_

#define MONTICULO_MIN 0
#define MONTICULO_MAX 1

#define METODO_FLOTAR 0
#define METODO_HUNDIR 1

typedef struct Monticulo {
    char tipo;
    char metodo;
    int num_elementos;
    int* array;
} Monticulo;

Monticulo* CrearMonticulo(char tipo, char metodo, int num_elementos, int* array);

void FlotarMaximo(int indice_elem, Monticulo* m);
void FlotarMinimo(int indice_elem, Monticulo* m);

void HundirMinimo(int indice_elem, Monticulo* m);
void HundirMaximo(int indice_elem, Monticulo* m); //Pendiente

void Insertar(int elem, Monticulo* m);
void Eliminar(int indice_elem, Monticulo* m); //Pendiente

void PrintMonticulo(Monticulo* m);

#endif
