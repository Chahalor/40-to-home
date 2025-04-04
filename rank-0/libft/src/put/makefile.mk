DIR_MODULE_PUT		:= put
DIR_INTERFACE_PUT	:= $(DIR_MODULE_PUT)
DIR_INTERNAL_PUT	:= $(DIR_MODULE_PUT)/_internal

SRC_INTERFACE_PUT	:= ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c 
SRC_INTERNAL_PUT	:= 

OBJ_PUT			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_PUT)/, $(SRC_INTERFACE_PUT:.c=.o))
OBJ_PUT			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_PUT)/, $(SRC_INTERNAL_PUT:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_PUT)/%.o: $(DIR_SRC)/$(DIR_MODULE_PUT)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_PUT)/_internal $(INCLUDE_ALL) -c $< -o $@
