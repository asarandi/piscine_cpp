/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 17:22:17 by asarandi         ###   ########.fr       */
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
		Form* result = new RobotomyRequestForm::RobotomyRequestForm(targetName);
		std::cout << "Intern creates a " << std::endl;
		std::cout << result->getName() << std::endl;
		std::cout << " (s. grade " << result->getGradeToSign();
		std::cout << ", ex.grade " << result->getGradeToExec();
		std::cout << ") targeted on " << result->getTarget();
		if (result->isSigned() == true)
			std::cout << " (Signed)" << std::endl;
		else
			std::cout << " (Unsigned)" << std::endl;

		return result;
	}
	if (formName.compare("shrubbery creation") == 0)
	{
		Form* result = new ShrubberyCreationForm::ShrubberyCreationForm(targetName);
		std::cout << "Intern creates a ";
		std::cout << result->getName();
		std::cout << " (s. grade " << result->getGradeToSign();
		std::cout << ", ex.grade " << result->getGradeToExec();
		std::cout << ") targeted on " << result->getTarget();
		if (result->isSigned() == true)
			std::cout << " (Signed)" << std::endl;
		else
			std::cout << " (Unsigned)" << std::endl;
		return result;

	}
	if (formName.compare("presidential pardon") == 0)
	{
		Form* result = new PresidentialPardonForm::PresidentialPardonForm(targetName);

		std::cout << "Intern creates a ";
		std::cout << result->getName();
		std::cout << " (s. grade " << result->getGradeToSign();
		std::cout << ", ex.grade " << result->getGradeToExec();
		std::cout << ") targeted on " << result->getTarget();
		if (result->isSigned() == true)
			std::cout << " (Signed)" << std::endl;
		else
			std::cout << " (Unsigned)" << std::endl;

		return result;
	
	}
	throw Intern::FormNameUnknownException();
	return NULL;
}

const char* Intern::FormNameUnknownException::what() const throw()
{
	return "EXCEPTION: Unknow Form Name!!";
}
