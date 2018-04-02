#include <peripherals.h>
#include <smb_0.h>

static volatile uint8_t command_complete;

uint8_t i2c_response[3];


void si7006_measure(void) {
	/*command_complete = 0;
	i2c_data[0] = SI7006_CMD_MEAS_HUM_HOLD;
	SMB0_transfer(SI7006_ADDR, i2c_data, i2c_response, 1, 0);
	while(!command_complete);*/
}

uint16_t si7006_read_temp(void) {
	uint8_t i2c_data[3];

	command_complete = 0;
	i2c_data[0] = SI7006_CMD_MEAS_TEMP_HOLD;
	i2c_data[1] = SI7006_ADDR;
	i2c_data[2] = SI7006_ADDR;

	SMB0_transfer(SI7006_ADDR, i2c_data, i2c_response, 3, 0);
	while(!command_complete);

	command_complete = 0;
	SMB0_transfer(SI7006_ADDR, NULL, i2c_response, 0, 2);
	while(!command_complete);

	return (i2c_response[0]) | (i2c_response[1]<<8);
}

uint16_t si7006_read_hum(void) {
	uint8_t i2c_data[3];

	command_complete = 0;
	i2c_data[0] = SI7006_CMD_MEAS_HUM_HOLD;
	i2c_data[1] = SI7006_ADDR;
	i2c_data[2] = SI7006_ADDR;

	SMB0_transfer(SI7006_ADDR, i2c_data, i2c_response, 3, 0);
	while(!command_complete);

	command_complete = 0;
	SMB0_transfer(SI7006_ADDR, NULL, i2c_response, 0, 2);
	while(!command_complete);

	return (i2c_response[0]) | (i2c_response[1]<<8);
}

void si7055_measure(void) {
	uint8_t i2c_data[3];

	command_complete = 0;
	i2c_data[0] = SI7055_CMD_MEAS_TEMP_HOLD;
	i2c_data[1] = SI7055_ADDR;
	i2c_data[2] = SI7055_ADDR;
	SMB0_transfer(SI7055_ADDR, i2c_data, i2c_response, 3, 0);
	while(!command_complete);
}

uint16_t si7055_read(void) {
	command_complete = 0;
	SMB0_transfer(SI7055_ADDR, NULL, i2c_response, 0, 2);
	while(!command_complete);

	return (i2c_response[0]) | (i2c_response[1]<<8);
}

void si4012_set_data(uint8_t SI_SEG_XDATA *buf, uint8_t len) {
	uint8_t i2c_data[80];

	uint8_t SI_SEG_XDATA i = 1;
	uint8_t SI_SEG_XDATA b = 0;
	uint8_t SI_SEG_XDATA id = 0;

	i2c_data[0] = SI4012_CMD_INIT_FIFO;

	for (id = 0; id < len; id++) {
		uint8_t dc = buf[id];

		for (b = 8; b > 0; b--) {
			// 10000000 for 0, 11110000 for 1
			uint8_t SI_SEG_XDATA d = 0xC0;
			if (dc & (1<<(b-1))) {
				d |= 0xFC;
			}

			i2c_data[i] = d;
			i++;
		}
	}

	si4012_request(i2c_data, 1+len*8, 1);
}

void si4012_tx(void) {
	uint8_t i2c_data[6];

	i2c_data[0] = SI4012_CMD_TX_START;
	i2c_data[1] = 0;
	i2c_data[2] = 255;
	i2c_data[3] = 0;
	i2c_data[4] = 0;
	i2c_data[5] = 0;

	si4012_request(i2c_data, 6, 2);
}

void si4012_tx_shutdown(void) {
	uint8_t i2c_data[6];

	i2c_data[0] = SI4012_CMD_TX_START;
	i2c_data[1] = 0;
	i2c_data[2] = 255;
	i2c_data[3] = 1; // goto shutdown after TX
	i2c_data[4] = 0;
	i2c_data[5] = 0;

	si4012_request(i2c_data, 6, 2);

	i2c_data[0] = SI4012_CMD_CHANGE_STATE;
	i2c_data[1] = 1;
	i2c_data[2] = 0;

	si4012_request(i2c_data, 3, 1);
}

uint16_t si4012_get_battery(void) {
	uint8_t i2c_data[3];

	i2c_data[0] = SI4012_CMD_GET_BAT_STATUS;
	i2c_data[1] = 0;

	si4012_request(i2c_data, 2, 3);

	return i2c_response[2]|(i2c_response[1]<<8);
}

void si4012_init(void) {
	uint8_t i2c_data[5];

	i2c_data[0] = SI4012_CMD_SET_PROPERTY;
	i2c_data[1] = SI4012_PROPERTY_LED_INTENSITY;
	i2c_data[2] = 1;
	si4012_request(i2c_data, 3, 1);

	i2c_data[0] = SI4012_CMD_SET_PROPERTY;
	i2c_data[1] = SI4012_PROPERTY_PA_CONFIG;
	i2c_data[2] = 0xdd;
	i2c_data[3] = 0xc7;
	i2c_data[4] = 0xc8;
	si4012_request(i2c_data, 5, 1);

	i2c_data[0] = SI4012_CMD_SET_PROPERTY;
	i2c_data[1] = SI4012_PROPERTY_MODULATION_FSKDEV;
	i2c_data[2] = 0; // OOK
	i2c_data[3] = 0x0;
	si4012_request(i2c_data, 4, 1);

	i2c_data[0] = SI4012_CMD_SET_PROPERTY;
	i2c_data[1] = SI4012_PROPERTY_BITRATE_CONFIG;
	i2c_data[2] = 0x00;
	i2c_data[3] = 0x14;
	i2c_data[4] = 0x01;
	si4012_request(i2c_data, 5, 1);
}

void si4012_led(uint8_t state) {
	uint8_t i2c_data[2];

	i2c_data[0] = SI4012_CMD_LED_CTRL;
	i2c_data[1] = state;

	si4012_request(i2c_data, 2, 1);
}

void si4012_change_state(void) {
	uint8_t i2c_data[3];

	i2c_data[0] = SI4012_CMD_GETREV;
	si4012_request(i2c_data, 1, 0);

	i2c_data[0] = SI4012_CMD_CHANGE_STATE;
	i2c_data[1] = 0;
	i2c_data[2] = 0;

	si4012_request(i2c_data, 3, 1);
}

void si4012_request (uint8_t* buf, uint8_t len, uint8_t rxlen) {
	command_complete = 0;
	SMB0_transfer(SI4012_ADDR, buf, i2c_response, len, 0);
	while(!command_complete);

	command_complete = 0;
	SMB0_transfer(SI4012_ADDR, buf, i2c_response, 0, rxlen);
	while(!command_complete);
}

void SMB0_transferCompleteCb() {
	command_complete = 1;
}

void SMB0_commandReceivedCb() {
}

void SMB0_errorCb (SMB0_TransferError_t error) {
	SMB0_abortTransfer();
	command_complete = 1;
}
