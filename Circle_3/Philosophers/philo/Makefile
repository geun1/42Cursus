# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 16:32:20 by gsong             #+#    #+#              #
#    Updated: 2023/04/11 17:07:28 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = philo

CFLAGS = -Wall -Werror -Wextra

SRCS = philo.c			\
	   philo_utils.c	\
	   philo_routine.c		\
		arg_atoi.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lpthread -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
