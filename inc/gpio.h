#include <stdint.h>
#include <stdbool.h>

void gpioSetDirection(uint8_t puerto, uint8_t bit, bool salida);
void gpioSetOutput(uint8_t puerto, uint8_t bit, bool estado);
bool gpioGetInput(uint8_t puerto, uint8_t bit);

typedef struct gpio_s * gpio_t; // pointer to anonymous structure

/**
 * @brief GPIO instance constructor
 *
 * @param port 8-bit port to use
 * @param bit GPIO pin to use
 * @return gpio_t
 */

gpio_t gpioCreate(uint8_t port, uint8_t bit);

void gpioSetOutput(gpio_t gpio, bool output);
void gpioSetState(gpio_t gpio, bool state);
bool gpioGetState(gpio_t gpio);
