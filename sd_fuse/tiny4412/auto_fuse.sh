#!/bin/bash

#EXEC="sd_fusing.sh"
EXEC="fast_fusing.sh"
SD_PATH="/dev/sdd"
FUSE_PATH="./${EXEC}"

if [ -e ${FUSE_PATH} ]
then
	if [ -e ${SD_PATH} ]
	then
		${FUSE_PATH} ${SD_PATH}
	else
		echo "Please Insert SD!"
	fi
else
	echo "File Not Exist!"
fi
