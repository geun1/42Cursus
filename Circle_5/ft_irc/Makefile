CXX		 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MMDFLAGS = -MMD

NAME	 = ircserv

SRC_DIR = srcs
INC_DIR = incs
BUILD_DIR = build

SRCS_ORG = main.cpp Channel.cpp ChannelDB.cpp UserDB.cpp Kevent.cpp Parser.cpp Delivery.cpp Message.cpp Server.cpp UserInfo.cpp ErrorExit.cpp ServerInfo.cpp

SRCS	= $(addprefix $(SRC_DIR)/, $(SRCS_ORG))
OBJS	= $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS_ORG))
DEPS	= $(patsubst %.cpp, $(BUILD_DIR)/%.d, $(SRCS_ORG))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(MMDFLAGS) -I $(INC_DIR) $^ -o $@

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir  -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(MMDFLAGS) -I $(INC_DIR) -c $< -o $@

clean :
	$(RM) -rf $(BUILD_DIR)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

-include $(DEPS)