#!/bin/bash

set -e

echo "Enter X value:"
read x
echo "Enter Y value:"
read y
echo "Enter Hz value:"
read hz
echo
name="${x}x${y}"
sleep 0.5

resmode="$name$(gtf $x $y $hz | grep -B 0 "Modeline" | awk '{printf $1="";printf $2="";print $0}')"

echo "Set resolution at ${name}_${hz}? y/n:"
read confirm
sleep 1

case $confirm in
    y | Y | yes | Yes)
        echo "Creating mode $name..."
        xrandr --newmode $resmode
        exit

        echo "Created mode: ${name}_${hz}."

        xrandr --dryrun --addmode eDP-1 $name

        echo "Force set new mode as resolution? y/n:"
        read ans
        case $ans in
            y | Y | yes | Yes)
                echo "Forcing mode..."
                sleep 1
                xrandr --output eDP-1 --mode $name
                echo "Done."
                ;;
            n | N | no | No)
                echo "Exiting."
                exit
                ;;
            *)
                echo "Argument not recognised. Exiting."
                exit
                ;;
        esac
        ;;

    n | no | N | No)
        echo "Disregard"
        ;;

    *)
        echo "what the fuck does that mean."
        ;;
esac
