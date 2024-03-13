# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsong <gsong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 16:57:36 by gsong             #+#    #+#              #
#    Updated: 2023/08/14 16:09:11 by gsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= PhoneBook
CFLAGS			= -Wall -Wextra -Werror -std=c++98
SRC =  Contact.cpp PhoneBook.cpp main.cpp

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
