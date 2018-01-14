/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:47:07 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/10 23:36:52 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>


/*
**  g++ -Wall -Werror -Wextra -c *.cpp   
**  g++ -Wall -Werror -Wextra *.o -o zomb
*/






int	main()
{
	ZombieEvent newevent; //stack

	Zombie::Zombie *newzo; //heap

	newzo = newevent.newZombie("Trololo"); //returns heap
	newevent.setZombieType(newzo, "hilarious");

	newzo->announce();

	delete(newzo); //must be deleted




	ZombieEvent	*another = new ZombieEvent;
	Zombie::Zombie *walking;

	walking = another->newZombie("Muahaha");
	another->setZombieType(walking, "DEADO");
	walking->announce();

	delete (walking);
	delete (another);



	return (0);
}
