/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 23:54:51 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class	RobotomyRequestForm : public Form
{

	private:
		std::string 	_target;

	public:
		RobotomyRequestForm(std::string target);
		virtual	~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );

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

std::ostream	&operator<<( std::ostream& os, const RobotomyRequestForm & rhs );

#endif
