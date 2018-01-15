/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:05:27 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Entity.hpp"
#include <ncurses.h>

Entity::Entity(int x, int y) : x(x), y(y)
{
	return ;
}

Entity::~Entity()
{
	return ;
}

Entity::Entity( const Entity& other )
{
	*this = other;
	return ;
}

Entity &Entity::operator=( const Entity& rhs )
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

void	Entity::clear_position()
{
	mvaddch(this->y, this->x, ' ');
}

void	Entity::clear_previous()
{
	mvaddch(this->py, this->px, ' ');
}
