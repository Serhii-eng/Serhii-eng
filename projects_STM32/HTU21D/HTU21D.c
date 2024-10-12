#include "HTU21D.h"

uint8_t data[3] = {0};
float HTU21D_getTemperature(uint8_t format_units)
{

	uint8_t reg = HTU21D_TEMPERATURE_REG;
	
//	HAL_I2C_Master_Transmit( &HTU21D_I2C, HTU21D_ADRESS, &reg, sizeof(reg), 500);
//	HAL_Delay(100);
//	HAL_I2C_Master_Receive( &HTU21D_I2C, HTU21D_ADRESS, data, sizeof(data), 500);
	HAL_I2C_Mem_Read(&HTU21D_I2C, HTU21D_ADRESS, HTU21D_TEMPERATURE_REG, I2C_MEMADD_SIZE_8BIT, data, sizeof(data), 500);
	uint16_t raw_temperature  = (uint16_t)(data[0] << 8) | data[1];
	float temperature = -46.85 + 175.72 * (raw_temperature / 65536.0);
	
	return temperature;
}