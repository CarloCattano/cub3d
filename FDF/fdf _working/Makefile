NAME = fdf

LIBPATH = ./libft/
LIB =$(LIBPATH)libft.a
CC = cc
CFLAGS = -Werror -Wextra -Wall #$(FSANITIZE) 
FT = -Ilibft/inc
INCLUDES = -Ilibft/inc -Imlx_linux -Iinc
FDF = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FSANITIZE =-fsanitize=address
COMPILE = $(CC) $(CFLAGS) -O3
REMOVE = rm -f
MLX = mlx_linux
HEADERS = fdf.h
MVH = $(addprefix $(INC_DIR), $(HEADERS))


MAPS = maps


INC_DIR = ./inc/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = fdf_map_rss fdf_setup fdf_colour_helper fdf_hock fdf_map_s fdf_start fdf_colours fdf_line fdf_math_utils fdf_store fdf_draw fdf_load_map fdf_render fdf_utils fdf_endfdf fdf_map_helpers fdf_rotation fdf_window fdf_map_rs fdf_rpoint_utils fdf_zoom fdf_keypress fdf_points
 



SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
 
all:  $(NAME)


$(NAME):$(OBJ_DIR) $(SRC_DIR) $(INC_DIR) $(OBJ) 
	$(COMPILE) $(OBJ) $(INCLUDES) main.c $(LIB) $(FDF) -o $(NAME) 		

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then \
		echo "CREATE $(OBJ_DIR)"; \
		mkdir -p $(OBJ_DIR); \
	fi 

$(INC_DIR):
	@if [ ! -d $(INC_DIR) ]; then \
		echo "CREATE $(INC_DIR)"; \
		mkdir -p $(INC_DIR); \
		mv $(HEADERS) $(MVH);\
	fi 



	
$(SRC_DIR):
	@if [ ! -d $(SRC_DIR) ]; then \
		echo "CREATE $(SRC_DIR)"; \
		mkdir -p $@; \
		mv $(addsuffix .c, $(SRC_FILES)) $(SRC_DIR); \
	fi

init: mlx lib dmaps $(OBJ_DIR) $(SRC_DIR) $(INC_DIR) 
	

mlx: 
	@if [ ! -d "$(MLX)" ]; then \
		echo "creating MLX";\
		wget https://projects.intra.42.fr/uploads/document/document/13502/minilibx-linux.tgz; \
		tar -xvzf minilibx-linux.tgz; \
		mv minilibx-linux mlx_linux; \
		rm minilibx-linux.tgz; \
		$(MAKE) -C ./mlx_linux; \
		echo "MLX ready";\
	fi
lib: 
	@$(MAKE) -C ./libft

	
dmaps: 
	@if [ ! -d "$(MAPS)" ]; then \
		echo "creating MAPS"; \
		wget https://projects.intra.42.fr/uploads/document/document/13499/maps.zip; \
		unzip  maps.zip; \
		rm -rf  __MACOSX maps.zip; \
		mv test_maps maps;\
	fi



clean:
	
	$(MAKE) clean -C ./libft
	$(REMOVE) $(OBJ)
	
fclean: clean 
	$(REMOVE) $(OBJ)
	$(MAKE) fclean -C ./libft
	$(REMOVE) $(NAME)

re: fclean init all


.PHONY: all re clean fclean lib dmaps mlx init 
