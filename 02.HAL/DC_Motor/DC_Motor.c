
/* 
 * File:   DC_Motor.h
 * Author: Moham
 *
 * Created on 09 ????, 2023, 05:07 ?
 */


#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/Micro_Config.h"
#include "../../MCAL/Dio/Dio.h"

#include "DC_Motor_config.h"
#include "DC_Motor.h"

std_ReturnType DC_Motor_init(const DC_Motor_Config * DcMotorConfigPtr )
{
std_ReturnType ret = E_OK;

Dio_ConfigType DcMotor_config_in1 = 
    {
     .Port_Index = DcMotorConfigPtr->PortId_in1,
	 .Channel_Index =DcMotorConfigPtr ->ChannelId_in1,
	 .direction = OUTPUT,
	 .resistor = OFF,
	 .initial_value = STD_LOW,
    };
Dio_ConfigType DcMotor_config_in2 = 
    {
     .Port_Index = DcMotorConfigPtr->PortId_in2,
	 .Channel_Index =DcMotorConfigPtr ->ChannelId_in2,
	 .direction = OUTPUT,
	 .resistor = OFF,
	 .initial_value = STD_LOW,
    };
	Dio_Init(&DcMotor_config_in1 ); 
	Dio_Init(&DcMotor_config_in2 ); 

return ret;
}
std_ReturnType DC_Motor_forward(const DC_Motor_Config * DcMotorConfigPtr   )
{
std_ReturnType ret = E_OK;
 Dio_WriteChannel( DcMotorConfigPtr->PortId_in1,DcMotorConfigPtr ->ChannelId_in1, STD_HIGH );
 Dio_WriteChannel( DcMotorConfigPtr->PortId_in2,DcMotorConfigPtr ->ChannelId_in2, STD_LOW );

return ret;
}

std_ReturnType DC_Motor_backward(const DC_Motor_Config * DcMotorConfigPtr  )
{
std_ReturnType ret = E_OK;
 Dio_WriteChannel( DcMotorConfigPtr->PortId_in1,DcMotorConfigPtr ->ChannelId_in1, STD_LOW );
 Dio_WriteChannel( DcMotorConfigPtr->PortId_in2,DcMotorConfigPtr ->ChannelId_in2, STD_HIGH );

return ret;
}
std_ReturnType DC_Motor_Stop(const DC_Motor_Config * DcMotorConfigPtr )
{
std_ReturnType ret = E_OK;

 Dio_WriteChannel( DcMotorConfigPtr->PortId_in1,DcMotorConfigPtr ->ChannelId_in1, STD_LOW );
 Dio_WriteChannel( DcMotorConfigPtr->PortId_in2,DcMotorConfigPtr ->ChannelId_in2, STD_LOW );


return ret;
}
