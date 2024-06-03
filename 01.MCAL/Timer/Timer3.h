/*
 * File:   timer3.h
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#ifndef TIMER3_H_
#define TIMER3_H_


std_ReturnType Timer3_init();
std_ReturnType Timer3_DeInit();
std_ReturnType Timer3_Write_Value( uint16 _value);
uint16 Timer3_Read_Value(void);


#endif
