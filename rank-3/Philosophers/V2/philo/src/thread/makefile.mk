DIR_MODULE_THREAD		:= thread
DIR_INTERFACE_THREAD	:= $(DIR_MODULE_THREAD)
DIR_INTERNAL_THREAD	:= $(DIR_MODULE_THREAD)/_internal

SRC_INTERFACE_THREAD	:= thread.c 
SRC_INTERNAL_THREAD	:= _thread.c 

OBJ_THREAD			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_THREAD)/, $(SRC_INTERFACE_THREAD:.c=.o))
OBJ_THREAD			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_THREAD)/, $(SRC_INTERNAL_THREAD:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_THREAD)/%.o: $(DIR_SRC)/$(DIR_MODULE_THREAD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_THREAD)/_internal -c $< -o $@
