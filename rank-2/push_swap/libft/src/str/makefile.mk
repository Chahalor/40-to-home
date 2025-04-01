DIR_MODULE_STR		:= str
DIR_INTERFACE_STR	:= $(DIR_MODULE_STR)
DIR_INTERNAL_STR	:= $(DIR_MODULE_STR)/_internal

SRC_INTERFACE_STR	:= ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c 
SRC_INTERNAL_STR	:= 

OBJ_STR			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_STR)/, $(SRC_INTERFACE_STR:.c=.o))
OBJ_STR			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_STR)/, $(SRC_INTERNAL_STR:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_STR)/%.o: $(DIR_SRC)/$(DIR_MODULE_STR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIR_SRC)/$(DIR_MODULE_STR)/_internal $(INCLUDE_ALL) -c $< -o $@
