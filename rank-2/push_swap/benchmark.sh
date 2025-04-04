#!/bin/bash

N_ARGS=$1
if [ -z "$N_ARGS" ]; then
	N_ARGS=100
fi
ITERATIONS=$2
if [ -z "$ITERATIONS" ]; then
	ITERATIONS=500
fi
EXECUTABLE=$3
if [ -z "$EXECUTABLE" ]; then
	EXECUTABLE=./push_swap
fi

AVRG=0
MAX=0
NB_FAIL=0
NB_SUCCESS=0

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
RESET='\033[0m'

printf "\033[0mstarting push_swap benchmark\n"
printf "\033[0m\e[?25l---------------------------------\n"
printf "\n\033[33m[ITERATION]: ${ITERATIONS}\n[NB_ARGS]: ${N_ARGS}\n\n\033[0m"

for i in $(seq 1 ${ITERATIONS});
do
	ARG="$(echo $(python3 rand_numbers.py ${N_ARGS}))"
	OK=$(${EXECUTABLE} "${ARG}" | ./checker_linux "${ARG}")
	COUNT=$(${EXECUTABLE} "${ARG}" | wc -l)
	if echo "$OK" | grep -q "KO"; then
		if echo "$OK" | grep -q "Error"; then
			printf "${RED}Error: ${RESET}invalid argument\n  ${OK}\n"
		else
			printf "${RED}Error${RESET}: invalide sort for the [$(echo "${ARG}")] list\n"
		fi
		NB_FAIL=$((NB_FAIL + 1))
	else
		AVRG=$((AVRG + COUNT))
		NB_SUCCESS=$((NB_SUCCESS + 1))
		if [ ${COUNT} -gt ${MAX} ]; then
			MAX=${COUNT}
			printf "push_swap score: \e[31m$[COUNT] (new max)\e[0m\n"
		else
			printf "push_swap score: \e[32m$[COUNT] [i: $i]\e[0m\r"
		fi
	fi
done

printf "\n\n\033[33m---------------------------------\n"
printf "results:\n"

# printing average
if [ ${NB_SUCCESS} -eq 0 ]; then
	printf "  ${RED}Error${RESET}: no valid sort\n"
elif [ ${NB_FAIL} -gt 0 ]; then
	printf "  max: ${BLUE}${MAX}\n${RESET}"
	AVRG=$(echo "scale=1; ${AVRG}/${NB_SUCCESS}" | bc)
	printf "  ${YELLOW}average${RESET}: \033[34m$AVRG\n"
	printf "  ${YELLOW}invalid sort${RESET}: ${BLUE}${NB_FAIL}/${ITERATIONS}${RESET}\n"
else
	printf "  max: ${BLUE}${MAX}\n${RESET}"
	AVRG=$(echo "scale=1; ${AVRG}/${NB_SUCCESS}" | bc)
	printf "  ${YELLOW}average${RESET}: \033[34m$AVRG\n"
fi

printf "\033[33m---------------------------------\n\e[?25h\n"
