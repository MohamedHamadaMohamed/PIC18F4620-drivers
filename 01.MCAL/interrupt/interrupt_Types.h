#ifndef INTERRUPT_TYPES_H_
#define INTERRUPT_TYPES_H_
 

typedef enum
{
    TMR0_OVERFLOW_INTERRUPT,                              /* timer 0 overflow interrupt */
    TMR1_OVERFLOW_INTERRUPT,                              /* TMR1 Overflow Interrupt */
    TMR2_OVERFLOW_INTERRUPT,                              /*TMR3 Overflow Interrupt*/
    TMR3_OVERFLOW_INTERRUPT,                              /*TMR3 Overflow Interrupt*/
    INT0_EXTERNAL_INTERRUPT,                              /* external interrupt 0       */
    INT1_EXTERNAL_INTERRUPT,                              /* external interrupt 1       */
    INT2_EXTERNAL_INTERRUPT,                              /* external interrupt 2       */
    RB_PORT_CHANGE_INTERRUPT,                             /* RB Port Change Interrupt */
    PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT,             /* Parallel Slave Port Read/Write Interrupt */
    ADC_INTERRUPT,                                        /* A/D Converter Interrupt */      
    EUSART_RECEIEVE_INTERRUPT ,                           /* EUSART Receive Interrupt  */
    EUSART_TRANSMIT_INTERRUPT,                            /* EUSART Transmit Interrupt*/
    MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRUPT,             /*Master Synchronous Serial Port Interrupt*/
    CCP1_INTERRUPT,                                       /* CCP1 interrupt*/
    TMR2_TO_PR2_MATCH_INTERRUPT,                          /*TMR2 to PR2 Match Interrupt*/
    OSCILLATOR_FAIL_INTERRUPT,                            /*  Oscillator Fail Interrupt  */
    COMPARATOR_INTERRUPT,                                 /*Comparator Interrupt*/
    DATA_EEPROM_FLASH_WRITE_OPERATIN_INTERRUPT,           /*Data EEPROM/Flash Write Operation Interrupt*/
    BUS_COLLISION_INTERRUPT,                              /* Bus Collision Interrupt */
    HIGH_LOW_VOLTAGE_DETECT_INTERRUPT,                    /*  High/Low-Voltage Detect Interrupt*/
    CCP2_INTERRUPT,                                       /* CCP2 Interrupt */
            
}Interrupt_Type;

typedef enum
{
    INTERRUPT_ON_FALLING_EDGE = 0,
    INTERRUPT_ON_RISINGING_EDGE = 1,
}Interrupt_Edge;

typedef enum
{
    LOW_PRIORITY = 0,
    HIGH_PRIORITY = 1,
}Interrupt_Priority;


typedef struct
{
Interrupt_Type type;
Interrupt_Edge edge;
Interrupt_Priority priority;
void (*CallBack)(void);

}interrupt_configType;


#define INTERRUPT_PRIORITY_ENABLE        1U
#define INTERRUPT_PRIORITY_DISABLE       0U

#define INTERRUPT_OCCUR                      1U
#define INTERRUPT_NOT_OCCUR                  0U

#define INTERRUPT_ENABLED                    1U
#define INTERRUPT_DISABLED                   0U

#endif