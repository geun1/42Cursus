NAME			= a.out
CXX				= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98
SRC = Bureaucrat.cpp Form.cpp main.cpp

OBJ = $(SRC:cpp=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling... \t$<"

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
