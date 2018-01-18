/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:37:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/18 04:26:16 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main ( void )
{


	Array<float>	alpha(10);
	alpha[0] = 1.1f;
	alpha[1] = 1.2f;
	alpha[2] = 1.3f;
	alpha[3] = 1.5f;
	alpha[4] = 2.4f;
	alpha[5] = 3.456f;

	Array<float>	beta = alpha;

	beta[0] = 3.14f;
	beta[1] = 42.24f;
	beta[2] = 1231.23f;
	beta[3] = 1.42f;
	beta[4] = 2.53f;
	beta[5] = 3.64f;
	beta[6] = 4.75f;
	beta[7] = 5.86f;
	beta[8] = 6.97f;
	beta[9] = 7.08f;
//	beta[10] = 12.3f; // index out of bounds

	unsigned int i = 0;
	while (i < alpha.size())
	{
		std::cout << "alpha: " << alpha[i] << "\tbeta: " << beta[i] << std::endl;
		i++;
	}


	std::cout << "--exception test---------------------------------" << std::endl;
	try
	{
		std::cout << alpha[10] << std::endl;
	}
	catch (std::exception)
	{
		std::cout << "caught std::exception" << std::endl;
	}

	return 0;
}
