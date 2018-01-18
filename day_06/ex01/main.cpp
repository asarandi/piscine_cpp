/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 03:18:34 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/17 09:28:49 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <iomanip>

struct Data
{ 
	std::string s1;
	int n;
	std::string s2;
};


std::string random8String()
{
	std::string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	std::string	result = "";

	int j = 0;
	while (j < 8)
	{
		std::srand(std::time(0) ^ std::rand());
		int i = std::rand() % table.size();
		result.append(table, i , 1);
		usleep( i );
		j++;
	}

	return result;

}

Data * deserialize( void * raw )
{

	unsigned char * uc = reinterpret_cast<unsigned char *>(raw);

	std::string *s1new = reinterpret_cast<std::string *>(uc);
	int			*nnew = reinterpret_cast<int * >(uc + sizeof(std::string));
	std::string *s2new = reinterpret_cast<std::string *>(uc + sizeof(std::string) + sizeof(int));

	Data * result = new Data;
	result->s1 = *s1new;
	result->n = *nnew;
	result->s2 = *s2new;

	return result ;
}


void	* serialize ( void )
{
	std::string		s1 = random8String();
	std::string		s2 = random8String();

	std::srand(std::time(0) ^ std::rand());
	int	n = std::rand();

	std::cout << "random string1: " << s1 << std::endl;
	std::cout << "random int: " << n << std::endl;
	std::cout << "random string2: " << s2 << std::endl << std::endl;

	unsigned char *raw = new unsigned char[sizeof(std::string) + sizeof(int) + sizeof(std::string)];

	int i = 0;
	unsigned long j = 0;
	unsigned char *s1uc = reinterpret_cast<unsigned char *>(&s1);
	while (j < sizeof(std::string))
	{
		raw[i] = s1uc[j];
		i++;
		j++;
	}
	j = 0;
	unsigned char *ptr = reinterpret_cast<unsigned char *>(&n);
	while (j < sizeof(int))
	{
		raw[i] = ptr[j];
		i++;
		j++;
	}
	j = 0;
	unsigned char *s2uc = reinterpret_cast<unsigned char *>(&s2);
	while (j < sizeof(std::string))
	{
		raw[i] = s2uc[j];
		i++;
		j++;
	}

	return (reinterpret_cast<void *>(raw));

}



int	main( void )
{
	void	*raw = serialize();

	std::cout << "s1 + n + s2   serialized: " << std::endl;

	int i = 0;
	int size = sizeof(std::string) * 2 + sizeof(int);
	while (i < size)
	{
		std::string hex = "0123456789ABCDEF";
		std::cout << hex.substr(reinterpret_cast<unsigned char *>(raw)[i] / 16, 1);
		std::cout << hex.substr(reinterpret_cast<unsigned char *>(raw)[i] % 16, 1);
		std::cout << " ";
		i++;
	}
	std::cout << std::endl;



	std::cout << "------------------------------------------" << std::endl;

	Data *des	= deserialize(raw);
	std::cout << "data is now deserialized " << std::endl;
	std::cout << "Data->s1: " << des->s1 << std::endl;
	std::cout << "Data-> n: " << des->n << std::endl;
	std::cout << "Data->s2: " << des->s2 << std::endl;

	return 0;
}
