DIR_MODULE_LINKED-LIST		:= linked-list
DIR_INTERFACE_LINKED-LIST	:= $(DIR_MODULE_LINKED-LIST)
DIR_INTERNAL_LINKED-LIST	:= $(DIR_MODULE_LINKED-LIST)/_internal

SRC_INTERFACE_LINKED-LIST	:= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 
SRC_INTERNAL_LINKED-LIST	:= 

OBJ_LINKED-LIST			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_LINKED-LIST)/, $(SRC_INTERFACE_LINKED-LIST:.c=.o))
OBJ_LINKED-LIST			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_LINKED-LIST)/, $(SRC_INTERNAL_LINKED-LIST:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_LINKED-LIST)/%.o: $(DIR_SRC)/$(DIR_MODULE_LINKED-LIST)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_LINKED-LIST)/_internal $(INCLUDE_ALL) -c $< -o $@
