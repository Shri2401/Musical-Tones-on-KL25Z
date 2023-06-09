#include "MKL25Z4.h"
#include "DAC.h"

#define DAC_POS 30
/*
 * Brief     : Initializes the DAC0 module
 *
 * Parameters: NULL
 *
 * Return    : NULL
 */

void Init_DAC0(){
	//Enable clock for DAC and PORTE
	SIM->SCGC6 |= SIM_SCGC6_DAC0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	//Select analog for pin
	PORTE->PCR[DAC_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[DAC_POS] |= PORT_PCR_MUX(0);
	//Disable buffer mode
	DAC0->C1 = 0;
	DAC0->C2 = 0;
	DAC0->C0 &= ~DAC_C0_DACTRGSEL_MASK;
	//Enable DAC, Select VDDA as reference voltage
	DAC0->C0 |= DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;

}
