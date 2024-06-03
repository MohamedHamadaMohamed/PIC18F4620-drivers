/*
 * File:   LM35.c
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#ifndef LM35_H_
#define	LM35_H_

#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/ADC/ADC.h"

#include "../../LIB/LM35.h"
#include "../../LIB/LM35_Cfg.h"

void LM35_Init(void)
{
    ADC_Init();

}
uint16 LM35_TempValue(void)
{
    uint16 Temp = 0;
    ADC_startConversion();
    Temp = ADC_ReadChannel(TEMP_ANALOG_PIN)/2;
    return Temp;
}

#endif	



