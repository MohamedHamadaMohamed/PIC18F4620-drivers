#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "interrupt_Types.h"
#include "interrupt_cfg.h"
#include "interrupt.h"
#include "interrupt_private.h"

void (*TMR_Overflow_callBack[4])(void)={NULL};
void (*EXTI_CallBack[4])(void)={NULL};
void (*RB_port_change_interrutpt_CallBack)(void)={NULL};
void(*parallel_slave_port_RW_interrupt_CallBack)(void)={NULL}; 
void(*ADC_interrupt_CallBack)(void)={NULL};                    
void(*EUSART_receieve_interrupt_CallBack)(void)={NULL};                
void(*EUSART_transmit_interrupt_CallBack)(void)={NULL};        
void(*master_synchronous_serial_port_interrupt_CallBack)(void)={NULL}; 

void(*ccp1_interrupt_CallBack)(void)={NULL};                          
void(*TMR2_to_PR2_match_interrupt_CallBack)(void)={NULL};               
void(*Oscillator_fail_interrupt_CallBack)(void)={NULL};                 
void(*comparator_interrupt_CallBack)(void)={NULL};                   
void(*data_eeprom_flash_write_operatin_interrupt_CallBack)(void)={NULL};
void(*bus_collision_interrupt_CallBack)(void)={NULL};                   
void(*high_low_voltage_detect_interrupt_callBack)(void)={NULL};
void(*CCP2_interrupt_CallBack)(void)={NULL};



void Interrupt_EnableGlobalInterupt(void)
{
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE

#elif INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_DISABLE

    GLOBAL_INTERRUPT_ENABLE();
    PERIPHERAL_INTERRUPT_ENABLE();
    
#endif    

}
void Interrypt_InitInterruptPerpherial(interrupt_configType* ConfigPtr)
{
    switch(ConfigPtr->type)
    {
		case TMR0_OVERFLOW_INTERRUPT     					 :
            TMR0_OVERFLOW_INTERRUPT_ENABLE();
            TMR_Overflow_callBack[0] = ConfigPtr->CallBack;
            break;            
		case TMR1_OVERFLOW_INTERRUPT                         :
            ENABLE_TMR1_OVERFLOW_INTERRUPT();
            TMR_Overflow_callBack[1] = ConfigPtr->CallBack;
            break;
		case TMR2_OVERFLOW_INTERRUPT                         : 
            ENABLE_THE_TMR2_TO_PR2_MATCH_INTERRUPT();
            TMR_Overflow_callBack[2] = ConfigPtr->CallBack;
            break;
		case TMR3_OVERFLOW_INTERRUPT                         : 
             ENABLE_TMR3_OVERFLOW_INTERRUPT();
            TMR_Overflow_callBack[3] = ConfigPtr->CallBack;
            break;
		case INT0_EXTERNAL_INTERRUPT                         : 
            INT0_EXTERNAL_INTERRUPT_ENABLE();
            switch(ConfigPtr->edge)
            {
                case INTERRUPT_ON_FALLING_EDGE: EXT0_FALLING_EDGE();  break;
                case INTERRUPT_ON_RISINGING_EDGE:EXT0_RISING_EDGE(); break;
            }
            switch(ConfigPtr->priority)
            {
                case LOW_PRIORITY  : TMR0_OVERFLOW_INTERRUPT_LOW_PRIORITY(); break;
                case HIGH_PRIORITY : TMR0_OVERFLOW_INTERRUPT_HIGH_PRIORITY(); break;

            }
            EXTI_CallBack[0] = ConfigPtr->CallBack;
            break;
		case INT1_EXTERNAL_INTERRUPT                         : 
            INT1_EXTERNAL_INTERRUPT_IS_ENABLE();
            switch(ConfigPtr->edge)
            {
                case INTERRUPT_ON_FALLING_EDGE: EXT1_FALLING_EDGE();  break;
                case INTERRUPT_ON_RISINGING_EDGE:EXT1_RISING_EDGE(); break;
            }
            switch(ConfigPtr->priority)
            {
                case LOW_PRIORITY :INT1_EXTERNAL_INTERRUPT_LOW_PRIORITY(); break;
                case HIGH_PRIORITY :INT1_EXTERNAL_INTERRUPT_HIGH_PRIORITY();break;

            }
            EXTI_CallBack[1] = ConfigPtr->CallBack;
            break;
		case INT2_EXTERNAL_INTERRUPT                         :
            INT2_EXTERNAL_INTERRUPT_IS_ENABLE();
            switch(ConfigPtr->edge)
            {
                case INTERRUPT_ON_FALLING_EDGE: EXT2_FALLING_EDGE();  break;
                case INTERRUPT_ON_RISINGING_EDGE:EXT2_RISING_EDGE(); break;
            }
            switch(ConfigPtr->priority)
            {
                case LOW_PRIORITY :INT2_EXTERNAL_INTERRUPT_LOW_PRIORITY(); break;
                case HIGH_PRIORITY :INT2_EXTERNAL_INTERRUPT_HIGH_PRIORITY();break;

            }
            EXTI_CallBack[2] = ConfigPtr->CallBack;
            break;
		case RB_PORT_CHANGE_INTERRUPT                        : break;
		case PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT        : break;
		case ADC_INTERRUPT                                   : break;
		case EUSART_RECEIEVE_INTERRUPT                       : break;
		case EUSART_TRANSMIT_INTERRUPT                       : break;
		case MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRUPT        : break;
		case CCP1_INTERRUPT                                  :
            ENABLE_THE_CCP1_INTERRUPT();
            ccp1_interrupt_CallBack = ConfigPtr->CallBack;
            break;
		case TMR2_TO_PR2_MATCH_INTERRUPT                     : break;
		case OSCILLATOR_FAIL_INTERRUPT                       : break;
		case COMPARATOR_INTERRUPT                            : break;
		case DATA_EEPROM_FLASH_WRITE_OPERATIN_INTERRUPT      : break;
		case BUS_COLLISION_INTERRUPT                         : break;
		case HIGH_LOW_VOLTAGE_DETECT_INTERRUPT               : break;
		case CCP2_INTERRUPT                                  :
            ENABLE_CCP2_INTERRUPT();
            CCP2_interrupt_CallBack = ConfigPtr->CallBack;
            break;
	    default :/*   error      */break;
	
	
    
    
    
    }


}


#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE

#elif INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_DISABLE
void __interrupt() InterruptManger()
{
    if((INTERRUPT_ENABLED== INT0_EXTERNAL_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == INT0_EXTERNAL_INTRRUPT_FLAG()))
    {
        CLEAR_INT0_EXTERNAL_INTRRUPT_FLAG();
        if(NULL!=  EXTI_CallBack[0])
        {
           EXTI_CallBack[0]();
        }
    }
    if((INTERRUPT_ENABLED== INT1_EXTERNAL_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == INT1_EXTERNAL_INTRRUPT_FLAG()))
    {
        CLEAR_INT1_EXTERNAL_INTRRUPT_FLAG();
        if(NULL!=  EXTI_CallBack[1])
        {
           EXTI_CallBack[1]();
        }        
    
    }    
    if((INTERRUPT_ENABLED== INT2_EXTERNAL_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == INT2_EXTERNAL_INTRRUPT_FLAG()))
    {
        if(NULL!=  EXTI_CallBack[2])
        {
           EXTI_CallBack[2]();
        }
    }
    if((INTERRUPT_ENABLED == TMR0_OVERFLOW_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == TMR0_OVERFLOW_INTRRUPT_FLAG()))
    {
        if(NULL != TMR_Overflow_callBack[0])
        {
             TMR_Overflow_callBack[0]();
            // __delay_ms(1000);
        }
        CLEAR_TMR0_OVERFLOW_INTRRUPT_FLAG();
    }
    if((INTERRUPT_ENABLED== TMR1_OVERFLOW_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == TMR1_OVERFLOW_INTERRUPT_FLAG()))
    {
        CLEAR_TMR1_OVERFLOW_INTERRUPT_FLAG();
        if(NULL != TMR_Overflow_callBack[1])
        {
            TMR_Overflow_callBack[1]();
        }
    }
    
     if((INTERRUPT_ENABLED== THE_TMR2_TO_PR2_MATCH_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == TMR2_TO_PR2_MATCH_INTERRUPT_FLAG()))
    {
        CLEAR_TMR2_TO_PR2_MATCH_INTERRUPT_FLAG();
        if(NULL != TMR_Overflow_callBack[2])
        {
            TMR_Overflow_callBack[2]();
        }
    }
    
    
    
     if((INTERRUPT_ENABLED== TMR3_OVERFLOW_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == TMR3_OVERFLOW_INTERRUPT_FLAG()))
    {
        CLEAR_TMR3_OVERFLOW_INTERRUPT_FLAG();
        if(NULL != TMR_Overflow_callBack[3])
        {
            TMR_Overflow_callBack[3]();
        }
    }
    if((INTERRUPT_ENABLED== RB_PORT_CHANGE_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == RB_PORT_CHANGE_INTRRUPT_FLAG()))
    {
        CLEAR_RB_PORT_CHANGE_INTRRUPT_FLAG();
       if (NULL != RB_port_change_interrutpt_CallBack)
       {
              RB_port_change_interrutpt_CallBack();
       }
    }  
    if((INTERRUPT_ENABLED== PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR == PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_FLAG()))
    {
        CLEAR_PARALLEL_SLAVE_PORT_READ_WRITE_INTERRUPT_FLAG();
        if(NULL != parallel_slave_port_RW_interrupt_CallBack)
        {
           parallel_slave_port_RW_interrupt_CallBack();
        
        }
    }    
    if((INTERRUPT_ENABLED==ENABLE_ADC_IS_INTERRUPT())&&(INTERRUPT_OCCUR ==ADC_INTERRUPT_FLAG()))
    {
       ADC_interrupt_CallBack();
    }       
    if((INTERRUPT_ENABLED==THE_EUSART_RECEIVE_INTERRUPTIS_ENABLE())&&(INTERRUPT_OCCUR ==EUSART_RECIEVE_INTERRYPT_FLAG()))
    {
       EUSART_receieve_interrupt_CallBack();
    }   
    if((INTERRUPT_ENABLED==THE_EUSART_TRANSMIT_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR ==EUSART_TRANSMIT_INTERRYPT_FLAG()))
    {
       EUSART_transmit_interrupt_CallBack();
    }
    if((INTERRUPT_ENABLED==THE_MSSP_INTERRUPT_IS_ENABLE())&&(INTERRUPT_OCCUR ==MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRYPT_FLAG()))
    {
         CLEAR_MASTER_SYNCHRONOUS_SERIAL_PORT_INTERRYPT_FLAG(); 
         if(NULL != master_synchronous_serial_port_interrupt_CallBack )
         {
                master_synchronous_serial_port_interrupt_CallBack();
         }
    }        
    if(/*(INTERRUPT_ENABLED==THE_CCP1_INTERRUPT_IS_ENABLE())&&*/(INTERRUPT_OCCUR ==CCP1_INTERRUPT_FLAG()))
    {
        CLEAR_CCP1_INTERRUPT_FLAG(); 
        if(NULL != ccp1_interrupt_CallBack )
         {
                ccp1_interrupt_CallBack();

         }
    }
}
#endif


