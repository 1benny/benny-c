#!/bin/bash

ani=( Updating Updating. Updating.. Updating... Updating... Updating.. Updating. )

echo Enter release name:
read release

sleep 1

echo Configuring package manager source...

echo "writing $release to apt source..."
sleep 1

rm -f /etc/apt/sources.list

echo "deb http://deb.debian.org/debian/ $release main non-free contrib" >> /etc/apt/sources.list
echo "deb-src http://deb.debian.org/debian/ $release main non-free contrib" >> /etc/apt/sources.list
sleep 1

echo Updated sources...
echo " "

echo "run apt update & upgrade? y/n"
read apt_update

case $apt_update in
    "y")
        apt -qq update --yes && apt -qq upgrade --yes
        while [ $? != 0 ]
        do
            for i in "${ani[@]}"
            do
                    echo -ne "\r$i"
                    sleep 0.4
            done
        done
        ;;

    "n")
        echo Continuing...
        ;;
esac