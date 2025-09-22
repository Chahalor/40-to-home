#!/bin/bash

if [ "$#" -ne 3 ]; then
	echo "Usage: $0 <pattern> <include> <exclude>"
	exit 1
fi

PATERN="$1"
INCLUDE="$2"
EXCLUDE="$3"

wordle_grep() {
	grep -iE "$1" words.txt | grep -iE "$2" | grep -viE "$3"
}

wordle_grep "$PATERN" "$INCLUDE" "$EXCLUDE"