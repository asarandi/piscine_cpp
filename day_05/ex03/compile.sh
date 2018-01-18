#!/bin/bash
rm -rf alpha
rm -rf *.o
clang++ -Wall -Werror -Wextra Bureaucrat.cpp Form.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp -o alpha
