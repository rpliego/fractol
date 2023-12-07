NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC =		main.c \
			utils.c \
			mlx_ft.c \
			calc_fractals.c

OBJ = $(SRC:.c=.o)
MLX_DIR = ./mlx
INCLUDE = fractol.h Makefile

all:
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FT_PRINTF)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(MLX_DIR)
	@make clean -C $(FT_PRINTF_DIR)

fclean: clean
	@$(MAKE) fclean -C $(FT_PRINTF_DIR) --no-print-directory
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
