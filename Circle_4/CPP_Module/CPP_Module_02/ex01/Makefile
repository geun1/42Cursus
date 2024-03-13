# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 18:29:03 by gsong             #+#    #+#              #
#    Updated: 2023/08/23 13:03:10 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 01
CXX				= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98
SRC = Fixed.cpp main.cpp

OBJ = $(SRC:cpp=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
