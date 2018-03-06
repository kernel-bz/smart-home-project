/**
 *  file name:  main.c
 *	comments:   SmartHomeM Humidity Switch Main program
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
        value = sm_command (SM_CMD_HUMTY_VALUE);
        printf("Humidity = %d\n", value);
        if (value < 40) {
            sm_command (SM_CMD_LED5_ON);
            sm_command (SM_CMD_LED4_OFF);
            printf("Humidifier On, Dehumidifier Off\n");
        }
        if (value > 60) {
            sm_command (SM_CMD_LED4_ON);
            sm_command (SM_CMD_LED5_OFF);
            printf("Humidifier Off, Dehumidifier On\n");
        }
        sleep(1);
    }

    sm_end();

    return 0;
}
