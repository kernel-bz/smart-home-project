/**
 *  file name:  main.c
 *	comments:   SmartHomeM Temperature Switch Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SmartHomeM.h"

int main (void)
{
	int value;

	sm_start();

	while (1)
	{
        value = sm_command (SM_CMD_TMPER_VALUE);
        printf("Temperature = %d\n", value);
        if (value < 19) {
            sm_command (SM_CMD_LED3_ON);
            sm_command (SM_CMD_LED2_OFF);
            printf("Boiler On, Aircon Off\n");
        }
        if (value > 30) {
            sm_command (SM_CMD_LED2_ON);
            sm_command (SM_CMD_LED3_OFF);
            printf("Boiler Off, Aircon On\n");
        }
        sleep(1);
    }

    sm_end();

    return 0;
}
