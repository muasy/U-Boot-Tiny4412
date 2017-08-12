#!/bin/bash

# Author  : SY
# Version : V1.0.0
# Date    : 2017-7-16 10:43:18
# brief   : Auto Sync To GitHub

echo "----------------------------------------"
git add -A

echo "Input Message:"
read MESSAGE
if [ -z $MESSAGE ];
then
        MESSAGE="update"
fi
time="`date +%F` `date +%T`"

_COMMIT="[$time]<$MESSAGE>"
echo $_COMMIT

echo "----------------------------------------"
git commit -m "[$time]<$MESSAGE>"

git push

echo "----------------------------------------"
echo "Done!"
