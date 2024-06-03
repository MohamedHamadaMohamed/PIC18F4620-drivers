/*
 * File:   timer0.h
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#ifndef TIMER0_H_
#define TIMER0_H_


std_ReturnType Timer0_init();
std_ReturnType Timer0_Write_Value( uint16 _value);
uint16 Timer0_Read_Value(void);


#endif
