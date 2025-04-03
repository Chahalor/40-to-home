#!/bin/bash

# cleaning the previous shit
rm -r **/*/makefile.mk Makefile

# Main dir && variables definitions
EXEC_NAME="$(basename "$(pwd)").a"

# other variables
CC="cc"
CFLAGS="-Wall -Wextra -Werror -MMD"
DEBUGFLAGS=""

DIR_SRC="src"
DIR_OBJ=".obj"
DIR_INTERNAL="_internal"
DIR_INTERFACE=""
DIR_INCLUDE="./"
# DIR_PRINTF="ft_printf"
# DIR_GNL="get_next_line"

# nice but useless config
HEADER="# Big Header #"

# Check if DIR_SRC exists
if [ ! -d "$DIR_SRC" ]; then
	echo "❌ Erreur : Le dossier '$DIR_SRC' n'existe pas."
	exit 1
# elif [ ! -d "$DIR_PRINTF" ]; then
# 	echo "❌ Erreur : Le dossier '$DIR_PRINTF' n'existe pas."
# 	exit 1
# elif [ ! -d "$DIR_GNL" ]; then
# 	echo "❌ Erreur : Le dossier '$DIR_GNL' n'existe pas."
# 	exit 1
fi

# All lists used
MAKEFILE_SUPP_LIST=""
OBJ_ALL_LIST=""
INCLUDE_ALL="-I$DIR_INCLUDE -I$DIR_LIBFT"

create_mk()
{
	module=$1
	if [ -d "$module" ]; then
		MODULE_NAME=$(basename "$module")
		INCLUDE_ALL+=" -I\$(DIR_SRC)/$MODULE_NAME"
		MODULE_VAR="OBJ_${MODULE_NAME^^}"	# OBJ variable name in uppercase
		MAKEFILE_SUPP_LIST+=" ${module}makefile.mk"
		OBJ_ALL_LIST+=" \$($MODULE_VAR)"	# OBJ_ALL variable name in makefile
		SRC_INTERFACE=$(find "$module" -maxdepth 1 -name "*.c" | sed 's|^.*/||' | tr '\n' ' ')	# listing all .c files in the module directory
		SRC_INTERNAL=""
		if [ -d "$module/_internal" ]; then
			SRC_INTERNAL=$(find "$module/_internal" -type f -name "*.c" | sed "s|$module/_internal/||" | tr '\n' ' ')
		fi

		# writing the makefile.mk file
		cat <<EOM > "$module/makefile.mk"
DIR_MODULE_${MODULE_NAME^^}		:= $MODULE_NAME
DIR_INTERFACE_${MODULE_NAME^^}	:= \$(DIR_MODULE_${MODULE_NAME^^})
DIR_INTERNAL_${MODULE_NAME^^}	:= \$(DIR_MODULE_${MODULE_NAME^^})/_internal

SRC_INTERFACE_${MODULE_NAME^^}	:= $SRC_INTERFACE
SRC_INTERNAL_${MODULE_NAME^^}	:= $SRC_INTERNAL

OBJ_${MODULE_NAME^^}			:= \$(addprefix \$(DIR_OBJ)/\$(DIR_INTERFACE_${MODULE_NAME^^})/, \$(SRC_INTERFACE_${MODULE_NAME^^}:.c=.o))
OBJ_${MODULE_NAME^^}			+= \$(addprefix \$(DIR_OBJ)/\$(DIR_INTERNAL_${MODULE_NAME^^})/, \$(SRC_INTERNAL_${MODULE_NAME^^}:.c=.o))

\$(DIR_OBJ)/\$(DIR_MODULE_${MODULE_NAME^^})/%.o: \$(DIR_SRC)/\$(DIR_MODULE_${MODULE_NAME^^})/%.c
	@mkdir -p \$(dir \$@)
	\$(CC) \$(CFLAGS) \$(DEBUGFLAGS) -I\$(DIR_SRC)/\$(DIR_MODULE_${MODULE_NAME^^})/_internal \$(INCLUDE_ALL) -c \$< -o \$@
EOM
		echo "✅ ${module}makefile.mk créé pour le module $MODULE_NAME !"
	fi
}

# generating a makefile.mk for each module
for module in "$DIR_SRC"/*/; do
	create_mk "$module"
done
# for module in "$DIR_PRINTF"/; do
# 	create_mk "$module"
# done
# for module in "$DIR_GNL"/; do
# 	create_mk "$module"
# done

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
DIR_BONUS	:= $DIR_BONUS
INCLUDE_ALL	:=$INCLUDE_ALL

# Here we include all the makefile.mk files
include $MAKEFILE_SUPP_LIST

SRC_MAIN	:=

# all object files for the modules
OBJ_MAIN	:= \$(addprefix \$(DIR_OBJ)/, \$(SRC_MAIN:.c=.o))
OBJ_ALL		:=$OBJ_ALL_LIST \$(OBJ_MAIN)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm \$(NAME)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

\$(NAME): \$(OBJ_ALL)
	@ar rcs \$(NAME) \$(OBJ_ALL)
	@ranlib \$(NAME)

\$(DIR_OBJ)/%.o: \$(DIR_SRC)/%.c
	@mkdir -p \$(DIR_OBJ)
	\$(CC) \$(CFLAGS) \$(DEBUGFLAGS) \$(INCLUDE_ALL) -c $< -o \$@

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -rf \$(DIR_OBJ)
# @make clean -C \$(DIR_LIBFT)
# @make clean -C \$(DIR_BONUS)

fclean: clean
	rm -f \$(NAME)
# @make fclean -C \$(DIR_LIBFT)
# @make fclean -C \$(DIR_BONUS)

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

.PHONY: header norm crazy test update # install uninstall

header:
	@echo "$HEADER"

norm:
	@errors=\$\$(norminette --use-gitignore | grep "Error"); \\
	if [ -n "\$\$errors" ]; then \\
		echo "\$\$errors"; \\
		echo "\033[31m ❌ Norminette errors found \033[0m"; \\
	else \\
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \\
	fi

# INSTALL_DIR = \$(HOME)/.local/bin

# install:
# 	mkdir -p \$(INSTALL_DIR)
# 	cp \$(NAME) \$(INSTALL_DIR)/
# 	chmod +x \$(INSTALL_DIR)/\$(NAME)
# 	echo "\033[1;32m ✅ \$(NAME) installed to \$(INSTALL_DIR) \033[0m"; \\

# uninstall:
# 	rm -rf \$(INSTALL_DIR)/\$(NAME)
# 	echo "\033[1;32m ✅ \$(NAME) uninstalled from \$(INSTALL_DIR) \033[0m";

update:
	if [ -f ./auto.sh ]; then \\
		echo "\033[1;33m Updating Makefile... \033[0m"; \\
	else \\
		echo "\033[1;31m auto.sh not found, please add the script to automate the update \033[0m"; \\
		exit 1; \\
	fi
	./auto.sh
	echo "\033[1;32m ✅ Makefile updated \033[0m";

.SILENT:
	@echo "\033[1;33m SILENT MODE ACTIVATED \033[0m

EOF

echo "✅ Makefile principal créé avec succès !"
