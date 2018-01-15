/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 21:36:28 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <ncurses.h>
#include "Entity.hpp"

class	Enemy : public Entity
{
	public:
		Enemy	*next;

		Enemy(int x, int y);
		virtual	~Enemy();
		Enemy( const Enemy& other );
		Enemy& operator=( const Enemy& rhs );
};

#endif
