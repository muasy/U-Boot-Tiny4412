/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/power.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <dm.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <power/max77686_pmic.h>
#include <errno.h>
#include <mmc.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#include <samsung/misc.h>

DECLARE_GLOBAL_DATA_PTR;

u32 get_board_rev(void)
{
	return 0;
}

static void board_gpio_init(void)
{
	/* USB复位 */
	gpio_request(EXYNOS4X12_GPIO_M24, "USB4604 Reset");

	/* KEY */
	gpio_request(EXYNOS4X12_GPIO_X32, "KEY 1");
	gpio_request(EXYNOS4X12_GPIO_X33, "KEY 2");
	gpio_request(EXYNOS4X12_GPIO_X34, "KEY 3");
	gpio_request(EXYNOS4X12_GPIO_X35, "KEY 4");
	
}

int exynos_init(void)
{
	board_gpio_init();

	return 0;
}

#ifdef CONFIG_USB_GADGET
static int s5pc210_phy_control(int on)
{
	return 0;
}

struct dwc2_plat_otg_data s5pc210_otg_data = {
	.phy_control	= s5pc210_phy_control,
	.regs_phy	= EXYNOS4X12_USBPHY_BASE,
	.regs_otg	= EXYNOS4X12_USBOTG_BASE,
	.usb_phy_ctrl	= EXYNOS4X12_USBPHY_CONTROL,
	.usb_flags	= PHY0_SLEEP,
};
#endif

int board_usb_init(int index, enum usb_init_type init)
{
	gpio_direction_output(EXYNOS4X12_GPIO_M24, 0);
   	gpio_direction_output(EXYNOS4X12_GPIO_M24, 1);
	
	return dwc2_udc_probe(&s5pc210_otg_data);
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int exynos_early_init_f(void)
{
	return 0;
}
#endif
