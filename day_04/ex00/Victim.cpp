/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:38:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 01:25:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"

Victim::Victim(std::string name) : name(name)
{
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
	return ;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
	return ;
}

Victim	&Victim::operator=( const Victim & rhs )
{
	this->name = rhs.name;
	return (*this);
}

Victim::Victim( const Victim & rhs )
{
	*this = rhs;
	return ;
}

void	Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream	&operator<<( std::ostream& os, const Victim & rhs)
{
	os << "I am " << rhs.name;
	os << " and I like otters !" << std::endl;
	return (os);
}

