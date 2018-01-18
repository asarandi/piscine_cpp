/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 23:54:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137)
{
	this->_target = target;	
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )  : Form("Shrubbery Creation Form", 145, 137)
{
	*this = other;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs )
{
	Form::operator=(rhs);
	return *this;
}

const char*	ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "ERROR [Shubbery Creation Form]: Grade too high";
}

const char*	ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "ERROR [Shubbery Creation Form]: Grade too low";
}

std::ostream	&operator<<( std::ostream& os, const ShrubberyCreationForm & rhs)
{
	os << "Form name: " << rhs.getName();
	os << ", is signed?: " << rhs.isSigned();
	os << ", grade to sign: " << rhs.getGradeToSign();
	os << ", grade to execute: " << rhs.getGradeToExec();
	os << std::endl;
	return (os);
}

void	ShrubberyCreationForm::action() const
{
	std::string fn = this->_target;
	fn.append("_shrubbery");
	std::ofstream	fd;
	fd.open(fn);

 	fd << "                     ; ; ;"	<< std::endl;
 	fd << "                   ;        ;  ;     ;;    ;"	<< std::endl;
 	fd << "                ;                 ;         ;  ;"	<< std::endl;
 	fd << "                                ;"	<< std::endl;
 	fd << "                               ;                ;;"	<< std::endl;
 	fd << "               ;          ;            ;              ;"	<< std::endl;
 	fd << "               ;            ';,        ;               ;"	<< std::endl;
 	fd << "               ;              'b      *"	<< std::endl;
 	fd << "                ;              '$    ;;                ;;"	<< std::endl;
 	fd << "               ;    ;           $:   ;:               ;"	<< std::endl;
 	fd << "             ;;      ;  ;;      *;  @):        ;   ; ;"	<< std::endl;
 	fd << "                          ;     :@,@):   ,;**:'   ;"	<< std::endl;
 	fd << "              ;      ;,         :@@*: ;;**'      ;   ;"	<< std::endl;
 	fd << "                       ';o;    ;:(@';@*'   ;"	<< std::endl;
 	fd << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;"	<< std::endl;
 	fd << "                          ,p$q8,:@)'  ;p*'      ;"	<< std::endl;
 	fd << "                   ;     '  ; '@@Pp@@*'    ;  ;"	<< std::endl;
 	fd << "                    ;  ; ;;    Y7'.'     ;  ;"	<< std::endl;
 	fd << "                              :@):."	<< std::endl;
 	fd << "                             .:@:'."	<< std::endl;
 	fd << "                           .::(@:.      -Sam Blumenstein-"	<< std::endl;

	fd.close();

	return ;

}
