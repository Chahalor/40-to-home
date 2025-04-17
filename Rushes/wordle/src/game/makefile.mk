DIR_MODULE_GAME		:= game
DIR_INTERFACE_GAME	:= $(DIR_MODULE_GAME)
DIR_INTERNAL_GAME	:= $(DIR_MODULE_GAME)/_internal

SRC_INTERFACE_GAME	:= game/checker.c game/_internal/_word.c game/menu.c game/word.c game/_internal/_alphabet.c
SRC_INTERNAL_GAME	:= #$SRC_INTERNAL

OBJ_GAME			:= $(addprefix $(DIR_OBJ)/, $(SRC_INTERFACE_GAME:.c=.o)) # $(DIR_INTERFACE_GAME)/
OBJ_GAME			+= $(addprefix $(DIR_OBJ)/, $(SRC_INTERNAL_GAME:.c=.o)) # $(DIR_INTERNAL_GAME)/

$(DIR_OBJ)/$(DIR_MODULE_GAME)/%.o: $(DIR_SRC)/$(DIR_MODULE_GAME)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_GAME)/_internal -c $< -o $@
