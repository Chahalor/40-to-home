DIR_MODULE_CHAR-CHANGE		:= char-change
DIR_INTERFACE_CHAR-CHANGE	:= $(DIR_MODULE_CHAR-CHANGE)
DIR_INTERNAL_CHAR-CHANGE	:= $(DIR_MODULE_CHAR-CHANGE)/_internal

SRC_INTERFACE_CHAR-CHANGE	:= ft_tolower.c ft_toupper.c 
SRC_INTERNAL_CHAR-CHANGE	:= 

OBJ_CHAR-CHANGE			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_CHAR-CHANGE)/, $(SRC_INTERFACE_CHAR-CHANGE:.c=.o))
OBJ_CHAR-CHANGE			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_CHAR-CHANGE)/, $(SRC_INTERNAL_CHAR-CHANGE:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_CHAR-CHANGE)/%.o: $(DIR_SRC)/$(DIR_MODULE_CHAR-CHANGE)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_CHAR-CHANGE)/_internal $(INCLUDE_ALL) -c $< -o $@
