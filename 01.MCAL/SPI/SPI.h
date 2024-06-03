/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#ifndef SPI_H_
#define SPI_H_

void SPI_init(void);
void SPI_SendByte(uint8 byte);
uint8 SPI_ReciveByte(void);
void SPI_SendString(uint8 *data , uint8 len);
void SPI_ReciveString(uint8 *data , uint8 len);

#endif