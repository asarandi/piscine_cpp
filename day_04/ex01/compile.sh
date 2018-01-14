#!/bin/bash
rm -rf alpha
clang++ -Wall -Werror -Wextra AWeapon.cpp PlasmaRifle.cpp PowerFist.cpp Enemy.cpp SuperMutant.cpp RadScorpion.cpp Character.cpp main.cpp -o alpha
