#!/bin/bash

# Nombre total d'essais
nombre_essais=10
oui=4000

# Boucle pour exécuter le programme plusieurs fois
for ((j = 200; j <= oui; j++)); do

    for ((i = 1; i <= nombre_essais; i++)); do
        nombre_elements=$(shuf -i 1-5000 -n 1)

        ./PmergeMe $(shuf -i 1-100000 -n "$j" | tr "\n" " ") > "./log/$i.log"

        # Vérifie le code de retour du programme
        if [ $? -eq 1 ]; then
            printf "\033[1;31m %04d 1 (%04d)\n" $i $j
            printf "\033[1;31m %04d 1 (%04d)\n" $i $j
        else
            printf "\r\033[1;32m %04d 0 (%04d)" $i $j


            rm "./log/$i.log"
        fi
    done
done

