


#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/Micro_Config.h"

#include "../../MCAL/Dio/Dio.h"

#include "Relay.h"
#include "Relay_config.h"


std_ReturnType Relay_init(const Relay_Config * RelayConfigPtr) 
{
    std_ReturnType ret =E_OK;
    
    if((RelayConfigPtr->PortId == NULL))
    {
        ret =E_NOT_OK;
    }
    else
    {
    Dio_ConfigType Relay_config_temp = 
    {
     .Port_Index = RelayConfigPtr->PortId,
	 .Channel_Index =RelayConfigPtr ->ChannelId,
	 .direction = OUTPUT,
	 .resistor = OFF,
	 .initial_value = STD_LOW,
    };
	Dio_Init(&Relay_config_temp ); 
    }
    return ret;
}
std_ReturnType Relay_On(const Relay_Config * RelayConfigPtr   )
{
  std_ReturnType ret =E_OK;
    
    if((RelayConfigPtr->PortId == NULL))
    {
        ret =E_NOT_OK;
    }
    else
    {
        Dio_WriteChannel( RelayConfigPtr ->PortId,RelayConfigPtr->ChannelId, STD_HIGH );
    }
    return ret;

}
std_ReturnType Relay_Off(const Relay_Config * RelayConfigPtr  )
{
  std_ReturnType ret =E_OK;
    
    if(RelayConfigPtr->PortId == NULL)
    {
        ret =E_NOT_OK;
    }
    else
    {
        Dio_WriteChannel( RelayConfigPtr ->PortId,RelayConfigPtr->ChannelId, STD_LOW);
    
    }
    return ret;



}

