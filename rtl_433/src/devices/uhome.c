/* µHome smart sensors decoder
 *
 *             2018 Alexander Müller
 * Copyright © 2016 Benjamin Larsson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <stdbool.h>
#include "rtl_433.h"
#include "pulse_demod.h"
#include "util.h"


/*
 * µHome smart sensors
 *
 * Message is 64 bits long
 * Messages start with 0xAA, 0xFF, 0xAA
 *
 */
#define UHOME_BITLEN      64
#define UHOME_STARTBYTE   0xAA
#define UHOME_STARTBYTE1  0xFF
#define UHOME_CRC_SUPPORT 0xA1
#define UHOME_CRC_POLY    0xB1
#define UHOME_CRC_INIT    0x00

uint8_t calc_crc(uint8_t *bb) {
	uint8_t crc = bb[1];

	// resetting crc in buf for calc
	bb[1] = 0xFF;

	uint8_t i, j, crcc = 0;
	for (i = 0; i < 10; i++) {
		crcc ^= bb[i];
		for (j = 0; j < 8; j++) {
			if (crcc & 0x01) {
				crcc ^= UHOME_CRC_POLY;
			}

			crcc >>= 1;
		}
	}
	// restore the byte we reset earlier
	bb[1] = crc;
	return crcc;
}

static int uhome_callback(bitbuffer_t *bitbuffer) {
    char time_str[LOCAL_TIME_BUFLEN];
    uint8_t *bb;
    uint16_t brow, row_nbytes;
    uint16_t sensor_id = 0;
    uint8_t msg_type, r_crc, c_crc;
    double temp;
    double voltage;
    double humidity;
    data_t *data;
    int valid = 0;


    /*
     * Early debugging aid to see demodulated bits in buffer and
     * to determine if your limit settings are matched and firing
     * this callback.
     *
     * 1. Enable with -D -D (debug level of 2)
     * 2. Delete this block when your decoder is working
     */
    if (debug_output > 1) {
        fprintf(stderr,"uhome callback:\n");
        bitbuffer_print(bitbuffer);
    }

    local_time_str(0, time_str);

    /*
     * bit buffer will contain multiple rows, many of them empty.
     * Typically a complete message will be contained in a single
     * row if long and reset limits are set correctly.
     * May contain multiple message repeats.
     * Message might not appear in row 0, if protocol uses
     * start/preamble periods of different lengths.
     */

    for (brow = 0; brow < bitbuffer->num_rows; ++brow) {
    bb = bitbuffer->bb[brow];

    /*
     * Validate message and reject invalid messages as
     * early as possible before attempting to parse data..
     *
     * Check "message envelope"
     * - valid message length
     * - valid preamble/device type/fixed bits if any
     * - Data integrity checks (CRC/Checksum/Parity)
     */

    if (bitbuffer->bits_per_row[brow] < UHOME_BITLEN-1)
        continue;

    /*
     * number of bytes in row.
     *
     * Number of decoded bits may not be a multiple of 8.
     * bitbuffer row will have enough bytes to contain
     * all bytes, so round up.
     */
    row_nbytes = (bitbuffer->bits_per_row[brow] + 7)/8;

    /*
     * Reject rows that don't start with the correct start byte
     * Example message should start with 0xAA
     */
    if (bb[0] != UHOME_STARTBYTE)
        continue;

    /*
     * Check CRC or magic number before inspecting rest of the payload
     */
	// sensors bigger A0 have CRC support
	if (bb[2] >= UHOME_CRC_SUPPORT) {
		if (row_nbytes < 10) {
			fprintf(stderr, "uhome: buffer too short, was: %u, should be 10\n", row_nbytes);
			continue;
		}

        uint8_t crc = bb[1];
		uint8_t crcc = calc_crc(bb);

		if (crcc != crc) {
			fprintf(stderr, "%s new_template bad CRC: calculated %02x, received %02x\n",
			    time_str, crcc, crc);

			continue;
		} else {
			if (debug_output > 1) {
				fprintf(stderr, "CRC matches (0x%02x)\n", crc);
			}
		}
	} else if (bb[1] != UHOME_STARTBYTE1) {
		fprintf(stderr, "%02x does not match startbyte 0xFF\n", bb[1]);
		continue;
	}

    /*
     * Now that message "envelope" has been validated,
     * start parsing data.
     */
    temp = -1.0;
    humidity = -1.0;
    // check the sensor type
    if (bb[2] == 0xAB) {
        // sensor is a temp/hum sensor
        sensor_id = (bb[2]<<8)|bb[3];

        // temperature
        // 2 status bits: 00
        if((bb[5] & 0x03) == 0) {
            int16_t it = (bb[4]<<8)|bb[5];
            temp = (175.72*it)/65536-46.85;
        }

        // voltage
        int16_t iv = (bb[7]<<8)|bb[6];
        voltage = iv/1000.0;

        // humidity
        // 2 status bits: 10
        if((bb[9] & 0x03) == 0x02) {
            int16_t ih = (bb[8]<<8)|bb[9];
            // zero out status bits
            ih &= 0xFFFC;
            humidity = (125.0*ih)/65536-6.0;
        }

        data = data_make("time", "", DATA_STRING, time_str,
        "model", "", DATA_STRING, "µHome",
        "id", "", DATA_INT, sensor_id,
        "temperature_C", "Temperature", DATA_FORMAT, "%.2f C", DATA_DOUBLE, temp,
        "humidity", "Humidity", DATA_FORMAT, "%.2f %%", DATA_DOUBLE, humidity,
        "voltage", "Voltage", DATA_FORMAT, "%.3f V", DATA_DOUBLE, voltage,
        NULL);

    } else if (bb[2] == 0xAA) {
        // sensor is a temperature sensor
        sensor_id = (bb[2]<<8)|bb[3];

        // temperature
        // 2 status bits: 00
        if((bb[5] & 0x03) == 0) {
            int16_t it = (bb[4]<<8)|bb[5];
            temp = (175.72*it)/65536-46.85;
        }

        // voltage
        int16_t iv = (bb[7]<<8)|bb[6];
        voltage = iv/1000.0;

        data = data_make("time", "", DATA_STRING, time_str,
        "model", "", DATA_STRING, "µHome",
        "id", "", DATA_INT, sensor_id,
        "temperature_C", "Temperature", DATA_FORMAT, "%.2f C", DATA_DOUBLE, temp,
        "voltage", "Voltage", DATA_FORMAT, "%.3f V", DATA_DOUBLE, voltage,
        NULL);
    } else {
	    continue;
    }

    data_acquired_handler(data);

    valid++;

    }

    // Return number of successfully decoded messages
    return valid;
}

/*
 * r_device - registers device/callback. see rtl_433_devices.h
 *
 * Timings:
 *
 * short, long, nad reset - specify pulse/period timings
 *     based on number of samples at 250 Khz samples/second.
 *     These timings will determine if the received pulses
 *     match, so your callback will fire after demodulation.
 *
 * for readabiliy, specify timings based on 1 Mhz samples
 *     but a divide by 4 in the definition.
 *
 *
 * Demodular:
 *
 * The function used to turn the received signal into bits.
 * See:
 * - pulse_demod.h for descriptions
 * - rtL_433.h for the list of defined names
 *
 * This device is disabled by default. Enable it with -R 61 on the commandline
 */

r_device uhome = {
    .name          = "µHome sensors",
    .modulation    = OOK_PULSE_PWM_TERNARY,
    .short_limit   = 120*4,
    .long_limit    = 520*4,
    .reset_limit   = 1000*4,
    .json_callback = &uhome_callback,
    .disabled      = 0,
    .demod_arg     = 0,
};
