
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "ADC.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"

void ADC_Init(void)
{
    ADC_Disable();
    ADC_ANALOG_DIGITAL_PORT_CONFIG(ADC_PORT_CONFIGURATION_CONTROL);
    ADC_ACQUISITION_TIME_SEECT(ADC_ACQUISITION_TIME);
    ADC_CONVERSION_CLOCK_SELECT(ADC_CONVERSION_CLOCK);
    ADC_RESULT_FORMAT_jUSTIFIED(ADC_RESULT_FORMAT);
    ADC_VOLTAGE_REFERENCE();

    ADC_Enable();
}
void ADC_Deinit()
{
    ADC_Disable();
}
void ADC_startConversion()
{
    ADC_START_CONVERSION();
}
uint16 ADC_ReadChannel(ADC_CHANNEL a_channel)
{ 
    uint16 Data =0;
    ADCON0bits.CHS = 0;
    Analog_Channel_Select(a_channel);
    while(ADC_CONVERSION_STATUS() == 0 );
    
    #if ADC_RESULT_FORMAT == ADC_RESULT_FORMAT_RIGHT

    Data = (ADRESH<<8)+(ADRESL);
    
    #else if ADC_RESULT_FORMAT == ADC_RESULT_FORMAT_LEFT
        Data = ((ADRESH<<8)+(ADRESL)>>6);
    #endif
    
    return Data;
}