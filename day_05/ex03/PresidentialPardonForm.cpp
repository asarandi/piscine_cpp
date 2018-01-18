/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 23:54:34 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
	this->_target = target;	
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )  : Form("Presidential Pardon Form", 25, 5)
{
	*this = other;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs )
{
	Form::operator=(rhs);
	return *this;
}

const char*	PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "ERROR [Presidential Pardon Form]: Grade too high";
}

const char*	PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "ERROR [Presidential Pardon Form]: Grade too low";
}

std::ostream	&operator<<( std::ostream& os, const PresidentialPardonForm & rhs)
{
	os << "Form name: " << rhs.getName();
	os << ", is signed?: " << rhs.isSigned();
	os << ", grade to sign: " << rhs.getGradeToSign();
	os << ", grade to execute: " << rhs.getGradeToExec();
	os << std::endl;
	return (os);
}

void	PresidentialPardonForm::action() const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}
