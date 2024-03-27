NAME		= RPN
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g
SRC			= main.cpp RPN.cpp
OBJ			= $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re