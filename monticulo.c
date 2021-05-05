#include "monticulo.h"

#include <stdio.h>
#include <stdlib.h>

Monticulo* CrearMonticulo(char tipo, int num_elementos, int* array) {
    Monticulo* m = (Monticulo*) malloc(sizeof(Monticulo));
    m->tipo = tipo;
    m->num_elementos = num_elementos;
    m->array = array;

    int i;
    if(m->tipo == MONTICULO_MIN) { //De menor a mayor
        for(i=1; i<m->num_elementos; i++) {
            FlotarMinimo(i, m);
        }
    } else if(m->tipo == MONTICULO_MAX) { //De mayor a menor
        for(i=1; i<m->num_elementos; i++) {
            FlotarMaximo(i, m);
        }
    }

    return m;
}

void FlotarMaximo(int indice_elem, Monticulo* m) {
    int j = indice_elem;

    int padre = j/2;
    if(j % 2 == 0) { padre--; }

    int aux;
    while(m->array[padre] < m->array[j]) {
        //Intercambio de posiciones
        aux = m->array[j];
        m->array[j] = m->array[padre];
        m->array[padre] = aux;

        //Subimos al nodo padre
        j = padre;
        padre = j/2;
        if(j % 2 == 0) { padre--; }
    }
}

void FlotarMinimo(int indice_elem, Monticulo* m) {
    int j = indice_elem;

    int padre = j/2;
    if(j % 2 == 0) { padre--; }
    //printf("%d\n", m->array[padre]);
    int aux;
    int flag = 0;
    while(j > 0 && m->array[padre] > m->array[j]) {
        //Intercambio de posiciones
        aux = m->array[j];
        m->array[j] = m->array[padre];
        m->array[padre] = aux;
        //Subimos al nodo padre
        j = padre;
        padre = j/2;
        if(j % 2 == 0) { padre--; }
    }
}

void Insertar(int elem, Monticulo* m) {
    m->num_elementos++;
    m->array[m->num_elementos-1] = elem;
    if(m->tipo == MONTICULO_MIN) {
        FlotarMinimo(m->num_elementos-1, m);
    } else {
        FlotarMaximo(m->num_elementos-1, m);
    }
}

void Eliminar(int indice_elem, Monticulo* m) {
    
}

void PrintMonticulo(Monticulo* m) {
    char* tipo;
    if(m->tipo == MONTICULO_MIN) { tipo = "min"; }
    else { tipo = "max"; }

    printf("---------------------------------\n");
    printf("Montículo\n");
    printf("Tipo: %s\t Tamaño: %d\n", tipo, m->num_elementos);

    printf("\nValores del montículo:\n");
    int i;
    for(i=0; i<m->num_elementos; i++) {
        printf("%d ", m->array[i]);
    }
    printf("\n---------------------------------\n\n");
}
