# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 21:03:29 by gsong             #+#    #+#              #
#    Updated: 2023/08/14 17:43:29 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 03
CXX				= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98
SRC = Weapon.cpp main.cpp HumanA.cpp HumanB.cpp

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
