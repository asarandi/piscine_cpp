/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:04:18 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/10 21:30:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PONY_H
# define CLASS_PONY_H

#include <iostream>

class	Pony
{

private:
	std::string	_name;

public:
int		age;
		Pony(std::string name);
		~Pony();



};

#endif
