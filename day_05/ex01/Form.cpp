/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 19:06:02 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form(std::string name, int gradeToSign, int gradeToExec)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();

	this->_signed = false;
	this->_name = name;
	this->_gradeToSign = gradeToSign;
	this->_gradeToExec = gradeToExec;
	
	return ;
}

Form::~Form()
{
	return ;
}

Form::Form( const Form& other )
{
	*this = other;
	return ;
}

Form &Form::operator=( const Form& rhs )
{
	this->_signed = rhs.isSigned();
	this->_name = rhs.getName();
	this->_gradeToSign = rhs.getGradeToSign();
	this->_gradeToExec = rhs.getGradeToExec();

	return *this;
}

bool		Form::isSigned() const
{
	return this->_signed;
}

std::string	Form::getName() const
{
	return this->_name;
	
}

int			Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int			Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

void		Form::beSigned(Bureaucrat bur)
{
	if (this->_signed == true)
	{
		std::cout << "Bureaucrat [" << bur.getName() << "] can't sign form [";
		std::cout << this->_name << "] because form is already signed" << std::endl;
		return ;
	}
	if (bur.getGrade() > this->_gradeToSign)
	{
		std::cout << "Bureaucrat [" << bur.getName() << "] can't sign form [";
		std::cout << this->_name << "] because his grade [" << bur.getGrade();
		std::cout << "] is too low; Throwing an exception!" << std::endl;
		throw Form::GradeTooLowException();
		return ;
	}
	std::cout << "Bureaucrat [" << bur.getName() << "] signs form [";
	std::cout << this->_name << "]" << std::endl;
	this->_signed = true;
	return ;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form Class Error: Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form Class Error: Grade too low";
}

std::ostream	&operator<<( std::ostream& os, const Form & rhs)
{
	os << "Form name: " << rhs.getName();
	os << ", is signed?: " << rhs.isSigned();
	os << ", grade to sign: " << rhs.getGradeToSign();
	os << ", grade to execute: " << rhs.getGradeToExec();
	os << std::endl;
	return (os);
}
