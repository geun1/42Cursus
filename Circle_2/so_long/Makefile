# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 21:08:00 by gsong             #+#    #+#              #
#    Updated: 2023/01/17 22:46:17 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# SETUP
NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
MLX			=	-L./mlx -lmlx -framework OpenGL -framework AppKit

# HEADER
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

LFT_DIR = ./libft
LFT_FLAG = -L$(LFT_DIR) -lft -I$(LFT_DIR)

# FILES
MPATH_SRCS	=	main.c check_map.c check_middle_line.c check_characters.c check_escapable_map.c \
				init.c mlx_utils.c move_a.c move_s.c move_w.c move_d.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

FUNC 		=	gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_M)
				@make -s -C $(LFT_DIR)
				@make -s -C ./mlx all
				@$(CC) $(LFT_FLAG) $(OBJ_F) $(OBJ_M) $(MLX) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@make -s -C $(LFT_DIR) clean
				@make -s -C ./mlx clean
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@make -s -C $(LFT_DIR) fclean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m
