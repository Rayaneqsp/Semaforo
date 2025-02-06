#include <stdio.h>
#include "pico/stdlib.h"  // Biblioteca padrão para funcionalidades básicas como GPIO, temporização e E/S.
#include "pico/time.h"    // Biblioteca para gerenciamento de tempo, como manipulação de temporizadores e atrasos.

#define LED_PIN_GREEN  11 // LED verde
#define LED_PIN_YELLOW 12 // LED amarelo
#define LED_PIN_RED    13 // LED vermelho

// Variável para controlar o estado dos LEDs
static enum { RED, YELLOW, GREEN } semaforo_estado = RED;

// Função de callback chamada pelo temporizador
bool repeating_timer_callback(repeating_timer_t *rt) {
    // Muda o estado do semáforo a cada 3 segundos
    if (semaforo_estado == RED) {
        gpio_put(LED_PIN_RED, 1);    // Liga o LED vermelho
        gpio_put(LED_PIN_YELLOW, 0); // Desliga o LED amarelo
        gpio_put(LED_PIN_GREEN, 0);  // Desliga o LED verde
        semaforo_estado = YELLOW;    // Proxima cor: amarelo
        printf("Sinal Vermelho - Iniciando contagem\n"); // Imprime no terminal a troca para vermelho
    } else if (semaforo_estado == YELLOW) {
        gpio_put(LED_PIN_RED, 0);    // Desliga o LED vermelho
        gpio_put(LED_PIN_YELLOW, 1); // Liga o LED amarelo
        gpio_put(LED_PIN_GREEN, 0);  // Desliga o LED verde
        semaforo_estado = GREEN;     // Proxima cor: verde
        printf("Sinal Amarelo - Iniciando contagem\n"); // Imprime no terminal a troca para amarelo
    } else {
        gpio_put(LED_PIN_RED, 0);    // Desliga o LED vermelho
        gpio_put(LED_PIN_YELLOW, 0); // Desliga o LED amarelo
        gpio_put(LED_PIN_GREEN, 1);  // Liga o LED verde
        semaforo_estado = RED;       // Proxima cor: vermelho
        printf("Sinal Verde - Iniciando contagem\n"); // Imprime no terminal a troca para verde
    }

    return true; // A tarefa continua se repetindo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializa os pinos dos LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Inicializa o semáforo no estado vermelho
    gpio_put(LED_PIN_RED, 1);    // Liga o LED vermelho
    gpio_put(LED_PIN_YELLOW, 0); // Desliga o LED amarelo
    gpio_put(LED_PIN_GREEN, 0);  // Desliga o LED verde
    printf("Sinal Vermelho - Iniciando contagem\n");   // Imprime no terminal a inicialização do semáforo com o sinal vermelho

    // Configura o temporizador para alternar a cada 3 segundos (3000 ms)
    repeating_timer_t timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // Alterna a cor a cada 3 segundos

    // Loop principal
    while (true) {
        // A cada segundo, imprime uma mensagem no terminal
        sleep_ms(1000);

        // A cada troca de cor, imprime o tempo restante
        if (semaforo_estado == RED) {
            printf("Sinal Vermelho - 1 segundo restante\n");
        } else if (semaforo_estado == YELLOW) {
            printf("Sinal Amarelo - 1 segundo restante\n");
        } else if (semaforo_estado == GREEN) {
            printf("Sinal Verde - 1 segundo restante\n");
        }
    }

    return 0;
}

