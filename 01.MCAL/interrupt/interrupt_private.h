/* 
 * File:   interrupt_private.h
 * Author: Eng : mohamed hamada
 * Comments:
 * Revision history:  v : 0.0.0 
 */
#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_

#include "../../LIB/BIT_MATHS.h"

/*REGISTER 10-1: INTCON: INTERRUPT CONTROL REGISTER*/


/* 
bit 7 GIE/GIEH: Global Interrupt Enable bit
When IPEN = 0:
1 = Enables all unmasked interrupts
0 = Disables all interrupts
When IPEN = 1:
1 = Enables all high-priority interrupts
0 = Disables all interrupts
 *  */
/* Global Interrupt disable*/
#define   GLOBAL_INTERRUPT_ENABLE() (INTCONbits.GIE = 1)
/*  Global Interrupt Enable */
#define   GLOBAL_INTERRUPT_DISABLE() (INTCONbits.GIE = 0)

/*
 bit 6 PEIE/GIEL: Peripheral Interrupt Enable bit
When IPEN = 0:
1 = Enables all unmasked peripheral interrupts
0 = Disables all peripheral interrupts
When IPEN = 1:
1 = Enables all low-priority peripheral interrupts
0 = Disables all low-priority peripheral interrupts
 */

/*bit 6 PEIE/GIEL: Peripheral Interrupt Enable bit*/
#define   PERIPHERAL_INTERRUPT_ENABLE() (INTCONbits.PEIE = 1)
/*bit 6 PEIE/GIEL: Peripheral Interrupt Enable bit*/
#define   PERIPHERAL_INTERRUPT_DISABLE() (INTCONbits.PEIE = 0)

/*
 bit 5 TMR0IE: TMR0 Overflow Interrupt Enable bit
1 = Enables the TMR0 overflow interrupt
0 = Disables the TMR0 overflow interrupt
 */

/* bit 5 TMR0IE: TMR0 Overflow Interrupt Enable bit  */
#define   TMR0_OVERFLOW_INTERRUPT_IS_ENABLE() (INTCONbits.TMR0IE)
/* bit 5 TMR0IE: TMR0 Overflow Interrupt Enable bit  */
#define   TMR0_OVERFLOW_INTERRUPT_ENABLE() (INTCONbits.TMR0IE = 1)
/* bit 5 TMR0IE: TMR0 Overflow Interrupt DISable bit  */
#define   TMR0_OVERFLOW_INTERRUPT_DISABLE() (INTCONbits.TMR0IE = 0)

/*
 bit 4 INT0IE: INT0 External Interrupt Enable bit
1 = Enables the INT0 external interrupt
0 = Disables the INT0 external interrupt
 */

/*bit 4 INT0IE: INT0 External Interrupt Enable bit*/
#define   INT0_EXTERNAL_INTERRUPT_IS_ENABLE() (INTCONbits.INT0IE)
/*bit 4 INT0IE: INT0 External Interrupt Enable bit*/
#define   INT0_EXTERNAL_INTERRUPT_ENABLE() (INTCONbits.INT0IE = 1)
/*bit 4 INT0IE: INT0 External Interrupt DISable bit*/
#define   INT0_EXTERNAL_INTERRUPT_DISABLE() (INTCONbits.INT0IE = 0)



/*
bit 3 RBIE: RB Port Change Interrupt Enable bit
1 = Enables the RB port change interrupt
0 = Disables the RB port change interrupt 
 */

/*bit 3 RBIE: RB Port Change Interrupt Enable bit*/
#define   RB_PORT_CHANGE_INTERRUPT_IS_ENABLE() (INTCONbits.RBIE)
/*bit 3 RBIE: RB Port Change Interrupt Enable bit*/
#define   RB_PORT_CHANGE_INTERRUPT_ENABLE() (INTCONbits.RBIE =1 )
/*bit 3 RBIE: RB Port Change Interrupt Enable bit*/
#define   RB_PORT_CHANGE_INTERRUPT_DISABLE() (INTCONbits.RBIE =0 )


/*
 bit 2 TMR0IF: TMR0 Overflow Interrupt Flag bit
1 = TMR0 register has overflowed (must be cleared in software)
0 = TMR0 register did not overflow
 */

/* bit 2 TMR0IF: TMR0 Overflow Interrupt Flag bit */
#define   TMR0_OVERFLOW_INTRRUPT_FLAG() (INTCONbits.TMR0IF)
/* bit 2 TMR0IF: TMR0 Overflow Interrupt Flag bit */
#define   SET_TMR0_OVERFLOW_INTRRUPT_FLAG() (INTCONbits.TMR0IF = 1)
/* bit 2 TMR0IF: TMR0 Overflow Interrupt Flag bit */
#define   CLEAR_TMR0_OVERFLOW_INTRRUPT_FLAG() (INTCONbits.TMR0IF = 0)


/*
 bit 1 INT0IF: INT0 External Interrupt Flag bit
1 = The INT0 external interrupt occurred (must be cleared in software)
0 = The INT0 external interrupt did not occur
 */
/*bit 1 INT0IF: INT0 External Interrupt Flag bit*/
#define   INT0_EXTERNAL_INTRRUPT_FLAG() (INTCONbits.INT0IF)
/*bit 1 INT0IF: SET INT0 External Interrupt Flag bit*/
#define   SET_INT0_EXTERNAL_INTRRUPT_FLAG() (INTCONbits.INT0IF =1)
/*bit 1 INT0IF:CLEAR INT0 External Interrupt Flag bit*/
#define   CLEAR_INT0_EXTERNAL_INTRRUPT_FLAG() (INTCONbits.INT0IF= 0)


/*
 bit 0 RBIF: RB Port Change Interrupt Flag bit(1)
1 = At least one of the RB7:RB4 pins changed state (must be cleared in software)
0 = None of the RB7:RB4 pins have changed state 
 */

/*bit 0 RBIF: RB Port Change Interrupt Flag bit(1) */
#define   RB_PORT_CHANGE_INTRRUPT_FLAG()  (INTCONbits.RBIF)
/*bit 1 INT0IF: SET INT0 External Interrupt Flag bit*/
#define   SET_RB_PORT_CHANGE_INTRRUPT_FLAG() (INTCONbits.RBIF = 1)
/*bit 1 INT0IF:CLEAR INT0 External Interrupt Flag bit*/
#define   CLEAR_RB_PORT_CHANGE_INTRRUPT_FLAG() (INTCONbits.RBIF = 0)




/*   REGISTER 10-2: INTCON2: INTERRUPT CONTROL REGISTER 2   */

/*
bit 7 RBPU: PORTB Pull-up Enable bit
1 = All PORTB pull-ups are disabled
0 = PORTB pull-ups are enabled by individual port latch values
 */
/*bit 7 RBPU: PORTB Pull-up Enable */
#define   PORTB_PULL_UP_IS_ENABLE()   (INTCON2bits.RBPU)
/*bit 7 RBPU: PORTB Pull-up Enable */
#define   PORTB_PULL_UP_ENABLE()  (INTCON2bits.RBPU = 1)
/*bit 7 RBPU: PORTB Pull-up disable */
#define   PORTB_PULL_UP_DISABLE() (INTCON2bits.RBPU = 0)

/*
 bit 6 INTEDG0: External Interrupt 0 Edge Select bit
1 = Interrupt on rising edge
0 = Interrupt on falling edge
 */
#define   EXT0_RISING_EDGE()   (INTCON2bits.INTEDG0 = 1)
#define   EXT0_FALLING_EDGE()  (INTCON2bits.INTEDG0 = 0)


/*
 bit 5 INTEDG1: External Interrupt 1 Edge Select bit
1 = Interrupt on rising edge
0 = Interrupt on falling edge
 */
#define   EXT1_RISING_EDGE() (INTCON2bits.INTEDG1 =1)
#define   EXT1_FALLING_EDGE() (INTCON2bits.INTEDG1 =0)

/*
 bit 4 INTEDG2: External Interrupt 2 Edge Select bit
1 = Interrupt on rising edge
0 = Interrupt on falling edge
 */
#define   EXT2_RISING_EDGE()  (INTCON2bits.INTEDG2 = 1)
#define   EXT2_FALLING_EDGE() (INTCON2bits.INTEDG2 = 0)

/*
 bit 2 TMR0IP: TMR0 Overflow Interrupt Priority bit
1 = High priority
0 = Low priority
 */
#define   TMR0_OVERFLOW_INTERRUPT_HIGH_PRIORITY() (INTCON2bits.INTEDG2 =1)
#define   TMR0_OVERFLOW_INTERRUPT_LOW_PRIORITY() (INTCON2bits.INTEDG2 =0)

/*
 bit 0 RBIP: RB Port Change Interrupt Priority bit
1 = High priority
0 = Low priority
 */
#define   RB_PORT_CHANGE_INTERRUPT_HIGH_PRIORITY() (INTCON2bits.RBIP =1)
#define   RB_PORT_CHANGE_INTERRUPT_LOW_PRIORITY()  (INTCON2bits.RBIP =0)

/*
 REGISTER 10-3: INTCON3: INTERRUPT CONTROL REGISTER 3
 */

/*
 bit 7 INT2IP: INT2 External Interrupt Priority bit
1 = High priority
0 = Low priority
 */
#define   INT2_EXTERNAL_INTERRUPT_HIGH_PRIORITY() (INTCON3bits.INT2IP = 1)
#define   INT2_EXTERNAL_INTERRUPT_LOW_PRIORITY() (INTCON3bits.INT2IP = 0)

/*
 bit 6 INT1IP: INT1 External Interrupt Priority bit
1 = High priority
0 = Low priority
 */
#define   INT1_EXTERNAL_INTERRUPT_HIGH_PRIORITY() (INTCON3bits.INT1IP =1)
#define   INT1_EXTERNAL_INTERRUPT_LOW_PRIORITY() (INTCON3bits.INT1IP =0)

/*
 bit 4 INT2IE: INT2 External Interrupt Enable bit
1 = Enables the INT2 external interrupt
0 = Disables the INT2 external interrupt
 
 */
#define   INT2_EXTERNAL_INTERRUPT_IS_ENABLE()       (INTCON3bits.INT2IE)
#define   INT2_EXTERNAL_INTERRUPT_ENABLE()          (INTCON3bits.INT2IE = 1)
#define   INT2_EXTERNAL_INTERRUPT_DISABLE()         (INTCON3bits.INT2IE = 0)

/*
 bit 3 INT1IE: INT1 External Interrupt Enable bit
1 = Enables the INT1 external interrupt
0 = Disables the INT1 external interrupt
 */
#define   INT1_EXTERNAL_INTERRUPT_IS_ENABLE()       (INTCON3bits.INT1IE)
#define   INT1_EXTERNAL_INTERRUPT_ENABLE()          (INTCON3bits.INT1IE = 1)
#define   INT1_EXTERNAL_INTERRUPT_DISABLE()         (INTCON3bits.INT1IE = 0)

/*
 bit 1 INT2IF: INT2 External Interrupt Flag bit
1 = The INT2 external interrupt occurred (must be cleared in software)
0 = The INT2 external interrupt did not occur
 */

/*1 = The INT2 external interrupt occurred (must be cleared in software) */
#define   INT2_EXTERNAL_INTRRUPT_FLAG() (INTCON3bits.INT2IF)
/*1 = SET The INT2 external interrupt occurred (must be cleared in software) */
#define   SET_INT2_EXTERNAL_INTRRUPT_FLAG() (INTCON3bits.INT2IF = 1)
/*1 =CLEAR The INT2 external interrupt occurred (must be cleared in software) */
#define   CLEAR_INT2_EXTERNAL_INTRRUPT_FLAG() (INTCON3bits.INT2IF = 0)


/*
 bit 0 INT1IF: INT1 External Interrupt Flag bit
1 = The INT1 external interrupt occurred (must be cleared in software)
0 = The INT1 external interrupt did not occur
 */
/*1 = The INT2 external interrupt occurred (must be cleared in software) */
#define   INT1_EXTERNAL_INTRRUPT_FLAG()  (INTCON3bits,INT1IF)
/*1 = SET The INT2 external interrupt occurred (must be cleared in software) */
#define   SET_INT1_EXTERNAL_INTRRUPT_FLAG() (INTCON3bits,INT1IF=1)
/*1 =CLEAR The INT2 external interrupt occurred (must be cleared in software) */
#define   CLEAR_INT1_EXTERNAL_INTRRUPT_FLAG() (INTCON3bits,INT1IF=0)


/* REGISTER 10-4: PIR1: PERIPHERAL INTERRUPT REQUEST (FLAG) REGISTER 1   */

/*
 * bit 7 PSPIF: Parallel Slave Port Read/Write Interrupt Flag bit(1)
1 = A read or a write operation has taken place (must be cleared in software)
0 = No read or write has occurred
*/
/* Parallel Slave Port Read/Write Interrupt Flag bit(1) */
#define   PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_FLAG() (PIR1bits.PSPIF)
/* 1 = A read or a write operation has taken place (must be cleared in software) */
#define   SET_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_FLAG() (PIR1bits.PSPIF = 1)
/*0 = No read or write has occurred */
#define   CLEAR_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_FLAG() (PIR1bits.PSPIF = 0)


/*
 bit 6 ADIF: A/D Converter Interrupt Flag bit
1 = An A/D conversion completed (must be cleared in software)
0 = The A/D conversion is not complete
 */
#define   ADC_INTERRUPT_FLAG()           (PIR1bits.ADIF)
#define   SET_ADC_INTERRUPT_FLAG()       (PIR1bits.ADIF = 1)
#define   CLEAR_ADC_INTERRUPT_FLAG()     (PIR1bits.ADIF = 0)

/*
 bit 5 RCIF: EUSART Receive Interrupt Flag bit
1 = The EUSART receive buffer, RCREG, is full (cleared when RCREG is read)
0 = The EUSART receive buffer is empty
 */
#define   EUSART_RECIEVE_INTERRYPT_FLAG()            (PIR1bits.RCIF)
#define   SET_EUSART_RECIEVE_INTERRYPT_FLAG()        (PIR1bits.RCIF = 1)
#define   CLEAR_EUSART_RECIEVE_INTERRYPT_FLAG()      (PIR1bits.RCIF = 0)

/*
 bit 4 TXIF: EUSART Transmit Interrupt Flag bit
1 = The EUSART transmit buffer, TXREG, is empty (cleared when TXREG is written)
0 = The EUSART transmit buffer is full
 */
#define   EUSART_TRANSMIT_INTERRYPT_FLAG()            (PIR1bits.TXIF)
#define   SET_EUSART_TRANSMIT_INTERRYPT_FLAG()        (PIR1bits.TXIF = 1)
#define   CLEAR_EUSART_TRANSMIT_INTERRYPT_FLAG()      (PIR1bits.TXIF = 0)

/*
 bit 3 SSPIF: Master Synchronous Serial Port Interrupt Flag bit
1 = The transmission/reception is complete (must be cleared in software)
0 = Waiting to transmit/receive
 */
#define   MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRYPT_FLAG()            (PIR1bits.SSPIF)
#define   SET_MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRYPT_FLAG()        (PIR1bits.SSPIF = 1)
#define   CLEAR_MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRYPT_FLAG()      (PIR1bits.SSPIF = 0) 

/*
 bit 2 CCP1IF: CCP1 Interrupt Flag bit
Capture mode:
1 = A TMR1 register capture occurred (must be cleared in software)
0 = No TMR1 register capture occurred
 */
#define   CCP1_INTERRUPT_FLAG()            (PIR1bits.CCP1IF)
#define   SET_CCP1_INTERRUPT_FLAG()        (PIR1bits.CCP1IF = 1)
#define   CLEAR_CCP1_INTERRUPT_FLAG()     (PIR1bits.CCP1IF = 0)

/*
 bit 1 TMR2IF: TMR2 to PR2 Match Interrupt Flag bit
1 = TMR2 to PR2 match occurred (must be cleared in software)
0 = No TMR2 to PR2 match occurred
 * 
 */
#define   TMR2_TO_PR2_MATCH_INTERRUPT_FLAG()            (PIR1bits.TMR2IF)
#define   SET_TMR2_TO_PR2_MATCH_INTERRUPT_FLAG()        (PIR1bits.TMR2IF = 1)
#define   CLEAR_TMR2_TO_PR2_MATCH_INTERRUPT_FLAG()      (PIR1bits.TMR2IF = 0) 

/*
 bit 0 TMR1IF: TMR1 Overflow Interrupt Flag bit
1 = TMR1 register overflowed (must
 
 */
#define   TMR1_OVERFLOW_INTERRUPT_FLAG()            (PIR1bits.TMR1IF)
#define   SET_TMR1_OVERFLOW_INTERRUPT_FLAG()        (PIR1bits.TMR1IF = 1)
#define   CLEAR_TMR1_OVERFLOW_INTERRUPT_FLAG()      (PIR1bits.TMR1IF = 0)

/*REGISTER 10-5: PIR2: PERIPHERAL INTERRUPT REQUEST (FLAG) REGISTER 2*/


/*
 bit 7 OSCFIF: Oscillator Fail Interrupt Flag bit
1 = Device oscillator failed, clock input has changed to INTOSC (must be cleared in software)
0 = Device clock operating
 */
#define   OSCILLATOR_FAIL_INTERRUPT_FLAG()            (PIR2bits.OSCFIF)
#define   DEVICE_OSCILLATOR_FAILED_CLOCK_INPUT_HAS_CHANGED_TO_INTOSC()        (PIR2bits.OSCFIF = 1)
#define   DEVICE_CLOCK_OPERATING()      (PIR2bits.OSCFIF = 0)

/*
 bit 6 CMIF: Comparator Interrupt Flag bit
1 = Comparator input has changed (must be cleared in software)
0 = Comparator input has not changed
 */
#define   COMPARATOR_INTERRUPT_FLAG()            (PIR2bits.CMIF)
#define   SET_COMPARATOR_INTERRUPT_FLAG()        (PIR2bits.CMIF = 1)
#define   CLEAR_COMPARATOR_INTERRUPT_FLAG()      (PIR2bits.CMIF = 0)

/*
 bit 4 EEIF: Data EEPROM/Flash Write Operation Interrupt Flag bit
1 = The write operation is complete (must be cleared in software)
0 = The write operation is not complete or has not been started
 */
#define   DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT_FLAG()              (PIR2bits.CMIF)
#define   SET_DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT_FLAG()          (PIR2bits.CMIF = 1)
#define   CLEAR_DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT_FLAG()        (PIR2bits.CMIF = 0)

/*
 bit 3 BCLIF: Bus Collision Interrupt Flag bit
1 = A bus collision occurred (must be cleared in software)
0 = No bus collision occurred
 */
#define   BUS_COLLISION_INTERRUPT_FLAG()              (PIR2bits.BCLIF)
#define   SET_BUS_COLLISION_INTERRUPT_FLAG()          (PIR2bits.BCLIF = 1 )
#define   CLEAR_BUS_COLLISION_INTERRUPT_FLAG()        (PIR2bits.BCLIF = 0 )

/*
 bit 2 HLVDIF: High/Low-Voltage Detect Interrupt Flag bit
1 = A high/low-voltage condition occurred (direction determined by VDIRMAG bit, HLVDCON<7>)
0 = A high/low-voltage condition has not occurred 
 */
#define   HIGH_LOW_VOLTAGE_DETECT_INTERRUPT_FLAG()              (PIR2bits.BCLIF)
#define   SET_HIGH_LOW_VOLTAGE_DETECT_INTERRUPT_FLAG()          (PIR2bits.BCLIF = 1)
#define   CLEAR_HIGH_LOW_VOLTAGE_DETECT_INTERRUPT_FLAG()        (PIR2bits.BCLIF = 0 )

/*
 bit 1 TMR3IF: TMR3 Overflow Interrupt Flag bit
1 = TMR3 register overflowed (must be cleared in software)
0 = TMR3 register did not overflow
 */
#define   TMR3_OVERFLOW_INTERRUPT_FLAG()              (PIR2bits.TMR3IF)
#define   SET_TMR3_OVERFLOW_INTERRUPT_FLAG()          (PIR2bits.TMR3IF = 1)
#define   CLEAR_TMR3_OVERFLOW_INTERRUPT_FLAG()        (PIR2bits.TMR3IF = 0)

/*
 bit 0 CCP2IF: CCP2 Interrupt Flag bit
Capture mode:
1 = A TMR1 register capture occurred (must be cleared in software)
0 = No TMR1 register capture occurred
Compare mode:
1 = A TMR1 register compare match occurred (must be cleared in software)
0 = No TMR1 register compare match occurred
 */
#define   CCP2_INTERRUPT_FLAG()              (PIR2bits.CCP2IF)
#define   SET_CCP2_INTERRUPT_FLAG()          (PIR2bits.CCP2IF = 1)
#define   CLEAR_CCP2_INTERRUPT_FLAG()        (PIR2bits.CCP2IF = 0)


/*  REGISTER 10-6: PIE1: PERIPHERAL INTERRUPT ENABLE REGISTER 1   */

/*
 bit 7 PSPIE: Parallel Slave Port Read/Write Interrupt Enable bit(1)
1 = Enables the PSP read/write interrupt
0 = Disables the PSP read/write interrupt
 */
#define PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_IS_ENABLE()           (PIE1bits.PSPIE)
#define ENABLE_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT()              (PIE1bits.PSPIE = 1)
#define DISABLE_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT()             (PIE1bits.PSPIE = 0)


/*
 bit 6 ADIE: A/D Converter Interrupt Enable bit
1 = Enables the A/D interrupt
0 = Disables the A/D interrupt
 */

#define ENABLE_ADC_IS_INTERRUPT()           (PIE1bits.ADIE)
#define ENABLE_ADC_INTERRUPT()              (PIE1bits.ADIE = 1)
#define DISABLE_ADC_INTERRUPT()             (PIE1bits.ADIE = 0)

/*
 bit 5 RCIE: EUSART Receive Interrupt Enable bit
1 = Enables the EUSART receive interrupt
0 = Disables the EUSART receive interrupt
 */
#define THE_EUSART_RECEIVE_INTERRUPTIS_ENABLE()           (PIE1bits.RCIE)
#define ENABLE_THE_EUSART_RECEIVE_INTERRUPT()           (PIE1bits.RCIE = 1)
#define DISABLE_THE_EUSART_RECEIVE_INTERRUPT()          (PIE1bits.RCIE = 0)

/*
 bit 4 TXIE: EUSART Transmit Interrupt Enable bit
1 = Enables the EUSART transmit interrupt
0 = Disables the EUSART transmit interrupt
 
 */
#define THE_EUSART_TRANSMIT_INTERRUPT_IS_ENABLE()           (PIE1bits.TXIE)
#define ENABLE_THE_EUSART_TRANSMIT_INTERRUPT()           (PIE1bits.TXIE = 1)
#define DISABLE_THE_EUSART_TRANSMIT_INTERRUPT()          (PIE1bits.TXIE = 0)

/*
bit 3 SSPIE: Master Synchronous Serial Port Interrupt Enable bit
1 = Enables the MSSP interrupt
0 = Disables the MSSP interrupt
*/
#define THE_MSSP_INTERRUPT_IS_ENABLE()    (PIE1bits.SSPIE)
#define ENABLE_THE_MSSP_INTERRUPT()    (PIE1bits.SSPIE= 1)
#define DISABLE_THE_MSSP_INTERRUPT()   (PIE1bits.SSPIE= 0)

/* bit 2 CCP1IE: CCP1 Interrupt Enable bit
1 = Enables the CCP1 interrupt
0 = Disables the CCP1 interrupt
*/
#define THE_CCP1_INTERRUPT_IS_ENABLE()    (PIE1bits.CCP1IE)
#define ENABLE_THE_CCP1_INTERRUPT()       (PIE1bits.CCP1IE = 1)
#define DISABLE_THE_CCP1_INTERRUPT()      (PIE1bits.CCP1IE = 0)


/* bit 1 TMR2IE: TMR2 to PR2 Match Interrupt Enable bit
1 = Enables the TMR2 to PR2 match interrupt
0 = Disables the TMR2 to PR2 match interrupt
*/
#define THE_TMR2_TO_PR2_MATCH_INTERRUPT_IS_ENABLE()    (PIE1bits.TMR2IE)

#define ENABLE_THE_TMR2_TO_PR2_MATCH_INTERRUPT()    (PIE1bits.TMR2IE= 1)
#define DISABLE_THE_TMR2_TO_PR2_MATCH_INTERRUPT()   (PIE1bits.TMR2IE = 0)


 /* bit 0 TMR1IE: TMR1 Overflow Interrupt Enable bit
1 = Enables the TMR1 overflow interrupt  
0 = Disables the TMR1 overflow interrupt
*/
#define TMR1_OVERFLOW_INTERRUPT_IS_ENABLE()    (PIE1bits.TMR1IE)
#define ENABLE_TMR1_OVERFLOW_INTERRUPT()    (PIE1bits.TMR1IE =1)
#define DISABLE_TMR1_OVERFLOW_INTERRUPT()  (PIE1bits.TMR1IE =0)


/* REGISTER 10-7: PIE2: PERIPHERAL INTERRUPT ENABLE REGISTER 2 */

/*
 bit 7 OSCFIE: Oscillator Fail Interrupt Enable bit
1 = Enabled
0 = Disabled
*/
#define OSCILLTOR_FAIL_INTERRUPT_IS_ENABLE()    (PIE2bits.OSCFIE)
#define ENABLE_OSCILLTOR_FAIL_INTERRUPT()    (PIE2bits.OSCFIE = 1)
#define DISABLE_OSCILLTOR_FAIL_INTERRUPT()   (PIE2bits.OSCFIE = 0)
/*
bit 6 CMIE: Comparator Interrupt Enable bit
1 = Enabled
0 = Disabled
*/
#define COMPARATOR_INTERRUPT_IS_ENABLE()    (PIE2bits.CMIE)
#define ENABLE_COMPARATOR_INTERRUPT()    (PIE2bits.CMIE = 1)
#define DISABLE_COMPARATOR_INTERRUPT()   (PIE2bits.CMIE = 0)
  
 /* 
bit 4 EEIE: Data EEPROM/Flash Write Operation Interrupt Enable bit
1 = Enabled
0 = Disabled
*/
#define DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT_IS_ENABLE()    (PIE2bits.EEIE)
#define ENABLE_DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT()    (PIE2bits.EEIE = 1)
#define DISABLE_DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT()   (PIE2bits.EEIE = 0)
  
/* bit 3 BCLIE: Bus Collision Interrupt Enable bit
1 = Enabled
0 = Disabled
*/
#define BUS_COLLISION_INTERRUPT_IS_ENABLE()           (PIE2bits.BCLIE)
#define ENABLE_BUS_COLLISION_INTERRUPT()            (PIE2bits.BCLIE = 1)
#define DISABLE_BUS_COLLISION_INTERRUPT()           (PIE2bits.BCLIE =0)

/*
bit 2 HLVDIE: High/Low-Voltage Detect Interrupt Enable bit
1 = Enabled
0 = Disabled
*/
#define HIGH_LOW_VOLTAGE_DETECT_INTERRUPT_IS_ENABLE()     (PIE2bits.HLVDIE)
#define ENABLE_HIGH_LOW_VOLTAGE_DETECT_INTERRUPT()        (PIE2bits.HLVDIE = 1)
#define DISABLE_HIGH_LOW_VOLTAGE_DETECT_INTERRUPT()       (PIE2bits.HLVDIE = 0)

 /*
bit 1 TMR3IE: TMR3 Overflow Interrupt Enable bit
1 = Enabled
0 = Disabled 
*/
#define TMR3_OVERFLOW_INTERRUPT_IS_ENABLE()     (PIE2bits.TMR3IE)
#define ENABLE_TMR3_OVERFLOW_INTERRUPT()        (PIE2bits.TMR3IE = 1)
#define DISABLE_TMR3_OVERFLOW_INTERRUPT()       (PIE2bits.TMR3IE = 0)

/*
 * bit 0 CCP2IE: CCP2 Interrupt Enable bit
1 = Enabled
0 = Disabled
*/
#define CCP2_INTERRUPT_IS_ENABLE()     (PIE2bits.CCP2IE)
#define ENABLE_CCP2_INTERRUPT()     (PIE2bits.CCP2IE = 1)
#define DISABLE_CCP2_INTERRUPT()     (PIE2bits.CCP2IE = 0)


/* REGISTER 10-8: IPR1: PERIPHERAL INTERRUPT PRIORITY REGISTER 1 */

/*
bit 7 PSPIP: Parallel Slave Port Read/Write Interrupt Priority bit(1)
1 = High priority
0 = Low priority
*/

#define SET_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.PSPIP=1)
#define SET_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_LOW_PRIORITY()    (IPR1bits.PSPIP = 0)

/*
bit 6 ADIP: A/D Converter Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_ADC_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.PSPIP =1)
#define SET_ADC_INTERRUPT_LOW_PRIORITY()     (IPR1bits.PSPIP = 0)

/*
bit 5 RCIP: EUSART Receive Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_EUSART_RECEIVE_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.RCIP =1)
#define SET_EUSART_RECEIEVE_INTERRUPT_LOW_PRIORITY()    (IPR1bits.RCIP = 0)
        
/*
bit 4 TXIP: EUSART Transmit Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_EUSART_TRANSMIT_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.TXIP=1)
#define SET_EUSART_TRANSMIT_INTERRUPT_LOW_PRIORITY()     (IPR1bits.TXIP =0)
 
/*
bit 3 SSPIP: Master Synchronous Serial Port Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_MSTER_SYNCHRONOUS_PORT_INTERRUPT_HIGH_PRIORITY()   (IPR1bits.SSPIP = 1)
#define SET_MSTER_SYNCHRONOUS_PORT_INTERRUPT_LOW_PRIORITY()    (IPR1bits.SSPIP = 0)
 
/*
bit 2 CCP1IP: CCP1 Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_CCP1_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.CCP1IP = 1)
#define SET_CCP1_INTERRUPT_LOW_PRIORITY()     (IPR1bits.CCP1IP = 0)
/*
bit 1 TMR2IP: TMR2 to PR2 Match Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_TMR2_TO_PR2_MATCH_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.TMR2IP = 1)
#define SET_TMR2_TO_PR2_MATCH_INTERRUPT_LOW_PRIORITY()    (IPR1bits.TMR2IP = 0)

/*        
bit 0 TMR1IP: TMR1 Overflow Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_TMR1_OVERFLOW_INTERRUPT_HIGH_PRIORITY()    (IPR1bits.TMR1IP = 1)
#define SET_TMR1_OVERFLOW_INTERRUPT_LOW_PRIORITY()     (IPR1bits.TMR1IP =0)

/*   REGISTER 10-9: IPR2: PERIPHERAL INTERRUPT PRIORITY REGISTER 2   */

/*
bit 7 OSCFIP: Oscillator Fail Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_OSCILLATOR_FAIL_INTERRUPT_HIGH_PRIORITY()    (IPR2bits.OSCFIP =1)
#define SET_OSCILLATOR_FAIL_INTERRUPT_LOW_PRIORITY()    (IPR2bits.OSCFIP = 0)
/* bit 6 CMIP: Comparator Interrupt Priority bit
1 = High priority
0 = Low priority
 */
#define SET_COMPARATOR_INTERRUPT_HIGH_PRIORITY()        (IPR2bits.CMIP =1)
#define SET_COMPARATOR_INTERRUPT_LOW_PRIORITY()         (IPR2bits.CMIP =0) 
/*
bit 4 EEIP: Data EEPROM/Flash Write Operation Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT_HIGH_PRIORITY()        (IPR2bits.EEIP =1)
#define SET_DATA_EEPROM_FLASH_WRITE_OPERATION_INTERRUPT_LOW_PRIORITY()         (IPR2bits.EEIP = 0) 

/*
bit 3 BCLIP: Bus Collision Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_BUS_COLLISION_INTERRUPT_HIGH_PRIORITY()        (IPR2bits.BCLIP = 1)
#define SET_BUS_COLLISION_INTERRUPT_LOW_PRIORITY()         (IPR2bits.BCLIP = 0) 

/*
 bit 2 HLVDIP: High/Low-Voltage Detect Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_HIGH_LOW_VOLTAGE_DETECT_INTERRUPT_HIGH_PRIORITY()        (IPR2bits.HLVDIP = 1)
#define SET_HIGH_LOW_VOLTAGE_DETECT_INTERRUPT_LOW_PRIORITY()         (IPR2bits.HLVDIP = 0) 

/*
bit 1 TMR3IP: TMR3 Overflow Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_TMR3_OVERFLOW_INTERRUPT_HIGH_PRIORITY()        (IPR2bits.TMR3IP = 1)
#define SET_TMR3_OVERFLOW_INTERRUPT_LOW_PRIORITY()         (IPR2bits.TMR3IP = 0)

/*
bit 0 CCP2IP: CCP2 Interrupt Priority bit
1 = High priority
0 = Low priority
*/
#define SET_CCP2_INTERRUPT_HIGH_PRIORITY()        (IPR2bits.CCP2IP =1)
#define SET_CCP2_INTERRUPT_LOW_PRIORITY()         (IPR2bits.CCP2IP =0)

/*  REGISTER 10-10: RCON: RESET CONTROL REGISTER  */

/*
 bit 7 IPEN: Interrupt Priority Enable bit
1 = Enable priority levels on interrupts
0 = Disable priority levels on interrupts (PIC16CXXX Compatibility mode)
 */
#define ENABLE_INTERRUPT_PRIORITY()        (RCONbits.IPEN =1)
#define DISABLE_INTERRUPT_PRIORITY()       (RCONbits.IPEN =0)



#endif