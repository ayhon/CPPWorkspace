#!/bin/bash

EXECUTABLE="masterminer"
DIR="$(pwd)"
if [ -e "$EXECUTABLE" ]; then
	g++ -g -o masterminer *.cpp
fi

case $OSTYPE in

	darwin)
	open -a Terminal "$DIR/$EXECUTABLE";;

	linux-gnu)
	alacritty -e "$DIR/$EXECUTABLE" --working-directory "$DIR";;

	*)
	open -a Terminal "$DIR/$EXECUTABLE";;
esac

