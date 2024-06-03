/* 
 * File:   CCP1.h
 * Author: Mohamed Hamada
 *
 * Created on 03 ?????, 2023, 02:11 ?
 */



#ifndef CCP1_H_
#define	CCP1_H_

#include "CCP_Cfg.h"
#include "CCP_Private.h"

std_ReturnType CCP_Init(const CCP_ConfigType *ccp_configPtr);
std_ReturnType CCP_DeInit(const CCP_ConfigType *ccp_configPtr);

#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_CAPTURE_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_CAPTURE_MODE_SELECTED)) 
std_ReturnType CCP_IsCapturedDataReady(CCP_Type type,uint8 *_capture_status);
std_ReturnType CCP_Capture_Mode_Read_Value(CCP_Type type,uint16 *capture_value);

#endif
#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_COMPARE_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_COMPARE_MODE_SELECTED)) 
 
std_ReturnType CCP_IsCompareComplete(CCP_Type type,uint8 *_compare_status);
std_ReturnType CCP_Compare_Mode_Set_Value(CCP_Type type, uint16 compare_value);

#endif
#if ((CCP1_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED)||(CCP2_CFG_MODE_SELECT == CCP_CFG_PWM_MODE_SELECTED)) 
std_ReturnType CCP_PWM_Set_Duty(const CCP_ConfigType *ccp_configPtr, const uint8 _duty);
std_ReturnType CCP_PWM_Start(const CCP_ConfigType *ccp_configPtr);
std_ReturnType CCP_PWM_Stop(const CCP_ConfigType *ccp_configPtr);


#endif

#endif