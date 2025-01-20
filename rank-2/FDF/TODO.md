# TODO FdF

## Mandatory

### SRC
 - [X] verifier que le parsing est fonctionnel
 - [X] comprendre comment fonctionne la minilibX
 - [X] regler les pbl de return de parsing_map()
 - [X] set up le gestionnaire de windows
 - [X] transformateur de t_map et img (fonctionne mais en 2d)
 - [X] comprendre la 3d isometric
 - [ ] gerer les retour de toute les fonction dans fdf()
 - [X] faire fonctioner la 3d isometric ([lien](https://www.youtube.com/watch?v=go1qrWFw_bs), autre [lien](https://www.youtube.com/watch?v=04oQ2jOUjkU))
 - [ ] faire fonctionner le degrader de couleur du fdf, avec une couleur de depart, darriver qui degrade en fonction de la hauteur max
 - [ ] changer les offset dans map_drawer() pur rendre sa modulaire
 - [ ] regler les truc qui sont jamais effeacer sur la map quqnd on zoom/dezoom

### Make
 - [X] faire que les option de debug compile correctement le minilibX
 - [X] ajouter un logo au header du makefile
 - [X] refaire le titre du makefile
 - [X] faire en sort que les espace apres les Rules du header soit en bonne quntiter pour pas le casser
 - [X] la barre de chargement de la compilation mange la ligne au dessus d elle quoi qu elle soit a regler (thx ugwentzi)

### Other
 - ...

## Bonus
 - [ ] l affichade du header du programme dans le terminal (pas dans le makefile mais le binaire)
 - [ ] ajouter une option pour definir les couleur d arriver et de depart
 - [X] empecher la segfault si on zoom/dezoom trop /!\
 - [X] prendre en compte les variable rotationx/y de t_data
 - [ ] une touche pour reset le model
 - [ ] augmenter la denciter de pixel avec le zoom
 - [ ] faire en sorte que bouger la souris avec clique gauche down bouge le modele avec la souris (mouse_move_hook()) maybe remplacer sa pour la rotation et les fleche pour la translation (good idea)


### SRC
 - ...

### Make
 - ...

### Avant de rendre
 - [ ] verifier que -h ou --help est bien a jour

## Other
 - si le makefile te dit que tel ou tel fonction est pas def regarde si tu compile le fichier bouffon, panique apres (so true)
 - ordre pour fermer la mlx: destroy_window puis destroy_display.
