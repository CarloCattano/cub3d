NAME = cub3d
SOURCES = hooks.c main.c keyhooks.c utils.c draw.c player.c init.c exit.c map.c minimap.c
HEADER = include
SRC_PATH  = src
OBJ_PATH  = objs
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -L./libft -lft -L./minilibx-linux -lmlx -L./ft_printf -lftprintf -lm -lXext -lX11 -lz
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux
INCLUDES = -I./include -I./libft -I./minilibx-linux -I./ft_printf 

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

TST = tst.c 

all: $(NAME)

getmlxlib:
	@if [ ! -d minilibx-linux ]; then \
		echo "Downloading miniLibX..."; \
		wget https://cdn.intra.42.fr/document/document/21669/minilibx-linux.tgz; \
		tar -xzf minilibx-linux.tgz; \
		rm minilibx-linux.tgz; \
	fi

debug:
	@cc -ggdb3 $(CFLAGS) $(INCLUDES) $(SRCS) $(LDLIBS) -o $(NAME)
	@echo "---Debug mode---"
	@gdb -ex run $(NAME) "Cubemap.cub"

mem:
	@cc -ggdb3 $(CFLAGS) $(INCLUDES) $(SRCS) $(LDLIBS) -o debug
	@echo "---Debug mode---"
	@help50 valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./debug somemap.cub

run: all
	@./$(NAME) "Cubemap.cub"

$(NAME): getmlxlib $(OBJS)
	make mlibft
	make mlx
	make printf
	@cc $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@mkdir -p $(OBJ_PATH)
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@
	
mlibft:
	@echo "building lbft.........."
	@make -s -C $(LIBFT_DIR)

tst:
	cc $(CFLAGS) $(TST) -o tst $(INCLUDES) $(LDLIBS)

mlx: getmlxlib
	@echo "building mlx.........."
	@make -s -C $(MLX_DIR)
	
printf:
	@echo "building ftprintf.........."
	@make -s -C $(PRINTF_DIR)

clean: fclean
	rm -rf $(OBJ_PATH)
	make fclean -s -C $(LIBFT_DIR)
	make fclean -s -C $(PRINTF_DIR)
	make clean -s -C $(MLX_DIR)

fclean:
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
