/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:38:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 21:37:18 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_gun = NULL;
	this->_ap = 40;
	return ;
}

Character::~Character()
{
	return ;
}

Character	&Character::operator=( const Character & rhs )
{
	this->_name = rhs.getName();
	this->_gun = rhs.getWeapon();
	this->_ap = rhs.getAP();

	return (*this);
}

Character::Character( const Character & rhs )
{
	*this = rhs;
	return ;
}

std::string	Character::getName() const
{
	return this->_name;
}

int	Character::getAP() const
{
	return this->_ap;
}

AWeapon*	Character::getWeapon() const
{
	return this->_gun;
}

void	Character::recoverAP()
{
	if (this->_ap + 10 >= 40)
		this->_ap = 40;
	else
		this->_ap += 10;
	return ;
}

void	Character::equip(AWeapon* wep)
{
	this->_gun = wep;
	return ;
}

void	Character::attack(Enemy* enem)
{
	if (this->_gun != NULL)
	{

		std::cout << this->getName() << " attacks " << enem->getType() << " with a " << this->_gun->getName() << std::endl;

		int apa = this->_gun->getAPCost();
		if (this->_ap < apa)
		{
			std::cout << "attack failed because " << this->getName() << " has only " << this->getAP() << " AP available" << std::endl;
			return ;
		}
		this->_ap -= apa;
		int dam = this->_gun->getDamage();
		enem->takeDamage(dam);
		this->_gun->attack();
		if (enem->getHP() < 0)
			delete enem;
	}
	return ;

}

std::ostream	&operator<<( std::ostream& os, const Character & rhs)
{
	os << rhs.getName();
	os << " has ";
	os << rhs.getAP();
	os << " AP and ";
	AWeapon* wep = rhs.getWeapon();
	if (wep == NULL)
		os << "is unarmed";
	else
		os << "wields a " << wep->getName();
	os << std::endl;
	return (os);
}

