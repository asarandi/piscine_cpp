/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 01:39:01 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class	Victim
{
	public:
		std::string	name;

		Victim(std::string name);
		~Victim();
		Victim(const Victim& other);
		Victim& operator=(const Victim& rhs);
		virtual void	getPolymorphed() const;

};

std::ostream	&operator<<( std::ostream& os, const Victim & rhs );

#endif
