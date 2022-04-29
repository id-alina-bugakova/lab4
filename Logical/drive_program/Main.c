
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	motor_speed = 100;
	EVIRD.ENABLE = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(motor_reverse)
	{
		motor_speed = -motor_speed;
		motor_reverse = 0;
	}
	DRIVE(&EVIRD);
}

void _EXIT ProgramExit(void)
{
}

