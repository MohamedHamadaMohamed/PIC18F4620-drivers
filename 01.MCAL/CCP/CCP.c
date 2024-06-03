/* 
 * File:   ADC.h
 * Author: Mohamed Hamada
 *
 * Created on 03 ?????, 2023, 02:11 ?
 */


#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"



#include "CCP_Cfg.h"
#include "CCP_Private.h"
#include "CCP.h"

static void CCP_Capture_MOde_Timer_Select(const CCP_ConfigType *ccp_configPtr);
static void CCP_Capture_Mode_Config(const  CCP_ConfigType *ccp_configPtr);
static void CCP_Compare_Mode_Config(const  CCP_ConfigType *ccp_configPtr);

std_ReturnType CCP_Init(const CCP_ConfigType *ccp_configPtr)
{
    std_ReturnType ret = E_NOT_OK;
    if(NULL == ccp_configPtr){
        ret = E_NOT_OK;
    }
    else
    {
        if(CCP1_t == ccp_configPtr->type )
        {
            
            CCP1_SET_MODE(CCP_MODULE_DISABLE);   
            if( CCP_CAPTURE_MODE_SELECTED ==  ccp_configPtr ->CCP_mode )
            {
                
                 
                
                switch(ccp_configPtr ->CCP_mode_variant)
                {
                    case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);   break;
                    case CCP_CAPTURE_MODE_1_RISING_EDGE  : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);    break;
                    case CCP_CAPTURE_MODE_4_RISING_EDGE  : CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);    break;
                    case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);   break;
                    default : break;
                }
            }
            else if( CCP_COMPARE_MODE_SELECTED ==  ccp_configPtr ->CCP_mode )
            {
             switch(ccp_configPtr ->CCP_mode_variant)
                {
                    case CCP_COMPARE_MODE_SET_PIN_LOW      : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);   break;
                    case CCP_COMPARE_MODE_SET_PIN_HIGH     : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);    break;
                    case CCP_COMPARE_MODE_TOGGLE_ON_MATCH  : CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);    break;
                    case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);   break;
                    case CCP_COMPARE_MODE_GEN_EVENT        : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);   break;
                    default : break;
                }            
            }
            else if( CCP_PWM_MODE_SELECTED ==  ccp_configPtr ->CCP_mode )
            {

            #if CCP1_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED       
             PR2 = (uint8)(((float)_XTAL_FREQ / ((float)ccp_configPtr->PWM_freqenucy * 4.0 * (float)ccp_configPtr->CCP_Timer2_postscaler * 
             (float)ccp_configPtr->CCP_Timer2_prescaler)) - 1);
            #endif

            }
        
        
        }
        else if (CCP2_t == ccp_configPtr->type)
        {                  
            
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
            if( CCP_CAPTURE_MODE_SELECTED ==  ccp_configPtr ->CCP_mode )
            {
                CCP_Capture_MOde_Timer_Select(ccp_configPtr);

                switch(ccp_configPtr ->CCP_mode_variant)
                {
                    case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);   break;
                    case CCP_CAPTURE_MODE_1_RISING_EDGE  : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);    break;
                    case CCP_CAPTURE_MODE_4_RISING_EDGE  : CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);    break;
                    case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);   break;
                    default : break;
                }
            }
            else if( CCP_COMPARE_MODE_SELECTED ==  ccp_configPtr ->CCP_mode )
            {
             switch(ccp_configPtr ->CCP_mode_variant)
                {
                    case CCP_COMPARE_MODE_SET_PIN_LOW      : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);   break;
                    case CCP_COMPARE_MODE_SET_PIN_HIGH     : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);    break;
                    case CCP_COMPARE_MODE_TOGGLE_ON_MATCH  : CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);    break;
                    case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);   break;
                    case CCP_COMPARE_MODE_GEN_EVENT        : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);   break;
                    default : break;
                }            
            }
            else if( CCP_PWM_MODE_SELECTED ==  ccp_configPtr ->CCP_mode )
            {

            #if CCP2_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED       
             PR2 = (uint8)(((float)_XTAL_FREQ / ((float)ccp_configPtr->PWM_freqenucy * 4.0 * (float)ccp_configPtr->CCP_Timer2_postscaler * 
             (float)ccp_configPtr->CCP_Timer2_prescaler)) - 1);
            #endif

            }
            
        }
                CCP_Capture_MOde_Timer_Select(ccp_configPtr);

        
    }
return ret;
}
std_ReturnType CCP_DeInit(const CCP_ConfigType *ccp_configPtr)
{
    std_ReturnType ret = E_OK;
    if(NULL == ccp_configPtr)
    {
        ret=E_NOT_OK;
    }
    else
    {
        if(CCP1_t == ccp_configPtr->type)
        {
            CCP1_SET_MODE(CCP_MODULE_DISABLE);

        }
        else if(CCP2_t == ccp_configPtr->type)
        {
             CCP2_SET_MODE(CCP_MODULE_DISABLE);
        }
    
        ret = E_OK;
    }
    return ret;

}

#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_CAPTURE_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_CAPTURE_MODE_SELECTED)) 
std_ReturnType CCP_IsCapturedDataReady(CCP_Type type,uint8 *_capture_status)
{
    std_ReturnType ret = E_NOT_OK;
    if((NULL == _capture_status )){
        ret = E_NOT_OK;
    }
    else
    {
        if(type == CCP1_t)
        {
            if( CCP_CAPTURE_READY == PIR1bits.CCP1IF ) 
            {
                *_capture_status = CCP_CAPTURE_READY; 
                PIR1bits.CCP1IF = 0;
                }
            else 
            {
                *_capture_status = CCP_CAPTURE_NOT_READY;               
            }
        }
        else if(type == CCP2_t)
        {
            if( CCP_CAPTURE_READY == PIR2bits.CCP2IF ) 
            {
                *_capture_status = CCP_CAPTURE_READY; 
                PIR2bits.CCP2IF = 0;
            }
            else 
            {
                *_capture_status = CCP_CAPTURE_NOT_READY;               
            }        
        }
       
    }
    return ret;
}
std_ReturnType CCP_Capture_Mode_Read_Value(CCP_Type type,uint16 *capture_value)
{
    std_ReturnType ret = E_NOT_OK;
    if((NULL == capture_value) ){
        ret = E_NOT_OK;
    }
    else
    {
       CCP_REG_T Capture_Temp_Value  ;
       if(type == CCP1_t)
       {
       Capture_Temp_Value.ccpr_low  = CCPR1L;
       Capture_Temp_Value.ccpr_high = CCPR1H;
       *capture_value = Capture_Temp_Value.ccpr_16Bit; 
   
       }
       else if(type == CCP2_t)
       {
        Capture_Temp_Value.ccpr_low  = CCPR2L;
       Capture_Temp_Value.ccpr_high = CCPR2H;
       *capture_value = Capture_Temp_Value.ccpr_16Bit; 
   
       
       }
       
    }   
    
        
        
    return ret;
}
#endif
#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_COMPARE_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_COMPARE_MODE_SELECTED)) 
std_ReturnType CCP_IsCompareComplete(CCP_Type type,uint8 *_compare_status)
{
    std_ReturnType ret = E_NOT_OK;
    if((NULL == _compare_status)){
        ret = E_NOT_OK;
    }
    else
    {
       if(CCP1_t == type )
       {
       if( CCP_COMPARE_READY == PIR1bits.CCP1IF ) 
           
          {
           *_compare_status = CCP_COMPARE_READY; 
           PIR1bits.CCP1IF = 0;
          }
       else 
          {
           *_compare_status = CCP_COMPARE_NOT_READY;               
          }
       }
       else if(CCP2_t == type)
       {
          if( CCP_CAPTURE_READY == PIR2bits.CCP2IF ) 
          {
           *_compare_status = CCP_COMPARE_READY; 
           PIR2bits.CCP2IF = 0;
          }
       else 
          {
           *_compare_status = CCP_COMPARE_NOT_READY;               
          }
       }

    }
    return ret;

}


std_ReturnType CCP_Compare_Mode_Set_Value(CCP_Type type, uint16 compare_value)
{
    std_ReturnType ret = E_OK;
    CCP_REG_T capture_temp_value;
    capture_temp_value.ccpr_16Bit = compare_value;

    if(0 == compare_value){
        ret = E_NOT_OK;
    }
    else{
      
      if( CCP1_t == type)
      {
        CCPR1L = capture_temp_value.ccpr_low   ;  
        CCPR1H = capture_temp_value.ccpr_high   ; 
      }
      else if(CCP2_t == type)
      {
        CCPR2L = capture_temp_value.ccpr_low   ;  
        CCPR2H = capture_temp_value.ccpr_high   ;      
      }
        /* Copy compared value */
    }   

}

#endif
#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED)) 
std_ReturnType CCP_PWM_Set_Duty(const CCP_ConfigType *ccp_configPtr, const uint8 _duty)
{
    std_ReturnType ret = E_OK;
   uint16 L_duty_temp =0; 
   L_duty_temp = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)_duty / 100.0));

   if(CCP1_t==ccp_configPtr->type)
   {
        CCP1CONbits.DC1B = (uint8)(L_duty_temp & 0x0003);
    CCPR1L = (uint8)(L_duty_temp >> 2);
   }
   else if(CCP2_t==ccp_configPtr->type)
   {
    CCP2CONbits.DC2B = (uint8)(L_duty_temp & 0x0003);
    CCPR2L = (uint8)(L_duty_temp >> 2);
   
   }
   
   
  
    return ret;
}

std_ReturnType CCP_PWM_Start(const CCP_ConfigType *ccp_configPtr)
{
   std_ReturnType ret = E_OK;
   if(NULL == ccp_configPtr)
   {
       ret = E_NOT_OK;
   }
   else
   {
       if(CCP1_t==ccp_configPtr->type)
       {
           CCP1_SET_MODE(CCP_PWM_MODE);

       }
       else if (CCP2_t==ccp_configPtr->type)
       {
           CCP2_SET_MODE(CCP_PWM_MODE);

       }
   }
   return ret;
}
std_ReturnType CCP_PWM_Stop(const CCP_ConfigType *ccp_configPtr)
{
   std_ReturnType ret = E_OK;
   if(NULL == ccp_configPtr)
   {
       ret = E_NOT_OK;
   }
   else
   {
       if(CCP1_t==ccp_configPtr->type)
       {
           CCP1_SET_MODE(CCP_MODULE_DISABLE);

       }
       else if (CCP2_t==ccp_configPtr->type)
       {
           CCP2_SET_MODE(CCP_MODULE_DISABLE);

       }
   }
   return ret;

}
#endif

static void CCP_Capture_MOde_Timer_Select(const CCP_ConfigType *ccp_configPtr)
{
    
     
    
    
    
    /* = Timer3 is the capture/compare clock source for the CCP modules */        
    if(   CCP1_CCP2_TIMER3 ==ccp_configPtr->ccp_capture_timer)
    {
       T3CONbits.T3CCP1 = 0;
       T3CONbits.T3CCP2 = 1;

    }
    /*
     Timer3 is the capture/compare clock source for CCP2;
     Timer1 is the capture/compare clock source for CCP1
     */
    else if (CCP1_TIMER1_CCP2_TIMER3 == ccp_configPtr->ccp_capture_timer)
    {
       T3CONbits.T3CCP1 = 1;
       T3CONbits.T3CCP2 = 0;
    }
    /*
     Timer1 is the capture/compare clock source for the CCP modules
     */
    else if (CCP1_CCP2_TIMER1 == ccp_configPtr->ccp_capture_timer)
    {
       T3CONbits.T3CCP1 = 0;
       T3CONbits.T3CCP2 = 0;
    
    }

}
static void CCP_Capture_Mode_Config(const  CCP_ConfigType *ccp_configPtr)
{





}
static void CCP_Compare_Mode_Config(const  CCP_ConfigType *ccp_configPtr);