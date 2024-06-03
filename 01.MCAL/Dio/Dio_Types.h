/* 
 * File:   Dio_Types.h
 * Author: Moham
 *
 * Created on November 22, 2022, 11:58 AM
 */

#ifndef DIO_TYPES_H
#define	DIO_TYPES_H

#include "../../LIB/Std_Types.h"

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;

typedef boolean Dio_LevelType;
typedef uint8 Dio_PortLevelType;

typedef enum{ OUTPUT,INPUT }Dio_PinDirectionType;

typedef enum{ OFF,PULL_DOWN , PULL_UP }Dio_InternalResistor;

typedef enum{PORTA_INDEX=0,PORTB_INDEX=1,PORTC_INDEX=2,PORTD_INDEX =3,PORTE_INDEX =4}PORT_INDEX;
typedef enum{
	    PIN0=0,
		PIN1=1,
		PIN2=2,
		PIN3=3,
		PIN4=4,
		PIN5=5,
		PIN6=6,
		PIN7=7
}PIN_INDEX;


typedef struct {
	Dio_PortType Port_Index ;
	Dio_ChannelType Channel_Index ;
	Dio_PinDirectionType direction ;
	Dio_InternalResistor resistor ;
	boolean initial_value ;
}Dio_ConfigType;

typedef struct
{
    Dio_PortType Port_Index ;
	Dio_ChannelType Channel_Index ;

}Pin_Config_t;

#endif	/* DIO_TYPES_H */

