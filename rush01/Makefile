NAME	= ft_gkrellm

SRC		= main.cpp \
			IMonitorModule.cpp \
			OSInfo.cpp \
			NetworkInfo.cpp \
			Date.cpp \
			IMonitorDisplay.cpp \
			GUI.cpp \
			CONSOLE.cpp \
			CPUActivity.cpp \
			CPUInfo.cpp \
			Packets.cpp \
			RamModule.cpp

OBJ		= $(SRC:.cpp=.o)

CC		= clang++
FLAGS	= -Wall -Wextra -Werror
INC		= -I SFML/include
FW1		= -F SFML/Frameworks
FW2		= -framework sfml-graphics -framework sfml-window -framework sfml-system 
LIB		= -lncurses

all:
ifneq ($(wildcard SFML/.*),)

		$(CC) $(INC) $(FLAGS) -c $(SRC)
		$(CC) $(FW1) $(FW2) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
		@clear
		@echo "first, run the command below in your terminal; then run ./ft_gkrellm"
		@echo export DYLD_FRAMEWORK_PATH=$(PWD)/SFML/Frameworks
else
		curl -L https://www.sfml-dev.org/files/SFML-2.4.2-osx-clang.tar.gz -o sfml.tgz
		mkdir SFML
		tar xvzf sfml.tgz -C SFML --strip-components 1
		mv SFML/extlibs/* SFML/Frameworks
#		curl -L 'https://github.com/caarlos0-graveyard/msfonts/raw/master/fonts/arial.ttf' -o arial.ttf
		@clear
		@echo "i got my files, now run make again"
		@rm -rf sfml.tgz
endif

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
