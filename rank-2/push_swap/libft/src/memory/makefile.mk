DIR_MODULE_MEMORY		:= memory
DIR_INTERFACE_MEMORY	:= $(DIR_MODULE_MEMORY)
DIR_INTERNAL_MEMORY	:= $(DIR_MODULE_MEMORY)/_internal

SRC_INTERFACE_MEMORY	:= ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c 
SRC_INTERNAL_MEMORY	:= 

OBJ_MEMORY			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_MEMORY)/, $(SRC_INTERFACE_MEMORY:.c=.o))
OBJ_MEMORY			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_MEMORY)/, $(SRC_INTERNAL_MEMORY:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_MEMORY)/%.o: $(DIR_SRC)/$(DIR_MODULE_MEMORY)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_MEMORY)/_internal $(INCLUDE_ALL) -c $< -o $@
