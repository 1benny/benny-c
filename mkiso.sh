#!/bin/bash

echo ########################################################################################

echo // "~~ Making new volume: 'Ventura'..."
hdiutil create -o /tmp/Ventura -size 13000mb -volname Ventura -layout SPUD -fs HFS+J
wait
echo "// ~~ Success..."
sleep 2
echo "// ~~ Mounting new volume..."
hdiutil attach /tmp/Ventura.dmg -noverify -mountpoint /Volumes/Ventura
wait
echo "// ~~ Success..."
sleep 1
echo "// ~~ Using media-install creator..."
sudo /Applications/Install\ macOS\ Ventura.app/Contents/Resources/createinstallmedia --volume /Volumes/Ventura --nointeraction
wait
echo "// ~~ Success..."
sleep 2
echo "// ###### Please ensure that the hardware is not loose or falling or some shit for the purpose of avoiding data failure during unmount ######"
echo; read -rsn1 -p "Press enter to continue"; echo
hdiutil eject -force /Volumes/Install\ macOS\ Ventura/
wait
echo "// ~~ Writing .CDR image file to /Desktop..."
sleep 1
hdiutil convert /tmp/Ventura.dmg -format UDTO -o ~/Desktop/Ventura
wait
echo "// ~~ Success..."
echo "###### Confirm the .CDR file is present in ~/Desktop before continuing. ######"
read -rsn1 -p "Press enter to continue"; echo
echo "// ~~ Converting file to .iso..."
my -v ~/Desktop/Ventura.cdr ~/Desktop/Ventura.iso
wait
echo "// ~~ Success..."
sleep 1
echo "// ~~ Cleaning up files: You're welcome..."
sleep 1
rm -fv /tmp/Ventura.dmg
wait
echo; echo "################################################################"; echo
echo "Done..."