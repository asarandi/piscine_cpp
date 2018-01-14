NAME	= ft_retro

SRC		= main.cpp

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
