/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:12:52 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 17:32:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);

	try
	{
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (OfficeBlock::internFailedException & e)
	{
	/* specific known error happens, say something */
		std::cout << "exception: office block failed to do bureacracy because the [intern] failed" << std::endl;
	}
	catch (OfficeBlock::signerFailedException & e)
	{
	/* specific known error happens, say something */
		std::cout << "exception: office block failed to do bureacracy because the [signer] failed" << std::endl;

	}
	catch (OfficeBlock::executorFailedException & e)
	{
	/* specific known error happens, say something */
		std::cout << "exception: office block failed to do bureacracy because the [executor] failed" << std::endl;

	}
	catch (PresidentialPardonForm::GradeTooLowException & e)
	{
		std::cout << "exception: office block failed to do bureaucracy because the signer's grade is too low" << std::endl;
	}
	catch (Intern::FormNameUnknownException())
	{
		std::cout << "exception: office block failed to do bureaucracy because the intern doesnt recognize the form name" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "generic exception: office block failed to do bureacray because 'because'" << std::endl;
	/* oh god, unknown error, what to do ?! */
	}











}
