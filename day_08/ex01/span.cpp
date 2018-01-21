/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 02:13:12 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/19 04:19:37 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "span.hpp"

Span::Span(unsigned int n)
{
	this->_array = std::vector<int>(n);
	this->_n = n;
	this->_count = 0;
}

Span::~Span(void)
{
	return ;
}

Span::Span( const Span& other)
{
	*this = other;
	return ;
}

Span &Span::operator=(const Span& rhs)
{
	this->_array = rhs._array;
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->_count >= this->_n)
	{
		throw Span::vectorFullException();
		return ;
	}
	this->_array[this->_count] = n;
	this->_count += 1;
	return ;
}

void	Span::fillWithRandoms()
{
	if (this->_count >= this->_n)
	{
		throw Span::vectorFullException();
		return ;
	}
	while (this->_count < this->_n)
	{
		std::srand(std::time(0) ^ std::rand());
		int i = std::rand();
		this->addNumber(i);
	}
}

void	Span::fillWithRandoms(int max_value)
{
	if (this->_count >= this->_n)
	{
		throw Span::vectorFullException();
		return ;
	}
	while (this->_count < this->_n)
	{
		std::srand(std::time(0) ^ std::rand());
		int i = std::rand();
		this->addNumber(i % max_value);
	}
}

int		Span::shortestSpan()
{
	if (this->_count < 2)
	{
		throw Span::noSpanException();
		return (0);
	}

	std::vector<int>	tempo = this->_array;

	std::sort(tempo.begin(), tempo.end());
	int shortest = INT_MAX;
	std::vector<int>::iterator j = tempo.begin();
	std::vector<int>::iterator k = tempo.begin();
	k++;
	while (k != tempo.end())
	{
		if (*k - *j < shortest)
			shortest = *k - *j;
		j++;
		k++;
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (this->_count < 2)
	{
		throw Span::noSpanException();
		return (0);
	}

	std::vector<int>	tempo = this->_array;
	int max = *std::max_element(tempo.begin(), tempo.end() - 1);
	int min = *std::min_element(tempo.begin(), tempo.end() - 1);

	return (max - min);
}

void Span::print(void)
{
	std::vector<int>::iterator j = this->_array.begin();
	std::vector<int>::iterator k = this->_array.end();
	std::cout << "array: ";
	while (j != k)
	{
		std::cout << *j << ", ";
		j++;
	}
	std::cout << std::endl;
}

Span::vectorFullException::vectorFullException()
{
	return ;
}

Span::vectorFullException::~vectorFullException() throw()
{
	return ;
}

Span::vectorFullException::vectorFullException(const Span::vectorFullException::vectorFullException& other)
{
	*this = other;
	return ;
}
Span::vectorFullException &Span::vectorFullException::operator=(const Span::vectorFullException::vectorFullException& rhs)
{
	(void)rhs;
	return *this;
}
const char* Span::vectorFullException::vectorFullException::what() const throw()
{
	return "error: can't add more data, vector is full";
}

Span::noSpanException::noSpanException()
{
	return ;
}

Span::noSpanException::~noSpanException() throw()
{
	return ;
}

Span::noSpanException::noSpanException(const Span::noSpanException& other)
{
	*this = other;
	return ;
}
Span::noSpanException &Span::noSpanException::operator=(const Span::noSpanException& rhs)
{
	(void)rhs;
	return *this;
}
const char* Span::noSpanException::noSpanException::what() const throw()
{
	return "error: not enough data, vector must have at least two elements";
}

