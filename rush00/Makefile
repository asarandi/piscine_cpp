NAME	= ft_retro

SRC		= 	Area.cpp \
			Character.cpp \
			Enemy.cpp \
			Entity.cpp \
			Missile.cpp \
			main.cpp \
			utils.cpp

OBJ		= $(SRC:.cpp=.o)

CC		= clang++
FLAGS	= -Wall -Wextra -Werror -g
LIB		= -lncurses

all:
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
