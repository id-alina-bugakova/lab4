
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	iterator = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(blinking)
	{
		led_button[0] = led_button[1] = led_button[2] = led_button[3] = 0;
		for(i = 0; i < 4; ++i)
			if(iterator % (i+1) == 0)
				led[i] = !led[i];
		++iterator;
	}
	else
	{
		for(i = 0; i < 4; ++i)
			led[i] = led_button[i];
	}
}

void _EXIT ProgramExit(void)
{
}

