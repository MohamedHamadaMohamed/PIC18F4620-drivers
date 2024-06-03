/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#include <pic18f4620.h>

#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"
 
#include "EUSART_Private.h"
#include "EUSART.h"
#include "EUSART_Cfg.h"

static void EUSART_TX_Init(void);
static void EUSART_RC_Init(void);

static void EUSART_TX_DeInit(void);
static void EUSART_RC_DeInit(void);

static void EUSART_Calc_BaudRate(void);

void EUSART_Init(void)
{
    /* Disable EUSART Module */
    RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
    
    TRISCbits.RC7 = 1;                      /* RX : Input Configuration as needed */
    TRISCbits.RC6 = 1;                      /* TX : Input Configuration as needed */
    
      
    EUSART_Calc_BaudRate();
    EUSART_TX_Init();
    EUSART_RC_Init();
    

    /* enable EUSART Module */    
    RCSTAbits.SPEN = EUSART_MODULE_ENABLE;
    

}
void EUSART_DeInit(void)
{
EUSART_TX_DeInit();
EUSART_RC_DeInit();
RCSTAbits.SPEN = EUSART_MODULE_DISABLE;

}

void EUSART_SendByte(uint8 byte)
{
    while(!(TXSTAbits.TRMT));
    TXREG = byte;
   while(!(PIR1bits.TXIF));
}
void EUSART_SendString(uint8 *data, uint8 len)
{
    for(uint8 i =0 ; i<len;i++)
    {
        EUSART_SendByte(data[i]);
    }


}
void EUSART_RecieveByte(uint8 *byte)
{
    while(!(PIR1bits.RCIF));
    *byte =  RCREG ;
}
void EUSART_RecieveString(uint8 *data, uint8 len)
{
    for(uint8 i =0 ; i<len;i++)
    {
    
    EUSART_RecieveByte(&(data[i]));
    }
}





/**************************************************/
/** static function   **/

static void EUSART_TX_Init(void)
{

    TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_nBit_TX_TRANSMISSION;
    /* enable TX module */
    TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE;
}
static void EUSART_RC_Init(void)
{

RCSTAbits.RC9 = EUSART_ASYNCHRONOUS_nBit_RC_TRANSMISSION;
RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;
}
static void EUSART_TX_DeInit(void)
{
    TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_DISABLE;
}
static void EUSART_RC_DeInit(void)
{
RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_DISABLE;


}

static void EUSART_Calc_BaudRate(void)
{
float Baud_Rate_Temp = 0;

#if BAUDRATE_CONFIG_MODE == BAUDRATE_ASYN_8BIT_lOW_SPEED  
    
    TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
    TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
    BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
    Baud_Rate_Temp = ((_XTAL_FREQ / ((float)(BAUDRATE_CONFIG_VALUE))) / 64) - 1;
    
#elif BAUDRATE_CONFIG_MODE == BAUDRATE_ASYN_8BIT_HIGH_SPEED       
   TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
   TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
   BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
   Baud_Rate_Temp = ((_XTAL_FREQ / ((float)(BAUDRATE_CONFIG_VALUE))) / 16) - 1; 
#elif BAUDRATE_CONFIG_MODE == BAUDRATE_ASYN_16BIT_lOW_SPEED  
    TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
    TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
    BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
    Baud_Rate_Temp = ((_XTAL_FREQ / ((float)(BAUDRATE_CONFIG_VALUE))) / 16) - 1;
#elif BAUDRATE_CONFIG_MODE == BAUDRATE_ASYN_16BIT_HIGH_SPEED      
    TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
    TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
    BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
    Baud_Rate_Temp = ((_XTAL_FREQ / ((float)(BAUDRATE_CONFIG_VALUE))) / 4) - 1;
#elif BAUDRATE_CONFIG_MODE == BAUDRATE_SYN_8BIT 
    TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
    BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
    Baud_Rate_Temp = ((_XTAL_FREQ / ((float)(BAUDRATE_CONFIG_VALUE))) / 4) - 1;

#elif BAUDRATE_CONFIG_MODE == BAUDRATE_SYN_16BIT  
    TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
    BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
    Baud_Rate_Temp = ((_XTAL_FREQ / ((float)(BAUDRATE_CONFIG_VALUE))) / 4) - 1;
    
#endif    
    SPBRG = (uint8)((uint32)Baud_Rate_Temp);
    SPBRGH = (uint8)(((uint32)Baud_Rate_Temp) >> 8);
}