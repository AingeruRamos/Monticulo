#include <stdio.h>
#include <string.h>

#include "monticulo.h"

#define ERROR_PARAMETROS -1
#define ERROR_TIPO_MONTICULO -2
#define ERROR_METODO -3

int main(int argc, char** argv) {

    //Control de los parámetros de entrada
    if(argc != 3) {
        printf("Modo de uso: ./main tipo_monticulo metodo\n");
        printf("Tipos de monticulos:\nmin\nmax\n");
        printf("Metodos:\nflotar\nhundir\n");
        return ERROR_PARAMETROS;
    }

    //Control del tipo de montículo
    char tipo;
    if(strcmp(argv[1], "max") == 0) {
        tipo = MONTICULO_MAX;
    } else if(strcmp(argv[1], "min") == 0) {
        tipo = MONTICULO_MIN;
    } else {
        printf("Tipos de monticulos:\nmin\nmax\n");
        return ERROR_TIPO_MONTICULO;
    }

    //Control del método de operación
    char metodo;
    if(strcmp(argv[2], "flotar") == 0) {
        metodo = METODO_FLOTAR;
    } else if(strcmp(argv[2], "hundir") == 0) {
        metodo = METODO_HUNDIR;
    } else {
        printf("Metodos:\nflotar\nhundir\n");
        return ERROR_METODO;
    }

    //Declaración del array
    int array[13] = {6, 4, 15, 2, 10, 11, 8, 1, 1, 7, 9, 12, 0};

    //Creación del montículo
    Monticulo* m = CrearMonticulo(tipo, metodo, 12, array);
    PrintMonticulo(m); /* Imprimir el montículo */

    //Operaciones sobre el montículo
    Eliminar(0, m);
    PrintMonticulo(m); /* Imprimir el montículo */

    Insertar(3, m);
    PrintMonticulo(m); /* Imprimir el montículo */

    return 0;
}