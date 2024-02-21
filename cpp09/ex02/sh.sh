#!/bin/bash
nombre_essais=1
oui=4000
for ((j = 1; j <= oui; j++)); do
    for ((i = 1; i <= nombre_essais; i++)); do
        # ./PmergeMe $(shuf -i 1-100000 -n "$j" |  tr "\n" " ") > /dev/null
        # ./PmergeMe $(shuf -i 1-100000 -n "$j" |  tr "\n" " ")
        valgrind ./PmergeMe $(shuf -i 1-100000 -n "$j" |  tr "\n" " ")
        if [ $? -eq 1 ]; then
            printf "\033[1;31m %04d 1\n" $j
        else
            printf "\033[1;32m %04d 0 \n" $j
        fi
    done
done

