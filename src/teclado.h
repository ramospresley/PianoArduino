#ifndef TECLADO_H
#define TECLADO_H

#include <Arduino.h>
#include "notas.h"

extern char teclasPC[NUM_NOTAS];
extern char teclasNum[NUM_NOTAS];

int verificarTeclaDigitada(char tecla);

#endif
