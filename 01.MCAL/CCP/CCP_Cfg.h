/* 
 * File:   ADC.h
 * Author: Mohamed Hamada
 *
 * Created on 03 ?????, 2023, 02:11 ?
 */



#ifndef CCP_CFG_H_
#define	CCP_CFG_H_


/*********************** CCP 1  *****************************/

/*  capture   / compare   /   PWM      */
#define CCP_CFG_CAPTURE_MODE_SELECTED           0X00
#define CCP_CFG_COMPARE_MODE_SELECTED           0X01
#define CCP_CFG_PWM_MODE_SELECTED               0X02


/*
 option :
    CCP_CFG_CAPTURE_MODE_SELECTED
    CCP_CFG_COMPARE_MODE_SELECTED
    CCP_CFG_PWM_MODE_SELECTED
 */

#define CCP1_CFG_MODE_SELECT      CCP_CFG_COMPARE_MODE_SELECTED 




/*********************** CCP 2  *****************************/
 /*
 option :
    CCP_CFG_CAPTURE_MODE_SELECTED
    CCP_CFG_COMPARE_MODE_SELECTED
    CCP_CFG_PWM_MODE_SELECTED
 */

#define CCP2_CFG_MODE_SELECT          CCP_CFG_COMPARE_MODE_SELECTED





#endif