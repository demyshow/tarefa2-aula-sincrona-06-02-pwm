#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PINO_SERVO 22
#define PINO_LED 12  // LED RGB no GPIO 12
#define PWM_CICLO 24999  // 20ms (50Hz)
#define DIVISOR_CLK 100  // Divisor de clock

// Converte tempo em microssegundos para nível PWM
uint32_t microssegundos_para_nivel(uint32_t us) {
    return (us * PWM_CICLO) / 20000;  // Conversão
}

void inicializa() {
    gpio_set_function(PINO_SERVO, GPIO_FUNC_PWM);
    uint slice_num_servo = pwm_gpio_to_slice_num(PINO_SERVO);
    pwm_config config_servo = pwm_get_default_config();
    pwm_config_set_clkdiv(&config_servo, DIVISOR_CLK);
    pwm_config_set_wrap(&config_servo, PWM_CICLO);
    pwm_init(slice_num_servo, &config_servo, true);
    
    gpio_init(PINO_LED);
    gpio_set_dir(PINO_LED, GPIO_OUT);
}

int main() {
    inicializa();
    uint slice_num_servo = pwm_gpio_to_slice_num(PINO_SERVO);

    // Teste de posição do servo
    pwm_set_gpio_level(PINO_SERVO, microssegundos_para_nivel(2400));
    gpio_put(PINO_LED, 1); // LED acende
    sleep_ms(5000);

    pwm_set_gpio_level(PINO_SERVO, microssegundos_para_nivel(1470));
    gpio_put(PINO_LED, 0); // LED apaga
    sleep_ms(5000);

    pwm_set_gpio_level(PINO_SERVO, microssegundos_para_nivel(500));
    gpio_put(PINO_LED, 1); // LED acende
    sleep_ms(5000);

    // Movimento contínuo do servo
    uint32_t nivel_inicial = microssegundos_para_nivel(500);
    uint32_t nivel_final = microssegundos_para_nivel(2400);

    while (1) {
        // 0° a 180°
        for (uint32_t i = nivel_inicial; i <= nivel_final; i += 5) {
            pwm_set_gpio_level(PINO_SERVO, i);
            gpio_put(PINO_LED, ((i - nivel_inicial) / 100) % 2);  // Pisca a cada 100µs
            sleep_ms(10);
        }

        // 180° a 0°
        for (uint32_t i = nivel_final; i >= nivel_inicial; i -= 5) {
            pwm_set_gpio_level(PINO_SERVO, i);
            gpio_put(PINO_LED, ((i - nivel_inicial) / 100) % 2);
            sleep_ms(10);
        }
    }
    return 0;
}
