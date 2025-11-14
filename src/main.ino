#include "hardware.h"
#include "teclado.h"

void setup() {
    Serial.begin(9600);
    inicializarHardware();
}

void loop() {

    bool tocou = false;

    // ---------------------------------------------------
    // LEITURA DOS BOTÕES FÍSICOS
    // ---------------------------------------------------
    for (int i = 0; i < NUM_NOTAS; i++) {
        if (digitalRead(buttonPins[i]) == HIGH) {
            acionaNotaFisica(i);
            tocou = true;
        } else {
            digitalWrite(ledPins[i], LOW);
        }
    }

    // ---------------------------------------------------
    // LEITURA DO TECLADO NO MONITOR SERIAL
    // ---------------------------------------------------
    if (Serial.available() > 0) {
        char tecla = Serial.read();

        int indice = verificarTeclaDigitada(tecla);

        if (indice != -1) {
            acionaNotaViaSerial(indice);
            tocou = true;
        }
    }

    // ---------------------------------------------------
    // SE NADA ESTÁ SENDO ACIONADO, DESLIGA O BUZZER
    // ---------------------------------------------------
    if (!tocou) {
        noTone(buzzerPin);
    }
}
