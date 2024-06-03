/*
 * File:   timer2.c
 * Author: Mohamed Hamada
 *
 * Created on September 2, 2023, 4:12 PM
 */
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "Timer_Types.h"
#include "Timer_Private.h"
#include "Timer2.h"
#include "Timer_Cfg.h"



std_ReturnType Timer2_init()
{
    TIMER2_MODULE_DISABLE();
    TIMER2_PRESCALER_SELECT(TIMER2_PRETSCALER_VALUE);
    TIMER2_POSTSCALER_SELECT(TIMER2_POSTSCALER_VALUE);
    TIMER2_MODULE_ENABLE();
}
std_ReturnType Timer2_DeInit()
{
    TIMER2_MODULE_DISABLE();

}
std_ReturnType Timer2_Write_Value( uint8 _value)
{
TMR2 = _value;
}
uint8 Timer2_Read_Value(void)
{
uint8 _value ;
_value = TMR2;

return _value;

}