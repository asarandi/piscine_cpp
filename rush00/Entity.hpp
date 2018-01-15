/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 21:50:17 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <iostream>
#include <ncurses.h>

class	Entity
{
	public:
		int		x;
		int		y;
		int		px;
		int		py;
		int		color;
		int		background;
		int		pair;
		chtype	face;

		Entity(int x, int y);
		virtual	~Entity();
		Entity( const Entity& other );
		Entity& operator=( const Entity& rhs );
		void	clear_position();
		void	clear_previous();
};

#endif
