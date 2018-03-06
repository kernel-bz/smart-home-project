/**
 *  file name:  device_data_get.c
 *	comments:   SmartHomeM Control Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include "SmartHomeM.h"

int main (int argc, char **argv)
{
    int value;

	sm_start();

	value = sm_command (SM_CMD_TMPER_VALUE);
    printf("%d\n", value);

    value = sm_command (SM_CMD_LIGHT_VALUE);
    printf("%d\n", value);

    value = sm_command (SM_CMD_HUMTY_VALUE);
    printf("%d\n", value);

    value = sm_command (SM_CMD_GAS_VALUE);
    printf("%d\n", value);

    sm_end();

    return 0xFF;    //return OK
}
