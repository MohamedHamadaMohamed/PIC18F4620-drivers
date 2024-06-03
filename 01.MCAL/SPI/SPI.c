
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "SPI_Private.h"
#include "SPI.h"
#include "SPI_Cfg.h"



void SPI_init(void)
{
/* Disables serial port and configures these pins as I/O port pins*/    
SSPCON1bits.SSPEN = 0;


/*
 SMP: Sample bit
SPI Master mode:
1 = Input data sampled at end of data output time
0 = Input data sampled at middle of data output time
SPI Slave mode:
SMP must be cleared when SPI is used in Slave mode
 */

SSPSTATbits.SMP = SPI_SAMPLE_SELECT;

SSPCON1bits.SSPM = SPI_MASTER_MODE_SELECT;



/*
 CKP: Clock Polarity Select bit
1 = Idle state for clock is a high level
0 = Idle state for clock is a low level
 
 */
SSPCON1bits.CKP = SPI_CLOCK_POLARITY_SELECT;



SSPCON1bits.SSPM = MASTER_SYNCHRONOUS_SERIAL_PORT_MODE_SELECT;


/*Enables serial port and configures SCK, SDO, SDI and SS as serial port pins */
SSPCON1bits.SSPEN = 1;
 }
void SPI_SendByte(uint8 byte)
{
    SSPBUF =byte;
    while(0 == PIR1bits.SSPIF );
    PIR1bits.SSPIF  = 0;

}
uint8 SPI_ReciveByte(void)
{
    uint8 byte;
    while(0 == SSPSTATbits.BF );
    byte = SSPBUF ;
    PIR1bits.SSPIF  = 0;
}
void SPI_SendString(uint8 *data , uint8 len)
{


}
void SPI_ReciveString(uint8 *data , uint8 len)
{


}