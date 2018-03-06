/**
 *  file name:  main.c
 *	comments:   SmartHomeM Light Switch Main program
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
        value = sm_command (SM_CMD_LIGHT_VALUE);
        printf("Light Value = %d\n", value);
        if (value < 50) {
            sm_command (SM_CMD_LED1_ON);
            printf("LED1 On\n");
        }
        if (value > 60) {
            sm_command (SM_CMD_LED1_OFF);
            printf("LED1 Off\n");
        }
        sleep(1);
    }

    sm_end();

    return 0;
}
