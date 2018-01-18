/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 17:48:05 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "OfficeBlock.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

OfficeBlock::OfficeBlock()
{
//	this->_intern = NULL;
//	this->_signer = NULL;
//	this->_executor = NULL;
	return ;
}

OfficeBlock::~OfficeBlock()
{
	return ;
}

void	OfficeBlock::setIntern(Intern::Intern interno)
{
	this->_intern = &interno;
	return ;
}


void	OfficeBlock::setSigner(Bureaucrat::Bureaucrat signer)
{
	this->_signer = &signer;
	return ;
}

void	OfficeBlock::setExecutor(Bureaucrat::Bureaucrat executor)
{
	this->_executor = &executor;
	return ;
}

void	OfficeBlock::doBureaucracy(std::string formName, std::string targetName)
{

	try
	{
		Form	*newform = this->_intern->makeForm(formName, targetName);
		newform->beSigned(*this->_signer);
		newform->execute(*this->_executor);
		return ;
	}
	catch (Intern::FormNameUnknownException())
	{
		std::cout << "intern doesnt know the name of the form" << std::endl;
		throw OfficeBlock::internFailedException();
	}
	catch (PresidentialPardonForm::GradeTooLowException())
	{
		std::cout << "bureaucrat's grade is too low" << std::endl;
		throw OfficeBlock::signerFailedException();
	}

	return ;

}

const char* OfficeBlock::internFailedException::what() const throw()
{
	return "doBureaucracy EXCEPTION: Intern failed !!";
}

const char* OfficeBlock::signerFailedException::what() const throw()
{
	return "doBureaucracy EXCEPTION: Signer failed !!";
}

const char* OfficeBlock::executorFailedException::what() const throw()
{
	return "doBureaucracy EXCEPTION: Executor failed !!";
}
