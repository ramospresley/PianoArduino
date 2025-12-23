// -------------------------------------------------
// NOTAS MUSICAIS (9 notas)
// -------------------------------------------------
// Array com as frequências em Hertz de cada nota musical
// Cada índice corresponde a uma nota específica
const int notas[] = {
  262,  // Do  (C4) - Nota mais grave
  294,  // Re  (D4)
  330,  // Mi  (E4)
  349,  // Fa  (F4)
  392,  // Sol (G4)
  440,  // La  (A4) - Nota padrão de afinação (440Hz)
  494,  // Si  (B4)
  523,  // Do  (C5) - Uma oitava acima
  587   // Re  (D5)
};

const int numKeys = 9; // Número total de teclas/notas disponíveis

// -------------------------------------------------
// PINOS
// -------------------------------------------------
const int buzzerPin = 8;  // Pino onde o buzzer/speaker está conectado
// Cada botão corresponde a uma nota musical
const int buttonPins[numKeys] = {2, 3, 4, 5, 6, 7, 9, 10, 12};

// -------------------------------------------------
// VARIÁVEIS PARA DEBOUNCE
// -------------------------------------------------
// Debounce é necessário para evitar leituras falsas do botão devido a ruídos elétricos
unsigned long ultimoDebounceTime[numKeys] = {0};  // Armazena o último momento que cada botão mudou de estado
const unsigned long debounceDelay = 50;  // Tempo de espera em milissegundos para considerar mudança válida
int ultimoEstadoBotao[numKeys] = {HIGH};  // Estado anterior de cada botão (HIGH = não pressionado)
int estadoBotao[numKeys] = {HIGH};  // Estado atual de cada botão após debounce
bool botaoPressionado[numKeys] = {false};  // Flag que indica se botão está pressionado no momento

// -------------------------------------------------
// TECLAS DO PC E NUMÉRICAS
// -------------------------------------------------
// Mapeamento de teclas do teclado do PC para as notas
// Teclas A-L (letras) correspondem às notas
char teclasPC[numKeys]  = {'A','S','D','F','G','H','J','K','L'};
// Teclas numéricas 1-9 também correspondem às notas
char teclasNum[numKeys] = {'1','2','3','4','5','6','7','8','9'};

// -------------------------------------------------
// MÚSICAS
// -------------------------------------------------
// Cada música é representada por dois arrays:
// 1. Array de bytes: indica qual nota tocar (índice + 1)
// 2. Array de ints: indica a duração de cada nota em milissegundos

// HAPPY BIRTHDAY - VERSÃO ESTENDIDA (48 notas)
// Notas são representadas por números de 1 a 9, onde 1=Do(C4) até 9=Re(D5)
byte happyNotes[] = {
  // Primeira estrofe
  5,5,6,5,8,7,                    // Happy birthday to you
  5,5,6,5,9,8,                    // Happy birthday to you
  5,5,5,3,8,7,6,                  // Happy birthday dear [nome]
  4,4,3,1,2,1,                    // Happy birthday to you
  
  // Segunda estrofe (variação)
  5,5,6,5,8,7,                    // May all your dreams come true
  5,5,6,5,9,8,                    // May angels watch over you
  5,5,5,3,8,7,6,                  // Happy birthday once again
  8,8,7,5,6,5,1,                  // And many more to you!
  
  // Refrão instrumental
  1,3,5,8,5,3,1,                  // Melodia ascendente
  8,7,6,5,4,3,2,1,                // Melodia descendente
  5,5,6,5,8,7,5,5,6,5,9,8        // Tema final
};

// Duração de cada nota na música Happy Birthday (em ms)
int happyDurations[] = {
  400,400,800,800,800,1200,
  400,400,800,800,800,1200,
  400,400,800,800,400,400,1200,
  400,400,800,800,800,1200,
  
  400,400,800,800,800,1200,
  400,400,800,800,800,1200,
  400,400,800,800,400,400,1200,
  400,400,800,800,800,1500,
  
  400,400,400,400,400,400,1200,
  400,400,400,400,400,400,400,1200,
  400,400,400,400,400,400,400,400,400,400,400,1500
};

int happySize = 48; // Número total de notas na música

// HINO DA ALEGRIA - VERSÃO COMPLETA (85 notas)
byte hinoNotes[] = {
  // Primeira estrofe
  3,3,4,5,5,4,3,2,1,1,2,3,3,2,2,
  // Segunda estrofe  
  3,3,4,5,5,4,3,2,1,1,2,3,2,1,1,
  // Ponte melódica
  2,2,3,1,2,3,4,3,1,2,3,4,3,2,1,2,5,
  // Reexposição
  3,3,4,5,5,4,3,2,1,1,2,3,2,1,1,
  // Desenvolvimento
  5,5,6,6,5,4,3,3,4,4,3,2,1,1,2,3,2,1,2,
  // Clímax
  3,4,5,5,4,3,4,5,6,5,4,3,2,1,2,3,4,5,4,3,2,1,
  // Final triunfante
  1,2,3,4,5,6,7,8,8,7,6,5,6,7,8,8,
  8,8,7,6,5,4,5,6,7,8,8,7,6,5,4,3,2,1
};

// Durações correspondentes para o Hino da Alegria
int hinoDurations[] = {
  // Primeira estrofe
  400,400,400,400,400,400,400,400,400,400,400,400,600,400,800,
  // Segunda estrofe
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,800,
  // Ponte melódica
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,1000,
  // Reexposição
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,800,
  // Desenvolvimento
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,800,
  // Clímax
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,1200,
  // Final triunfante
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,800,
  400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,1500
}; 

int hinoSize = 85;   // Número total de notas na música

// -------------------------------------------------
// SETUP
// -------------------------------------------------
void setup() {
  Serial.begin(9600);  // Inicia comunicação serial a 9600 baud rate
  Serial.println("=== PIANO SEM LEDs ===");
  Serial.println("Teclas: 1-9 ou A-L (notas individuais)");
  Serial.println("Z = Happy Birthday (48 notas)");
  Serial.println("X = Hino da Alegria (85 notas)");
  Serial.println("======================");

  // Configura buzzer - INICIA DESLIGADO
  pinMode(buzzerPin, OUTPUT);  // Define pino do buzzer como saída
  digitalWrite(buzzerPin, LOW);  // Garante que buzzer comece desligado
  
  // Configura botões com pull-up interno
  for (int i = 0; i < numKeys; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);  // Habilita resistor pull-up interno
    // Com INPUT_PULLUP, botão pressionado = LOW, solto = HIGH
    ultimoEstadoBotao[i] = HIGH; // Começa não pressionado
  }
  
  // Sinal de inicialização
  tone(buzzerPin, 440, 200);  // Toca La (440Hz) por 200ms
  delay(250);  // Aguarda 250ms
  noTone(buzzerPin);  // Para o som
  digitalWrite(buzzerPin, LOW);  // Garante que pino fica em LOW
}

// -------------------------------------------------
// LOOP PRINCIPAL - COM DEBOUNCE CORRETO
// -------------------------------------------------
void loop() {
  unsigned long tempoAtual = millis();  // Obtém tempo atual em milissegundos
  bool algumaNotaTocando = false;  // Flag para controlar se alguma nota está tocando
  
  // 1. LEITURA DOS BOTÕES FÍSICOS COM DEBOUNCE
  for (int i = 0; i < numKeys; i++) {
    // Lê estado atual do botão 
    int leitura = digitalRead(buttonPins[i]);
    
    // Verifica se mudou desde a última leitura
    if (leitura != ultimoEstadoBotao[i]) {
      ultimoDebounceTime[i] = tempoAtual;  // Atualiza tempo da última mudança
    }
    
    // Se passou tempo suficiente desde a última mudança
    if ((tempoAtual - ultimoDebounceTime[i]) > debounceDelay) {
      // Se o estado mudou após o período de debounce
      if (leitura != estadoBotao[i]) {
        estadoBotao[i] = leitura;  // Atualiza estado estável
        
        // Se o botão foi pressionado (LOW com pull-up)
        if (estadoBotao[i] == LOW) {
          botaoPressionado[i] = true;  // Marca botão como pressionado
          algumaNotaTocando = true;    // Indica que há nota tocando
        } else {
          botaoPressionado[i] = false; // Marca botão como solto
        }
      }
    }
    
    // Toca nota se botão está pressionado
    if (botaoPressionado[i]) {
      tone(buzzerPin, notas[i]);  // Toca a frequência correspondente
    }
    
    // Atualiza último estado para próxima iteração
    ultimoEstadoBotao[i] = leitura;
  }
  
  // Se nenhum botão está pressionado, desliga o buzzer
  if (!algumaNotaTocando) {
    noTone(buzzerPin);        // Para de gerar onda sonora
    digitalWrite(buzzerPin, LOW);  // Garante nível baixo no pino
  }
  
  // 2. LEITURA DO TECLADO SERIAL (entrada pelo computador)
  if (Serial.available() > 0) {
    char tecla = Serial.read();  // Lê caractere enviado pelo serial
    
    // Primeiro, desliga qualquer som dos botões
    for (int i = 0; i < numKeys; i++) {
      botaoPressionado[i] = false;  // Reseta todos os botões
    }
    noTone(buzzerPin);  // Para som atual
    digitalWrite(buzzerPin, LOW);  // Garante buzzer desligado
    
    // Notas individuais (A-L) - letras maiúsculas e minúsculas
    for (int i = 0; i < numKeys; i++) {
      if (tecla == teclasPC[i] || tecla == teclasPC[i] + 32) {
        tocarNota(i);  // Toca a nota correspondente
        break;  // Sai do loop após encontrar tecla
      }
    }
    
    // Notas individuais (1-9)
    for (int i = 0; i < numKeys; i++) {
      if (tecla == teclasNum[i]) {
        tocarNota(i);  // Toca a nota correspondente
        break;  // Sai do loop após encontrar tecla
      }
    }
    
    // COMANDOS PARA MÚSICAS
    if (tecla == 'Z' || tecla == 'z') {
      Serial.println(">> Tocando: Happy Birthday");
      tocarMusica(happyNotes, happyDurations, happySize);  // Executa música
    }
    else if (tecla == 'X' || tecla == 'x') {
      Serial.println(">> Tocando: Hino da Alegria");
      tocarMusica(hinoNotes, hinoDurations, hinoSize);  // Executa música
    }
  }
  
  // Pequeno delay para estabilidade
  delay(10);
}

// -------------------------------------------------
// FUNÇÃO PARA TOCAR NOTA
// -------------------------------------------------
void tocarNota(int index) {
  tone(buzzerPin, notas[index]);  // Toca a frequência da nota
  delay(300);                     // Mantém por 300ms
  noTone(buzzerPin);              // Para o som
  digitalWrite(buzzerPin, LOW);   // Garante buzzer desligado
}

// -------------------------------------------------
// FUNÇÃO PARA TOCAR MÚSICA
// -------------------------------------------------
void tocarMusica(byte notasMusica[], int duracoes[], int tamanho) {
  // Para qualquer som atual
  noTone(buzzerPin);
  digitalWrite(buzzerPin, LOW);
  
  delay(200); // Pausa antes de começar a música
  
  // Toca cada nota
  for (int i = 0; i < tamanho; i++) {
    int indiceNota = notasMusica[i] - 1;  // Converte número da nota para índice (1-9 → 0-8)
    
    // Verifica se índice está dentro dos limites
    if (indiceNota >= 0 && indiceNota < numKeys) {
      tone(buzzerPin, notas[indiceNota]);  // Toca a nota
      delay(duracoes[i]);                  // Mantém pelo tempo especificado
      noTone(buzzerPin);                   // Para o som
      digitalWrite(buzzerPin, LOW);        // Garante buzzer desligado
      
      // Pequena pausa entre notas (articulação)
      if (i < tamanho - 1) {
        delay(30);
      }
    }
  }
  
  // Final da música
  Serial.println(">> Fim da musica");
  delay(300);  // Pausa final
}