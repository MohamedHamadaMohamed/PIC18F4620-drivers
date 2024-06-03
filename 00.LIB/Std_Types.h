
/*
 * Std_Types.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char                uint8;
typedef signed char                  sint8;

typedef unsigned short int           uint16;
typedef signed short int             sint16;

typedef unsigned long int            uint32;
typedef signed long int              sint32;


typedef unsigned long long int        uint64;
typedef signed long long int          sint64;


typedef float                         float32;
typedef double                        float64;


typedef unsigned char                std_ReturnType;


/************************* Boolean ****************************/
typedef uint8    boolean;


#ifndef STD_TRUE
#define STD_TRUE           0X01
#endif

#ifndef STD_FALSE
#define STD_FALSE          0X00
#endif


#ifndef STD_HIGH
#define STD_HIGH           0X01
#endif

#ifndef STD_LOW
#define STD_LOW            0X00
#endif

#ifndef STD_ON
#define STD_ON           0X01
#endif

#ifndef STD_OFF
#define STD_OFF            0X00
#endif

#ifndef STD_ENABLE
#define STD_ENABLE         0X01
#endif

#ifndef STD_DISABLE
#define STD_DISABLE         0X00
#endif

#ifndef STD_ACTIVE
#define STD_ACTIVE         0X01
#endif

#ifndef STD_IDLE
#define STD_IDLE           0X00
#endif


#ifndef E_OK
#define E_OK         (std_ReturnType)0X01
#endif

#ifndef E_NOT_OK
#define E_NOT_OK           (std_ReturnType)0X00
#endif

#define ZERO_INIT         0U

#ifndef NULL_PTR
#define NULL_PTR            ((void*)0)
#endif



#endif /* ATMEGA16_00_LIB_STD_TYPES_H_ */
