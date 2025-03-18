#!/bin/bash

# Main dir && variables definitions
DIR_SRC="src"
DIR_OBJ=".obj"
DIR_INTERNAL="_internal"
DIR_INTERFACE=""
DIR_INCLUDE="include"
EXEC_NAME=$(basename "$(pwd)")

# other variables
CC="cc"
CFLAGS="-Wall -Wextra -Werror"
DEBUGFLAGS=""

DIR_LIBFT="libft"

# nice but useless config
HEADER="# Big Header #"

# Check if DIR_SRC exists
if [ ! -d "$DIR_SRC" ]; then
	echo "❌ Erreur : Le dossier '$DIR_SRC' n'existe pas."
	exit 1
fi

# All lists used
MAKEFILE_SUPP_LIST=""
OBJ_ALL_LIST=""
INCLUDE_ALL="-I$DIR_INCLUDE -I$DIR_LIBFT"

# building the list of includes
for module in "$DIR_SRC"/*/; do
	if [ -d "$module" ]; then
		MODULE_NAME=$(basename "$module")
		INCLUDE_ALL+=" -I\$(DIR_SRC)/$MODULE_NAME"
	fi
done

# generating a makefile.supp for each module
for module in "$DIR_SRC"/*/; do
	if [ -d "$module" ]; then
		MODULE_NAME=$(basename "$module")
		MODULE_VAR="OBJ_${MODULE_NAME^^}"	# OBJ variable name in uppercase
		MAKEFILE_SUPP_LIST+=" ${module}makefile.supp"
		OBJ_ALL_LIST+=" \$($MODULE_VAR)"	# OBJ_ALL variable name in makefile
		SRC_INTERFACE=$(find "$module" -maxdepth 1 -name "*.c" | sed 's|^.*/||' | tr '\n' ' ')	# listing all .c files in the module directory
		SRC_INTERNAL=""
		if [ -d "$module/_internal" ]; then
			SRC_INTERNAL=$(find "$module/_internal" -name "*.c" | sed 's|^.*/||' | tr '\n' ' ')	# listing all .c files in the _internal directory
		fi

		# writing the makefile.supp file
		cat <<EOM > "$module/makefile.supp"
DIR_MODULE_${MODULE_NAME^^}		:= $MODULE_NAME
DIR_INTERFACE_${MODULE_NAME^^}	:= \$(DIR_MODULE_${MODULE_NAME^^})
DIR_INTERNAL_${MODULE_NAME^^}	:= \$(DIR_MODULE_${MODULE_NAME^^})/_internal

SRC_INTERFACE_${MODULE_NAME^^}	:= $SRC_INTERFACE
SRC_INTERNAL_${MODULE_NAME^^}	:= $SRC_INTERNAL

OBJ_${MODULE_NAME^^}			:= \$(addprefix \$(DIR_OBJ)/\$(DIR_INTERFACE_${MODULE_NAME^^})/, \$(SRC_INTERFACE_${MODULE_NAME^^}:.c=.o))
OBJ_${MODULE_NAME^^}			+= \$(addprefix \$(DIR_OBJ)/\$(DIR_INTERNAL_${MODULE_NAME^^})/, \$(SRC_INTERNAL_${MODULE_NAME^^}:.c=.o))

\$(DIR_OBJ)/\$(DIR_MODULE_${MODULE_NAME^^})/%.o: \$(DIR_SRC)/\$(DIR_MODULE_${MODULE_NAME^^})/%.c
	@mkdir -p \$(dir \$@)
	\$(CC) \$(CFLAGS) \$(DEBUGFLAGS) \$(INCLUDE_ALL) -c \$< -o \$@
EOM
		echo "✅ ${module}makefile.supp créé pour le module $MODULE_NAME !"
	fi
done

# writing the main Makefile
cat <<EOF > Makefile
$HEADER

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME		:= $EXEC_NAME

CC			:= $CC
CFLAGS		:= $CFLAGS
DEBUGFLAGS	:= $DEBUGFLAGS
DIR_SRC		:= $DIR_SRC
DIR_OBJ		:= $DIR_OBJ
INCLUDE_ALL	:=$INCLUDE_ALL

DIR_LIBFT	:= $DIR_LIBFT
LIBFT		:= \$(DIR_LIBFT)/libft.a

# Here we include all the makefile.supp files
include $MAKEFILE_SUPP_LIST

# all object files for the modules
OBJ_ALL := $OBJ_ALL_LIST

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm \$(NAME)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

\$(NAME): \$(LIBFT) \$(OBJ_ALL)
	\$(CC) \$(CFLAGS) \$(DEBUGFLAGS) \$(INCLUDE_ALL) \$^ \$(LIBFT) -o \$(NAME)

\$(LIBFT):
	@make -C \$(DIR_LIBFT) NO_HEADER=true

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -rf \$(DIR_OBJ)

fclean: clean
	rm -f \$(NAME)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs debug.pg

debug:
	\$(eval DEBUGFLAGS=\$(DEBUGFLAGS) -g3 -D DEBUG=1)
	@echo "\033[1;33m DEBUG MODE ACTIVATED \033[0m"


debug.fsanitize: debug
	\$(eval DEBUGFLAGS=\$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

debug.pg:
	\$(eval DEBUGFLAGS=\$(DEBUGFLAGS) -pg)

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

header:
	@echo "$HEADER"

norm:
	@errors=\$\$(norminette | grep "Error"); \\
	if [ -n "\$\$errors" ]; then \\
		echo "\$\$errors"; \\
		echo "\033[31m ❌ Norminette errors found \033[0m"; \\
	else \\
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \\
	fi
EOF

echo "✅ Makefile principal créé avec succès !"
