/* 
 * File:   Relay.h
 * Author: Moham
 *
 * Created on 06 ????, 2023, 11:55 ?
 */

#ifndef RELAY_H
#define	RELAY_H

#include "../../LIB/Std_Types.h"


#define RELAY_OFF          0
#define RELAY_ON           1

typedef boolean     Relay_State;

typedef struct
{
Dio_PortType PortId;
Dio_ChannelType ChannelId;
Relay_State state;     
}Relay_Config;

std_ReturnType Relay_init(const Relay_Config * RelayConfigPtr );
std_ReturnType Relay_On(const Relay_Config * RelayConfigPtr   );
std_ReturnType Relay_Off(const Relay_Config * RelayConfigPtr  );


#endif	/* RELAY_H */

