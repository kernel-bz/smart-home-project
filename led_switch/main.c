/**
 *  file name:  main.c
 *	comments:   SmartHomeM LED Switch Control Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SmartHomeM.h"

int main()
{
    int ret;

    sm_start();

    printf("command LED ON\n");
    ret = sm_command (SM_CMD_LED1_ON);
    ret = sm_command (SM_CMD_LED2_ON);
    ret = sm_command (SM_CMD_LED3_ON);
    ret = sm_command (SM_CMD_LED4_ON);
    ret = sm_command (SM_CMD_LED5_ON);
    ret = sm_command (SM_CMD_LED6_ON);
    ret = sm_command (SM_CMD_LED7_ON);
    ret = sm_command (SM_CMD_LED8_ON);
    printf("command ret=%d\n", ret);
    sleep(1);
    printf("command LED OFF\n");
    ret = sm_command (SM_CMD_LED1_OFF);
    ret = sm_command (SM_CMD_LED2_OFF);
    ret = sm_command (SM_CMD_LED3_OFF);
    ret = sm_command (SM_CMD_LED4_OFF);
    ret = sm_command (SM_CMD_LED5_OFF);
    ret = sm_command (SM_CMD_LED6_OFF);
    ret = sm_command (SM_CMD_LED7_OFF);
    ret = sm_command (SM_CMD_LED8_OFF);
    printf("command ret=%d\n", ret);

    sm_end();
}
