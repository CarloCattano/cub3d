NAME := cube3d

CC := cc
CFLAGS := -Werror -Wextra -Wall
INCLUDES := -Iinc -Ilibft/inc
COMPILE := $(CC) $(CFLAGS) $(INCLUDES)
REMOVE := rm -rf 

LIBPATH = ./libft/
LIB =$(LIBPATH)libft.a


INC_DIR := ./inc/
SRC_DIR := ./src/
OBJ_DIR := ./obj/


C := cub_countparts cub_evalfile cub_isnumber cub_pfloor cub_readmap cub_dfree cub_evalline cub_loadscene cub_psprites cub_splits cub_error cub_freelextra cub_parser cub_pwalls cub_loadmap cub_cparr
H :=  cube3d
MAIN := main.c

INC := $(addprefix $(INC_DIR), $(addsuffix .h, $(H))) 
SRC := $(addprefix $(SRC_DIR),$(addsuffix .c, $(C)))
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: init  $(NAME)

init: libft $(SRC_DIR) $(INC_DIR) $(OBJ_DIR)

$(INC_DIR):
	@echo "CREATE $(INC_DIR)" && mkdir -p $(INC_DIR)
	@mv  $(addprefix ./, $(addsuffix .h, $(H)))  $(INC_DIR)

$(SRC_DIR):
	@echo "CREATE $(SRC_DIR)" && mkdir -p $(SRC_DIR)
	@mv  $(addprefix ./, $(addsuffix .c, $(C))) $(SRC_DIR)

$(OBJ_DIR):
	@echo "CREATE $(OBJ_DIR)" && mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE) -c $< -o $@

$(NAME):$(OBJ) 
	$(COMPILE) $(OBJ)  $(MAIN) $(LIB) -o $(NAME) 

#$(NAME): $(OBJ) $(MAIN)
#	$(COMPILE) -L./libft -lft $^ -o $@		

clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

libft: 
	@$(MAKE) -C ./libft
	@echo "LIBFT DONE!"

undo: fclean 
	@mv $(INC) ./
	@mv $(SRC) ./
	@$(REMOVE) $(INC_DIR) $(SRC_DIR) $(OBJ_DIR)
.PHONY: all re clean fclean undo init libft
