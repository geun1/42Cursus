# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 16:57:15 by gsong             #+#    #+#              #
#    Updated: 2023/08/14 16:09:20 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= megaphone
CFLAGS			= -Wall -Wextra -Werror -std=c++98
SRC = Megaphone.cpp

OBJ = $(SRC:cpp=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@${CXX} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
