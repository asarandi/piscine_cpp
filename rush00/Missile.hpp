/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 21:41:57 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
# define MISSILE_HPP

#include <iostream>
#include <ncurses.h>
#include "Entity.hpp"

class	Missile : public Entity
{
	public:
		Missile	*next;

		Missile(int x, int y);
		virtual	~Missile();
		Missile( const Missile& other );
		Missile& operator=( const Missile& rhs );
};

#endif
