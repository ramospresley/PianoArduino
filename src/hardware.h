#ifndef HARDWARE_H
#define HARDWARE_H

#include "Arduino.h"
#include "notas.h"

extern const int buzzerPin;
extern const int buttonPins[NUM_NOTAS];
extern const int ledPins[NUM_NOTAS];

void inicializarHardware();
void acionaNotaFisica(int index);
void acionaNotaViaSerial(int index);

#endif
