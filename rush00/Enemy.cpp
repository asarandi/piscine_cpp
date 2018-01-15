/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:05:14 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Enemy.hpp"
#include "Entity.hpp"

Enemy::Enemy(int x, int y) : Entity::Entity(x, y)
{
	this->next = NULL;
	this->face = 'o';
	this->color = COLOR_MAGENTA;
	this->background = COLOR_BLACK;
	this->pair = 3;
	return ;
}

Enemy::~Enemy()
{
	return ;
}

Enemy::Enemy( const Enemy& other ) : Entity::Entity(other)
{
	*this = other;
	return ;
}

Enemy &Enemy::operator=( const Enemy& rhs )
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
