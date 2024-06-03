/* 
 * File:   Dio.h
 * Author: Mohamed Hamada
 *
 * Created on November 22, 2022, 11:57 AM
 */

#ifndef DIO_H
#define	DIO_H


#include "Dio_Types.h"


#define PORT_PIN_MAX_NUMBER           (uint8)8
#define PORT_MAX_NUMBER               (uint8)5



std_ReturnType Dio_Init( const Dio_ConfigType *ConfigPtr );
std_ReturnType Dio_SetPinDirection( Dio_PortType PortId,Dio_ChannelType ChannelId, Dio_PinDirectionType Direction );
std_ReturnType Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
std_ReturnType Dio_WriteChannel( Dio_PortType PortId,Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_LevelType Dio_ReadChannel( Dio_PortType PortId,Dio_ChannelType ChannelId );


#endif	/* DIO_H */

