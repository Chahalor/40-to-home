DIR_MODULE_ALGO		:= algo
DIR_INTERFACE_ALGO	:= $(DIR_MODULE_ALGO)
DIR_INTERNAL_ALGO	:= $(DIR_MODULE_ALGO)/_internal

SRC_INTERFACE_ALGO	:= algo.c 
SRC_INTERNAL_ALGO	:= _utils.c _turkish.c _da_fuck.c 

OBJ_ALGO			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_ALGO)/, $(SRC_INTERFACE_ALGO:.c=.o))
OBJ_ALGO			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_ALGO)/, $(SRC_INTERNAL_ALGO:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_ALGO)/%.o: $(DIR_SRC)/$(DIR_MODULE_ALGO)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_ALGO)/_internal $(INCLUDE_ALL) -c $< -o $@
