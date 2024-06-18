#include "gpio.h"
#include <stddef.h>

#define USE_DYNAMIC_MEM

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool used;
};

/**
 * @brief Allocates an instance from a static pool of GPIO structures.
 *
 * @return gpio_t Pointer to a gpio_t structure if available, NULL otherwise.
 */

static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index].used;
            result->used = true;
            break;
        }
    }
    return result;
}

/**
 * @brief Creates a GPIO instance.
 *
 * @param puerto The port number of the GPIO.
 * @param bit The bit number of the GPIO.
 * @return gpio_t Pointer to the created gpio_t structure.
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif
    if (self) {
        self->port = puerto;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

/**
 * @brief Sets the GPIO direction to output.
 *
 * @param self Pointer to the gpio_t structure.
 * @param output Boolean value to set the direction as output.
 */
void gpioSetOutput(gpio_t self, bool output) {
    HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

/**
 * @brief Sets the state of the GPIO.
 *
 * @param self Pointer to the gpio_t structure.
 * @param state Boolean value to set the state of the GPIO.
 */
void gpioSetState(gpio_t self, bool state) {
    HAL_GPIO_SET_STATE(self->port, self->bit);
}

/**
 * @brief Gets the state of the GPIO.
 *
 * @param self Pointer to the gpio_t structure.
 * @return bool Current state of the GPIO.
 */
bool gpioGetState(gpio_t self) {
    return HAL_GPIO_GET_STATE(self->port, self->bit);
}
