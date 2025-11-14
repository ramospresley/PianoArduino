# Piano Arduino – Mini Piano com Botões e Teclado do PC

Projeto desenvolvido como atividade avaliativa da disciplina de Tecnologia da Informação (TI) no curso Técnico em Desenvolvimento de Sistemas da ETEC Martin Luther King, durante o 3º semestre de 2025.

O objetivo é demonstrar, de forma prática, o uso de eletrônica básica, lógica de programação e modularização em C++ aplicadas ao Arduino.  
O sistema consiste em um **mini piano eletrônico**, onde cada uma das nove notas musicais pode ser acionada de três maneiras:

1. **Botões físicos conectados ao Arduino UNO**  
2. **LEDs que acendem conforme a nota tocada**  
3. **Teclas do computador via Monitor Serial**, usando:
   - Letras: **A S D F G H J K L**
   - Números: **1 2 3 4 5 6 7 8 9**

O buzzer foi configurado para emitir áudio limpo, sem ruído, e todo o código foi modularizado em múltiplos arquivos, simulando um projeto real.

---

## 🎵 Funcionalidades

- 9 notas musicais (Dó a Ré da oitava superior).  
- LEDs que indicam visualmente a nota acionada.  
- Controle por botões físicos.  
- Controle alternativo pelo teclado do PC via Serial.  
- Projeto organizado em múltiplos arquivos (`.ino`, `.h`, `.cpp`).  
- Totalmente compatível com Tinkercad e Arduino IDE.

---

## 📁 Estrutura do Projeto

/piano-arduino
│
├── src/
│ ├── main.ino
│ ├── notas.h
│ ├── teclado.h
│ ├── teclado.cpp
│ ├── hardware.h
│ ├── hardware.cpp
│
├── README.md
└── LICENSE

---

## 🔧 Hardware Utilizado

- **Arduino UNO**
- 9 Botões (push-buttons)
- 9 LEDs
- 9 Resistores para LEDs (220 Ω)
- 1 Buzzer piezo
- Jumpers e protoboard

---

## ▶️ Como Testar no Tinkercad

1. Crie um novo circuito.  
2. Monte a estrutura com os pinos conforme especificado no código.  
3. Copie os arquivos da pasta `src` para o editor do Tinkercad.  
4. Abra o **Monitor Serial**, digite as teclas A–L ou 1–9 e teste as notas.  

---

## 📜 Licença

Este projeto está disponível sob a licença MIT.  
Consulte o arquivo `LICENSE` para mais detalhes.

---

## 🔗 Repositório Oficial

O projeto completo pode ser encontrado em:

**https://github.com/ramospresley**

---

## 💡 Autor

Desenvolvido por **Elvis Presley Ramos Miranda da Conceição**  
Técnico em Desenvolvimento de Sistemas – ETEC MLK (2025)

---
"# financecontrol" 
