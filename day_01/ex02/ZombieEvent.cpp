/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:44:21 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/10 23:26:27 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

ZombieEvent::ZombieEvent()
{
}

ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(Zombie *subject, std::string type)
{
	subject->type = type;
}


Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie	*newguy;

	newguy = new Zombie;
	newguy->name = name;
	return (newguy);
}

