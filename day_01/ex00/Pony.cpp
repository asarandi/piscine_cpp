/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:03:53 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/10 21:40:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "hello, my name is [" << this->_name << "] and i am a pony" << std::endl;
}

Pony::~Pony()
{
	std::cout << "bye! pony [" << this->_name << "] is now gone at the age of [" << this->age << "]" << std::endl;
}
