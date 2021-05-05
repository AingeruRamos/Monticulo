#include <stdio.h>
#include <string.h>

#include "monticulo.h"

int main(int argc, char** argv) {

    if(argc != 2) {
        printf("Modo de uso: ./main tipo_monticulo\n");
        printf("Tipos de monticulos:\nmin\nmax\n");
        return -1;
    }

    int tipo;
    if(strcmp(argv[1], "max") == 0) {
        tipo = MONTICULO_MAX;
    } else if(strcmp(argv[1], "min") == 0) {
        tipo = MONTICULO_MIN;
    } else {
        printf("Tipos de monticulos:\nmin\nmax\n");
        return -2;
    }

    int array[13] = {6, 4, 15, 2, 10, 11, 8, 1, 1, 7, 9, 12, 0};

    Monticulo* m = CrearMonticulo(tipo, 12, array);
    PrintMonticulo(m);

    Insertar(3, m);
    PrintMonticulo(m);

    return 0;
}