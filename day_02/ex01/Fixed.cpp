/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:55:24 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/11 23:40:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=( const Fixed & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_n = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<( std::ostream& os, const Fixed & rhs)
{
	os << (float)rhs.getRawBits();
	return (os);
}

Fixed::Fixed( const Fixed & rhs )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return ;
}

Fixed::Fixed( const int i )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i);
	return ;
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)f);
	return ;
}

float	Fixed::toFloat ( void ) const
{
	float	f;

	std::cout << "toFloat member function called" << std::endl;
	f = (float)this->getRawBits();
	return (f);
}

int		Fixed::toInt ( void ) const
{
	std::cout << "toInt member function called" << std::endl;
	return (this->getRawBits());
}


int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
	return ;
}

