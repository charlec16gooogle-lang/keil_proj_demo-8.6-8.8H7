#ifndef __ALARM_SYS_H
#define __ALARM_SYS_H

#include "main.h"

/* 把 main.c 里的宏定义搬过来，供灯光循环和判断使用 */
#define LED_COUNT 4U

/* 


用0，1，2定义 3 种工作模式，为了方便又用单词再定义一下 */
typedef enum {
    MODE_STANDBY = 0, /* 待机模式 */
    MODE_RUN     = 1, /* 运行模式 */
    MODE_ALARM   = 2  /* 报警模式 */
} AlarmMode_t;

/* 从 main.c 原封不动搬过来的函数声明 */
void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms);
void beep(uint32_t beep_ms);

/* 报警系统总控制函数声明 */
void alarm_sys_func(AlarmMode_t mode);

#endif