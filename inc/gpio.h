#include <stdint.h>
#include <stdbool.h>

// void gpioSetDirection(uint8_t puerto, uint8_t bit, bool salida);
// void gpioSetOutput(uint8_t puerto, uint8_t bit, bool estado);
// bool gpioGetInput(uint8_t puerto, uint8_t bit);

typedef struct gpio_s * gpio_t; // pointer to anonymous structure

/**
 * @brief Creates a GPIO instance with the specified port and bit.
 *
 * @param port 8-bit port to use
 * @param bit GPIO pin to use
 * @return gpio_t Pointer to the created GPIO instance
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Sets the GPIO direction to output.
 *
 * @param gpio Pointer to the GPIO instance
 * @param output Boolean value to set the direction as output
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Sets the state of the GPIO.
 *
 * @param gpio Pointer to the GPIO instance
 * @param state Boolean value to set the state of the GPIO
 */
void gpioSetState(gpio_t gpio, bool state);
/**
 * @brief Gets the state of the GPIO.
 *
 * @param gpio Pointer to the GPIO instance
 * @return bool Current state of the GPIO
 */
bool gpioGetState(gpio_t gpio);
