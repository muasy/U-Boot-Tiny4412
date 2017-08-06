#
# Copyright (C) 2011 Samsung Electronics Co., Ltd.
#              http://www.samsung.com/
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
####################################

if [ -z $1 ]
then
    echo "usage: ./mk_uboot.sh <SD Reader's device file>"
    exit 0
fi

if [ -b $1 ]
then
    echo "$1 reader is identified."
else
    echo "$1 is NOT identified."
    exit 0
fi

####################################
#<verify device>

BDEV_NAME=`basename $1`
BDEV_SIZE=`cat /sys/block/${BDEV_NAME}/size`

if [ ${BDEV_SIZE} -le 0 ]; then
	echo "Error: NO media found in card reader."
	exit 1
fi

if [ ${BDEV_SIZE} -gt 32000000 ]; then
	echo "Error: Block device size (${BDEV_SIZE}) is too large"
	exit 1
fi

####################################
# fusing file

bl1_name="E4412_N.bl1.bin"
bl2_name="tiny4412-spl.bin"
uboot_name="u-boot.bin"
tzsz_name="E4412_tzsw.bin"

####################################
# fusing images

signed_bl1_position=1
bl2_position=17
uboot_position=49
tzsw_position=2097

#<BL1 fusing>
echo "---------------------------------------"
echo "BL1 fusing"
dd iflag=dsync oflag=dsync if=$bl1_name of=$1 seek=$signed_bl1_position

#<BL2 fusing>
echo "---------------------------------------"
echo "BL2 fusing"
dd iflag=dsync oflag=dsync if=$bl2_name of=$1 seek=$bl2_position

#<u-boot fusing>
echo "---------------------------------------"
echo "u-boot fusing"
dd iflag=dsync oflag=dsync if=$uboot_name of=$1 seek=$uboot_position

#<TrustZone S/W fusing>
echo "---------------------------------------"
echo "TrustZone S/W fusing"
dd iflag=dsync oflag=dsync if=$tzsz_name of=$1 seek=$tzsw_position


#<flush to disk>
sync

####################################
#<Message Display>
echo "---------------------------------------"
echo "U-boot image is fused successfully."
echo "Eject SD card and insert it again."

