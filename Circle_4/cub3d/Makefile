
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
#-g
#-g3 -fsanitize=address
# -g3 -fsanitize=address
# -o2 or -o3
NAME = cub3D

SRCS_DIR = src
SRCS =	src/main.c			\
		src/exit.c			\
		src/check_make_map.c	\
		src/check_type.c		\
		src/make_type.c		\
		src/check_value.c		\
		src/make_value.c		\
		src/init.c			\
		src/validate.c	\
		src/input_key.c 	\
		src/make_ray.c 		\
		src/make_texture.c 	\
		src/raycast.c 		\
		src/draw.c 	\


OBJS = $(SRCS:.c=.o)

MLX_NAME = mlx
MLX_DIR = include/minilibx_opengl_20191021

LIBFT_NAME = ft
LIBFT_DIR = include/libft

GNL_NAME = gnl
GNL_DIR = include/get_next_line

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(GNL_DIR) all
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_NAME) \
			-L$(GNL_DIR) -l$(GNL_NAME) \
			-L$(LIBFT_DIR) -l$(LIBFT_NAME) \
			-framework OpenGL -framework AppKit $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR) -c $< -o $@

all : $(NAME)
bonus : $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean :
	rm -rf $(NAME) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
