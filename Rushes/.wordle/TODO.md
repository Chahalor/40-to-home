# **__Rushe__: Wordle**

## __Internal__

### parsing

#### args
 - [ ] we can to handle a -h/--help (not mandatory)
 - [ ] adding an option with a custome dico ???

#### dico
 - [ ] every line is a word (gnl ???)
 - [ ] a la generation de la game, lire le dico jusqu au nb choisi (less alloc)

### user input
 - [ ] should only be asii char
 - [ ] max 5 letter
 - [ ] no space
 - [ ] mode raw tout control every thing

### Game

### word
 - [ ] choose a random world bettween 0 and dico_len
 - [ ] read the dico until the choosen one
 - [ ] send the word to the user

### user input
 - [ ] should only have the possiblility to type letter (a-z/A-Z)
 - [ ] can delete a letter
 - [ ] like the differente button with the  good function

### cursor handle
 - [ ] get the user click coord
 - [ ] check if the coord correspond to a button
	- [ ] is a button: do the correcte action. Otherwith ignore the input


## __interface__

### Header
 - [ ] clear the cmd
 - [ ] show the program header at every new game
 - [ ] some button for the option
	- [ ] start a game
	- [ ] change dico
	- [ ] quit

### Game
 - [ ] display the actual grid
 - [ ] a prompt area so the user can input here
 - [ ] at every press on ENTER (+5 valide letter input) show how the word match

### cursor
 - [ ] add some clicable button so the user can: 
	- [ ] restart a game
	- [ ] exit the program
	- [ ] get an hint (maybe not)
	- [ ] change the dico (dangerous)

## __other__

...