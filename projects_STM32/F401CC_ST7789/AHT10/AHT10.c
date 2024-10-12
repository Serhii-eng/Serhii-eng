#include "AHT10.h"



static void AHT10_I2C_Receive(I2C_HandleTypeDef* MyI2C, uint16_t i2c_add, uint8_t* data, uint16_t size)
{
	HAL_I2C_Master_Receive( MyI2C, i2c_add, data, size, 100);
}

static void AHT10_I2C_Transmit(I2C_HandleTypeDef* MyI2C, uint16_t i2c_add, uint8_t* data, uint16_t size)
{
	HAL_I2C_Master_Transmit( MyI2C, i2c_add, data, size, 100);
}




void AHT10_SetMeasurment(AHT10_SENSOR* sensor)
{
	uint8_t triger_measurment_data[3] = {AHT10_START_MEASUREMENT_REG, AHT10_START_MEASUREMENT_CTRL, AHT10_START_MEASUREMENT_CTRL_NOP};	//command for sensor
	AHT10_I2C_Transmit( sensor->current_I2C, sensor->I2C_adress, triger_measurment_data, sizeof(triger_measurment_data) );
}

void AHT10_GetMeasurment(AHT10_SENSOR* sensor)
{
	AHT10_I2C_Receive( sensor->current_I2C, sensor->I2C_adress, sensor->raw_data, sizeof(sensor->raw_data) );
	if(~sensor->raw_data[0] & MEASURMENT_READINESS_REG){
		
		uint32_t raw_temperature = ((uint32_t)(sensor->raw_data[3] & 0x0F) << 16) | ((uint16_t)sensor->raw_data[4] << 8) | sensor->raw_data[5];
		sensor->temperature = (raw_temperature / 1048576.0) * 200.0 - 50.0;
		
		uint32_t raw_humidity = ((uint32_t)sensor->raw_data[1]  << 12) | ((uint16_t)sensor->raw_data[2] << 4) | (sensor->raw_data[5] >> 4);
		sensor->humidity = (raw_humidity / 1048576.0) * 100.0;
	}
}

float AHT10_GetTemperature(AHT10_SENSOR* sensor)
{
	return sensor->temperature;
}

float AHT10_GetHumidity(AHT10_SENSOR* sensor)
{
	return sensor->humidity;
}

void AHT10_SoftReset(AHT10_SENSOR* sensor)
{
	uint8_t reset_value = AHT10_SOFT_RESET_REG;
	AHT10_I2C_Transmit( sensor->current_I2C, sensor->I2C_adress, &reset_value, sizeof(reset_value) );
}





