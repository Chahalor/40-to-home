#  \
# ╔════════════════════════════════════════════════════════════════════════════════════════════╗
# ║                                                                                            ║
# ║       ________        ___  ___          ___          ___               ________            ║
# ║      |\   __  \      |\  \|\  \        |\  \        |\  \             |\   __  \           ║
# ║      \ \  \|\  \     \ \  \ \  \       \ \  \       \ \  \            \ \  \|\  \          ║
# ║       \ \   ____\     \ \   __  \       \ \  \       \ \  \            \ \  \ \  \         ║
# ║        \ \  \___|      \ \  \ \  \       \ \  \       \ \  \____        \ \  \ \  \        ║
# ║         \ \__\          \ \__\ \__\       \ \__\       \ \_______\       \ \_______\       ║
# ║          \|__|           \|__|\|__|        \|__|        \|_______|        \|_______|       ║
# ║                                                                                            ║
# ║    By: nduvoid <nduvoid@student.42mulhouse.fr>                                             ║
# ║    A 42 cursus Project                                                                     ║
# ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

DIR_MANDATORY	:= philo
DIR_BONUS 		:= philo_bonus
DIR_BIN			:= .bin

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header mandatory

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

mandatory: $(DIR_BIN)
	@make -C $(DIR_MANDATORY) $(MAKEFLAGS)
	@cp $(DIR_MANDATORY)/philo .bin/philo

bonus: $(DIR_BIN)
	@make -C $(DIR_BONUS) $(MAKEFLAGS)
	@cp $(DIR_BONUS)/philo_bonus .bin/philo_bonus

${DIR_BIN}:
	@mkdir -p $(DIR_BIN)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@make -C $(DIR_MANDATORY) clean $(MAKEFLAGS)
	@make -C $(DIR_BONUS) clean $(MAKEFLAGS)
#@make clean -C $(DIR_LIBFT)

fclean:
	@make -C $(DIR_MANDATORY) fclean $(MAKEFLAGS)
	@make -C $(DIR_BONUS) fclean $(MAKEFLAGS)
	@rm -rf $(DIR_BIN)
#@make fclean -C $(DIR_LIBFT)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

# ...

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: header norm crazy test install uninstall update hellgrind

header:
	@echo " \
╔════════════════════════════════════════════════════════════════════════════════════════════╗\n \
║                                                                                            ║\n \
║       ________        ___  ___          ___          ___               ________            ║\n \
║      |\   __  \      |\  \|\  \        |\  \        |\  \             |\   __  \           ║\n \
║      \ \  \|\  \     \ \  \ \  \       \ \  \       \ \  \            \ \  \|\  \          ║\n \
║       \ \   ____\     \ \   __  \       \ \  \       \ \  \            \ \  \ \  \         ║\n \
║        \ \  \___|      \ \  \ \  \       \ \  \       \ \  \____        \ \  \ \  \        ║\n \
║         \ \__\          \ \__\ \__\       \ \__\       \ \_______\       \ \_______\       ║\n \
║          \|__|           \|__|\|__|        \|__|        \|_______|        \|_______|       ║\n \
║                                                                                            ║\n \
║    By: nduvoid <nduvoid@student.42mulhouse.fr>                                             ║\n \
║    A 42 cursus Project                                                                     ║\n \
╚════════════════════════════════════════════════════════════════════════════════════════════╝\n"

norm:
	@errors=$$(norminette --use-gitignore | grep --color=always "Error"); \
	if [ -n "$$errors" ]; then \
		echo "$$errors"; \
		echo "\033[31m ❌ Norminette errors found \033[0m"; \
	else \
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \
	fi

update:
	@make -i -C $(DIR_MANDATORY) update $(MAKEFLAGS)
	@make -i -C $(DIR_BONUS) update $(MAKEFLAGS)

.SILENT:
	@echo "\033[1;33m SILENT MODE ACTIVATED \033[0m