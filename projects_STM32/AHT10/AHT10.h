
#ifndef _AHT10_H
#define _AHT10_H


/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

#include "main.h"
#include "AHT10_config.h"

//#define AHT10_ADRESS 						(0x38 << 1)  

/* list of command registers */
#define AHT10_INIT_REG                    0xE1  //initialization register
#define AHT10_START_MEASUREMENT_REG       0xAC	//start measurement register
#define AHT10_SOFT_RESET_REG              0xBA  //soft reset register


/* measurement register controls */
#define AHT10_START_MEASUREMENT_CTRL      0x33  //measurement controls, suspect this is temperature & humidity DAC resolution
#define AHT10_START_MEASUREMENT_CTRL_NOP  0x00  //NOP control, send after any "AHT10_START_MEASUREMENT_CTRL..."

/*status register for checking the readiness of measurements*/
#define MEASURMENT_READINESS_REG					0x80	//register for checking the readiness of measurements

/* calibration register controls */
#define AHT10_INIT_CTRL_NORMAL_MODE       0x00  //normal mode on/off       bit[6:5]
#define AHT10_INIT_CTRL_CYCLE_MODE        0x20  //cycle mode on/off        bit[6:5]
#define AHT10_INIT_CTRL_CMD_MODE          0x40  //command mode  on/off     bit[6:5]
#define AHT10_INIT_CTRL_CAL_ON            0x08  //calibration coeff on/off bit[3]
#define AHT10_INIT_CTRL_NOP               0x00  //NOP control, send after any "AHT10_INIT_CTRL..."



//extern I2C_HandleTypeDef AHT10_I2C;

typedef struct
{
	uint8_t raw_data[6]; //status and raw data
	uint16_t I2C_adress;
	float temperature;
	float humidity;
	I2C_HandleTypeDef* current_I2C;
}AHT10_SENSOR;


void AHT10_SetMeasurment(AHT10_SENSOR* sensor);
void AHT10_GetMeasurment(AHT10_SENSOR* sensor);
float AHT10_GetTemperature(AHT10_SENSOR* sensor);
float AHT10_GetHumidity(AHT10_SENSOR* sensor);
void AHT10_SoftReset(AHT10_SENSOR* sensor);




/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif	/*	_AHT10_H */