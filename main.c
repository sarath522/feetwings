/**
 * @file    
 * @brief   SPIM example using the MX25.
 * @details Uses the MX25 on the EvKit to show the SPIM. Erases, writes, and then
 *          verifies the data. BUFF_SIZE, MX25_BAUD, MX25_ADDR, and MX25_SPIM_WIDTH
 *          can be changed to alter the communication between the devices. Refer
 *          to the schematic for the pinout and ensure that there are no switches
 *          blocking the communication to the MX25.
 */

/* *****************************************************************************
 * Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 * $Date: 2017-02-28 11:00:56 -0600 (Tue, 28 Feb 2017) $
 * $Revision: 26738 $
 *
 *************************************************************************** */

/***** Includes *****/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "mxc_config.h"
#include "clkman.h"
#include "ioman.h"
#include "spim.h"
#include "max30009.h"

/***** Definitions *****/
#define MX25_BAUD           100000    // 48 MHz maximum, 20 kHz minimum
#define MX25_ADDR           0x0
#define MX25_SPIM_WIDTH     SPIM_WIDTH_8
#define MX25_EXP_ID         0xc22538

#define BUFF_SIZE           16

/***** Globals *****/
spim_req_t req;

/***** Functions *****/

/******************************************************************************/
int main(void)
{
    int error, i;
    uint8_t txdata[BUFF_SIZE];
    uint8_t rxdata[BUFF_SIZE];
//    printf("\n\n***** SPIM MX25 Example *****\n");
//
//    printf(" System freq \t: %d Hz\n", SystemCoreClock);
//    printf(" MX25 freq \t: %d Hz\n", MX25_BAUD);
//    printf(" MX25 ID \t: 0x%x\n", MX25_EXP_ID);
//    printf(" SPI data width : %d bits\n", (0x1 << MX25_SPIM_WIDTH));
//    printf(" Write/Verify   : %d bytes\n\n", BUFF_SIZE);

    // Initialize the data buffers
    for(i = 0; i < BUFF_SIZE; i++) {
        txdata[i] = i;
    }
    memset(rxdata, 0x0, BUFF_SIZE);

    // Initialize the SPIM
    spim_cfg_t cfg;
    cfg.mode = 0;
    cfg.ssel_pol = 0;
    cfg.baud = MX25_BAUD;

    sys_cfg_spim_t sys_cfg;

    // MX25 IO Config                  core I/O, ss0, ss1, ss2, quad, fast I/O
    sys_cfg.io_cfg = (ioman_cfg_t)IOMAN_SPIM0(1,   1,  0,    0,    0,        0, 0, 0);
    sys_cfg.clk_scale = CLKMAN_SCALE_AUTO;

    if((error = SPIM_Init(MXC_SPIM0, &cfg, &sys_cfg)) != E_NO_ERROR) {
        printf("Error initializing SPIM %d\n", error);
        while(1) {}
    } else {
        printf("SPIM Initialized\n");
    }

    uint8_t cmd[2] = {0xFF,0x80};
	uint8_t id = 0;

	// Send the command
	req.len     = 3;
	req.tx_data  = cmd;
	req.rx_data  = id;
	req.deass   = 0;
	SPIM_Trans(MXC_SPIM0, &req);

//	// Read the data
//	req.len     = 1;
//	req.tx_data  = NULL;
//	req.rx_data  = id;
//	req.deass   = 1;
//	SPIM_Trans(MXC_SPIM1, &req);

    while(1) {}
}
