#ifndef SPI_MOCK_H
#define SPI_MOCK_H

#include <stdint.h>

void mock_spi_transmit(uint8_t *tx, uint8_t *rx, uint16_t len);

#endif // SPI_MOCK_H
