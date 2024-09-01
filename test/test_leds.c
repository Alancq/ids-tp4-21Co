#include "unity.h"
#include "leds.h"
static uint16_t puerto_virtual;
void setUp(void) {
    leds_init(&puerto_virtual);
}
//-Al arrancar el sistema todos los leds tienen que estar apagados.

void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    TEST_ASSERT_EQUAL_HEX16(0X0000, puerto_virtual);
}

//-despues de arrancar el sistema, con todos los leds apagados, voy a prender un led cualquiera.

void test_prender_un_solo_led(void) {

    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

//-voy a prender un led y volver a apagarlo para ver si se apaga.
void test_prender_y_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x000, puerto_virtual);
}

//-prender dos leds, apagar uno, y ver que solo se apaga el que corresponde y que el otro sigue
// prendido
void test_prender_dos_y_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_on(7);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << (6 - 2), puerto_virtual);
}

// Prender y apagar todos los leds juntos.
void test_prender_y_apagar_todos_los_leds(void) {
    leds_turn_all_on();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

    leds_turn_all_off();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Prender un led, consultar el estado y verificar que está prendido.
void test_consultar_estado_led_encendido(void) {
    leds_turn_on(5);
    TEST_ASSERT_TRUE(leds_is_on(5));
}

// Consultar el estado de un led apagado y verificar que está apagado.
void test_consultar_estado_led_apagado(void) {
    TEST_ASSERT_FALSE(leds_is_on(5));
}

// Revisar que los leds están bien mapeados en la memoria.
void test_revisar_mapeo_de_leds(void) {
    leds_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, puerto_virtual);

    leds_turn_on(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, puerto_virtual);
}
