#!/bin/bash

echo -e "\n] shutdown  :     1)   Power off system via regular shutdown procedure \n] reboot    :     2)   Restart system via regular reboot procedure \n] halt      :     3)   Bring system and kernel to halt. Please don't pick this\n"
echo -e " Enter the number corresponding with your choice\n"
read choice

case $choice in
	1)
		echo "Are you sure? y/n"
		read answer
		if [ $answer == "y" ]
		then
			sudo poweroff
		else
			echo "stopped process"
		fi
		;;

	2)
		echo "Are you sure? y/n"
		read answer
		if [ $answer == "y" ]
		then
			sudo reboot
		else
			echo "stopped process"
		fi
		;;

	3)
		echo "Are you sure? y/n"
		read answer
		if [ $answer == "y" ]
		then
			sudo halt
		else
			echo "stopping process"
		fi
		;;
esac
