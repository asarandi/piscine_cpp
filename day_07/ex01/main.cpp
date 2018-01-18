/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:37:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/18 00:11:43 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T array[], int size, void (func) (T &) )
{
	int i = 0;
	while (i < size)
		func(array[i++]);
}

template <typename T>
void	print_item(T & x)
{
	std::cout << x << " ";
}

template <typename T>
void	add_one(T & x)
{
	x += 1;
}

void	add_one(std::string & x)
{
	size_t i = 0;
	while (x[i])
	{
		x[i] += 1;
		i++;
	}
}


template <typename T>
void	sub_two(T & x)
{
	x -= 2;
}

void	sub_two(std::string & x)
{
	size_t i = 0;
	while (x[i])
	{
		x[i] -= 2;
		i++;
	}
}







int	main ( void )
{

	int b[] = {0, 3, 5, 7, 8, 1, 23};
	int size = sizeof(b) / sizeof(int);
	iter(b, size, &print_item);	std::cout << std::endl;
	iter(b, size, &add_one);
	iter(b, size, &print_item);	std::cout << std::endl;

	std::string c[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zetha", "eta"};
	size = sizeof(c) / sizeof(std::string);
	iter(c, size, &print_item);	std::cout << std::endl;
	iter(c, size, &add_one);
	iter(c, size, &print_item);	std::cout << std::endl;

	double d[] = {-1.23, 0.34, 1.45, 2.56, 3.67, 4.78, 5.89};
	size = sizeof(d) / sizeof(double);
	iter(d, size, &print_item);	std::cout << std::endl;
	iter(d, size, &add_one);
	iter(d, size, &print_item);	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	size = sizeof(b) / sizeof(int);
	iter(b, size, &print_item);	std::cout << std::endl;
	iter(b, size, &sub_two);
	iter(b, size, &print_item);	std::cout << std::endl;

	size = sizeof(c) / sizeof(std::string);
	iter(c, size, &print_item);	std::cout << std::endl;
	iter(c, size, &sub_two);
	iter(c, size, &print_item);	std::cout << std::endl;

	size = sizeof(d) / sizeof(double);
	iter(d, size, &print_item);	std::cout << std::endl;
	iter(d, size, &sub_two);
	iter(d, size, &print_item);	std::cout << std::endl;

	return 0;
}
