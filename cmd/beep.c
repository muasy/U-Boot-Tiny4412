/*
 * Copyright (C) 2017 SY <1530454315@qq.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <dm.h>
#include <pwm.h>
#include <asm/gpio.h>
#include <backlight.h>

DECLARE_GLOBAL_DATA_PTR;

static int do_beep(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	uint channel;
	uint period_ns;
	uint duty_ns;
	struct udevice *dev;
	int ret;
	bool enable;

	if (argc < 4) {
		return CMD_RET_USAGE;	
	}
	channel = simple_strtoul(argv[1], NULL, 10);
	period_ns = simple_strtoul(argv[2], NULL, 10);
	duty_ns = simple_strtoul(argv[3], NULL, 10);

	ret = uclass_get_device(UCLASS_PWM, 0, &dev);
	if (ret) {
		return cmd_process_error(cmdtp, ret);
	}

	pwm_set_enable(dev, channel, false);
	
	gpio_set_pull(EXYNOS4X12_GPIO_D00, S5P_GPIO_PULL_NONE);
	gpio_cfg_pin(EXYNOS4X12_GPIO_D00, S5P_GPIO_FUNC(0x2));

	ret = pwm_set_config(dev, channel, period_ns, duty_ns);
	if (ret) {
		return cmd_process_error(cmdtp, ret);
	}
	
	enable = (period_ns) ? true : false;
	ret = pwm_set_enable(dev, channel, enable);

	return cmd_process_error(cmdtp, ret);
}

U_BOOT_CMD(
	beep, 4, 1, do_beep,
	"Control tiny4412 boards beep device!",
	"beep [channel] [period_ns] [duty_ns]"
);
