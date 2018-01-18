/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:12:52 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 00:04:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "---------------------------------------------------" << std::endl;



	Bureaucrat	omega("Oh-mega", 149);
	std::cout << omega;

	ShrubberyCreationForm	bush("FORREST");
	std::cout << bush;

	try
	{
		bush.execute(omega);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	try
	{
		bush.beSigned(omega);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	try
	{
		bush.execute(omega);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	Bureaucrat	delta("Del-tah", 14);
	RobotomyRequestForm	mush("Han Solo");
	std::cout << mush;

	try
	{
		mush.execute(delta);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	try
	{
		mush.beSigned(delta);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	try
	{
		mush.execute(delta);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}


	Bureaucrat	gamma("Jabba The Hutt", 3);
	PresidentialPardonForm	zush("Forrest Gump");
	std::cout << mush;

	try
	{
		zush.execute(delta);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	try
	{
		zush.beSigned(omega);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}

	try
	{
		zush.beSigned(delta);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}


	try
	{
		zush.execute(gamma);
		bush.beSigned(gamma);
		gamma.executeForm(bush);
	}
	catch (std::exception & e)
	{
		std::cout << "caught exception!! " << e.what() << std::endl << std::endl;
	}









	return 0;
}
