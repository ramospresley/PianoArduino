#include "teclado.h"

char teclasPC[NUM_NOTAS]  = {'A','S','D','F','G','H','J','K','L'};
char teclasNum[NUM_NOTAS] = {'1','2','3','4','5','6','7','8','9'};

int verificarTeclaDigitada(char tecla) {

    for (int i = 0; i < NUM_NOTAS; i++) {
        if (tecla == teclasPC[i] || tecla == teclasPC[i] + 32)
            return i;
    }

    for (int i = 0; i < NUM_NOTAS; i++) {
        if (tecla == teclasNum[i])
            return i;
    }

    return -1;
}
