# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 19:58:41 by gsong             #+#    #+#              #
#    Updated: 2023/01/11 21:48:40 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = \
push_swap.c stack.c stack_utils.c \
operations.c operation2.c operation3.c \
ft_split.c ft_check_valid_param.c \
indexing.c sort.c sort_rotate.c sort_find.c \
sort_utils.c

OBJS_CHECKER = \
checker.c get_next_line.c get_next_line_utils.c \
indexing.c operations.c operation2.c operation3.c \
stack.c stack_utils.c ft_check_valid_param.c \
ft_split.c checker_utils.c


SRCS = $(addprefix mandatory/, $(OBJS))
SRCS_BONUS = $(addprefix bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:c=o)
SRCS_BONUS_FILES = $(SRCS_BONUS:c=o)

NAME = push_swap
BONUS = checker
RM = rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(SRCS_BONUS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(SRCS_FILES)
	$(RM) $(SRCS_BONUS_FILES)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus
