#include "pico/stdlib.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Variáveis para mostrar o estado do semáforo
enum estado_semaforo {
    VERMELHO,
    AMARELO,
    VERDE
};

volatile enum estado_semaforo estado_atual = VERMELHO;

// Função de callback do temporizador que alterna os LEDs
bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    switch (estado_atual) {
        case VERMELHO:
            estado_atual = AMARELO;
            gpio_put(LED_AMARELO, 1);
            break;
        case AMARELO:
            estado_atual = VERDE;
            gpio_put(LED_VERDE, 1);
            break;
        case VERDE:
            estado_atual = VERMELHO;
            gpio_put(LED_VERMELHO, 1);
            break;
    }
    return true;  // Retorna true para que o temporizador continue repetindo
}

int main() {
    // Inicializa os pinos dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa a porta serial
    stdio_init_all();

    // Cria um temporizador repetitivo para alternar os LEDs a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Inicia o semáforo com o LED vermelho aceso
    gpio_put(LED_VERMELHO, 1);

    // Laço principal
    while (true) {
        sleep_ms(1000);  // Aguarda 1 segundo
    }

    return 0;
}
