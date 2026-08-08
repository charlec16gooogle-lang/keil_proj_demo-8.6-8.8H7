#include "user_88_task.h"
#include "led.h"
#include "buzzer.h"

void user_88_task(void)
{
    uint8_t current_led = 1U;
    uint32_t delay_ms = 250U;
    uint8_t led_count = 4U;

    /* 作业三：依次控制 4 颗 LED闪的次数 */
    while (current_led <= led_count)
    {
        /* 第 2 个参数由blink_led改成current_led，实现 LED1 闪 1 次，LED2 闪 2 次... */
        blink_led(current_led, current_led, delay_ms);
        current_led++;
    }

    /* 作业一：原本这里的 beep(BEEP_MS); 被注释掉了，所以不写任何关/开蜂鸣器的指令 */
}