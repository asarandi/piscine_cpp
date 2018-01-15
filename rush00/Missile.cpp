/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:05:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Missile.hpp"
#include "Entity.hpp"

Missile::Missile(int x, int y) : Entity::Entity(x, y)
{
	this->next = NULL;
	this->face = ACS_BULLET;
	this->color = COLOR_CYAN;
	this->background = COLOR_BLACK;
	this->pair = 2;
	return ;
}

Missile::~Missile()
{
	return ;
}

Missile::Missile( const Missile& other ) : Entity::Entity(other)
{
	*this = other;
	return ;
}

Missile &Missile::operator=( const Missile& rhs )
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
