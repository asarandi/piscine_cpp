/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 23:54:25 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class	PresidentialPardonForm : public Form
{

	private:
		std::string 	_target;

	public:
		PresidentialPardonForm(std::string target);
		virtual	~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );

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

std::ostream	&operator<<( std::ostream& os, const PresidentialPardonForm & rhs );

#endif
