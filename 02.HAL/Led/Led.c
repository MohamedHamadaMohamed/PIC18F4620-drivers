/*
 * Led.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */



#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/Micro_Config.h"

#include "../../MCAL/Dio/Dio.h"

#include "Led_config.h"
#include "Led.h"

Led_Config  Leds_Array[Num_OF_LEDS] ; 
void LED_init(const Led_Config* Led_ConfigPtr)
{
    Leds_Array[Led_ConfigPtr->index].Led_Port = Led_ConfigPtr->Led_Port;
    Leds_Array[Led_ConfigPtr->index].Led_Pin =  Led_ConfigPtr->Led_Pin;
    Leds_Array[Led_ConfigPtr->index].Logic_Type = Led_ConfigPtr->Logic_Type;
    
    Dio_ConfigType led_config_temp = 
    {
     .Port_Index = Leds_Array[Led_ConfigPtr->index].Led_Port,
	 .Channel_Index = Leds_Array[Led_ConfigPtr->index].Led_Pin,
	 .direction = OUTPUT,
	 .resistor = OFF,
	 .initial_value = STD_LOW,
    };
	Dio_Init(&led_config_temp );
}
void LED_On(Index index)
{
    if (Leds_Array[index].Logic_Type == NEGATIVE_LOGIC)
    {
        Dio_WriteChannel(  Leds_Array[index].Led_Port,Leds_Array[index].Led_Pin, STD_LOW );
    }
    else if (Leds_Array[index].Logic_Type == POSITIVE_LOGIC)
    {
        Dio_WriteChannel(  Leds_Array[index].Led_Port,Leds_Array[index].Led_Pin, STD_HIGH );

    }
    else
    {

    }
}
void LED_Off(Index index)
{
    if (Leds_Array[index].Logic_Type == NEGATIVE_LOGIC)
    {
        Dio_WriteChannel(  Leds_Array[index].Led_Port,Leds_Array[index].Led_Pin, STD_HIGH );
    }
    else if (Leds_Array[index].Logic_Type == POSITIVE_LOGIC)
    {
        Dio_WriteChannel(  Leds_Array[index].Led_Port,Leds_Array[index].Led_Pin, STD_LOW );

    }
    else
    {

    }


}
void LED_Toggle(Index index)
{


}