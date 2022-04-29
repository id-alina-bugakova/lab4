
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Drive_lib.h"
#ifdef __cplusplus
	};
#endif

void DRIVE(struct DRIVE* inst)
{
	UINT mask = inst->STATE & 0x6f;
	if(inst->ENABLE)
	{
		switch(mask)
		{
			case State_Disabled:
				inst->COMMAND = CMD_Shutdown;
				break;
			case State_Ready:
				inst->COMMAND = CMD_Enable;
				break;
			case State_Switched_ON:
				inst->COMMAND = CMD_Switch_ON;
				break;
		}
	}
	else
	{
		inst->COMMAND = CMD_Shutdown;
	}
}
