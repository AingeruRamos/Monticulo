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
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
Monticulo* CrearMonticulo(char tipo, char metodo, int num_elementos, int* array);


/*
 * @name: FlotarMaximo
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
void FlotarMaximo(int indice_elem, Monticulo* m);

/*
 * @name: FlotarMinimo
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
void FlotarMinimo(int indice_elem, Monticulo* m);


/*
 * @name: HundirMinimo
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
void HundirMinimo(int indice_elem, Monticulo* m);

/*
 * @name: HundirMaximo
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
void HundirMaximo(int indice_elem, Monticulo* m);

/*
 * @name: Insertar
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
void Insertar(int elem, Monticulo* m);

/*
 * @name: RetirarRaiz
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
int RetirarRaiz(Monticulo* m);

/*
 * @name: Eliminar
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
int Eliminar(int indice_elem, Monticulo* m);


/*
 * @name: PrintMonticulo
 * @desc:
 * @params:
 *      @param:
 *      @param:
 *      @param:
 *      @param:
 * @return:
 */
void PrintMonticulo(Monticulo* m);

#endif
