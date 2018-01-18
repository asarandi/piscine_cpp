/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 16:51:37 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->_name = name;
	this->_grade = grade;
	
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	*this = other;
	return ;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& rhs )
{
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();

	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
	
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException(); 
	this->_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}

std::ostream	&operator<<( std::ostream& os, const Bureaucrat & rhs)
{
	os << rhs.getName();
	os << ", bureaucrat grade ";
	os << rhs.getGrade();
	os << std::endl;
	return (os);
}

void	Bureaucrat::executeForm(Form const & form) const
{
	std::cout << this->_name << " executes form " << form.getName() << std::endl;
	form.execute(*this);
	return ;
}
