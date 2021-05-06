#include <stdio.h>
#include <string.h>

#include "monticulo.h"

int main(int argc, char** argv) {

    if(argc != 3) {
        printf("Modo de uso: ./main tipo_monticulo metodo\n");
        printf("Tipos de monticulos:\nmin\nmax\n");
        printf("Metodos:\nflotar\nhundir\n");
        return -1;
    }

    char tipo;
    if(strcmp(argv[1], "max") == 0) {
        tipo = MONTICULO_MAX;
    } else if(strcmp(argv[1], "min") == 0) {
        tipo = MONTICULO_MIN;
    } else {
        printf("Tipos de monticulos:\nmin\nmax\n");
        return -2;
    }

    char metodo;
    if(strcmp(argv[2], "flotar") == 0) {
        metodo = METODO_FLOTAR;
    } else if(strcmp(argv[2], "hundir") == 0) {
        metodo = METODO_HUNDIR;
    } else {
        printf("Metodos:\nflotar\nhundir\n");
        return -3;
    }

    int array[13] = {6, 4, 15, 2, 10, 11, 8, 1, 1, 7, 9, 12, 0};

    Monticulo* m = CrearMonticulo(tipo, metodo, 12, array);
    PrintMonticulo(m);

    Eliminar(1, m);
    PrintMonticulo(m);

/*
    Insertar(3, m);
    PrintMonticulo(m);
    */

    return 0;
}