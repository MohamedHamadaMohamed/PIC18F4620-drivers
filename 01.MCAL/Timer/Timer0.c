/*
 * File:   timer0.c
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "Timer_Types.h"
#include "Timer_Private.h"
#include "Timer0.h"
#include "Timer_Cfg.h"

std_ReturnType Timer0_init()
{
    TIMER0_MODULE_DISABLE();
    
#if TIMER0_nBIT_REGISTER_MODE == TIMER0_8BIT_REGISTER_MODE
    TIMER0_8BIT_REGISTER_MODE_ENABLE();
#elif TIMER0_nBIT_REGISTER_MODE == TIMER0_16BIT_REGISTER_MODE
    TIMER0_16BIT_REGISTER_MODE_ENABLE();
#endif
#if TIMER0_MODE_SELECT == TIMER0_TIMER_MODE
    TIMER0_TIMER_MODE_ENABLE();
#elif TIMER0_MODE_SELECT == TIMER0_COUNTER_MODE
    TIMER0_COUNTER_MODE_ENABLE();
    

    
#if TIMER0_COUNTER_EDGE_CFG == TIMER0_COUNTER_RISING_EDGE_CFG
    TIMER0_RISING_EDGE_ENABLE();
#elif TIMER0_COUNTER_EDGE_CFG == TIMER0_COUNTER_FALLING_EDGE_CFG
    TIMER0_FALLING_EDGE_ENABLE();
#endif

#endif
  
 /** enable / disable prescaler **/   
#if TIMER0_PRESCALER_CFG == TIMER0_PRESCALER_ENABLE_CFG
    TIMER0_PRESCALER_ENABLE();

    TIMER0_PRESCALER_CONFIG(TIMER0_PRESCALER_SELECT);

#elif TIMER0_PRESCALER_CFG == TIMER0_PRESCALER_DISABLE_CFG
    TIMER0_PRESCALER_DISABLE();    
#endif

    

    TIMER0_MODULE_ENABLE();
}


std_ReturnType Timer0_Write_Value( uint16 _value){
    std_ReturnType ret = E_NOT_OK;
    TMR0H = (_value) >> 8;
    TMR0L = (uint8)(_value);
    ret = E_OK;
    return ret;
}

uint16 Timer0_Read_Value(void)
{
    uint16 ret = ZERO_INIT;
    uint8 l_tmr0l = ZERO_INIT, l_tmr0h = ZERO_INIT;
    l_tmr0l = TMR0L;
    l_tmr0h = TMR0H;
    ret = (uint16)((l_tmr0h << 8) + l_tmr0l);
    
    return ret;
}