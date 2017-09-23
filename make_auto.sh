#!/bin/bash

echo "-----------------------------------------------------"
echo "Auto Backup Config..."
cp .config tiny4412_config

echo "-----------------------------------------------------"
echo "make..."
make arch=arm

echo "-----------------------------------------------------"
echo "Done..."

