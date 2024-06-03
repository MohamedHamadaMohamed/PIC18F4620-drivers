/* 
 * File:   BIT_MATHS.h
 * Author: Moham
 *
 * Created on November 22, 2022, 11:51 AM
 */

#ifndef BIT_MATHS_H
#define	BIT_MATHS_H

#define SET_BIT(REG,BIT)		(REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)		(REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)		(REG^=(1<<BIT))
#define GET_BIT(REG,BIT)        ((REG>>BIT)&0X01)


#define BIT_IS_CLEAR(REG,BIT)    (!((REG)&(1<<BIT)))
#define BIT_IS_SET(REG,BIT)      (((REG)&(1<<BIT)))

 /* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )


#endif	/* BIT_MATHS_H */

