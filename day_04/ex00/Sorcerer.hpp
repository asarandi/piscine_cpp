/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 01:36:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class	Sorcerer
{
	public:
		std::string	name;
		std::string	title;

		Sorcerer(std::string name, std::string title);
		~Sorcerer();
		Sorcerer(const Sorcerer& other);
		Sorcerer& operator=(const Sorcerer& rhs);
		void	polymorph(Victim const &);
};

std::ostream	&operator<<( std::ostream& os, const Sorcerer & rhs );

#endif
