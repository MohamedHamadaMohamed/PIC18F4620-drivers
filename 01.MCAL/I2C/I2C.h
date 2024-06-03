/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C_H_
#define	I2C_H_

#include "I2C_Private.h"


std_ReturnType MSSP_I2C_Init(const I2C_ConfigType *i2c_configPtr);
std_ReturnType MSSP_I2C_DeInit(const I2C_ConfigType *i2c_configPtr);

std_ReturnType MSSP_I2C_SendStart(const I2C_ConfigType *i2c_configPtr);
std_ReturnType MSSP_I2C_SendRepeatedStart(const I2C_ConfigType *i2c_configPtr);

std_ReturnType MSSP_I2C_SendStop(const I2C_ConfigType *i2c_configPtr);

std_ReturnType MSSP_I2C_SendByte(const I2C_ConfigType *i2c_configPtr ,uint8 byte,uint8 *ack);
std_ReturnType MSSP_I2C_RecieveByte(const I2C_ConfigType *i2c_configPtr,uint8 ack,uint8* byte);



#endif	/* XC_HEADER_TEMPLATE_H */

