/*
 * switch.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "../../LIB/Std_Types.h"

typedef enum
{
  SW_PULL_UP,SW_PULL_DOWN
}LOGIC_CONNECTION;

typedef uint8       Index_t;


typedef struct
{
  Index_t index;
  PORT_INDEX Switch_Port ;
  PIN_INDEX  Switch_Pin  ;
  LOGIC_CONNECTION Switch_connection;
}Switch_Config;

void switch_init(const Switch_Config* Led_ConfigPtr);
boolean switch_readSwitch(Index_t index);

#endif /* SWITCH_H_ */
