/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Area.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:04:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Area.hpp"
#include "Entity.hpp"

Area::Area(int x, int y) : Entity::Entity(x, y)
{
	return ;
}

Area::~Area()
{
	return ;
}

Area::Area( const Area& other ) : Entity::Entity(other)
{
	*this = other;
	return ;
}

Area &Area::operator=( const Area& rhs )
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
