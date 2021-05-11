#include "monticulo.h"

//DECLARACIÓN FUNCIONES AUXILIARES
void intercambio(int* p1, int* p2);

///////////////////////////////////////////////
//  IMPLEMENTACIÓN DE FUNCIONES PRINCIPALES  //
///////////////////////////////////////////////
Monticulo* CrearMonticulo(char tipo, char metodo, int num_elementos, int* array) {

    //Se crea la estructura en memoria y se rellena
    Monticulo* m = (Monticulo*) malloc(sizeof(Monticulo));
    m->tipo = tipo;
    m->num_elementos = num_elementos;
    m->array = array;

    //Se construye el montículo teniendo en cuenta tipo y método:
    int i;
    if(m->tipo == MONTICULO_MIN) { /* Tipo de montículo MIN */
        if(metodo == METODO_FLOTAR) { /* Método de construcción  FLOTAR*/
            for(i=1; i<m->num_elementos; i++) {
                FlotarMinimo(i, m);
            }
        } else if(metodo == METODO_HUNDIR) { /* Método de construcción HUNDIR */
            for(i=m->num_elementos; i>=0; i--) {
                HundirMaximo(i, m);
            }
        }
    } else if(m->tipo == MONTICULO_MAX) { /* Tipo de montículo MAX*/
        if(metodo == METODO_FLOTAR) { /* Método de construcción FLOTAR*/
            for(i=1; i<m->num_elementos; i++) {
                FlotarMaximo(i, m);
            }
        } else if(metodo == METODO_HUNDIR) { /* Método de construcción HUNDIR*/
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
        //Intercambio de posiciones
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
        if(hijoMax+1 < m->num_elementos && m->array[hijoMax+1] > m->array[hijoMax]) {
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
    m->array[m->num_elementos] = elem;
    m->num_elementos++;
    if(m->tipo == MONTICULO_MIN) { FlotarMinimo(m->num_elementos-1, m); } 
    else if(m->tipo == MONTICULO_MAX) { FlotarMaximo(m->num_elementos-1, m); }
}

int RetirarRaiz(Monticulo* m) {
    int aux = m->array[0];
    m->num_elementos--;
    m->array[0] = m->array[m->num_elementos];
    m->num_elementos--;
    if(m->tipo == MONTICULO_MIN) { HundirMaximo(0, m); } 
    else if(m->tipo == MONTICULO_MAX) { HundirMinimo(0, m); }

    return aux;
}

int Eliminar(int indice_elem, Monticulo* m) {
    int aux = m->array[indice_elem];
    m->array[indice_elem] = m->array[m->num_elementos-1];
    m->num_elementos--;
    if(m->tipo == MONTICULO_MIN) { HundirMaximo(indice_elem, m); } 
    else if(m->tipo == MONTICULO_MAX) { HundirMinimo(indice_elem, m); }

    return aux;
}

void PrintMonticulo(Monticulo* m) {
    char* tipo;
    if(m->tipo == MONTICULO_MIN) { tipo = "MIN"; }
    else if(m->tipo == MONTICULO_MAX) { tipo = "MAX"; }

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

///////////////////////////////////////////////
//  IMPLEMENTACIÓN DE FUNCIONES AUXILIARES   //
///////////////////////////////////////////////
void intercambio(int* p1, int* p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}