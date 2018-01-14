/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:38:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 01:33:44 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}

Peon	&Peon::operator=( const Peon & rhs )
{
	this->name = rhs.name;
	return (*this);
}

Peon::Peon( const Peon & rhs ) : Victim(rhs)
{
	*this = rhs;
	return ;
}

void	Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony !" << std::endl;
}

std::ostream	&operator<<( std::ostream& os, const Peon & rhs)
{
	os << "I am " << rhs.name;
	os << " and I like otters !" << std::endl;
	return (os);
}

