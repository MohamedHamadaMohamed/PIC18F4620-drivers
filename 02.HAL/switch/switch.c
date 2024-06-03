/*
 * switch.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */


#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/Micro_Config.h"

#include "../../MCAL/Dio/Dio.h"

#include "switch_config.h"
#include "switch.h"


Switch_Config  Switches_Array[Num_OF_SWITCHES] ={NULL} ; 

void switch_init(const Switch_Config* Switch_ConfigPtr)
{
    Switches_Array[Switch_ConfigPtr->index].Switch_Port = Switch_ConfigPtr->Switch_Port ;
    Switches_Array[Switch_ConfigPtr->index].Switch_Pin = Switch_ConfigPtr ->Switch_Pin ;
    Switches_Array[Switch_ConfigPtr->index].Switch_connection = Switch_ConfigPtr ->Switch_connection;
    
    Dio_ConfigType Dio_switch_Config = 
    {
     .Port_Index=  Switch_ConfigPtr->Switch_Port,
	 .Channel_Index= Switch_ConfigPtr ->Switch_Pin,
	 .direction= INPUT,
	 .resistor= OFF,
	 .initial_value= STD_LOW
    
    };
	Dio_Init(&Dio_switch_Config);

}
boolean switch_readSwitch(Index_t index)
{

boolean pressed = 0;

    if(Switches_Array[index].Switch_connection == SW_PULL_UP)
    {
        pressed =(! Dio_ReadChannel( Switches_Array[index].Switch_Port,Switches_Array[index].Switch_Pin ));

    }
    else if (Switches_Array[index].Switch_connection == SW_PULL_DOWN)
    {
        pressed =( Dio_ReadChannel( Switches_Array[index].Switch_Port,Switches_Array[index].Switch_Pin ));

    }
    else
    {

    }



return pressed;
}
