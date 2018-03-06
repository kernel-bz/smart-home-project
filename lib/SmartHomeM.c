/*
 *  file name:  SmartHomeM.c
 *	comments:   Library Module for SmartHomeM
 *  author:     JungJaeJoon(rgbi3307@nate.com)
 *  Copyright (c) www.kernel.bz
 *  This is under the GPL License (see <http://www.gnu.org/licenses/>)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include "wiringPi.h"
#include "wiringPiI2C.h"
#include "SmartHomeM.h"

int I2Cfd;
int I2CSending = 0;

void ISR0(void)
{
    I2CSending = -1;    //stop
}

void sm_start (void)
{
	wiringPiSetup();
	wiringPiISR(IRA_SMARTHOME_PIN, INT_EDGE_RISING, &ISR0);	//P27
    pinMode (IRQ_SMARTHOME_PIN, OUTPUT);
    digitalWrite (IRQ_SMARTHOME_PIN, LOW);

    I2Cfd = wiringPiI2CSetup (I2C_ADDR_SMARTHOME);
    if (I2Cfd < 0)
        printf("I2C Open Error(%d)\n", I2Cfd);
    else
        printf("I2C Open Succeeded(%d)\n", I2Cfd);
}

void sm_end (void)
{
    close(I2Cfd);
}

int sm_command (int cmd)
{
	int ret, cnt=0;

    ///Request IRQ for I2C Sending
    digitalWrite (IRQ_SMARTHOME_PIN, HIGH);
    I2CSending = 0;
    digitalWrite (IRQ_SMARTHOME_PIN, LOW);

    while(I2CSending >= 0) {
        ret = wiringPiI2CWrite (I2Cfd, cmd);
        //printf("tx data=%02X\n", cmd);
        I2CSending++;
        do {
            cnt++;
            usleep(10000); ///10ms
        } while(I2CSending > 0 && cnt < 100);

        if (cnt >= 100) return 0;

        ret = wiringPiI2CRead(I2Cfd);  ///read between 30ms and 40ms
        //printf("rx data=%02X\n", ret);
    }
    usleep(300000); ///300ms
	return ret;
}

int sm_motor (int c, int d, int s)
{
	int ret, cmd, cnt=0;

    ///Request IRQ for I2C Sending
    digitalWrite (IRQ_SMARTHOME_PIN, HIGH);
    I2CSending = 0;
    cmd = c | (d << 1) | (s << 4);
    digitalWrite (IRQ_SMARTHOME_PIN, LOW);

    while(I2CSending >= 0) {
        ret = wiringPiI2CWrite (I2Cfd, cmd);
        //printf("tx data=%02X\n", cmd);
        I2CSending++;
        do {
            cnt++;
            sleep(1); ///1s
        } while(I2CSending > 0 && cnt < 10);

        if (cnt >= 10) return 0;

        ret = wiringPiI2CRead(I2Cfd);  ///read between 30ms and 40ms
        //printf("rx data=%02X\n", ret);
    }
    usleep(300000); ///300ms
	return ret;
}
