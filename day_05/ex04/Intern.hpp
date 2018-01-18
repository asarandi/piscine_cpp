/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 01:17:17 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>

class	Form;
class	PresidentialPardonForm;
class	RobotomyRequestForm;
class	ShrubberyCreationForm;

class	Intern
{
	public:
		Intern();
		virtual	~Intern();
		Intern( const Intern& other );
		Intern& operator=( const Intern& rhs );


		Form* makeForm(std::string formName, std::string targetName);

		class	FormNameUnknownException : public std::exception
		{
			virtual	const char *what() const throw();
		};

};

#endif
