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