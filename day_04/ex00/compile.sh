#!/bin/bash
rm -rf alpha
clang++ -Wall -Werror -Wextra Peon.cpp Victim.cpp Sorcerer.cpp main.cpp -o alpha
