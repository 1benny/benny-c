#!/bin/bash

pkgs=(blueman bluetooth bluez broadcom-sta-source broadcom-sta-dkms cherrytree ipheth-utils git git-credential-oauth ssh network-manager net-tools synaptic usbmuxd wireless-tools wpasupplicant qterminal)

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
        echo "Working..."
        sleep 2
        apt -qq update --yes && apt -qq upgrade --yes
        ;;
    "n")
        echo Continuing...
esac

printf "Install all previously used packages? y/n:  " >&2
read -r answer

case $answer in
    "n")
        echo "Finishing up..."
        apt autoremove
        ;;
    "y")
        echo "starting install for  ~>"
        for package in "${pkgs[@]}"
        do
            echo $package
        done
        ;;
esac
echo "Continue?"
read -r answer2 
case $answer2 in
    "n")
        echo "Done."
        apt autoremove
        ;;
    "y")
        echo "Starting..."
        for package in "${pkgs[@]}"
        do
            apt install $package
        done
        ;;
esac

echo "Finished..."