/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:38:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 19:35:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return ;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

SuperMutant	&SuperMutant::operator=( const SuperMutant & rhs )
{
	Enemy::operator=(rhs);
	return (*this);
}

SuperMutant::SuperMutant( const SuperMutant & rhs ) : Enemy(rhs)
{
	*this = rhs;
	return ;
}

void	SuperMutant::takeDamage(int damage)
{
	if (this->getHP() < 0)
		return ;
	if (damage >= 3)
		damage -= 3;
	this->Enemy::takeDamage(damage);
	return ;
}

