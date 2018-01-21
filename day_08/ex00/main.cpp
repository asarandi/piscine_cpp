/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:37:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/18 19:44:58 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <algorithm>

template <class T>
int	easyfind(T container, int item )
{
	if (std::find(container.begin(), container.end(), item) == container.end())
		throw std::exception();
	return (item);
}

int	main ( void )
{
	std::vector<int>	v;
	v.push_back(25);
	v.push_back(45);
	v.push_back(12);
	v.push_back(76);

	try {	std::cout << easyfind(v, 45) << std::endl;		}
	catch (std::exception)
		{	std::cout << "exception!! number not found!" << std::endl;	}

	std::list<int>	lst;
	lst.push_back(12);
	lst.push_back(23);
	lst.push_back(34);
	lst.push_back(45);
	lst.push_back(56);

	try {	std::cout << easyfind(lst, 56) << std::endl;	}
	catch (std::exception)
		{	std::cout << "exception!! number not found!" << std::endl;	}



	return 0;
}
