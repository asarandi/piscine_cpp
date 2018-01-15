/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:05:01 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Character.hpp"
#include "Entity.hpp"

Character::Character(int x, int y) : Entity::Entity(x, y)
{
	this->face = ACS_DIAMOND;
	this->color = COLOR_YELLOW;
	this->background = COLOR_BLACK;
	this->pair = 1;
	return ;
}

Character::~Character()
{
	return ;
}

Character::Character( const Character& other ) : Entity::Entity(other)
{
	*this = other;
	return ;
}

Character &Character::operator=( const Character& rhs )
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->px = rhs.px;
	this->py = rhs.py;
	this->color = rhs.color;
	this->background = rhs.background;
	this->pair = rhs.pair;
	this->face = rhs.face;

	return *this;
}
