/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 01:40:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Intern.hpp"
//#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern::Intern( const Intern& other )
{
	*this = other;
	return ;
}

Intern &Intern::operator=( const Intern& rhs)
{
	(void)rhs;
	return *this;
}

Form*	Intern::makeForm(std::string formName, std::string targetName)
{
	if (formName.compare("robotomy request") == 0)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm::RobotomyRequestForm(targetName);
	}
	if (formName.compare("shrubbery creation") == 0)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm::ShrubberyCreationForm(targetName);
	}
	if (formName.compare("presidential pardon") == 0)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm::PresidentialPardonForm(targetName);
	}
	throw Intern::FormNameUnknownException();
	return NULL;
}

const char* Intern::FormNameUnknownException::what() const throw()
{
	return "EXCEPTION: Unknow Form Name!!";
}
