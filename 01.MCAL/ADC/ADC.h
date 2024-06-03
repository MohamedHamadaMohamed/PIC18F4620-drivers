/* 
 * File:   ADC.h
 * Author: Mohamed Hamada
 *
 * Created on 03 ?????, 2023, 02:11 ?
 */

#ifndef ADC_H
#define	ADC_H

typedef enum
{
  ADC_CHANNEL_AN0=0,
  ADC_CHANNEL_AN1=1,
  ADC_CHANNEL_AN2=2,
  ADC_CHANNEL_AN3=3,
  ADC_CHANNEL_AN4=4,
  ADC_CHANNEL_AN5=5,
  ADC_CHANNEL_AN6=6,
  ADC_CHANNEL_AN7=7,       
  ADC_CHANNEL_AN8=8,
  ADC_CHANNEL_AN9=9,
  ADC_CHANNEL_AN10=10,
  ADC_CHANNEL_AN11=11,
  ADC_CHANNEL_AN12=12
}ADC_CHANNEL;    


void ADC_Init();
void ADC_Deinit();
void ADC_startConversion();
uint16 ADC_ReadChannel(ADC_CHANNEL a_channel);


#endif	/* ADC_H */

