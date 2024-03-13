NAME			= 00
CXX				= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98
SRC = Animal.cpp main.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Cat.cpp

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
