#/bin/bash
#
#
echo "creating dmg vol"
hdiutil create -o /tmp/Monterey -size 16384m -volname Monterey -layout SPUD -fs HFS+J
wait
echo "mounting installer to vol"
hdiutil attach /tmp/Monterey.dmg -noverify -mountpoint /Volumes/Monterey
wait
echo "creating install media"
sudo /Applications/Install\ macOS\ Monterey.app/Contents/Resources/createinstallmedia --volume /Volumes/Monterey --nointeraction
wait
echo; read -rsn1 -p "Press enter to continue"; echo
hdiutil eject -force /Volumes/Install\ macOS\ Monterey
wait
echo "converting to .cdr"
hdiutil convert /tmp/Monterey.dmg -format UDTO -o ~/Desktop/Monterey
wait