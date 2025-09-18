#include <stdio.h>
#include <stdint.h>
#include "spi_mock.h"

void mock_spi_transmit(uint8_t *tx, uint8_t *rx, uint16_t len)
{
    printf("[MOCK SPI] Transmitting %d bytes...\n", len);
    for (uint16_t i = 0; i < len; ++i)
    {
        printf("  TX[%d] = 0x%02X\n", i, tx[i]);
        rx[i] = 0xFF; // Dummy readback
    }
}
