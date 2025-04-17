#!/bin/bash

INPUT_FILE="dico_fr.txt"
OUTPUT_FILE="dico_fr_5.txt"

# Crée ou vide le fichier de sortie
> "$OUTPUT_FILE"

# Lire le fichier, extraire les mots de 5 lettres, et les écrire dans le fichier de sortie
grep -oE '\b[a-zA-Z]{5}\b' "$INPUT_FILE" | tr '[:upper:]' '[:lower:]' | sort -u > "$OUTPUT_FILE"
