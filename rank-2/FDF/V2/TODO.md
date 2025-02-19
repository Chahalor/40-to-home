# TODO: FdF V2

## Mandatory

### SRC
 - [X] tracer l autre moitier des ligne entre les point
 - [X] mettre en place le degrader de couleur
  - [X] ~~passez les couleur en du RGB avec une struct~~ aborted
  - [X] faut le min/max de la map
  - [X] faut un fonction pour calculer les couleur pour les ligne
 - [X] mettre args.c a la norm
 - [X] regler la segfault de isometric()
 - [X] mettre a jour les docs 
 - [X] enverser les axe de la rotation
 - [X] optimiser le pieline de drawing !!!
 - [X] affiner la condiation avant de put un pixel pour pas que sa deborde
 - [X] rework interpolate pour que les couleurs sois pas random
 - [X] finish separing all nodule in is own module
 - [X] afficher les toutes petites map
 - [X] verifier que nb_high de fdf.map != 0
 - [ ] rotation sur les toute petite map avec de petite valeurs

### Headers

### Make

### Other
 - [X] regler d_print_pos() pour qu il print les double

## Bonus

### SRC
 - [ ] ~~faut ajouter une option pour le titre~~
 - [X] la fonction pour le -h/--help
 - [X] le deuxieme projection
  - [ ] regler les rotation avec
 - [X] le zoom est douteux, a changer

### Headers

### Make

### Other
 - [ ] ~~avoir un icon d app custom~~ aborted


## Avant de rendre
- ```bash
  norminette src/ includes/ libft/ | grep Error
  ```
 - check leak
 - verifier avec des **BIG** map et des map fausse
 - verifier que les 42 git est pas vide

## Note
 - si la fonction est pas def compile le fichier (et oui jamy)
 - l erreur c est toi (si si)