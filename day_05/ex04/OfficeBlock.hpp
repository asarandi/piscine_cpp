/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/16 16:36:13 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include <iostream>
#include <exception>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

//class	Intern;
//class	Bureaucrat;

class	OfficeBlock
{
	private:
		Intern			*_intern;
		Bureaucrat		*_signer;
		Bureaucrat		*_executor;

	public:
		OfficeBlock();
		virtual	~OfficeBlock();

		void	setIntern(Intern::Intern 		interno);
		void	setSigner(Bureaucrat::Bureaucrat	signer);
		void	setExecutor(Bureaucrat::Bureaucrat	executor);
		void	doBureaucracy(std::string formName, std::string targetName);


		class	internFailedException : public std::exception
		{
			virtual	const char *what() const throw();
		};

		class	signerFailedException : public std::exception
		{
			virtual	const char *what() const throw();
		};

		class	executorFailedException : public std::exception
		{
			virtual	const char *what() const throw();
		};


};

#endif
