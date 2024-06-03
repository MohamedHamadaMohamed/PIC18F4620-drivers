/* 
 * File:   CCP_Private.h
 * Author: Mohamed Hamada
 *
 * Created on 03 ?????, 2023, 02:11 ?
 */



#ifndef CCP_PRIVATE_H_
#define	CCP_PRIVATE_H_

#include "../../LIB/Micro_Config.h"

#include "CCP_Cfg.h"

/******** CCP Type  *******/
typedef enum
{
    CCP1_t,CCP2_t
}CCP_Type;
/* CCP1 Module Mode Select  */
#define CCP_MODULE_DISABLE                 ((uint8)0x00)
#define CCP_CAPTURE_MODE_1_FALLING_EDGE    ((uint8)0x04)
#define CCP_CAPTURE_MODE_1_RISING_EDGE     ((uint8)0x05)
#define CCP_CAPTURE_MODE_4_RISING_EDGE     ((uint8)0x06)
#define CCP_CAPTURE_MODE_16_RISING_EDGE    ((uint8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW       ((uint8)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH      ((uint8)0x09)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH   ((uint8)0x02)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT  ((uint8)0x0A)
#define CCP_COMPARE_MODE_GEN_EVENT         ((uint8)0x0B)
#define CCP_PWM_MODE                       ((uint8)0x0C)


/* CCP1 Capture Mode State  */
#define CCP_CAPTURE_NOT_READY              0X00
#define CCP_CAPTURE_READY                  0X01

/* CCP1 Compare Mode State  */
#define CCP_COMPARE_NOT_READY              0X00
#define CCP_COMPARE_READY                  0X01



#define CCP1_SET_MODE(_CONFIG)       (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)       (CCP2CONbits.CCP2M = _CONFIG)

/* Timer2 Input Clock Post-scaler */
#define CCP_TIMER2_POSTSCALER_DIV_BY_1       1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2       2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3       3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4       4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5       5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6       6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7       7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8       8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9       9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10      10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11      11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12      12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13      13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14      14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15      15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16      16

/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16





/*
  @Summary      Defines the values to convert from 16bit to two 8 bit and vice versa
  @Description  Used to get two 8 bit values from 16bit also two 8 bit value are combine to get 16bit.
*/
typedef union{
    struct{
        uint8 ccpr_low;  /* CCPR1 low register */
        uint8 ccpr_high; /* CCPR1 high register */
    };
    struct{
        uint16 ccpr_16Bit; /* Read CCPR1 as a 16 Bit value */
    };
}CCP_REG_T;


typedef enum{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1
}ccp_capture_timer_t;



/*
  @Summary      Define the values to select the CCP1 Main mode
*/
typedef enum{
    CCP_CAPTURE_MODE_SELECTED = 0, /* Select CCP1 Capture Mode */
    CCP_COMPARE_MODE_SELECTED,     /* Select CCP1 Compare Mode */
    CCP_PWM_MODE_SELECTED          /* Select CCP1 PWM Mode */
}ccp_mode_t;



typedef struct
{
CCP_Type type;
ccp_mode_t CCP_mode;
uint8 CCP_mode_variant;

ccp_capture_timer_t ccp_capture_timer;
/** for PWM mode  **/
#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED)) 

uint32 PWM_freqenucy;
uint8 CCP_Timer2_postscaler;
uint8 CCP_Timer2_prescaler;

#endif

}CCP_ConfigType;

#endif