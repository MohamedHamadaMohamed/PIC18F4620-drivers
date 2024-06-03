/*
 * File:   timer2.h
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#ifndef TIMER2_H_
#define TIMER2_H_


std_ReturnType Timer2_init();
std_ReturnType Timer2_DeInit();
std_ReturnType Timer2_Write_Value( uint8 _value);
uint8 Timer2_Read_Value(void);



#endif
