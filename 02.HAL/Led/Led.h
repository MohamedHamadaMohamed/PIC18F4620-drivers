/*
 * Led.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#ifndef LED_H_
#define LED_H_

typedef enum
{
  NEGATIVE_LOGIC                 
 ,POSITIVE_LOGIC  
}LOGIC_TYPE	;

typedef uint8       Index;

typedef struct
{
  Index index;
  PORT_INDEX Led_Port ;
  PIN_INDEX  Led_Pin  ;
  LOGIC_TYPE Logic_Type;
}Led_Config;

void LED_init(const Led_Config* Led_ConfigPtr);
void LED_On(Index index);
void LED_Off(Index index);
void LED_Toggle(Index index);

#endif /* _LED_H_ */
