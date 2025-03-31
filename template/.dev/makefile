# Définir le compilateur et les options (on lie avec ncurses)
CC = gcc
CFLAGS = -Wall
LIBS = -lncurses

# Cible par défaut : compiler puis lancer l'interface
all: cli
	./cli

# Cible de compilation
cli: cli.c
	$(CC) $(CFLAGS) -o cli cli.c $(LIBS)

# Cible de nettoyage
clean:
	rm -f cli
