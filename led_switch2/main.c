/**
 *  file name:  main.c
 *	comments:   SmartHomeM LED Switch2 Control Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SmartHomeM.h"

int main()
{
    int led_on[8] = {
            SM_CMD_LED1_ON, SM_CMD_LED2_ON, SM_CMD_LED3_ON, SM_CMD_LED4_ON
          , SM_CMD_LED5_ON, SM_CMD_LED6_ON, SM_CMD_LED7_ON, SM_CMD_LED8_ON };

    int led_off[8] = {
            SM_CMD_LED1_OFF, SM_CMD_LED2_OFF, SM_CMD_LED3_OFF, SM_CMD_LED4_OFF
          , SM_CMD_LED5_OFF, SM_CMD_LED6_OFF, SM_CMD_LED7_OFF, SM_CMD_LED8_OFF };

    int i, ret;

    sm_start();

    for (i=0; i<8; i++) {
        printf("LED %d th ON\n", i+1);
        sm_command (led_on[i]);
    }
    sleep(1);
    for (i=0; i<8; i++) {
        printf("LED %d th OFF\n", i+1);
        sm_command (led_off[i]);
    }

    printf("LED ALL ON\n");
    ret = sm_command (SM_CMD_LED_ALL_ON);
    printf("Command Result=%d\n", ret);
    sleep(1);
    printf("LED ALL OFF\n");
    ret = sm_command (SM_CMD_LED_ALL_OFF);
    printf("Command Result=%d\n", ret);

    sm_end();

    return 0;
}
