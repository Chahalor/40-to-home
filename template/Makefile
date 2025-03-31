all: cli

cli: header user information progression

# ╣ ╠ ╔ ═ ║ 

SRC1 = $(wildcard $(DIR_SRC)/$(DIR_CLIENT)/*.c)
SRC2 = $(wildcard $(DIR_SRC)/$(DIR_UTILS)/*.c)


STATUS1	= false
STATUS2	= false

header:
	@clear
	@printf "\n \
	                                                                                                                         \n \
	    _____ ______       ___        ________       ___      _________      ________        ___           ___  __           \n \
	   |\   _ \  _   \    |\  \      |\   ___ \     |\  \    |\___   ___\   |\   __  \      |\  \         |\  \|\  \         \n \
	   \ \  \\\__\  \   \   \ \  \     \ \  \\ \  \    \ \  \   \|___ \  \_|   \ \  \|\  \     \ \  \        \ \  \/  /|_       \n \
	    \ \  \\|__| \   \   \ \  \     \ \  \\ \  \    \ \  \       \ \  \     \ \   __  \     \ \  \        \ \   ___  \      \n \
	     \ \  \    \ \  \   \ \  \     \ \  \\ \  \    \ \  \       \ \  \     \ \  \ \  \     \ \  \____    \ \  \\  \  \     \n \
	      \ \__\    \ \__\   \ \__\     \ \__\\ \__\    \ \__\       \ \__\     \ \__\ \__\     \ \_______\   \ \__\\  \__\    \n \
	       \|__|     \|__|    \|__|      \|__| \|__|    \|__|        \|__|      \|__|\|__|      \|_______|    \|__|   \__|   \n \
	                                                                                                                        \n \
	                                                                                                                         \n"
	@printf " --------------------------------------------------------------------------------------------------------------------------- \n"


user:
	@printf "\n \
	                                                                                                                        \n \
	     $(UNDERLINE)By :$(RESET)      nduvoid <nduvoid@student.42mulhouse.fr>                                                                                  \n" \
	@$(call write_goals)
	@printf " \
	                                                                                                                         \n"
	@printf " --------------------------------------------------------------------------------------------------------------------------- \n"

information:
	@printf "\n \
	     $(UNDERLINE)information :$(RESET)                                                                                                       \n \
	      - LIBFT [$(RED)NO$(RESET)]                                                                                                        \n \
	      - SRC [$(RED)NO$(RESET)]                                                                                                        \n \
	         - Args []                                                                                                       \n \
	         - Algo []                                                                                                       \n \
	         - ... []                                                                                                        \n \
	                                                                                                                         \n \
	                                                                                                                         \n "
	@printf " --------------------------------------------------------------------------------------------------------------------------- \n"


progression:
	@printf " \
	     $(UNDERLINE)progression :$(RESET)                                                                                                       \n \
	                                                                                                                         \n \
	                                                                                                                         \n \
	                                                                                                                         \n \
	                                                                                                                         \n"
	@printf " --------------------------------------------------------------------------------------------------------------------------- \n"

status:
	$(call show_status, 1)


UNDERLINE	:= "\\e[4m"
RED			:= "\\e[31m"
GREEN		:= "\\e[32m"
BLUE		:= "\\e[34m"
YELLOW		:= "\\e[33m"
RESET		:= "\\e[0m"

define write_goals
	line_size=106; \
	line="$(if $(MAKECMDGOALS), $(MAKECMDGOALS), all)"; \
	line_size=$$(( $$line_size - $${#line} )); \
	printf "      $(UNDERLINE)Rule(s):$(RESET) %s%*s\e[0m\n" "$$line" $$line_size " "
endef

# Helper function to print a progress bar
# Credits: ugwentzi@student.42mulhouse.fr
#=- Progress Bar -=#
BAR_LENGTH		= 42
PADDING			= 10
COLOR_YELLOW	= \033[1;33m
COLOR_GREEN		= \033[1;32m
COLOR_CYAN		= \033[1;36m
COLOR_RED		= \033[31m
COLOR_ORANGE	= \033[38;5;208m
COLOR_BLUE		= \033[1;34m
COLOR_RESET		= \033[0m
COUNT			= 0

reset_count:
	$(eval COUNT := 0)

define compile_object
	$(eval COUNT := $(shell echo $$(( $(COUNT) + 1 ))))
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@
	@printf "\r$(3)\bCompiling %s%*s[%-$(BAR_LENGTH)s] %d/%d$(COLOR_RESET)" \
		"$<" \
		$$(($(PADDING) - $$(echo -n "$(NAME)" | wc -c))) "" \
		$(shell printf '=%.0s' $$(seq 1 $$(echo "$$(( $(BAR_LENGTH) * $(COUNT) / $(words $(2)) ))"))) \
		$(COUNT) \
		$(words $(2))
		@printf " "
	@true
endef

define show_status
	@if [ "$1" -eq 0 ]; then \
		printf "\r$(COLOR_RED)KO$(COLOR_RESET)"; \
	elif [ "$1" -eq 1 ]; then \
		printf "\r$(COLOR_ORANGE)PROG$(COLOR_RESET)"; \
	else \
		printf "\r$(COLOR_GREEN)OK$(COLOR_RESET)"; \
	fi
endef