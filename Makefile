# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

NAME=fractol

CC= gcc
#CFLAGS=-Wall -Werror -Wextra -fsanitize=address -g3
CFLAGS=-Wall -Werror -Wextra -g3

# librarys
LIB= libft/libft.a
MLX= mlx/libmlx.a

FUNCTION=	main.c \
			render.c \
			math_utils.c \
			key_hooks.c \
			mouse_hooks.c \
			fractol_utils.c \

OBJ=$(FUNCTION:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(PINK)Compiling the librarys.$(CLEAR)"
	$(MAKE) bonus -sC ./libft
	$(MAKE) -sC ./mlx
	@echo "$(GREEN)librarys compiled correctly\n$(CLEAR)"
	@echo "$(PINK)Compiling the fractol.$(CLEAR)"
	$(CC) $(OBJ) $(LIB) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g3
#	$(CC) $(OBJ) $(LIB) $(MLX) -o $(NAME) -fsanitize=address -g3
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	@echo "$(PINK)Compiling Object.$(CLEAR)"
	$(CC) $(CFLAGS) -c $<
	@echo "\n"

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	rm -rf $(OBJ)
	@$(MAKE) clean -sC ./libft
	@$(MAKE) clean -sC ./mlx
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) fclean -sC ./libft
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!\n$(CLEAR)"

re: fclean all
.PHONY: clean fclean re all
