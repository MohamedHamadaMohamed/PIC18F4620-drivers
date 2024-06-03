/*
 * File:   timer1.c
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "Timer_Types.h"
#include "Timer_Private.h"
#include "Timer1.h"
#include "Timer_Cfg.h"

std_ReturnType Timer1_init()
{
 TIMER1_MODULE_DISABLE();
 
 
#if TIMER1_MODE_SELECT == TIMER1_TIMER_MODE
 TIMER1_TIMER_MODE_ENABLE();
#elif  TIMER1_MODE_SELECT == TIMER1_COUNTER_MODE
 TIMER1_COUNTER_MODE_ENABLE();
#endif
#if TIMER1_SYNC_ASYNC_COUNTER_MODE == TIMER1_SYNC_COUNTER_MODE
 TIMER1_SYNC_COUNTER_MODE_ENABLE(); 
#elif  TIMER1_SYNC_ASYNC_COUNTER_MODE == TIMER1_ASYNC_COUNTER_MODE
 TIMER1_ASYNC_COUNTER_MODE_ENABLE(); 
#endif 
 
TIMER1_PRESCALER_SELECT( TIMER1_PRESCALER_Cfg ); 
#if TIMER1_RW_REG_nBit_MODE == TIMER1_RW_REG_8Bit_MODE
TIMER1_RW_REG_8BIT_MODE_ENABLE();
#elif TIMER1_RW_REG_nBit_MODE == TIMER1_RW_REG_16Bit_MODE
TIMER1_RW_REG_8BIT_MODE_ENABLE();
#endif
#if TIMER1_OSC_HW_Cfg == TIMER1_OSCILLATOR_ENABLE
TIMER1_OSC_HW_ENABLE();
#elif TIMER1_OSC_HW_Cfg == TIMER1_OSCILLATOR_DISABLE
TIMER1_OSC_HW_DISABLE();
#endif


 
 
 
TIMER1_MODULE_ENABLE();


}
std_ReturnType Timer1_DeInit()
{
TIMER1_MODULE_DISABLE();

}
std_ReturnType Timer1_Write_Value( uint16 _value)
{
    std_ReturnType ret = E_NOT_OK;
    TMR1H = (_value) >> 8;
    TMR1L = (uint8)(_value);
    ret = E_OK;
    return ret;
}
uint16 Timer1_Read_Value(void)
{
    uint16 ret = ZERO_INIT;
    uint8 l_tmr0l = ZERO_INIT, l_tmr0h = ZERO_INIT;
    l_tmr0l = TMR0L;
    l_tmr0h = TMR0H;
    ret = (uint16)((l_tmr0h << 8) + l_tmr0l);
    
    return ret;
}