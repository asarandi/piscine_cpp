/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:38:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 19:40:18 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type)
{
	return ;
}

Enemy::~Enemy()
{
	return ;
}

Enemy	&Enemy::operator=( const Enemy & rhs )
{
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();
	return (*this);
}

Enemy::Enemy( const Enemy & rhs )
{
	*this = rhs;
	return ;
}


std::string	Enemy::getType() const
{
	return this->_type;
}

int	Enemy::getHP() const
{
	return this->_hp;
}


void	Enemy::takeDamage(int damage)
{
	if (this->_hp < 0)
		return ;
	this->_hp -= damage;
	return ;
}

