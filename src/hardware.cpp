#include "hardware.h"

// Definições dos pinos
const int buzzerPin = 8;

const int buttonPins[NUM_NOTAS] = {2, 3, 4, 5, 6, 7, 9, 10, 12};
const int ledPins[NUM_NOTAS]    = {11, 13, A0, A1, A2, A3, A4, A5, A6};

void inicializarHardware() {
    pinMode(buzzerPin, OUTPUT);

    for (int i = 0; i < NUM_NOTAS; i++) {
        pinMode(buttonPins[i], INPUT);
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

void acionaNotaFisica(int index) {
    tone(buzzerPin, notas[index]);
    digitalWrite(ledPins[index], HIGH);
}

void acionaNotaViaSerial(int index) {
    tone(buzzerPin, notas[index]);
    digitalWrite(ledPins[index], HIGH);
    delay(150);
    digitalWrite(ledPins[index], LOW);
    noTone(buzzerPin);
}
