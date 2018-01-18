/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 04:21:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/18 04:24:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class	Array
{
	private:
		T		*		_array;
		unsigned int	_n;

	public:
		Array();
		Array(unsigned int);
		Array( const Array& other);
		Array& operator=( const Array& rhs);
		T& operator[]( unsigned int n) const;
		~Array();
		unsigned int	size() const;

};

template <typename T>
Array<T>::Array()
{
	this->_array = NULL;
	this->_n = 0;
	return ;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_array != NULL)
		delete (this->_array);
	this->_n = 0;
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	T * array = new T[n];
	unsigned int i = 0;
	while (i < n)
		array[i++] = * new T();
	this->_array = array;
	this->_n = n;
	return ;
}

template <typename T>
Array<T>::Array( const Array<T> &other )
{
	*this = other;
	return ;
}

template <typename T>
T &Array<T>::operator[]( unsigned int n ) const
{	
	if (n < this->_n)
	{
		return this->_array[n];
	}
	else
	{
		std::cout << "Index out of bounds !!" << std::endl;
		throw (std::exception());
		return this->_array[0];
	}
}

template <typename T>
Array<T> &Array<T>::operator=( const Array<T> &rhs )
{
	this->_n = rhs.size();

	this->_array = new T[this->_n];

	unsigned int	i = 0;
	while (i < this->_n)
	{
		this->_array[i] = rhs[i];
		i++;
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_n;
}
