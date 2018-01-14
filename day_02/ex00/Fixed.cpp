/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:55:24 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/11 22:46:53 by asarandi         ###   ########.fr       */
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

Fixed::Fixed( const Fixed & rhs )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return ;
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
}

