#include "alarm_sys.h"
#include "led.h"
#include "buzzer.h"

/* ----------------- 从 main.c 移进来的基础函数 ----------------- */

void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms)
{
  uint16_t i = 0U; /* 循环计数变量 */

  /* if 判断：LED 编号只允许 1~4 */
  if (led_num > LED_COUNT)
  {
    return; /* return 直接结束当前函数 */
  }

  /* for 循环：初始化; 判断条件; 每次循环后执行 */
  for (i = 0U; i < times; i++)
  {
    led_on(led_num);          /* 点亮指定 LED */
    HAL_Delay(delay_ms);      /* 延时一段时间 */
    led_off(led_num);         /* 熄灭指定 LED */
    HAL_Delay(delay_ms);
  }
}

void beep(uint32_t beep_ms)
{
  buzzer_on();          /* 打开蜂鸣器 */
  HAL_Delay(beep_ms);   /* 保持响一段时间 */
  buzzer_off();         /* 关闭蜂鸣器 */
}


/* ----------------- 作业四的alarm_sys_func 不同模式切换和反应结果 ----------------- */

void alarm_sys_func(AlarmMode_t mode)
{
    uint8_t current_led = 1U;

    /* switch 根据传入的 mode 选择执行那个模式对应的代码 */
    switch (mode)
    {
        case MODE_STANDBY:
            /* 待机模式：流水灯不亮，蜂鸣器不响 */
            for (uint8_t i = 1U; i <= LED_COUNT; i++)
            {
                led_off(i); /* 灯全部熄灭 */
            }
            buzzer_off();   /* 蜂鸣器关闭 */
            HAL_Delay(100); 
            break;

        case MODE_RUN:
            /* 运行模式：只有流水灯正常速度（250ms）运转 */
            while (current_led <= LED_COUNT)
            {
                blink_led(current_led, 1, 250);
                current_led++;
            }
            break;

        case MODE_ALARM:
            /* 报警模式：流水灯加速（80ms），蜂鸣器发声（100ms）--自己定义的速度和发声时间 */
            while (current_led <= LED_COUNT)
            {
                blink_led(current_led, 1, 80);
                beep(100); /* 蜂鸣器在这里被调用报警 */
                current_led++;
            }
            break;

        default:
            break;
    }
}