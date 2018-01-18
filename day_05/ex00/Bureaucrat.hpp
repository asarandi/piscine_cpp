/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/15 17:29:16 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class	Bureaucrat
{

	private:
		std::string 	_name;
		int				_grade;

	public:
		Bureaucrat(std::string name, int grade);
		virtual	~Bureaucrat();
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& rhs );

		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();

		class	GradeTooHighException : public std::exception
		{
			virtual	const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual	const char *what() const throw();
		};

};

std::ostream	&operator<<( std::ostream& os, const Bureaucrat & rhs );

#endif
