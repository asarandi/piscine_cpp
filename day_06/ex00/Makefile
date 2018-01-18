NAME	= convert

SRC		= main.cpp

OBJ		= $(SRC:.cpp=.o)

CC		= clang++
FLAGS	= -Wall -Wextra -Werror -Wconversion

all:
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
