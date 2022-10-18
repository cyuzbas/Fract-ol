NAME 		= fractol

CFLAGS 		= -Wall -Werror -Wextra

SRCS 		= sources/main.c \
			sources/draw.c \
			sources/keypress.c \
			sources/mandelbrot.c \
			sources/julia.c \
			sources/bonus.c \
			sources/mouse.c \
			sources/utils.c

# library locations
MLX			= lib/mlx
LIBFT		= lib/libft
FRACTOL		= inc/

# librarys
LIBS		= -L $(MLX) -L $(LIBFT) -L $(FRACTOL)

FRAMEWORK 	=	-framework OpenGl\
				-framework AppKit

# includes
INCLUDES	= -I $(MLX) -I $(LIBFT) -I $(FRACTOL)

# shell colors
RESET		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"

all: 	$(NAME)

$(NAME):
			@make -C $(MLX) 
			@make -C $(LIBFT)
			@mv ./lib/mlx/libmlx.a ./
			@$(CC) $(CFLAGS) $(FRAMEWORK) $(INCLUDES) $(LIBS) $(LIBFT)/libft.a $(SRCS) libmlx.a -o $(NAME)
			@echo $(GREEN)"Object files created"$(RESET)

clean:
			@make clean -C $(MLX) 
			@make fclean -C $(LIBFT)
			@rm -rf libmlx.a mlx/libmlx.a
			@echo $(RED)"Object files deleted"$(RESET)

fclean:		clean
			@rm -f $(NAME)
			@echo $(RED)"$(NAME) deleted"$(RESET)

re: 	fclean all
