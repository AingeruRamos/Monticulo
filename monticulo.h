#ifndef _MONTICULO_H_
#define _MONTICULO_H_

//LIBRERÍAS USADAS
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
    int num_elementos;
    int* array;
} Monticulo;

//DECLARACIÓN FUNCIONES PRINCIPALES

/*
 * @name: CrearMonticulo
 * @desc: Crea un montículo con las características y valores indicados por parametros
 * @params:
 *      @param: Tipo de montículo (MAX o MIN)
 *      @param: Método con el que se quiere construir el árbol (HUNDIR o FLOTAR)
 *      @param: Número de elementos del montículo
 *      @param: Array donde se albergan los valores del montículo
 * @return: Monticulo* -> Dirección del monticulo
 */
Monticulo* CrearMonticulo(char tipo, char metodo, int num_elementos, int* array);


/*
 * @name: FlotarMaximo
 * @desc: Dado el indice del elemento este "flota" en el montículo 
 *          si es MAYOR que su padre
 * @params:
 *      @param: Indice del elemento a "flotar"
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: none
 */
void FlotarMaximo(int indice_elem, Monticulo* m);

/*
 * @name: FlotarMinimo
 * @desc: Dado el indice del elemento este "flota" en el montículo 
 *          si es MENOR que su padre
 * @params:
 *      @param: Indice del elemento a "flotar"
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: none
 */
void FlotarMinimo(int indice_elem, Monticulo* m);


/*
 * @name: HundirMinimo
 * @desc: Dado el indice del elemto este se "hunde" en el montículo 
 *          si es MENOR que cualquiera de sus hijos
 * @params:
 *      @param: Indice del elemento a "hundir"
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: none
 */
void HundirMinimo(int indice_elem, Monticulo* m);

/*
 * @name: HundirMaximo
 * @desc: Dado el indice del elemto este se "hunde" en el montículo 
 *          si es MAYOR que cualquiera de sus hijos
 * @params:
 *      @param: Indice del elemento a "hundir"
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: none
 */
void HundirMaximo(int indice_elem, Monticulo* m);

/*
 * @name: Insertar
 * @desc: Inserta el valor indicado en el montículo
 * @params:
 *      @param: Valor a insertar en el montículo
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @precondition: El array donde se guardan los valores debe tener espacio para albergar el elemento.
 *                  length(array) < m->num_elementos
 * @return: none
 */
void Insertar(int elem, Monticulo* m);

/*
 * @name: RetirarRaiz
 * @desc: Retira la raiz del monticulo y devuelve su valor
 * @params:
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: El valor de la raiz extraida
 */
int RetirarRaiz(Monticulo* m);

/*
 * @name: Eliminar
 * @desc: Elimina del montículo el elemento indicado y devuelve su valor
 * @params:
 *      @param: Indice del elemento a eliminar
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: Valor del elemento eliminado
 */
int Eliminar(int indice_elem, Monticulo* m);


/*
 * @name: PrintMonticulo
 * @desc: Imprime las características y valores del montículo
 * @params:
 *      @param: Dirección del monticulo sobre el que se quiere operar
 * @return: none
 */
void PrintMonticulo(Monticulo* m);

#endif
