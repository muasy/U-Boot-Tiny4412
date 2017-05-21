#!/bin/bash

echo "Clean Configuration File..."
make distclean

echo "Clean Obj..."
make clean

echo "Load Configuration File..."
make tiny4412_defconfig

echo "make..."
make ARCH=arm CROSS_COMPILE=arm-linux-

echo "Update tiny4412_defconfig..."
cp .config configs/tiny4412_defconfig

echo "Done..."

