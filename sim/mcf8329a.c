#include <stdio.h>
#include <stdint.h>
#include "spi_mock.h"
#include "mcf8329a.h"

#define MCF_REG_COUNT 64

// 🧠 Simulated register space (shadow map)
static uint16_t reg_map[MCF_REG_COUNT];

void mcf8329a_write_register(uint8_t reg, uint16_t data)
{
    if (reg >= MCF_REG_COUNT)
    {
        printf("[MCF8329A] ❌ Invalid register: 0x%02X\n", reg);
        return;
    }

    // 💾 Store data in fake shadow register map
    reg_map[reg] = data;

    // 📝 Log the register write
    printf("[MCF8329A] ✅ WRITE  Reg: 0x%02X  Data: 0x%04X\n", reg, data);

    // 📡 Create SPI TX frame
    uint8_t tx[3];
    tx[0] = reg & 0x7F; // MSB=0 for write
    tx[1] = (data >> 8) & 0xFF;
    tx[2] = data & 0xFF;

    uint8_t rx[3] = {0};

    // 🧪 Simulated SPI transmit
    mock_spi_transmit(tx, rx, 3);
}
