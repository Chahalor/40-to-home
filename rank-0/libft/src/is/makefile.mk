DIR_MODULE_IS		:= is
DIR_INTERFACE_IS	:= $(DIR_MODULE_IS)
DIR_INTERNAL_IS	:= $(DIR_MODULE_IS)/_internal

SRC_INTERFACE_IS	:= is_char.c is_str.c 
SRC_INTERNAL_IS	:= 

OBJ_IS			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_IS)/, $(SRC_INTERFACE_IS:.c=.o))
OBJ_IS			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_IS)/, $(SRC_INTERNAL_IS:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_IS)/%.o: $(DIR_SRC)/$(DIR_MODULE_IS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_IS)/_internal $(INCLUDE_ALL) -c $< -o $@
