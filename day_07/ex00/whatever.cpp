/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:37:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/17 22:18:15 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T & x, T & y)
{
	T	z;

	z = x;
	x = y;
	y = z;
}

template <typename T>
T		min(T x, T y)
{
	return	( x < y ? x : y);
}


template <typename T>
T		max(T x, T y)
{
	return ( x > y ? x : y);
}




int	main ( void )
{

	char	c1 = 'a';
	char	c2 = 'b';
	std::cout << "before swap: c1=" << c1 << ", c2=" << c2 << std::endl;
	swap(c1, c2);
	std::cout << " after swap: c1=" << c1 << ", c2=" << c2 << std::endl;
	std::cout << "comparing c1=" << c1 << " and c2=" << c2;
	std::cout << "; minimum is: " << min(c1, c2) << std::endl;
	std::cout << "comparing c1=" << c1 << " and c2=" << c2;
	std::cout << "; maximum is: " << max(c1, c2) << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	int	i1 = 123;
	int i2 = 234;
	std::cout << "before swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	swap(i1, i2);
	std::cout << " after swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	std::cout << "comparing i1=" << i1 << " and i2=" << i2;
	std::cout << "; minimum is: " << min(i1, i2) << std::endl;
	std::cout << "comparing i1=" << i1 << " and i2=" << i2;
	std::cout << "; maximum is: " << max(i1, i2) << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	float	f1 = 0.1345f;
	float	f2 = 0.1346f;
	std::cout << "before swap: f1=" << f1 << ", f2=" << f2 << std::endl;
	swap(f1, f2);
	std::cout << " after swap: f1=" << f1 << ", f2=" << f2 << std::endl;
	std::cout << "comparing f1=" << f1 << " and f2=" << f2;
	std::cout << "; minimum is: " << min(f1, f2) << std::endl;
	std::cout << "comparing f1=" << f1 << " and f2=" << f2;
	std::cout << "; maximum is: " << max(f1, f2) << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	double	d1 = 178.98;
	double	d2 = 178.99;
	std::cout << "before swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	swap(d1, d2);
	std::cout << " after swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	std::cout << "comparing d1=" << d1 << " and d2=" << d2;
	std::cout << "; minimum is: " << min(d1, d2) << std::endl;
	std::cout << "comparing d1=" << d1 << " and d2=" << d2;
	std::cout << "; maximum is: " << max(d1, d2) << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	double d0 = 0;
	d1 = 1 / d0;
	d2 = -1 / d0;
	std::cout << "before swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	swap(d1, d2);
	std::cout << " after swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	std::cout << "comparing d1=" << d1 << " and d2=" << d2;
	std::cout << "; minimum is: " << min(d1, d2) << std::endl;
	std::cout << "comparing d1=" << d1 << " and d2=" << d2;
	std::cout << "; maximum is: " << max(d1, d2) << std::endl;
	std::cout << "--------------------------------------------" << std::endl;


	return 0;


}
