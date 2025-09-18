void test_spi_transmit()
{
    uint8_t txData[2] = { 0xDE, 0xAD };
    uint8_t rxData[2] = { 0 };

    HAL_StatusTypeDef result = HAL_SPI_TransmitReceive(&hspi1, txData, rxData, 2, HAL_MAX_DELAY);

    if (result == HAL_OK)
    {
        // Placeholder: in real test, print or inspect rxData
    }
    else
    {
        Error_Handler();
    }
}
