#include <stdio.h>
#include <unistd.h>

#define MAX_POSITIONS 5

// Structure pour enregistrer une position (ligne, colonne)
typedef struct {
    int row;
    int col;
} CursorPos;

CursorPos saved_positions[MAX_POSITIONS];

// Fonction pour sauvegarder la position actuelle du curseur
void save_position(int index) {
    if (index < 0 || index >= MAX_POSITIONS) return;
    // Utilisation des séquences ANSI pour obtenir la position actuelle
    printf("\033[s");
    saved_positions[index].row = 0; // Par défaut, vous devrez ajuster pour capturer la position exacte
    saved_positions[index].col = 0; // Par défaut, idem
}

// Fonction pour restaurer une position sauvegardée
void restore_position(int index) {
    if (index < 0 || index >= MAX_POSITIONS) return;
    // Utilisation des séquences ANSI pour restaurer la position
    printf("\033[u");
}

int main() {
    // Exemple d'utilisation
    save_position(0);  // Sauvegarde la position 0
    printf("Message à la première position\n");

	sleep(1);

    // Déplacer et afficher un autre message
    printf("\033[10;10H");
	save_position(1);  // Sauvegarde la position 1
    printf("Message à une autre position\n");
	
	sleep(1);

    // Restaurer la position 0
    restore_position(0);
    printf("Retour à la position 0 !\n");

	sleep(1);

    // Restaurer la position 0
    restore_position(1);
    printf("Retour à la position 1 !\n");

    return 0;
}
