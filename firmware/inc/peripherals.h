#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include <SI_EFM8SB1_Register_Enums.h>                  // SFR declarations
#include <si_toolchain.h>

#include <stdint.h>

#define SI4012_ADDR 0xE0

#define SI4012_CMD_GETREV 0x10
#define SI4012_CMD_SET_PROPERTY 0x11
#define SI4012_CMD_GET_PROPERTY 0x12
#define SI4012_CMD_LED_CTRL 0x13
#define SI4012_CMD_CHANGE_STATE 0x60
#define SI4012_CMD_GET_STATE 0x61
#define SI4012_CMD_TX_START 0x62
#define SI4012_CMD_SET_INT 0x63
#define SI4012_CMD_GET_INT_STATUS 0x64
#define SI4012_CMD_INIT_FIFO 0x66
#define SI4012_CMD_TX_STOP 0x67
#define SI4012_CMD_GET_BAT_STATUS 0x68

#define SI4012_PROPERTY_CHIP_CONFIG 0x10
#define SI4012_PROPERTY_LED_INTENSITY 0x11
#define SI4012_PROPERTY_MODULATION_FSKDEV 0x20
#define SI4012_PROPERTY_TUNE_INTERVAL 0x21
#define SI4012_PROPERTY_FIFO_THRESHOLD 0x30
#define SI4012_PROPERTY_BITRATE_CONFIG 0x31
#define SI4012_PROPERTY_TX_FREQ 0x40
#define SI4012_PROPERTY_LBD_CONFIG 0x41
#define SI4012_PROPERTY_XO_CONFIG 0x50
#define SI4012_PROPERTY_PA_CONFIG 0x60

#define SI7055_ADDR 0x80
#define SI7055_CMD_MEAS_TEMP_HOLD 0xE3
#define SI7055_CMD_MEAS_TEMP 0xF3
#define SI7055_CMD_RESET 0xFE
#define SI7055_CMD_WRITE_UREG1 0xE6
#define SI7055_CMD_WRITE_UREG2 0xE7

#define SI7006_ADDR 0x80
#define SI7006_CMD_MEAS_TEMP_HOLD 0xE3
#define SI7006_CMD_MEAS_HUM_HOLD 0xE5
#define SI7006_CMD_MEAS_HUM 0xF5
#define SI7006_CMD_RESET 0xFE
#define SI7006_CMD_READ_TEMP 0xE0

void si4012_request (uint8_t* buf, uint8_t len, uint8_t rxlen);
void si4012_led (uint8_t state);
void si4012_init(void);
void si4012_change_state(void);
void si4012_set_data (uint8_t SI_SEG_XDATA *buf, uint8_t len);
void si4012_tx(void);
void si4012_tx_shutdown(void);
uint16_t si4012_get_battery(void);

void si7055_measure(void);
uint16_t si7055_read(void);

void si7006_measure(void);
uint16_t si7006_read_temp(void);
uint16_t si7006_read_hum(void);

#endif
