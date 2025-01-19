#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"


#include "hardware/clocks.h"
#include "hardware/pwm.h"

// Definição dos pinos
#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUZZER 21

#define BUZZER_FREQUENCY 10000

// Função para inicializar os GPIOs
void setup_gpio() {
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(BUZZER);

    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Função para desligar todos os LEDs
void turn_off_leds() {
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
}

// Função para ligar um LED específico
void turn_on_led(uint pin) {
    turn_off_leds();
    gpio_put(pin, 1);
}
//ligar leds vermelho e verde
void rg() {
    turn_off_leds();
    sleep_ms(10);
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 1);
}

//ligar leds vermelho e azul
void rb() {
  turn_off_leds();
  sleep_ms(10);
  gpio_put(LED_RED, 1);
  gpio_put(LED_BLUE, 1); 
}

//ligar leds verde e azul
void gb() {
    turn_off_leds();
    sleep_ms(10);
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1); 
}

// Função para ligar todos os LEDs (luz branca)
void turn_on_all_leds() {
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1);
}

void pwm_init_buzzer(uint pin) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

// Ativação do buzzer
void beep_buzzer(uint duration, uint repetitions) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    for (int i = 0; i < repetitions; i++) {
        pwm_set_gpio_level(BUZZER, 2048);
        sleep_ms(duration);
        pwm_set_gpio_level(BUZZER, 0);
        sleep_ms(100);
    }
}

// Função principal
int main() {
    stdio_init_all();
    setup_gpio();
    pwm_init_buzzer(BUZZER);

    char command = 'B';

    printf("Sistema iniciado. Aguardando comandos via UART...\n");
    printf("Digite R para a cor vermelha\n");
    printf("Digite B para a cor azul \n");
    printf("Digite G para ligar o led verde \n");
    printf("Digite Y para a cor amarela \n");
    printf("Digite V para a cor violeta \n");
    printf("Digite C para a cor ciano \n");
    printf("Digite W para a cor branca\n");
    printf("Digite O para desligar todos os leds \n");
    printf("Digite Z para ligar o buzzer \n");
    
    while (true) {
        // Aguarda um comando do usuário
            if (scanf("%c", &command) == 1) {
                switch (command) {
                    case 'G':
                        printf("Ligando LED verde...\n");
                        turn_on_led(LED_GREEN);
                        break;
                    case 'B':
                        printf("Ligando LED azul...\n");
                        turn_on_led(LED_BLUE);
                        break;
                    case 'R':
                        printf("Ligando LED vermelho...\n");
                        turn_on_led(LED_RED);
                        break;
                    case 'Y':
                        printf("Ligando led vermelho e verde\n");
                        rg();
                        break;
                    case 'V':
                        printf("Ligando led vermelho e azul\n");
                        rb();
                        break;
                    case 'C':
                        printf("Ligando led azul e verde\n");
                        gb();
                        break;
                    case 'W':
                        printf("Ligando todos os LEDs (branco)...\n");
                        turn_on_all_leds();
                        break;
                    case 'O':
                        printf("Desligando todos os LEDs...\n");
                        turn_off_leds();
                        break;
                    case 'Z':
                        printf("Acionando buzzer...\n");
                        beep_buzzer(2000, 1);
                        break;
                    case 'Q':
                        printf("Saindo do programa...\n");
                        reset_usb_boot(0, 0);
                        return 0;
                    default:
                        printf("Comando desconhecido: %c\n", command);
                        break;
                }
            }
        }
        sleep_ms(100);
    return 0;
}
