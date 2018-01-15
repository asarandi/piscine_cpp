/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:31:25 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:15:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Entity.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "Area.hpp"
#include "Missile.hpp"

void	center_text();
void	update_enemies();
void	draw_entity(Entity *alpha);
void	init_game();
void	spawn_enemies();
void	update_bullets(int player_y);

#endif
