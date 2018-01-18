/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 23:55:00 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include <fstream>


RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45)
{
	this->_target = target;	
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )  : Form("Robotomy Request Form", 72, 45)
{
	*this = other;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs )
{
	Form::operator=(rhs);
	return *this;
}

const char*	RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "ERROR [Robotomy Request Form]: Grade too high";
}

const char*	RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "ERROR [Robotomy Request Form]: Grade too low";
}

std::ostream	&operator<<( std::ostream& os, const RobotomyRequestForm & rhs)
{
	os << "Form name: " << rhs.getName();
	os << ", is signed?: " << rhs.isSigned();
	os << ", grade to sign: " << rhs.getGradeToSign();
	os << ", grade to execute: " << rhs.getGradeToExec();
	os << std::endl;
	return (os);
}

void	RobotomyRequestForm::action() const
{
	std::srand(std::time(0) ^ std::rand());
	std::cout << " * DRILLL ** DDRRRILLLLL *** DDDDRRRRRIIIIIILLLLLLLLLLL ****" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << " Failed to robotomize " << this->_target << std::endl;

	return ;

}
