/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 17:00:24 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class	ShrubberyCreationForm : public Form
{

	private:
//		std::string 	_target;

	public:
		ShrubberyCreationForm(std::string target);
		virtual	~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );

		class	GradeTooHighException : public std::exception
		{
			virtual	const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual	const char *what() const throw();
		};

		void	action() const;

};

std::ostream	&operator<<( std::ostream& os, const ShrubberyCreationForm & rhs );

#endif
