/*
 * File:   timer_Cfg.h
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/************** Timer 0  **************/
#define TIMER0_MODE_SELECT          TIMER0_TIMER_MODE
#define TIMER0_PRESCALER_CFG        TIMER0_PRESCALER_ENABLE_CFG
#define TIMER0_PRESCALER_SELECT     TIMER0_PRESCALER_DIV_BY_4 
#define TIMER0_nBIT_REGISTER_MODE   TIMER0_16BIT_REGISTER_MODE
#define TIMER0_COUNTER_EDGE_CFG     TIMER0_COUNTER_RISING_EDGE_CFG

/************** Timer 1  **************/

#define TIMER1_MODE_SELECT               TIMER1_TIMER_MODE
#define TIMER1_SYNC_ASYNC_COUNTER_MODE   TIMER1_ASYNC_COUNTER_MODE        
#define TIMER1_PRESCALER_Cfg             TIMER1_PRESCALER_DIV_BY_4 
#define TIMER1_RW_REG_nBit_MODE          TIMER1_RW_REG_16Bit_MODE
#define TIMER1_OSC_HW_Cfg                TIMER1_OSCILLATOR_DISABLE

/************** Timer 2  **************/
#define TIMER2_POSTSCALER_VALUE             TIMER2_POSTSCALER_DIV_BY_1
#define TIMER2_PRETSCALER_VALUE             TIMER2_PRESCALER_DIV_BY_1

/* Timer 3*/

#define TIMER3_MODE_SELECT                  TIMER3_TIMER_MODE
#define TIMER3_PRETSCALER_VALUE             TIMER3_PRESCALER_DIV_BY_1
#define TIMER3_RW_REG_nBit_MODE             TIMER3_RW_REG_16Bit_MODE
#define TIMER3_SYNC_ASYNC_COUNTER_MODE      TIMER3_ASYNC_COUNTER_MODE


#endif
