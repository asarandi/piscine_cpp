/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:15:14 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/10 21:51:08 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>


void	ponyOnTheStack(std::string name)
{
	Pony	theMule(name);

	std::cout << " .. first line of 'ponyOnTheStack' function" << std::endl;
	theMule.age = 12;
	std::cout << " .. last line of 'ponyOnTheStack' function" << std::endl;
}

void	ponyOnTheHeap(std::string name)
{
	Pony	*theMule;

	std::cout << " .. first line of 'ponyOnTheHeap' function" << std::endl;
	theMule = new Pony(name);
	theMule->age = 15;
	delete(theMule);
	std::cout << " .. last line of 'ponyOnTheHeap' function" << std::endl;

}

int	main()
{
	ponyOnTheStack("El Burrito");
	std::cout << std::endl << std::endl;
	ponyOnTheHeap("Oscar");

	return(0);

}
