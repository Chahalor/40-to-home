DIR_MODULE_DEBUG		:= debug
DIR_INTERFACE_DEBUG	:= $(DIR_MODULE_DEBUG)
DIR_INTERNAL_DEBUG	:= $(DIR_MODULE_DEBUG)/_internal

SRC_INTERFACE_DEBUG	:= debug.c 
SRC_INTERNAL_DEBUG	:= 

OBJ_DEBUG			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_DEBUG)/, $(SRC_INTERFACE_DEBUG:.c=.o))
OBJ_DEBUG			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_DEBUG)/, $(SRC_INTERNAL_DEBUG:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_DEBUG)/%.o: $(DIR_SRC)/$(DIR_MODULE_DEBUG)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_DEBUG)/_internal -c $< -o $@

