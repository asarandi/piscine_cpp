/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 01:39:32 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class	Peon : public Victim
{
	public:
		Peon(std::string name);
		~Peon();
		Peon(const Peon& other);
		Peon& operator=(const Peon& rhs);
		virtual void	getPolymorphed() const;

};

std::ostream	&operator<<( std::ostream& os, const Peon & rhs );

#endif
