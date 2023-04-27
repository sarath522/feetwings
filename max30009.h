/*
 * max30009.h
 *
 *  Created on: 11-Apr-2023
 *      Author: Srushty00
 */

#ifndef MAX30009_H_
#define MAX30009_H_

/* start of Registers list*/

#define STATUS_1 							0x00
#define STATUS_2 							0x01

#define FIFO_WRITE_POINTER 					0x08
#define FIFO_READ_POINTER 					0x09
#define FIFO_COUNTER_1 						0x0A
#define FIFO_COUNTER_2 						0x0B
#define FIFO_DATA_REGISTER 					0x0C
#define FIFO_CONFIG_1 						0x0D
#define FIFO_CONFIG_2 						0xOE

#define SYSTEM_SYNC 						0x10
#define SYSTEM_CONFIG 						0x11
#define PIN_FUNC_CONFIG						0x12
#define OUTPUT_PIN_CONFIG 					0x13
#define I2C_BROADCAST_ADDR 					0x14

#define PLL_CONFIG_1 						0x17
#define PLL_CONFIG_2 						0x18
#define PLL_CONFIG_3 						0x19
#define PLL_CONFIG_4 						0x1A

#define BIOZ_CONFIG_1 						0x20
#define BIOZ_CONFIG_2 						0x21
#define BIOZ_CONFIG_3 						0x22
#define BIOZ_CONFIG_4 						0x23
#define BIOZ_CONFIG_5 						0x24
#define BIOZ_CONFIG_6 						0x25
#define BIOZ_CONFIG_LOW_THRES				0x26
#define BIOZ_CONFIG_HIGH_THRES 				0x27
#define BIOZ_CONFIG_7 						0x28

#define BIOZ_MUX_CONFIG_1					0x41
#define BIOZ_MUX_CONFIG_2 					0x42
#define BIOZ_MUX_CONFIG_3 					0x43
#define BIOZ_MUX_CONFIG_4 					0x44

#define DC_LEAD_CONFIG 						0x50
#define DC_LEAD_DETECT_THRES 				0x51

#define LEAD_BIAS_CONFIG 					0x58

#define INTERRUPT_ENABLE_1 					0x80
#define INTERRUPT_ENABLE_2 					0x81

#define PART_ID_REG 						0xFF

/* End of Registers list*/


			//*status_1*//

#define SET_PHASE_LOCK 						0x02

#define CHECK_FULL_BIT_DISABLE				(0x00 << 7)
#define CHECK_FULL_BIT_ENABLE				(0x01 << 7)
			//*status_2*//

			//*FIFO_config_1*//

#define FIFO_A_FULL_156  					156

//typdef enum{
//
//	FIFO_A_FULL_0 = 0,
//	FIFO_A_FULL_1,
//	FIFO_A_FULL_2,
//	FIFO_A_FULL_3,
//	FIFO_A_FULL_4,
//	FIFO_A_FULL_5,
//	FIFO_A_FULL_6,
//	FIFO_A_FULL_7,
//	FIFO_A_FULL_8,
//	FIFO_A_FULL_9,
//	FIFO_A_FULL_10,
//	FIFO_A_FULL_11,
//	FIFO_A_FULL_12,
//	FIFO_A_FULL_13,
//	FIFO_A_FULL_14,
//	FIFO_A_FULL_15,
//	FIFO_A_FULL_16,
//	FIFO_A_FULL_17,
//	FIFO_A_FULL_18,
//	FIFO_A_FULL_19,
//
//}

			//*FIFO_config_2*//

#define FIFO_SELF_CLEANING_DISABLE 			(0x00 << 5)
#define FIFO_SELF_CLEANING_ENABLE 			(0x01 << 5)

#define FIFO_FLUSH_DISABLE          		(0x00 << 4)
#define FIFO_FLUSH_ENABLE 	         		(0x01 << 4)

#define FIFO_STATUS_CLEAR_ENABLE			(0x01 << 3)
#define FIFO_STATUS_CLEAR_DISABLE			(0x00 << 3)

#define FULL_TYPE_ENABLE           			(0x01 << 2)
#define FULL_TYPE_DISABLE           		(0x00 << 2)

#define FIFO_RO_ENABLE     					(0x01 << 1)
#define FIFO_RO_DISABLE 		    		(0x00 << 1)

				//*System_sync*//

#define TIMING_SYS_RESET_NORMAL_MODE 		(0x00 << 7)
#define TIMING_SYS_RESET_MASTER_SLAVE		(0x01 << 7)

				//*System_Config_1*/

#define MASTER_DISABLE						(0x00 << 7)//set the AFE to SLAVE mode
#define MASTER_ENABLE						(0x01 << 7)//set the AFE to master mode

#define ENABLE_I2C							(0x00 << 6)
#define DISABLE_I2C         				(0x01 << 6) // enables i2c/spi mode

#define SHDN_DISABLE      					(0x01 << 1)//NORMAL
#define SHDN_DISABLE      					(0x00 << 1) //Shutdown the max3009

#define RESET_DISABLE      					0x00//NORMAL
#define RESET_ENABLE      					0x01//forcely reset the MAX30009

				//*Pin_Func_Config_*/

#define INT_FCFG_FALLING				    0x00
#define INT_FCFG_RISING					    0x01

				//*output_Pin_Config_*/

#define INT_OUTPUT_OP_DRAIN_LOWOP 			(0x00 << 2)
#define INT_OUTPUT_HIGH_OUPUT				(0x01 << 2)
#define INT_OUTPUT_LOW_OUPUT				(0x02 << 2)
#define INT_OUTPUT_DONOT_USE      			(0x03 << 2)

#define TRIG_OUTPUT_OP_DRAIN_LOWOP 			0x00
#define TRIG_OUTPUT_HIGH_OUPUT				0X01
#define TRIG_OUTPUT_LOW_OUPUT				0X02
#define TRIG_OUTPUT_DONOT_USE       		0x03


//*I2C_Broad_cast*/
#define I2C_BCAST_DISABLE 					0x00
#define I2C_BCAST_ENABLE 					0x01 // write transactions to multiple devices

//*PLL_Config_1*/


#define MDIV_MSB							(0x01 << 6)
#define SET_CLK_BIOZ_ADC_1 					0x00
#define SET_CLK_BIOZ_ADC_2					0x20

#define NDIV_512							(0x00 << 5)
#define NDIV_1024							(0x01 << 5)

#define KDIV_1 								(0x00 << 1)
#define KDIV_2								(0x01 << 1)
#define KDIV_4 								(0x02 << 1)
#define KDIV_8 								(0x03 << 1)
#define KDIV_16 							(0x04 << 1)
#define KDIV_32 							(0x05 << 1)
#define KDIV_64 							(0x06 << 1)
#define KDIV_128 							(0x07 << 1)
#define KDIV_256 							(0x08 << 1)
#define KDIV_512 							(0x09 << 1)
#define KDIV_1024 							(0x0A << 1)
#define KDIV_2048 							(0x0B << 1)
#define KDIV_4096 							(0x0C << 1)
#define KDIV_8192 							(0x0D << 1)
#define KDIV_8192 							(0x0E << 1) 								(0x00 << 6)
#define KDIV_8192 							(0x0F << 1) 								(0x00 << 6)


#define PLL_DISABLE							0x00 //
#define PLL_ENABLE 							0x01 // PL_EN is set to one before enabling bioz measurement

				//*PLL_Config_2*/

#define MDIV_LSB  							0xE7


				//*PLL_Config_3*/
#define PLL_LOCK_WNDW_DISABLE 				0x00
#define PLL_LOCK_WNDW_ENABLE 				0x01 //(recommended when using high-jitter FCLK input)


				//*PLL_Config_4*/

#define PLL_REF_SEL_INTERNAL				(0x00 << 6) 		//Internal 32.0kHz or 32.768kHz oscillator used for REF_CLK
#define PLL_REF_SEL_EXTERNAL				(0x01 << 6)	 //External oscillator used for REF_CLK


#define SET_INTERNAL_CLK_32					(0x00 << 5)
#define SET_INTERNAL_CLK_32768				(0x01 << 5)	//

#define PLL_CLK_FINE_TUNE_00				(0x00 << 4)
#define PLL_CLK_FINE_TUNE_01				(0x01 << 4)
#define PLL_CLK_FINE_TUNE_02				(0x02 << 4)
#define PLL_CLK_FINE_TUNE_03				(0x03 << 4)
#define PLL_CLK_FINE_TUNE_04				(0x04 << 4)
#define PLL_CLK_FINE_TUNE_05				(0x05 << 4)
#define PLL_CLK_FINE_TUNE_06				(0x06 << 4)
#define PLL_CLK_FINE_TUNE_07				(0x07 << 4)
#define PLL_CLK_FINE_TUNE_08				(0x08 << 4)
#define PLL_CLK_FINE_TUNE_09				(0x09 << 4)
#define PLL_CLK_FINE_TUNE_10				(0x0A << 4)
#define PLL_CLK_FINE_TUNE_11				(0x0B << 4)
#define PLL_CLK_FINE_TUNE_12				(0x0C << 4)
#define PLL_CLK_FINE_TUNE_13				(0x0D << 4)
#define PLL_CLK_FINE_TUNE_14				(0x0E << 4)
#define PLL_CLK_FINE_TUNE_15				(0x0F << 4)
#define PLL_CLK_FINE_TUNE_16				(0x10 << 4)
#define PLL_CLK_FINE_TUNE_17				(0x11 << 4)
#define PLL_CLK_FINE_TUNE_18				(0x12 << 4)
#define PLL_CLK_FINE_TUNE_19				(0x13 << 4)
#define PLL_CLK_FINE_TUNE_20				(0x14 << 4)
#define PLL_CLK_FINE_TUNE_21				(0x15 << 4)
#define PLL_CLK_FINE_TUNE_22				(0x16 << 4)
#define PLL_CLK_FINE_TUNE_23				(0x17 << 4)
#define PLL_CLK_FINE_TUNE_24				(0x18 << 4)
#define PLL_CLK_FINE_TUNE_25				(0x19 << 4)
#define PLL_CLK_FINE_TUNE_26				(0x1A << 4)
#define PLL_CLK_FINE_TUNE_27				(0x1B << 4)
#define PLL_CLK_FINE_TUNE_28				(0x1C << 4)
#define PLL_CLK_FINE_TUNE_29				(0x1D << 4)
#define PLL_CLK_FINE_TUNE_30				(0x1E << 4)
#define PLL_CLK_FINE_TUNE_32				(0x1F << 4)

//*BioZ_Config_1*/


#define DISABLE_BIOZ 			  			0x00

#define BIOZ_DAC_OSR_32						(0x00 << 6) //Sample ratio 32
#define BIOZ_DAC_OSR_64						(0x01 << 6) //Sample ratio 64
#define BIOZ_DAC_OSR_128					(0x02 << 6) //Sample ratio 128
#define BIOZ_DAC_OSR_256					(0x03 << 6) //Sample ratio 256

#define BIOZ_ADC_OSR_8						(0x00 << 3) //Sample ratio 8
#define BIOZ_ADC_OSR_16						(0x01 << 3) //Sample ratio 16
#define BIOZ_ADC_OSR_32						(0x02 << 3) //Sample ratio 32
#define BIOZ_ADC_OSR_64						(0x03 << 3) //Sample ratio 64
#define BIOZ_ADC_OSR_128					(0x04 << 3) //Sample ratio 128
#define BIOZ_ADC_OSR_256					(0x05 << 3) //Sample ratio 256
#define BIOZ_ADC_OSR_512					(0x06 << 3) //Sample ratio 512
#define BIOZ_ADC_OSR_1024					(0x07 << 3) //Sample ratio 1024


#define BIOZ_BANDGP_DISABLE				 	0x00
#define BIOZ_BANDGP_ENABLE					(0x01 << 2)
#define BIOZ_Q_ENABLE       				(0x01 << 1)
#define BIOZ_Q_DISABLE      				(0x00 << 1)
#define BIOZ_I_ENABLE       				0x01
#define BIOZ_I_DISABLE      				0x00

//*BioZ_Config_2*/




//*BioZ_Config_3*/
#define BIOZ_EXT_RES_ENABLE		 			(0x01 << 7)
#define BIOZ_EXT_RES_DISABLE	 			(0x00 << 7)

#define LOFF_RAPID_DELAY					(0x00 << 6)
#define LOFF_RAPID_IMMEDIATE				(0x01 << 6)

#define BIOZ_VDRV_MAG_50mV					(0x00 << 4)
#define BIOZ_VDRV_MAG_100mV					(0x01 << 4)
#define BIOZ_VDRV_MAG_250mV					(0x02 << 4)
#define BIOZ_VDRV_MAG_500mV					(0x03 << 4)

#define BIOZ_IDRV_RGE_0						(0x00 << 2) // Internal resistor - 552.5 kOhms
#define BIOZ_IDRV_RGE_1						(0x01 << 2) // Internal resistor - 110.5 kOhms
#define BIOZ_IDRV_RGE_2						(0x02 << 2) // Internal resistor - 5.525 kOhms
#define BIOZ_IDRV_RGE_3						(0x03 << 2) // Internal resistor - 276.25 kOhms

#define BIOZ_DRV_MODE_CURRENT				0x00
#define BIOZ_DRV_MODE_VOLTAGE				0x01
#define BIOZ_DRV_MODE_HBRIDGE				0x02
#define BIOZ_DRV_MODE_STANDBY				0x03

/*BioZ_Config_5*/

#define BIOZ_AHPF_BYPASS_FILTER 			(0x0f << 4)
#define BIOZ_INA_MODE_HIGH_POWER			(0x00 << 3)
#define BIOZ_INA_MODE_LOW_P0WER				(0x01 << 3)
#define BIOZ_DM_DIS_DEMOD_CLK_ENABLE		(0x00 << 2)
#define BIOZ_DM_DIS_DEMOD_CLK_DISABLE		(0x00 << 2)
#define BIOZ_GAIN_1							0x00
#define BIOZ_GAIN_2 						0x01
#define BIOZ_GAIN_5 						0x02
#define BIOZ_GAIN_10 						0x04

/*BioZ_Config_6*/
#define BIOZ_EXT_CAP_NOT_USED 				(0x00 << 7)
#define BIOZ_EXT_CAP_USED					(0x01 << 7)
#define BIOZ_DC_RESTORE_SW_OPEN				(0x00 << 6)
#define BIOZ_DC_RESTORE_SW_CLOSE			(0x01 << 6)
#define	BIOZ_DRV_RESET_SW_OPEN				(0x00 << 5)
#define	BIOZ_DRV_RESET_SW_CLOSE				(0x01 << 5)
#define BIOZ_DAC_RESET						(0x00 << 4)//BIOZ_DAC_RESET forces the DDS DAC output to zero.
#define	BIOZ_AMP_RGE_LOW					(0x00 << 2)
#define	BIOZ_AMP_RGE_MED_LOW				(0x01 << 2)
#define	BIOZ_AMP_RGE_MED_HIGH				(0x02 << 2)
#define	BIOZ_AMP_RGE_HIGH					(0x03 << 2)
#define	BIOZ_AMP_BW_LOW 					0x00
#define	BIOZ_AMP_BW_MED_LOW 				0x01
#define	BIOZ_AMP_BW_MED_HIGH 				0x02
#define	BIOZ_AMP_BW_HIGH 					0x03


/*BioZ_Config_7*/
#define BIOZ_STBYON_DISABLE 				(0x00 << 4)//. The receive channel's amplifiers, demodulators, and ADCs are disabled.
#define BIOZ_STBYON_ENABLE	 				(0x00 << 4)//The BioZ receive channel's amplifiers, demodulators, and ADCs remain enabled.

#define BIOZ_Q_CLK_PHASE_NORMAL				(0x00 << 3)
#define BIOZ_Q_CLK_PHASE_IPHASE				(0x01 << 3)

#define BIOZ_I_CLK_PHASE_NORMAL				(0x00 << 2)
#define BIOZ_I_CLK_PHASE_QPHASE				(0x01 << 2)


#define BIOZ_INA_CHOP_DISABLE 				(0x00 << 1)
#define BIOZ_INA_CHOP_ENABLE 				(0x01 << 1)

#define BIOZ_CH_FSEL_8						0x00
#define BIOZ_CH_FSEL_4						0x01


/*BioZ_mux_Config_1*/

#define BMUX_RSEL_5100						(0X00 << 6)
#define BMUX_RSEL_900						(0X01 << 6)
#define BMUX_RSEL_600						(0X02 << 6)
#define BMUX_RSEL_280						(0X03 << 6)

#define BMUX_BIST_EN_DISABLE				(0X00 << 5)//Disabled. The internal resistive load is disconnected.
#define BMUX_BIST_EN_ENABLE					(0X01 << 5)//Enabled. The internal resistive load is connected between DRVP and BIP, and DRVN and BIN.

#define CONNECT_CAL_ONLY_ENABLE				(0x00 << 2)
#define CONNECT_CAL_ONLY_DISABLE			(0x01 << 2)

#define MUX_EN_0							(0x00 << 1)
#define MUX_EN_1							(0x01 << 1)

#define CAL_EN_DISCONNECT					 0X00
#define CAL_EN_CONNECTED					 0X01

/*BioZ_mux_Config_2*/

#define BMUX_GSR_RSEL_25					(0x00 << 6)
#define BMUX_GSR_RSEL_101					(0x01 << 6)
#define BMUX_GSR_RSEL_505					(0x02 << 6)
#define BMUX_GSR_RSEL_1000					(0x03 << 6)

#define GSR_LOAD_DISABLE					(0x00 << 5)
#define GSR_LOAD_ENABLE						(0x01 << 5)

#define EN_EXT_INLOAD_DISABLE				(0x00 << 1)
#define EN_EXT_INLOAD_ENABLE				(0x01 << 1)

#define EN_INT_INLOAD_DISABLE				0x00
#define EN_INT_INLOAD_DISABLE				0x01


/*BioZ_mux_Config_3*/

#define	BIP_ASSGN_EL1						(0x00 << 6)
#define	BIP_ASSGN_EL2A						(0x01 << 6)
#define	BIP_ASSGN_EL2B						(0x02 << 6)
#define	BIP_ASSGN_DO_NOT					(0x03 << 6)

#define	BIN_ASSGN_EL4						(0x00 << 4)
#define	BIN_ASSGN_EL3A						(0x01 << 4)
#define	BIN_ASSGN_EL3B						(0x02 << 4)
#define	BIN_ASSGN_DO_NOT					(0x03 << 4)

#define	DRVP_ASSGN_EL1						(0x00 << 2)
#define	DRVP_ASSGN_EL2A						(0x01 << 2)
#define	DRVP_ASSGN_EL2B						(0x02 << 2)
#define	DRVP_ASSGN_DO_NOT					(0x03 << 2)

#define	DRVN_ASSGN_EL4						0x00
#define	DRVN_ASSGN_EL3A						0x01
#define	DRVN_ASSGN_EL3B						0x02
#define	DRVN_ASSGN_DO_NOT					0x03

/*BioZ_mux_Config_4*/



/*DC_LEAD_COnfiguration*/

#define EN_LON_DET_ULP_DISABLE 				(0x00 << 7) //lead off detection
#define EN_LON_DET_ULP_ENABLE 				(0x01 << 7)

#define EN_LOFF_DET_DISABLE 				(0x00 << 6)//BioZ DC lead-off detection is disabled
#define EN_LOFF_DET_ENABLE 					(0x01 << 6)//BioZ DC lead-off detection is ENabled

#define EN_EXT_LOFF_0						(0x00 << 5)
#define EN_EXT_LOFF_1						(0x01 << 5)

#define EN_DRV_OOR_DISABLE					(0x00 << 4)
#define EN_DRV_OOR_ENABLE					(0x01 << 4)

#define	LOFF_IPOL_NON_INVERTED				(0x00 << 3)
#define	LOFF_IPOL_INVERTED	  				(0x01 << 3)

#define LOFF_IMAG_0 						(0x00 << 2)
#define LOFF_IMAG_5 						(0x01 << 2)
#define LOFF_IMAG_10 						(0x02 << 2)
#define LOFF_IMAG_20 						(0x03 << 2)
#define LOFF_IMAG_50 						(0x04 << 2)
#define LOFF_IMAG_100 						(0x05 << 2)
#define LOFF_IMAG_100 						(0x06 << 2)
#define LOFF_IMAG_100 						(0x07 << 2)


/*DC_LEAD_Detect_THreshold*/

#define DC_LEAD_OFF_THRESHOLD 				 0x00 //Voltage Threshold for leads off window comparators

/*LEAD_Bias_config*/

#define  RBIAS_VALUE_50mV 					(0x00 << 3)
#define  RBIAS_VALUE_100mV 					(0x01 << 3)
#define  RBIAS_VALUE_200mV 					(0x02 << 3)
#define  RBIAS_VALUE_DO_NOT 				(0x03 << 3)

#define  EN_RBIAS_BIP_NOT_CONNECTED			(0x00 << 1)  //Enables Lead BIAS on BIP through Rbias value
#define  EN_RBIAS_BIP_CONNECTED		   		(0x01 << 1) //Enables Lead BIAS on BIn through Rbias value

#define  EN_RBIAS_BIN_NOT_CONNECTED		   	0x00
#define  EN_RBIAS_BIN_CONNECTED		   		0x01

/*Interrupt Enable 1*/

#define INT_A_FULL_DISABLE 					(0x00 << 7)
#define INT_A_FULL_ENABLE 					(0x01 << 7)

#define FIFO_DATA_RDY_DISABLE				(0x00 << 5)
#define FIFO_DATA_RDY_ENABLE				(0x01 << 5)

#define FREQ_UNLOCK_ENABLE 					(0x00 << 4)
#define FREQ_UNLOCK_DISABLE 				(0x01 << 4)

#define FREQ_LOCK_ENABLE					(0x00 << 3)
#define FREQ_LOCK_DISABLE					(0x01 << 3)

#define PHASE_UNLOCK_ENABLE					(0x00 << 2)
#define PHASE_UNLOCK_DISABLE				(0x01 << 2)

#define PHASE_LOCK_ENABLE					(0x00 << 1)
#define PHASE_LOCK_DISABLE					(0x01 << 1)


/*Interrupt Enable 2*/
#define LON_EN_DISABLE 						(0x00 << 7)
#define LON_EN_ENABLE 						(0x01 << 7)

#define BIOZ_OVER_EN_DISABLE 				(0x00 << 6)
#define BIOZ_OVER_EN_ENABLE 				(0x01 << 6)

#define BIOZ_UNDR_EN_DISABLE				(0x00 << 5)
#define BIOZ_UNDR_EN_ENABLE					(0x01 << 5)

#define DRV_OOR_EN_ENABLE 					(0x00 << 4)
#define DRV_OOR_EN_DISABLE 					(0x01 << 4)

#define DC_LOFF_PH_EN_ENABLE				(0x00 << 3)
#define DC_LOFF_PH_EN_DISABLE				(0x01 << 3)

#define DC_LOFF_PL_EN_ENABLE				(0x00 << 2)
#define DC_LOFF_PL_EN_DISABLE				(0x01 << 2)

#define DC_LOFF_NH_EN_ENABLE				(0x00 << 1)
#define DC_LOFF_NH_EN_DISABLE				(0x01 << 1)

#define DC_LOFF_NL_EN_DISABLE				0X00
#define DC_LOFF_NL_EN_ENABLE				0x01

uint16_t getFifoDataCount();


#endif /* MAX30009_H_ */
