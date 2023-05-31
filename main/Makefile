NAME = so_long.a
SO_LONG_FILES = $(shell find . -name "*.c" ! -name "so_long.c")
SO_LONG_OBJ := $(SO_LONG_FILES:%.c=%.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

$(NAME): $(SO_LONG_FILES) $(SO_LONG_OBJ)
		@make -C ../libs/minilibx
		@make -C ../libs/libft
		@cp ../libs/minilibx/libmlx.a .
		@cp ../libs/libft/libft.a .
		@ar -rcs $(NAME) *.o
		@gcc $(FLAGS) -o so_long so_long.c libmlx.a so_long.a libft.a -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	@rm -rf *.o
	@make clean -C ../libs/minilibx/
	@make clean -C ../libs/libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf so_long
	@rm -rf *.a

re: fclean $(NAME)

debug: $(NAME)
	@gcc $(FLAGS) so_long.c $(NAME) && ./a.out