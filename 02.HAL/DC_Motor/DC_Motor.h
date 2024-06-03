/* 
 * File:   DC_Motor.h
 * Author: Moham
 *
 * Created on 09 ????, 2023, 05:07 ?
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

#include "../../LIB/Std_Types.h"


#define DC_Motor_OFF          0
#define DC_Motor_ON           1


typedef struct
{
Dio_PortType PortId_in1;
Dio_PortType PortId_in2;
Dio_ChannelType ChannelId_in1;
Dio_ChannelType ChannelId_in2;

}DC_Motor_Config;

std_ReturnType DC_Motor_init(const DC_Motor_Config * DcMotorConfigPtr );
std_ReturnType DC_Motor_forward(const DC_Motor_Config * DcMotorConfigPtr   );
std_ReturnType DC_Motor_backward(const DC_Motor_Config * DcMotorConfigPtr  );
std_ReturnType DC_Motor_Stop(const DC_Motor_Config * DcMotorConfigPtr );



#endif	/* DC_MOTOR_H */

