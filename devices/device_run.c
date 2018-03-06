/**
 *  file name:  device_run.c
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
    int led_on[9] = { SM_CMD_LED_ALL_ON
          , SM_CMD_LED1_ON, SM_CMD_LED2_ON, SM_CMD_LED3_ON, SM_CMD_LED4_ON
          , SM_CMD_LED5_ON, SM_CMD_LED6_ON, SM_CMD_LED7_ON, SM_CMD_LED8_ON };
    int led_off[9] = { SM_CMD_LED_ALL_OFF
          , SM_CMD_LED1_OFF, SM_CMD_LED2_OFF, SM_CMD_LED3_OFF, SM_CMD_LED4_OFF
          , SM_CMD_LED5_OFF, SM_CMD_LED6_OFF, SM_CMD_LED7_OFF, SM_CMD_LED8_OFF };

    int rely_on[5] = { SM_CMD_RELY0_ON
        , SM_CMD_RELY1_ON, SM_CMD_RELY2_ON, SM_CMD_RELY3_ON, SM_CMD_RELY4_ON };
    int rely_off[5] = { SM_CMD_RELY0_OFF
        , SM_CMD_RELY1_OFF, SM_CMD_RELY2_OFF, SM_CMD_RELY3_OFF, SM_CMD_RELY4_OFF };

	int idx, sw, dir, ret=0;

	sm_start();

	if (argc > 2) {
        idx = atoi(argv[1]);
        sw = atoi(argv[2]);
        if (idx >= 0 && idx <= 8) {
            if (sw) ret = sm_command (led_on[idx]);
            else ret = sm_command (led_off[idx]);
        } else if (idx == 9) { ///Step Motor
            dir = (sw) ? SM_CMD_MOTOR_CW : SM_CMD_MOTOR_CCW;
            ret = sm_motor (dir, MOTOR_D90, MOTOR_S90);
        } else if (idx >= 10 && idx <= 14) {
            if (sw) ret = sm_command (rely_on[idx-10]);
            else ret = sm_command (rely_off[idx-10]);
        }
	}

_end:
	sm_end();

	return ret;
}
