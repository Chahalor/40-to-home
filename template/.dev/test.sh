#!/bin/bash

# Définir la position cible pour la barre (ligne 10, colonne 1)
target_line=10
target_col=1

# Longueur de la barre
bar_length=50

for progress in $(seq 0 100); do
	# Déplacer le curseur à la position souhaitée
	tput cup $target_line $target_col
	
	# Calculer la partie remplie et la partie vide de la barre
	filled=$(( progress * bar_length / 100 ))
	empty=$(( bar_length - filled ))
	bar=$(printf "%0.s#" $(seq 1 $filled))
	spaces=$(printf "%0.s " $(seq 1 $empty))
	
	# Effacer la ligne (optionnel si vous voulez vous assurer qu'il n'y a pas d'anciens caractères)
	tput el
	
	# Afficher la barre de chargement
	printf "Progression : [%s%s] %d%%" "$bar" "$spaces" "$progress"
	
	# Temporisation pour visualiser l'animation
	sleep 0.1
done

# Remettre le curseur à la ligne suivante après la barre
echo ""
