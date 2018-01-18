/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:12:52 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 17:28:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main()
{
//////////////
	try
	{
		Bureaucrat	alpha("Centauri", 149);
		std::cout << alpha;		alpha.decrementGrade();
		std::cout << alpha;		alpha.decrementGrade();
		std::cout << alpha;		alpha.decrementGrade();
		std::cout << alpha;		alpha.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "CAUGHT EXCEPTION!! " << e.what() << std::endl << std::endl;
	}
/////////////
	try
	{
		Bureaucrat	beta("Big dipper", 2);
		std::cout << beta;		beta.incrementGrade();
		std::cout << beta;		beta.incrementGrade();
		std::cout << beta;		beta.incrementGrade();
		std::cout << beta;		beta.incrementGrade();
		std::cout << beta;		beta.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "cAUGHT aNOTHER eXCEPTION!! " << e.what() << std::endl << std::endl;
	}
///////////////
	try
	{
		Bureaucrat	theta("Tyranosaurus", 167);
		std::cout << theta;		theta.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "OMG MOAR EXCEPSHIONZ!! " << e.what() << std::endl << std::endl;
	}

///////////////
	try
	{
		Bureaucrat	omega("Oh mega", 0);
		std::cout << omega;		omega.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "its not a bug, its a feature!! " << e.what() << std::endl << std::endl;
	}

///////////////
	std::cout << "FIN!" << std::endl;






	return 0;
}
