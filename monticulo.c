#include "monticulo.h"

#include <stdio.h>
#include <stdlib.h>

void intercambio(int* p1, int* p2);

Monticulo* CrearMonticulo(char tipo, char metodo, int num_elementos, int* array) {
    Monticulo* m = (Monticulo*) malloc(sizeof(Monticulo));
    m->tipo = tipo;
    m->metodo = metodo;
    m->num_elementos = num_elementos;
    m->array = array;

    int i;
    if(m->tipo == MONTICULO_MIN) { //De menor a mayor
        if(m->metodo == METODO_FLOTAR) {
            for(i=1; i<m->num_elementos; i++) {
                FlotarMinimo(i, m);
            }
        } else if(m->metodo == METODO_HUNDIR) {
            for(i=m->num_elementos; i>=0; i--) {
                HundirMaximo(i, m);
            }
        }
    } else if(m->tipo == MONTICULO_MAX) { //De mayor a menor
        if(m->metodo == METODO_FLOTAR) {
            for(i=1; i<m->num_elementos; i++) {
                FlotarMaximo(i, m);
            }
        } else if(m->metodo == METODO_HUNDIR) {
            for(i=m->num_elementos; i>=0; i--) {
                HundirMinimo(i, m);
            }
        }
    }

    return m;
}

void FlotarMaximo(int indice_elem, Monticulo* m) {
    int j = indice_elem;

    int padre = j/2;
    if(j % 2 == 0) { padre--; }

    int aux;
    while(j > 0 && m->array[padre] < m->array[j]) {
        intercambio(&m->array[j], &m->array[padre]);

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

    int aux;
    while(j > 0 && m->array[padre] > m->array[j]) {
        //Intercambio de posiciones
        intercambio(&m->array[j], &m->array[padre]);

        //Subimos al nodo padre
        j = padre;
        padre = j/2;
        if(j % 2 == 0) { padre--; }
    }
}

void HundirMinimo(int indice_elem, Monticulo* m) {
    int j = indice_elem;

    int hijoMax = (2*j)+1;
    while(hijoMax < m->num_elementos) {
        if(hijoMax < m->num_elementos-1 && m->array[hijoMax+1] > m->array[hijoMax]) {
            hijoMax++;
        }
        if(m->array[j] < m->array[hijoMax]) {
            //Intercambio de posiciones
            intercambio(&m->array[j], &m->array[hijoMax]);

            //Bajamos al nodo hijoMax
            j = hijoMax;
            hijoMax = (2*j)+1;
        } else {
            break;
        }
    }
}

void HundirMaximo(int indice_elem, Monticulo* m) {
    int j = indice_elem;

    int hijoMin = (2*j)+1;
    while(hijoMin < m->num_elementos) {
        if(hijoMin+1 < m->num_elementos && m->array[hijoMin+1] < m->array[hijoMin]) {
            hijoMin++;
        }

        if(m->array[j] > m->array[hijoMin]) {
            //Intercambio de posiciones
            intercambio(&m->array[j], &m->array[hijoMin]);

            //Bajamos al nodo hijoMin
            j = hijoMin;
            hijoMin = (2*j)+1;
        } else {
            break;
        }
    }
}

void Insertar(int elem, Monticulo* m) {
    m->num_elementos++;
    m->array[m->num_elementos-1] = elem;
    if(m->tipo == MONTICULO_MIN) {
        if(m->metodo == METODO_FLOTAR) {
            FlotarMinimo(m->num_elementos-1, m);
        } else if(m->metodo == METODO_HUNDIR) {
            printf("No disponible\n");
        }
    } else {
        if(m->metodo == METODO_FLOTAR) {
            FlotarMaximo(m->num_elementos-1, m);
        } else if(m->metodo == METODO_HUNDIR) {
            HundirMinimo(0, m);
        }
    }
}

void Eliminar(int indice_elem, Monticulo* m) {}

void PrintMonticulo(Monticulo* m) {
    char* tipo;
    if(m->tipo == MONTICULO_MIN) { tipo = "MIN"; }
    else if(m->tipo == MONTICULO_MAX) { tipo = "MAX"; }

    char* metodo;
    if(m->metodo == METODO_FLOTAR) { metodo = "FLOTAR"; }
    else if(m->metodo == METODO_HUNDIR) { metodo = "HUNDIR"; }

    printf("---------------------------------\n");
    printf("Montículo\n");
    printf("Tipo: %s\t Metodo: %s\n", tipo, metodo);
    printf("Tamaño: %d\n", m->num_elementos);

    printf("\nValores del montículo:\n");
    int i;
    for(i=0; i<m->num_elementos; i++) {
        printf("%d ", m->array[i]);
    }
    printf("\n---------------------------------\n\n");
}

//FUNCIONES AUXILIARES
void intercambio(int* p1, int* p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}