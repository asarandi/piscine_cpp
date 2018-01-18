/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 03:18:34 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/17 05:03:55 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <math.h>
#include <float.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		double d;
		try
		{
			d = std::stod(av[1]);
		}
		catch (std::invalid_argument & e)
		{
			std::cout << "Invalid argument exception: " << e.what() << std::endl;
			return 0;
		}
		catch (std::out_of_range & e)
		{
			std::cout << "Value out of range Exception: " << e.what() << std::endl;
			return 0;
		}

		float	f;
		long	lo;
		bool	valid_long = false;
		int		i;
		bool	valid_int = false;
		char	c;
		bool	valid_char = false;

		f = static_cast<float>(d);

		try
		{
			lo = std::stol(av[1]);
			valid_long = true;
		}
		catch (std::invalid_argument & e) { }	
		catch (std::out_of_range & e) { }
	
		if (valid_long == true)
		{
			if ((lo >= INT_MIN) && (lo <= INT_MAX))
			{
				i = static_cast<int>(lo);
				valid_int = true;
				if ((i >= CHAR_MIN) && (i <= CHAR_MAX))
				{
					c = static_cast<char>(i);
					valid_char = true;
				}
			
			}
		}

		if (valid_char == true)
		{
			if (isprint(c))
			{
				std::cout << "char: '" << c << "'" << std::endl;
			}
			else
			{
				std::cout << "char: Non displayable" << std::endl;
			}
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
		}

		if (valid_int == true)
		{
			std::cout << "int: " << i << std::endl;

		}
		else
		{
			std::cout << "int: impossible" << std::endl;
		}

		std::cout << "float: ";
		if ((isinf(f)) && (f > 0))
			std::cout << "+";
		std::cout << std::setprecision(1) << std::fixed << f;
		std::cout << "f" << std::endl;

		std::cout << "double: ";
		if ((isinf(d)) && (d > 0))
			std::cout << "+";
		std::cout << std::setprecision(1) << std::fixed << d << std::endl;


	}
	return 0;
}
