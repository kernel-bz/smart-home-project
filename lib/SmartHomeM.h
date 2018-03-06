/*
 *  file name:  SmartHomeM.h
 *	comments:   Library Module for SmartHomeM
 *  author:     JungJaeJoon(rgbi3307@nate.com)
 *  Copyright (c) www.kernel.bz
 *  This is under the GPL License (see <http://www.gnu.org/licenses/>)
 */

#ifndef	__SMARTHOME_M_H__
#define	__SMARTHOME_M_H__

//gpio readall
#define IRQ_SMARTHOME_PIN    7  ///P7
#define IRA_SMARTHOME_PIN   30  ///P27

//I2C Clock: 100KHz
//sudo i2cdetect -y 1 (/dev/i2c-1)
/**
root@SmartHomeM:/home/pi# i2cdetect -y 1
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- 2b -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --
*/
///#define I2C_ADDR_SMARTHOME   0x357   ///Cortex-M0 (Slave)
#define I2C_ADDR_SMARTHOME      0x2B    ///i2cdetect (Master)

#define SM_CMD_LED1_OFF         0x00
#define SM_CMD_LED1_ON          0x01
#define SM_CMD_LED2_OFF         0x02
#define SM_CMD_LED2_ON          0x03
#define SM_CMD_LED3_OFF         0x04
#define SM_CMD_LED3_ON          0x05
#define SM_CMD_LED4_OFF         0x06
#define SM_CMD_LED4_ON          0x07
#define SM_CMD_LED5_OFF         0x08
#define SM_CMD_LED5_ON          0x09
#define SM_CMD_LED6_OFF         0x0A
#define SM_CMD_LED6_ON          0x0B
#define SM_CMD_LED7_OFF         0x0C
#define SM_CMD_LED7_ON          0x0D
#define SM_CMD_LED8_OFF         0x0E
#define SM_CMD_LED8_ON          0x0F

#define SM_CMD_LED_ALL_OFF      0x10
#define SM_CMD_LED_ALL_ON       0x11

#define SM_CMD_LIGHT_VALUE      0x21
#define SM_CMD_ULTRA_VALUE      0x31
#define SM_CMD_GAS_VALUE        0x41
#define SM_CMD_TMPER_VALUE      0x51
#define SM_CMD_HUMTY_VALUE      0x61

#define SM_CMD_RELY0_OFF        0x70
#define SM_CMD_RELY0_ON         0x71
#define SM_CMD_RELY1_OFF        0x72
#define SM_CMD_RELY1_ON         0x73
#define SM_CMD_RELY2_OFF        0x74
#define SM_CMD_RELY2_ON         0x75
#define SM_CMD_RELY3_OFF        0x76
#define SM_CMD_RELY3_ON         0x77
#define SM_CMD_RELY4_OFF        0x78
#define SM_CMD_RELY4_ON         0x79

#define SM_CMD_MOTOR_CW         0x80
#define SM_CMD_MOTOR_CCW        0x81
///Stepping Motor Degree
#define MOTOR_D20        0x00
#define MOTOR_D30        0x01
#define MOTOR_D40        0x02
#define MOTOR_D50        0x03
#define MOTOR_D60        0x04
#define MOTOR_D70        0x05
#define MOTOR_D80        0x06
#define MOTOR_D90        0x07
///Stepping Motor Speed
#define MOTOR_S20        0x00
#define MOTOR_S30        0x01
#define MOTOR_S40        0x02
#define MOTOR_S50        0x03
#define MOTOR_S60        0x04
#define MOTOR_S70        0x05
#define MOTOR_S80        0x06
#define MOTOR_S90        0x07

void sm_start (void);
void sm_end (void);
int sm_command (int cmd);
int sm_motor (int c, int d, int s);

#endif
