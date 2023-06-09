#!/bin/bash
#
#

COMPRESS=0
PULL=0
CLEAN=0
args=()	


for arg in $@;
do
	if [[ "$arg" == "-z" ]] || [[ "$arg" == "--compress" ]]; then
		COMPRESS=1
	elif [[ "$arg" == "pull" ]]; then
		PULL=1
	elif [[ "$arg" == "clean" ]]; then
		CLEAN=1
	else
		args+=($arg)
	fi
done

pullall () {
	cd bdives-c && git pull --quiet
	cd ../bdives-py && git pull --quiet
	cd ../bdives-ps1 && git pull --quiet
	cd ../bdives-js && git pull --quiet
	cd ..
	echo "// All subs up to date..."
	echo //
	sleep 2
	return 0
}

packup () {
	tar -cf ./bdxves.tar ./bdives-*
	if [[ $COMPRESS -eq 1 ]]; then
		gzip -9 ./bdxves.tar
	fi

	if [[ -f "bdxves.tar" ]] || [[ -f "bdxves.tar.gz" ]]; then
		echo "// Created archive..."
		echo //
		sleep 2
	else
		echo "## There was a problem creating the archive..."
		echo 
	fi
}
echo ...

if [[ $PULL -eq 1 ]]; then
	pullall && packup
else
	packup
fi


if [[ $CLEAN -eq 1 ]]; then
	rm -rf ./bdives-*
	if [[ -d ./bdives-* ]]; then
		echo "// There was a problem removing the original directories..."
	else
		echo "// Removed original directories..."
		echo //
		sleep 2

	fi
fi
echo "** Done."
echo //
