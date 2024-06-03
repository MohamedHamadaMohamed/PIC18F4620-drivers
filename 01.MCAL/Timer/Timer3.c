/*
 * File:   timer3.c
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "Timer_Types.h"
#include "Timer_Private.h"
#include "Timer3.h"
#include "Timer_Cfg.h"




std_ReturnType Timer3_init()
{
TIMER3_MODULE_DISABLE();


#if TIMER3_MODE_SELECT == TIMER3_TIMER_MODE
 TIMER3_TIMER_MODE_ENABLE();
#elif TIMER3_MODE_SELECT == TIMER3_COUNTER_MODE
 TIMER3_COUNTER_MODE_ENABLE(); 
#endif
#if TIMER3_RW_REG_nBit_MODE == TIMER3_RW_REG_8Bit_MODE
TIMER3_RW_REG_8BIT_MODE_ENABLE();
#elif TIMER3_RW_REG_nBit_MODE == TIMER3_RW_REG_16Bit_MODE
TIMER3_RW_REG_16BIT_MODE_ENABLE();
#endif

#if TIMER3_SYNC_ASYNC_COUNTER_MODE == TIMER3_ASYNC_COUNTER_MODE
TIMER3_ASYNC_COUNTER_MODE_ENABLE();
#elif TIMER3_SYNC_ASYNC_COUNTER_MODE == TIMER3_SYNC_COUNTER_MODE
TIMER3_SYNC_COUNTER_MODE_ENABLE();
#endif



TIMER3_PRESCALER_SELECT(TIMER3_PRETSCALER_VALUE);


TIMER3_MODULE_ENABLE();

}
std_ReturnType Timer3_DeInit()
{
TIMER3_MODULE_DISABLE();
}
std_ReturnType Timer3_Write_Value( uint16 _value)
{
   std_ReturnType ret = E_NOT_OK;
    TMR3H = (_value) >> 8;
    TMR3L = (uint8)(_value);
    ret = E_OK;
    return ret;

}
uint16 Timer3_Read_Value(void)
{
 uint16 ret = ZERO_INIT;
    uint8 l_tmr0l = ZERO_INIT, l_tmr0h = ZERO_INIT;
    l_tmr0l = TMR3L;
    l_tmr0h = TMR3H;
    ret = (uint16)((l_tmr0h << 8) + l_tmr0l);
    
    return ret;
}

