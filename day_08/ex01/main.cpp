/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:37:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/19 04:23:15 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include "span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;



	Span zp	= Span(20);		//vector of 100 elements
	zp.fillWithRandoms(1000);	//random values from 0 to 1000
	zp.print();					//print vector on screen

	std::cout << "shortest span: " << zp.shortestSpan() << std::endl;
	std::cout << " longest span: " << zp.longestSpan() << std::endl;


/* comment this out to test the second exception */
	std::cout << "--- [exception test # 1] ------------" << std::endl;
	zp.addNumber(123); //    <<--- exception ..


/* exception # 2, mambo # 5 */
	std::cout << "--- [exception test # 2] ------------" << std::endl;
	Span xp = Span(10);
	xp.print();
	(void)xp.shortestSpan(); //  <<---- exception

	return 0;
}
