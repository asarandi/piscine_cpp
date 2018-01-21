/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:53:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/19 05:46:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack	: public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;

	MutantStack() : std::stack<T>()
	{
		return ;
	}

	~MutantStack(void)
	{
		return ;
	}

	MutantStack( const MutantStack& other) : std::stack<T>(other)
	{
		return ;
	}

	MutantStack &operator=(const MutantStack& rhs)
	{
		std::stack<T>::operator=(rhs);
		return *this;
	}

	T &operator[](const T& rhs)
	{	
		return this->c.operator[](rhs);
	}


	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}
};

#endif
