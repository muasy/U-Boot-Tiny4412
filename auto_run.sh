#!/bin/bash

echo "Clean Configuration File..."
make distclean

echo "Clean Obj..."
make clean

echo "Load Configuration File..."
make tiny4412_defconfig

echo "make..."
make CROSS_COMPILE=arm-linux-

