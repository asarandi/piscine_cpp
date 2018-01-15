/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Area.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 21:38:26 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AREA_HPP
# define AREA_HPP

#include <iostream>
#include <ncurses.h>
#include "Entity.hpp"

class	Area : public Entity
{
	public:
		Area(int x, int y);
		virtual	~Area();
		Area( const Area& other );
		Area& operator=( const Area& rhs );
};

#endif
