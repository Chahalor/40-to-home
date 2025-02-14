#!/bin/bash

# Parcourt tous les répertoires du dossier courant
for dir in */; do
	# Supprime le slash final du nom du répertoire
	dir=${dir%/}
	
	# Vérifie que c'est bien un répertoire
	[ -d "$dir" ] || continue
	
	# Création des dossiers s'ils n'existent pas
	mkdir -p "$dir/interface" "$dir/interne"

	# Définit les chemins des fichiers
	interface_file="$dir/interface/$dir.h"
	interne_file="$dir/internal/_$dir.h"

	# Crée les fichiers uniquement s'ils n'existent pas
	[ -f "$interface_file" ] || touch "$interface_file"
	[ -f "$interne_file" ] || touch "$interne_file"
done
