/**
 *  file name:  main.c
 *	comments:   SmartHomeM Motor Control2 Main program
 *  author:     JungJaeJoon(rgbi3307@nate.com) on the www.kernel.bz
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SmartHomeM.h"

int main (void)
{
    int motor_dir[2] = { SM_CMD_MOTOR_CW, SM_CMD_MOTOR_CCW };
    int motor_degree[8] = {
            MOTOR_D20, MOTOR_D30, MOTOR_D40, MOTOR_D50,
            MOTOR_D60, MOTOR_D70, MOTOR_D80, MOTOR_D90 };
    int motor_speed[8] = {
            MOTOR_S20, MOTOR_S30, MOTOR_S40, MOTOR_S50,
            MOTOR_S60, MOTOR_S70, MOTOR_S80, MOTOR_S90 };
	int dir, degree, speed;

    sm_start();

    while(1)
    {
        printf("Input Motor Direction(0~1):");
        scanf("%d", &dir);
        if (dir > 1 || dir < 0) break;

        printf("Input Motor Degree(0~7):");
        scanf("%d", &degree);
        if (degree > 7 || degree < 0) break;

        printf("Input Motor Speed(0~7):");
        scanf("%d", &speed);
        if (speed > 7 || speed < 0) break;

        printf("dir=%d, degree=%d, speed=%d\n", dir, degree, speed);
        sm_motor (motor_dir[dir], motor_degree[degree], motor_speed[speed]);

        printf("\n\n");
    }

    sm_end();

    return 0;
}
