NAME := cub3D
ARCH := $(shell uname -s)
CC := cc
CFLAGS := -Werror -Wextra -Wall
DEBUGFLAGS := -ggdb3 -fsanitize=address
INCLUDES := -Iinc -Ilibft/inc

ifeq ($(ARCH), Darwin)
	INCLUDES += -Iminilibx_opengl_20191021
else ifeq ($(ARCH), Linux)
	INCLUDES += -Iminilibx-linux
endif

REMOVE := rm -rf 
LIBPATH = ./libft/
LIB =$(LIBPATH)libft.a

INC_DIR := ./inc/
SRC_DIR := ./src/
OBJ_DIR := ./obj/

YELLOW := $(shell tput setaf 3)
NC := $(shell tput sgr0)

C := main cub_countparts cub_evalfile cub_isnumber cub_pfloor cub_readmap cub_dfree cub_evalline cub_loadsc \
	 cub_psprites cub_splits cub_error cub_freelextra cub_parser cub_pwalls cub_loadmap cub_cparr \
	 cub_loadpl cub_loadcfpl cub_pload cub_freesc cub_checkmap cub_loadextra cub_init cub_draw_minimap cub_draw cub_mpp cub_point cub_line cub_draw_ray cub_ray cub_piinte cub_dmpl\
	 cub_draw_screen cub_loadwalls cub_loadfile player hooks keyhooks weapon wall_orientation exit \
	 utils hook_init cub_open_door

H :=  cub3d

INC := $(addprefix $(INC_DIR), $(addsuffix .h, $(H)))
SRC := $(addprefix $(SRC_DIR),$(addsuffix .c, $(C)))
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: init $(NAME)
init: libft $(SRC_DIR) $(INC_DIR) $(OBJ_DIR) getmlxlib

$(INC_DIR):
	@echo "CREATE $(INC_DIR)" && mkdir -p $(INC_DIR)
	@mv  $(addprefix ./, $(addsuffix .h, $(H)))  $(INC_DIR)

$(SRC_DIR):
	@echo "CREATE $(SRC_DIR)" && mkdir -p $(SRC_DIR)
	@mv  $(addprefix ./, $(addsuffix .c, $(C))) $(SRC_DIR)

$(OBJ_DIR):
	@echo "CREATE $(OBJ_DIR)" && mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):$(OBJ)
	$(CC) $(INCLUDES) $(OBJ) $(LIB) $(MLXFLAGS) -o $(NAME) 
	@echo "$(YELLOW)------------------------"
	@echo "FINISHED COMPILING $(NAME) for $(ARCH)"
	@echo "--------------------------------------"
	@echo "$(NC)"

MLX_URL = ""

ifeq ($(ARCH), Darwin)
	MLX := "minilibx_opengl_20191021"
	MLX_URL = "https://cdn.intra.42.fr/document/document/22380/minilibx_opengl.tgz"
	MLXFLAGS := -L$(MLX) -lmlx -framework OpenGL -framework AppKit 
else ifeq ($(ARCH), Linux)
	MLX := "minilibx-linux"
	MLX_URL = "https://cdn.intra.42.fr/document/document/22379/minilibx-linux.tgz"
	MLXFLAGS := -Lminilibx-linux -lmlx -L./minilibx-linux -Iminilibx-linux -lXext -lX11 -lm -lz
endif
# wget $(MLX_URL) -O $(MLX).tgz; \
# tar -xvf $(MLX).tgz; \
# rm $(MLX).tgz; \
	
getmlxlib:
	@if [ ! -d $(MLX) ]; then \
		echo "GETTING MLX LIBRARY"; \
		git clone https://github.com/42Paris/minilibx-linux.git; \
		echo "MLX LIBRARY Downloaded"; \
	fi
	
	@make -C $(MLX)

run : all
	./$(NAME) test.cub

debug: all
	$(CC) $(INCLUDES) $(DEBUGFLAGS) $(OBJ) $(LIB) $(MLXFLAGS) -o $(NAME) 
	./$(NAME) test.cub

clean:
	make clean -C ./libft
	make fclean -C ./libft
	make clean -C ./$(MLX)
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

.PHONY: all re clean fclean undo init libft mlx
