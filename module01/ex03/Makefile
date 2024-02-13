NAME	= ex03
CFLAGS	= -std=c++98 -Wall -Werror -Wextra
SRC 	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ		= $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all