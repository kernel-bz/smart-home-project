/**
 *  file name:  main.c
 *	comments:   SmartHomeM Motor Control Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SmartHomeM.h"

int main (void)
{
	sm_start();

	printf("SM_CMD_MOTOR_CW, D90, S90\n");
    sm_motor (SM_CMD_MOTOR_CW, MOTOR_D90, MOTOR_S90);

    printf("SM_CMD_MOTOR_CCW, D90, S90\n");
    sm_motor (SM_CMD_MOTOR_CCW, MOTOR_D90, MOTOR_S90);

    printf("SM_CMD_MOTOR_CW, D20, S20\n");
    sm_motor (SM_CMD_MOTOR_CW, MOTOR_D20, MOTOR_S20);

    printf("SM_CMD_MOTOR_CCW, D20, S20\n");
    sm_motor (SM_CMD_MOTOR_CCW, MOTOR_D20, MOTOR_S20);

    sm_end();

    return 0;
}
