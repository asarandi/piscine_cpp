/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:38:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 01:20:17 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
	return ;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", is dead. ";
	std::cout << "Consequences will never be the same !" << std::endl;
	return ;
}

Sorcerer	&Sorcerer::operator=( const Sorcerer & rhs )
{
	this->name = rhs.name;
	this->title = rhs.title;
	return (*this);
}

Sorcerer::Sorcerer( const Sorcerer & rhs )
{
	*this = rhs;
	return ;
}

std::ostream	&operator<<( std::ostream& os, const Sorcerer & rhs)
{
	os << "I am " << rhs.name << ", " << rhs.title;
	os << ", and I like ponies !" << std::endl;
	return (os);
}

void	Sorcerer::polymorph(Victim const &vic)
{
	vic.getPolymorphed();
	return ;
}
