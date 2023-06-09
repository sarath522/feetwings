/*
 * max30009.c
 *
 *  Created on: 12-Apr-2023
 *      Author: Srushty00
 */


#include "max30009.h"

#define NUM_BYTES_PER_SAMPLE	3
#define NUM_SAMPLES_PER_INT		2

uint8_t readBuf[FIFO_A_FULL_156*NUM_BYTES_PER_SAMPLE];	// array to store register reads


uint32_t i_adcCountArr[FIFO_A_FULL_156];
uint32_t q_adcCountArr[FIFO_A_FULL_156];
uint32_t adcCountArr[FIFO_A_FULL_156];

uint16_t max30009_getFifoDataCount()
{
	uint8_t value = 0;
	uint16_t FIFODataCount = 0;
	value = spi_read(FIFO_COUNTER_2);
	FIFODataCount = value;
	value = spi_read(FIFO_COUNTER_1);
	value = value >> 7;
	FIFODataCount |= (value << 8);
	return FIFODataCount;
}

uint8_t max30009_getFifoOverflowCount()
{
	uint8_t value = 0;
	value = spi_read(FIFO_COUNTER_1);
	value &= 0x7F;
	return value;
}

void max30009_init()
{

	spi_write(BIOZ_CONFIG_1, BIOZ_DAC_OSR_32 | BIOZ_ADC_OSR_512 | BIOZ_BANDGP_DISABLE | BIOZ_Q_DISABLE | BIOZ_I_DISABLE);//set DAC_OSR and ADC_OSR & Disable BioZ

	spi_write(PLL_CONFIG_4, PLL_REF_SEL_INTERNAL | SET_INTERNAL_CLK_32 | PLL_CLK_FINE_TUNE_26);//Set internal clock source, Set PLL clock reference to 32.768Khz

	spi_write(PLL_CONFIG_1,MDIV_MSB | NDIV_512 | KDIV_1);//set MDIV MSB, NDIV and KDIV

	spi_write(PLL_CONFIG_2,MDIV_LSB); //set MDIV LSB

	spi_write(PLL_CONFIG_3,PLL_LOCK_WNDW_ENABLE);//Enabling PLL window helps to avoid false phase_unlock interrupt

    spi_write(PLL_CONFIG_1, PLL_ENABLE);//PLL Enabled

    uint8_t freq_lock = 0;

    while (!freq_lock) // Wait till PLL is locked
    {
    	freq_lock = spi_read(STATUS_1);
    	freq_lock = ((freq_lock & 0x08) >> 3);
    	MXC_Delay(10);
    }
    //Set Voltage magnitude = 250mVpk, set internal current range resistor=5.525Kohm, stimulus type = current
    spi_write(BIOZ_CONFIG_3, BIOZ_EXT_RES_DISABLE | LOFF_RAPID_DELAY | BIOZ_VDRV_MAG_250mV | BIOZ_IDRV_RGE_2 | BIOZ_DRV_MODE_CURRENT);

    spi_write(BIOZ_CONFIG_4, 0x00); // Fast start Disabled

    //Resistor opened, internal capacitor shorted, Bioz gain is 10, Bioz demodulation clk enabled,Bioz INA High Power Mode is enabled
    spi_write(BIOZ_CONFIG_5,BIOZ_AHPF_BYPASS_FILTER | BIOZ_INA_MODE_HIGH_POWER | BIOZ_DM_DIS_DEMOD_CLK_ENABLE | BIOZ_GAIN_10);

    //
    spi_write(BIOZ_CONFIG_6 , BIOZ_EXT_CAP_USED | BIOZ_DC_RESTORE_SW_CLOSE | BIOZ_AMP_BW_MED_HIGH| BIOZ_AMP_RGE_MED_HIGH);

//	spi_write(BIOZ_CONFIG_LOW_THRES, 0x00);//BIOZ_LO_THRESH sets the BioZ under-range threshold
//
//	spi_write(BIOZ_CONFIG_HIGH_THRES, 0xFF);//BIOZ_HI_THRESH sets the BioZ over-range threshold.

	spi_write(BIOZ_CONFIG_7,BIOZ_STBYON_DISABLE | BIOZ_Q_CLK_PHASE_NORMAL |  BIOZ_I_CLK_PHASE_NORMAL | BIOZ_INA_CHOP_ENABLE | BIOZ_CH_FSEL_8);

	spi_write(BIOZ_MUX_CONFIG_1, BMUX_RSEL_5100 | BMUX_BIST_EN_DISABLE | CONNECT_CAL_ONLY_ENABLE | MUX_EN_1 | CAL_EN_DISCONNECT);

	spi_wite(BIOZ_MUX_CONFIG_2 , BMUX_GSR_RSEL_25 | GSR_LOAD_DISABLE | EN_EXT_INLOAD_DISABLE | EN_EXT_INLOAD_ENABLE);

	spi_write(BIOZ_MUX_CONFIG_3 , BIP_ASSGN_EL2A | BIN_ASSGN_EL3A | DRVP_ASSGN_EL1 | DRVN_ASSGN_EL4 );

	spi_write(DC_LEAD_CONFIG , EN_LON_DET_ULP_DISABLE | EN_LOFF_DET_DISABLE | EN_EXT_LOFF_0 | EN_DRV_OOR_DISABLE | LOFF_IPOL_NON_INVERTED | LOFF_IMAG_0);

	spi_write(DC_LEAD_DETECT_THRES, DC_LEAD_OFF_THRESHOLD);

	spi_write(LEAD_BIAS_CONFIG, RBIAS_VALUE_200mV | EN_RBIAS_BIP_CONNECTED | EN_RBIAS_BIN_CONNECTED);

	spi_write(INTERRUPT_ENABLE_1,INT_A_FULL_ENABLE);

	spi_write(FIFO_CONFIG_1,FIFO_A_FULL_156);

	spi_write(FIFO_CONFIG_1,FIFO_SELF_CLEANING_DISABLE | FIFO_FLUSH_ENABLE | FIFO_STATUS_CLEAR_ENABLE | FULL_TYPE_DISABLE | FIFO_RO_ENABLE);

	enable_bioz();

}

void max30009_startBiozMeasurement(){

		uint8_t value = 0;
		value = spi_read(BIOZ_CONFIG_1);
		value = ((value & 0xF8)| BIOZ_BANDGP_ENABLE | BIOZ_Q_ENABLE | BIOZ_I_ENABLE);
		spi_write(BIOZ_CONFIG_1,value);

}

void max30009_stopBiozMeasurement(){

		uint8_t value = 0;
		value = spi_read(BIOZ_CONFIG_1);
		value = (value & 0xF8);
		spi_write(BIOZ_CONFIG_1,value);

}


uint8_t get_data_from_buffer()
{
	uint8_t value[8];
	value=spiRead(STATUS_1, 0x80);	// read and clear all status registers
	if (!(value[0] & CHECK_FULL_BIT_ENABLE))										// check A_FULL bit
		return 0;
	uint32_t count = getFifoDataCount();		// read FIFO_DATA_COUNT
	readBuf=spiRead(FIFO_DATA_REGISTER, count*NUM_BYTES_PER_SAMPLE);	// read FIFO_DATA

}

uint32_t parse_data(uint8_t readBuf[])
{
	uint32_t count = getFifoDataCount();
	uint8_t ix=0, jx=0;
	for (ix=0; ix < count * NUM_BYTES_PER_SAMPLE; ix+=NUM_BYTES_PER_SAMPLE)
	{
		uint8_t tag = (readBuf[ix+0]&0xf0);
		if(16 == tag) //
		{
			i_phase();

		}
		else if(32 == tag)
		{
			q_phase();
		}
																							// parse the FIFO data
		//adcCountArr[jx++] = ((readBuf[ix+0]&0xf)<<16) + (readBuf[ix+1]<<8) + readBuf[ix+2];
	}

	return adcCountArr;

}

uint32_t i_phase_parsing(uint8_t readBuf[])
{
	uint32_t count = getFifoDataCount();

	uint8_t ix=0, jx=0;

	for (ix=0; ix < count * NUM_BYTES_PER_SAMPLE; ix+=NUM_BYTES_PER_SAMPLE)
	{
		i_adcCountArr[jx++] = ((readBuf[ix+0]&0xf)<<16) + (readBuf[ix+1]<<8) + readBuf[ix+2];
	}
	return i_adcCountArr;

}

uint32_t q_phase_parsing(uint8_t readBuf[])
{
	uint32_t count = getFifoDataCount();

	uint8_t ix=0, jx=0;

	for (ix=0; ix < count * NUM_BYTES_PER_SAMPLE; ix+=NUM_BYTES_PER_SAMPLE)
	{
		q_adcCountArr[jx++] = ((readBuf[ix+0]&0xf)<<16) + (readBuf[ix+1]<<8) + readBuf[ix+2];
	}
	return q_adcCountArr;

}
