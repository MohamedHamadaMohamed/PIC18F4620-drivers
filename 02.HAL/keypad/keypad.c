
#include "../../LIB/Micro_Config.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"

#include "../../MCAL/Dio/Dio.h"

#include "keypad.h"
#include "keypad_Cfg.h"

#if (N_col == 3)
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);
#elif (N_col == 4) 
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);
#endif

static Pin_Config_t ROWS[N_row] = 
{
    {ROW_0_PORT,ROW_0_PIN},
    {ROW_1_PORT,ROW_1_PIN},
    {ROW_2_PORT,ROW_2_PIN},
    {ROW_3_PORT,ROW_3_PIN}
};

static Pin_Config_t COLS[N_col] = 
{
    {COL_0_PORT,COL_0_PIN},
    {COL_1_PORT,COL_1_PIN},
    {COL_2_PORT,COL_2_PIN},
    {COL_3_PORT,COL_3_PIN}
};


void keypad_init()
{

    for(uint8 i = ZERO_INIT; i <N_row;i++)
    {
      Dio_SetPinDirection( ROWS[i].Port_Index,ROWS[i].Channel_Index, OUTPUT );
      Dio_SetPinDirection( COLS[i].Port_Index,COLS[i].Channel_Index, INPUT );
    }
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8 KeyPad_getPressedKey(void)
{
	uint8 col,row;
	
		for(col=0;col<N_col;col++) /* loop for columns */
		{
            
			
			/* 
			 * clear the output pin column in this trace and enable the internal 
			 * pull up resistors for the rows pins
			 */ 
            for(uint8 i = ZERO_INIT ;i<N_col ;i++)
            {
                Dio_WriteChannel( ROWS[i].Port_Index,ROWS[i].Channel_Index, STD_LOW );
            }
            Dio_WriteChannel( ROWS[col].Port_Index,ROWS[col].Channel_Index, STD_HIGH );

            
			for(row=0;row<N_row;row++) /* loop for rows */
			{ 
				if(Dio_ReadChannel( COLS[row].Port_Index, COLS[row].Channel_Index )) /* if the switch is press in this row */ 
				{
					#if (N_col == 3)
						return KeyPad_4x3_adjustKeyNumber((row*N_col)+col+1);
					#elif (N_col == 4)
						return KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);
					#endif
				}
			}
		}
	
}

#if (N_col == 3) 

static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
		case 10: return '*'; // ASCII Code of *
				 break;
		case 11: return 0;
				 break;		
		case 12: return '#'; // ASCII Code of #
				 break;
		default: return button_number;								 						
	}
} 

#elif (N_col == 4)
 
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
		case 1: return 7; 
				break;
		case 2: return 8; 
				break;
		case 3: return 9; 
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4; 
				break;
		case 6: return 5;
				break;
		case 7: return 6; 
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;		
		case 9: return 1; 
				break;
		case 10: return 2; 
				break;
		case 11: return 3; 
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return 13;  /* ASCII of Enter */
				break;			
		case 14: return 0; 
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return button_number;								 						
	}
} 

#endif


