void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
    if (hspi->Instance == SPI1)
    {
        __HAL_RCC_SPI1_CLK_ENABLE();
        // No real GPIO configuration needed in simulation
    }
}
