

#include "../../LIB/Micro_Config.h"
#include "../../LIB/BIT_MATHS.h"
#include "Dio_Types.h"

#include "Dio_Types.h"
#include "Dio.h"


std_ReturnType Dio_Init( const Dio_ConfigType *ConfigPtr )
{
    std_ReturnType ret = E_OK;
    
    if( (ConfigPtr->Channel_Index > PORT_PIN_MAX_NUMBER -1) )
    {
        ret = E_NOT_OK;
        
    }
    else
    {
        switch(ConfigPtr->Port_Index)
        {
            /******************** PORTA   ***********************/
            case PORTA_INDEX : 
                switch(ConfigPtr->direction)
                {
                    case INPUT  : SET_BIT(TRISA,ConfigPtr->Channel_Index); break;
                    case OUTPUT : CLEAR_BIT(TRISA,ConfigPtr->Channel_Index);   break;
                    default     : ret = E_NOT_OK;                              break;
                }

                switch(ConfigPtr->initial_value)
                {
                    case STD_HIGH : SET_BIT(LATA,ConfigPtr->Channel_Index); break;
                    case STD_LOW  : CLEAR_BIT(LATA,ConfigPtr->Channel_Index); break;
                    default       : ret = E_NOT_OK;                break;

                }

                break;

           /******************** PORTB   ***********************/

            case PORTB_INDEX : 
                switch(ConfigPtr->direction)
                {
                    case INPUT  : SET_BIT(TRISB,ConfigPtr->Channel_Index); break;
                    case OUTPUT : CLEAR_BIT(TRISB,ConfigPtr->Channel_Index);   break;
                    default     :  ret = E_NOT_OK;   break;
                }

                switch(ConfigPtr->initial_value)
                {
                    case STD_HIGH : SET_BIT(LATB,ConfigPtr->Channel_Index); break;
                    case STD_LOW  : CLEAR_BIT(LATB,ConfigPtr->Channel_Index); break;
                    default       :  ret = E_NOT_OK;     break;

                }

                break;

           /******************** PORTC   ***********************/

            case PORTC_INDEX : 
                switch(ConfigPtr->direction)
                {
                    case INPUT  : SET_BIT(TRISC,ConfigPtr->Channel_Index); break;
                    case OUTPUT : CLEAR_BIT(TRISC,ConfigPtr->Channel_Index);   break;
                    default     : ret = E_NOT_OK;    break;
                }

                switch(ConfigPtr->initial_value)
                {
                    case STD_HIGH : SET_BIT(LATC,ConfigPtr->Channel_Index); break;
                    case STD_LOW  : CLEAR_BIT(LATC,ConfigPtr->Channel_Index); break;
                    default       : ret = E_NOT_OK;   break;

                }

                break;  
             /******************** PORTD   ***********************/

            case PORTD_INDEX : 
                switch(ConfigPtr->direction)
                {
                    case INPUT  : SET_BIT(TRISD,ConfigPtr->Channel_Index); break;
                    case OUTPUT : CLEAR_BIT(TRISD,ConfigPtr->Channel_Index);   break;
                    default     : ret = E_NOT_OK;   break;
                }

                switch(ConfigPtr->initial_value)
                {
                    case STD_HIGH : SET_BIT(LATD,ConfigPtr->Channel_Index); break;
                    case STD_LOW  : CLEAR_BIT(LATD,ConfigPtr->Channel_Index); break;
                    default       : ret = E_NOT_OK;   break;

                }

                break;

           /******************** PORTE   ***********************/

            case PORTE_INDEX : 
                switch(ConfigPtr->direction)
                {
                    case INPUT  : SET_BIT(TRISE,ConfigPtr->Channel_Index); break;
                    case OUTPUT : CLEAR_BIT(TRISE,ConfigPtr->Channel_Index);   break;
                    default     : ret = E_NOT_OK;    break;
                }

                switch(ConfigPtr->initial_value)
                {
                    case STD_HIGH : SET_BIT(LATE,ConfigPtr->Channel_Index); break;
                    case STD_LOW  : CLEAR_BIT(LATE,ConfigPtr->Channel_Index); break;
                    default       : ret = E_NOT_OK;   break;

                }

                break;            
        }
    }
    return ret;
}
std_ReturnType Dio_SetPinDirection( Dio_PortType PortId,Dio_ChannelType ChannelId, Dio_PinDirectionType Direction )
{
    std_ReturnType ret = E_OK;
    
    if( (ChannelId > PORT_PIN_MAX_NUMBER -1) )
    {
        ret = E_NOT_OK;
        
    }
    else
    {
      
        switch(PortId)
        {

          /******************** PORTA   ***********************/ 
            case PORTA_INDEX :
            switch(Direction)
            {
                case INPUT  : SET_BIT(TRISA,ChannelId); break;
                case OUTPUT : CLEAR_BIT(TRISA,ChannelId);   break;
                default     : ret = E_NOT_OK;   break;
            }
            break;
          /******************** PORTB   ***********************/ 
            case PORTB_INDEX :
            switch(Direction)
            {
                case INPUT  : SET_BIT(TRISB,ChannelId); break;
                case OUTPUT : CLEAR_BIT(TRISB,ChannelId);   break;
                default     : ret = E_NOT_OK;   break;
            }
            break;
          /******************** PORTC   ***********************/ 
            case PORTC_INDEX :
            switch(Direction)
            {
                case INPUT  : SET_BIT(TRISC,ChannelId); break;
                case OUTPUT : CLEAR_BIT(TRISC,ChannelId);   break;
                default     : ret = E_NOT_OK;   break;
            }
            break; 
          /******************** PORTD   ***********************/ 
            case PORTD_INDEX :
            switch(Direction)
            {
                case INPUT  : SET_BIT(TRISD,ChannelId); break;
                case OUTPUT : CLEAR_BIT(TRISD,ChannelId);   break;
                default     : ret = E_NOT_OK;   break;
            }
            break;
          /******************** PORTE   ***********************/ 
            case PORTE_INDEX :
            switch(Direction)
            {
                case INPUT  : SET_BIT(TRISE,ChannelId); break;
                case OUTPUT : CLEAR_BIT(TRISE,ChannelId);   break;
                default     : ret = E_NOT_OK;   break;
            }
            break;       
        }
        
    }
    return ret;

}
    std_ReturnType Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
    {
        std_ReturnType ret = E_OK;
        switch(PortId)
        {
          case PORTA_INDEX :  LATA = Level;   break;
          case PORTB_INDEX :  LATB = Level;   break;
          case PORTC_INDEX :  LATC = Level;   break;
          case PORTD_INDEX :  LATD = Level;   break;
          case PORTE_INDEX :  LATE = Level;   break;
          default          :  ret = E_NOT_OK;      break;
        }
        return ret;
    }
    Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
    {
        Dio_PortLevelType Level =0;
        switch(PortId)
        {
          case PORTA_INDEX :  Level = PORTA;   break;
          case PORTB_INDEX :  Level = PORTB;   break;
          case PORTC_INDEX :  Level = PORTC;   break;
          case PORTD_INDEX :  Level = PORTD;   break;
          case PORTE_INDEX :  Level = PORTE;   break;
          default          :                  break;
        }
        return Level;
    }
    std_ReturnType Dio_WriteChannel( Dio_PortType PortId,Dio_ChannelType ChannelId, Dio_LevelType Level )
    {
         std_ReturnType ret = E_OK;
         switch(PortId)
        {
           /******************** PORTA   ***********************/ 
           case PORTA_INDEX : 
               switch (Level)
               {
                   case STD_HIGH : SET_BIT(LATA,ChannelId); break; 
                   case STD_LOW  : CLEAR_BIT(LATA,ChannelId); break;
                   default :  ret = E_NOT_OK;  break;
               } break;
           /******************** PORTB   ***********************/ 
           case PORTB_INDEX : 
               switch (Level)
               {
                   case STD_HIGH : SET_BIT(LATB,ChannelId); break; 
                   case STD_LOW  : CLEAR_BIT(LATB,ChannelId); break;
                   default :  ret = E_NOT_OK;  break;
               } break;
           /******************** PORTC   ***********************/ 
           case PORTC_INDEX : 
               switch (Level)
               {
                   case STD_HIGH : SET_BIT(LATC,ChannelId); break; 
                   case STD_LOW  : CLEAR_BIT(LATC,ChannelId); break;
                   default :  ret = E_NOT_OK;  break;
               } break;    
           /******************** PORTD   ***********************/ 
           case PORTD_INDEX : 
               switch (Level)
               {
                   case STD_HIGH : SET_BIT(LATD,ChannelId); break; 
                   case STD_LOW  : CLEAR_BIT(LATD,ChannelId); break;
                   default :  ret = E_NOT_OK;  break;
               } break; 

           /******************** PORTE   ***********************/ 
           case PORTE_INDEX : 
               switch (Level)
               {
                   case STD_HIGH : SET_BIT(LATE,ChannelId); break; 
                   case STD_LOW  : CLEAR_BIT(LATE,ChannelId); break;
                   default :  ret = E_NOT_OK;  break;
               } break;            
        }
    
     return ret;
    
}


Dio_LevelType Dio_ReadChannel( Dio_PortType PortId,Dio_ChannelType ChannelId )
{
    Dio_LevelType Level =0;  
    
    switch(PortId)
    {
      case PORTA_INDEX :  Level = GET_BIT(PORTA,ChannelId);   break;
      case PORTB_INDEX :  Level = GET_BIT(PORTB,ChannelId);   break;
      case PORTC_INDEX :  Level = GET_BIT(PORTC,ChannelId);   break;
      case PORTD_INDEX :  Level = GET_BIT(PORTD,ChannelId);   break;
      case PORTE_INDEX :  Level = GET_BIT(PORTE,ChannelId);   break;
      default          :                  break;
    }
 
    
    
    return Level;

}
