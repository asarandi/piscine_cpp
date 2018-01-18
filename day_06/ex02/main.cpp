/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 03:18:34 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/17 10:07:14 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class	Base
{
	public:
		virtual ~Base();
};

class	A	:	public Base { };
class	B	:	public Base { };
class	C	:	public Base { };

Base::~Base()
{
	return ;
}

Base * generate (void )
{
	std::srand(std::time(0) ^ std::rand());
	int i = std::rand() % 3;

	if (i == 0)
		return new A;
	if (i == 1)
		return new B;
	return new C;
}

void identify_from_pointer( Base * p )
{
	A * ap;
	B * bp;
	C * cp;

	ap = dynamic_cast<A *>(p);
	if (ap != NULL)
		std::cout << "A" << std::endl;
	bp = dynamic_cast<B *>(p);
	if (bp != NULL)
		std::cout << "B" << std::endl;
	cp = dynamic_cast<C *>(p);
	if (cp != NULL)
		std::cout << "C" << std::endl;

}

void identify_from_reference( Base & p )
{
	A * ap;
	B * bp;
	C * cp;

	ap = dynamic_cast<A *>(&p);
	if (ap != NULL)
		std::cout << "A" << std::endl;
	bp = dynamic_cast<B *>(&p);
	if (bp != NULL)
		std::cout << "B" << std::endl;
	cp = dynamic_cast<C *>(&p);
	if (cp != NULL)
		std::cout << "C" << std::endl;

}

int	main( void )
{
	Base *ptr = generate();
	std::cout << "From pointer: ";
	identify_from_pointer(ptr);
	std::cout << "From reference: ";
	identify_from_reference(*ptr);



	return 0;
}
