#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Inicializa el sistema de LEDs apagando todos los LEDs.
 *
 * @param puerto Puntero al puerto virtual donde están mapeados los LEDs.
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Enciende el LED especificado.
 *
 * @param led Número del LED a encender (1 a 16).
 */
void leds_turn_on(int led);

/**
 * @brief Apaga el LED especificado.
 *
 * @param led Número del LED a apagar (1 a 16).
 */
void leds_turn_off(int led);

/**
 * @brief Verifica si un LED específico está encendido.
 *
 * @param led Número del LED a consultar.
 * @return true si el LED está encendido.
 * @return false si el LED está apagado.
 */
bool leds_is_on(int led);

/**
 * @brief Enciende todos los LEDs.
 */
void leds_turn_all_on(void);

/**
 * @brief Apaga todos los LEDs.
 */
void leds_turn_all_off(void);

#endif
