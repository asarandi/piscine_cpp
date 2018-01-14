/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:38:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/10 23:26:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class	ZombieEvent
{

public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void	setZombieType(Zombie::Zombie *subject, std::string type);
	Zombie	*newZombie(std::string name);
};


#endif
