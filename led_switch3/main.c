/**
 *  file name:  main.c
 *	comments:   SmartHomeM LED Switch3 Control Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio_ext.h>

#include "SmartHomeM.h"

int main()
{
    int led_on[8] = {
            SM_CMD_LED1_ON, SM_CMD_LED2_ON, SM_CMD_LED3_ON, SM_CMD_LED4_ON
          , SM_CMD_LED5_ON, SM_CMD_LED6_ON, SM_CMD_LED7_ON, SM_CMD_LED8_ON };

    int led_off[8] = {
            SM_CMD_LED1_OFF, SM_CMD_LED2_OFF, SM_CMD_LED3_OFF, SM_CMD_LED4_OFF
          , SM_CMD_LED5_OFF, SM_CMD_LED6_OFF, SM_CMD_LED7_OFF, SM_CMD_LED8_OFF };

    int key;

    sm_start();

    while(1)
    {
        printf("Input Key:");
        scanf("%d", &key);
        printf("key value = %d\n", key);
        if (key > 8) break;

        key = key - 1;

        sm_command (led_on[key]);

        sleep(1);

        sm_command (led_off[key]);

        printf("\n\n");
        //__fpurge(0);
    }

    sm_end();

    return 0;
}
