#!/bin/bash

set -e

echo "What do you want to set the resolution as:"
read res

echo -e "Set resolution as $res? [y/n]."
read confirm

case $confirm in
    y | Y | yes | Yes)
        echo "Creating mode $(gtf $res | grep -B 0 "Modeline" | awk '{printf $2}')..."
      
        until xrandr --newmode$(gtf $res | grep -B 0 "Modeline" | awk '{printf $1="";print $0}')
        do
            wait
        done
        echo "Mode $(gtf $res | grep -B 0 "Modeline" | awk '{printf $2}') created."
      
        xrandr --addmode eDP-1 $(gtf $res | grep -B 0 "Modeline" | awk '{print $2}')
        #xrandr --output eDP-1 --mode $(gtf $res | grep -B 0 "Modeline" | awk '{printf $2}')
        ;;

    n | no | N | No)
        echo "Disregard"
        ;;

    *)
        echo "what the fuck does that mean."
        ;;
esac
