/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mmc.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <usb.h>

DECLARE_GLOBAL_DATA_PTR;

u32 get_board_rev(void)
{
	printf("[TINY4412] %s\n"," board_rev");
	return 0;
}

int exynos_init(void)
{
	printf("[TINY4412] %s\n", "exynos_init");
	return 0;
}

int board_usb_init(int index, enum usb_init_type init)
{
	printf("[TINY4412] %s\n", "usb_init");
	return 0;
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int exynos_early_init_f(void)
{
	printf("[TINY4412] %s\n", "early_init");
	return 0;
}
#endif
