NAME = libft.a

CC = cc
CFLAGS = -Werror -Wextra -Wall
INCDIR = inc



COMPILE = $(CC) $(CFLAGS) -I$(INCDIR) -c 
REMOVE = rm -f
LIB = ar -rc $(NAME)
LIBFT_PATH = ft/
GNL_PATH = gnl/
PF_PATH = pf/
SRC_DIR = src/
OBJ_DIR = obj/


SRC_FILES = $(LIBFT_PATH)ft_memcmp \
			$(LIBFT_PATH)ft_strdup \
			$(LIBFT_PATH)ft_strtrim \
			$(LIBFT_PATH)ft_atoi \
			$(LIBFT_PATH)ft_memcpy \
			$(LIBFT_PATH)ft_striteri \
			$(LIBFT_PATH)ft_substr \
			$(LIBFT_PATH)ft_bzero \
			$(LIBFT_PATH)ft_memmove \
			$(LIBFT_PATH)ft_strjoin \
			$(LIBFT_PATH)ft_tolower \
			$(LIBFT_PATH)ft_calloc \
			$(LIBFT_PATH)ft_memset \
			$(LIBFT_PATH)ft_strlcat \
			$(LIBFT_PATH)ft_toupper \
			$(LIBFT_PATH)ft_isalnum \
			$(LIBFT_PATH)ft_putchar_fd \
			$(LIBFT_PATH)ft_strlcpy \
			$(LIBFT_PATH)ft_isalpha \
			$(LIBFT_PATH)ft_putendl_fd \
			$(LIBFT_PATH)ft_strlen \
			$(LIBFT_PATH)ft_isascii \
			$(LIBFT_PATH)ft_putnbr_fd \
			$(LIBFT_PATH)ft_strmapi \
			$(LIBFT_PATH)ft_isdigit \
			$(LIBFT_PATH)ft_putstr_fd \
			$(LIBFT_PATH)ft_strncmp \
			$(LIBFT_PATH)ft_isprint \
			$(LIBFT_PATH)ft_split \
			$(LIBFT_PATH)ft_strnstr \
			$(LIBFT_PATH)ft_itoa \
			$(LIBFT_PATH)ft_memchr \
			$(LIBFT_PATH)ft_strchr \
			$(LIBFT_PATH)ft_strrchr \
			$(LIBFT_PATH)ft_lstnew \
			$(LIBFT_PATH)ft_lstadd_front \
			$(LIBFT_PATH)ft_lstsize \
			$(LIBFT_PATH)ft_lstlast \
			$(LIBFT_PATH)ft_lstadd_back \
			$(LIBFT_PATH)ft_lstdelone \
			$(LIBFT_PATH)ft_lstclear\
			$(LIBFT_PATH)ft_lstiter \
			$(LIBFT_PATH)ft_lstmap \
			$(PF_PATH)ft_printf \
			$(PF_PATH)pf_lenvp \
			$(PF_PATH)pf_p_p \
			$(PF_PATH)pf_putnbr_fd_base \
			$(PF_PATH)pf_pvx \
			$(PF_PATH)pf_setwidth \
			$(PF_PATH)pf_count_base \
			$(PF_PATH)pf_lenvs \
			$(PF_PATH)pf_p_percent \
			$(PF_PATH)pf_putnbr_fd_base_ull	\
			$(PF_PATH)pf_p_x \
			$(PF_PATH)pf_count_base_ull \
			$(PF_PATH)pf_lenvu \
			$(PF_PATH)pf_printwidth \
			$(PF_PATH)pf_pvid \
			$(PF_PATH)pf_resform\
			$(PF_PATH)pf_isctype \
			$(PF_PATH)pf_lenvx \
			$(PF_PATH)pf_process \
			$(PF_PATH)pf_pvp \
			$(PF_PATH)pf_setflg \
			$(PF_PATH)pf_itoui \
			$(PF_PATH)pf_p_c \
			$(PF_PATH)pf_p_s \
			$(PF_PATH)pf_pvs \
			$(PF_PATH)pf_setform \
			$(PF_PATH)pf_lenvid \
			$(PF_PATH)pf_p_id \
			$(PF_PATH)pf_p_u \
			$(PF_PATH)pf_pvu \
			$(PF_PATH)pf_setper \
			$(GNL_PATH)gnl_get_next_line \
			$(GNL_PATH)gnl_get_next_line_utils




SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))



all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(LIB) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE)  $< -o $@

$(OBJ_DIR):  
	mkdir -p $(OBJ_DIR)$(GNL_PATH) $(OBJ_DIR)$(PF_PATH) $(OBJ_DIR)$(LIBFT_PATH);
clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: re clean fclean 
