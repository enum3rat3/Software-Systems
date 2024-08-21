#!/bin/bash

if [ $1 ]
then

	if [ -e $1 ]
	then

		echo "------------ $1 Information ------------"
		echo "1. Inode Number: `stat --format=%i $1`"
		echo "2. No. of hardlinks: `stat --format=%h $1`"
		echo "3. UID: `stat --format=%i $1`"
		echo "4. GID: `stat --format=%g $1`"
		echo "5. Size: `stat --format=%s $1`"
		echo "6. Block Size: `stat --format=%B $1`"
		echo "7. No. of Blocks: `stat --format=%b $1`"
		echo "8. Time of last access: `stat --format=%x $1`"
		echo "9. Time of last modification: `stat --format=%y $1`"
		echo "10. Time of last change: `stat --format=%z $1`"
	else
		echo "$1 Doesn't exist"
	fi
else
	echo "./p9.sh file-name"
fi
