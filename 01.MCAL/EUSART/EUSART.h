/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#ifndef EUSART_H_
#define EUSART_H_

void EUSART_Init(void);
void EUSART_DeInit(void);
void EUSART_SendByte(uint8 byte);
void EUSART_SendString(uint8 *data, uint8 len);
void EUSART_RecieveByte(uint8 *byte);
void EUSART_RecieveString(uint8 *data, uint8 len);
#endif