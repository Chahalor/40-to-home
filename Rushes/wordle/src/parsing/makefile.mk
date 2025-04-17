DIR_MODULE_PARSING		:= parsing
DIR_INTERFACE_PARSING	:= $(DIR_MODULE_PARSING)
DIR_INTERNAL_PARSING	:= $(DIR_MODULE_PARSING)/_internal

SRC_INTERFACE_PARSING	:= parsing/args/_internal/_args.c parsing/args/args.c parsing/dico/dico.c parsing/dico/memory.c 
SRC_INTERNAL_PARSING	:= #$SRC_INTERNAL

OBJ_PARSING			:= $(addprefix $(DIR_OBJ)/, $(SRC_INTERFACE_PARSING:.c=.o)) # $(DIR_INTERFACE_PARSING)/
OBJ_PARSING			+= $(addprefix $(DIR_OBJ)/, $(SRC_INTERNAL_PARSING:.c=.o)) # $(DIR_INTERNAL_PARSING)/

$(DIR_OBJ)/$(DIR_MODULE_PARSING)/%.o: $(DIR_SRC)/$(DIR_MODULE_PARSING)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_PARSING)/_internal -c $< -o $@
