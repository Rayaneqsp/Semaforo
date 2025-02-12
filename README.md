# Simulação de Semáforo 

Este projeto simula o funcionamento de um semáforo utilizando um **Raspberry Pi Pico** e três **LEDs** (vermelho, amarelo e verde). O programa alterna as luzes do semáforo a cada 3 segundos, utilizando um temporizador repetitivo para controlar o ciclo de LEDs.

## Funcionalidades

- O programa controla 3 LEDs que representam o semáforo (vermelho, amarelo e verde).
- Cada LED acende em sequência, simulando o ciclo de um semáforo real.
- A troca de luzes ocorre automaticamente a cada 3 segundos, repetindo o ciclo infinitamente.
- 
## Como Usar o Programa

### Passo 1: Clonando o Repositório

   - No GitHub, acesse o repositório e clique em **Code** (Código) para copiar o link de clonagem.
   - No terminal do seu VSCode, execute o comando para clonar o repositório:

  Adicione este comando:
  
   git clone https://github.com/Rayaneqsp/Semaforo.git

2. **Abrindo o projeto no VSCode**:
   - Abra o VSCode e carregue a pasta do projeto clonada.
     
### Passo 3: Rodando a Simulação do Wokwi

2. **Configurando o Circuito no Simulador**:
   - No editor Wokwi, adicione 3 LEDs e conecte-os aos seguintes pinos do Raspberry Pi Pico:
     - LED Vermelho: Pino 11
     - LED Amarelo: Pino 12
     - LED Verde: Pino 13
   - Conecte os LEDs ao GND com resistores para protegê-los.

### Passo 4: Observando o Comportamento do Semáforo

- O semáforo alterna entre **vermelho**, **amarelo** e **verde** a cada 3 segundos.
- O ciclo de troca de luzes segue esta ordem:
  1. LED **vermelho** acende por 3 segundos.
  2. LED **amarelo** acende por 3 segundos.
  3. LED **verde** acende por 3 segundos.
  4. O ciclo se repete infinitamente.

## Licença

Este projeto está licenciado para estudo e conhecimento.

## Autora:

**RAYANE QUEIROZ DOS SANTOS PASSOS**
