/*
 * File:   timer1.h
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#ifndef TIMER1_H_
#define TIMER1_H_

std_ReturnType Timer1_init();
std_ReturnType Timer1_DeInit();
std_ReturnType Timer1_Write_Value( uint16 _value);
uint16 Timer1_Read_Value(void);




#endif
