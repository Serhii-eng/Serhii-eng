




#ifndef _HTU21D_H
#define _HTU21D_H


/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

#include "main.h"
#include "HTU21D_config.h"

#define HTU21D_ADRESS 						(0x40 << 1)  

// registers
#define HTU21D_TEMPERATURE_REG		0xE3
#define HTU21D_HUMIDITY_REG				0xE5
#define HTU21D_USER_WRITE_REG			0xE6
#define HTU21D_USER_READ_REG			0xE7
#define HTU21D_SOFT_RESET_REG			0xFE


extern I2C_HandleTypeDef HTU21D_I2C;




float HTU21D_getTemperature(uint8_t format_units);





/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif	/*	_HTU21D_H */