DIR_MODULE_STACK		:= stack
DIR_INTERFACE_STACK	:= $(DIR_MODULE_STACK)
DIR_INTERNAL_STACK	:= $(DIR_MODULE_STACK)/_internal

SRC_INTERFACE_STACK	:= information.c stack.c 
SRC_INTERNAL_STACK	:= push.c rotate.c swap.c utils.c 

OBJ_STACK			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_STACK)/, $(SRC_INTERFACE_STACK:.c=.o))
OBJ_STACK			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_STACK)/, $(SRC_INTERNAL_STACK:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_STACK)/%.o: $(DIR_SRC)/$(DIR_MODULE_STACK)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_STACK)/_internal $(INCLUDE_ALL) -c $< -o $@
