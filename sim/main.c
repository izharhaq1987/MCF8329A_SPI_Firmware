#include <stdint.h>
#include "mcf8329a.h"

int main(void)
{
    // Simulated full configuration for MCF8329A startup
    mcf8329a_write_register(0x20, 0x1234);  // Control Register 1
    mcf8329a_write_register(0x21, 0xABCD);  // Control Register 2
    mcf8329a_write_register(0x22, 0x4000);  // Motor Startup Config
    mcf8329a_write_register(0x30, 0x7F7F);  // Motor Parameter Config
    mcf8329a_write_register(0x31, 0x0055);  // Gate Drive Strength
    mcf8329a_write_register(0x3E, 0x0003);  // Enable Fault Masking
    mcf8329a_write_register(0x3F, 0x0001);  // Enable Driver

    return 0;
}
