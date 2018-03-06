/**
 *  file name:  main.c
 *	comments:   SmartHomeM GAS Switch Main program
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
        value = sm_command (SM_CMD_GAS_VALUE);
        printf("GAS Value = %d\n", value);
        if (value < 40) {
            sm_command (SM_CMD_LED6_OFF);
            sm_command (SM_CMD_LED7_OFF);
            printf("Air Cleaner, Cooling FAN, Buzzer Off\n");
        }
        if (value > 60) {
            sm_command (SM_CMD_LED6_ON);
            sm_command (SM_CMD_LED7_ON);
            printf("Air Cleaner, Cooling FAN, Buzzer On\n");
        }
        sleep(1);
    }

    sm_end();

    return 0;
}
