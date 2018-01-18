/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 18:54:00 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class	Form
{

	private:
		bool			_signed;
		int				_gradeToSign;
		int				_gradeToExec;
		std::string 	_name;

	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		virtual	~Form();
		Form( const Form& other );
		Form& operator=( const Form& rhs );

		bool			isSigned() const;
		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;
		void			beSigned(Bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			virtual	const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual	const char *what() const throw();
		};

};

std::ostream	&operator<<( std::ostream& os, const Form & rhs );

#endif
