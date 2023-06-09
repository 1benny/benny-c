#!/bin/bash
#
#

bar_size=50
done_char="#"
todo_char="-"
bar_scale=2

current="$1"
total="$2"

percent=$(cat /sys/class/power_supply/BAT0/capacity)
done=$(bc <<< "scale=0; $bar_size * $percent / 100" )
todo=$(bc <<< "scale=0; $bar_size - $done" )

done_sub=$(printf "%${done}s" |tr " " "#")
todo_sub=$(printf "%${todo}s" |tr " " "-")

echo
echo -e "\r  [${done_sub}${todo_sub}]-[${percent}%]"
echo
