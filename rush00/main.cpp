/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:17:42 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

WINDOW	*wnd;
Area			board(0, 0);
Missile			bullet(-1, -1);
Enemy			gamma(-1, -1);
int 			level_flag = 0;
int				frame_rate = 30000;
int 			level = 1;
int 			lives = 5;
unsigned long	tick = 0;
int				spawned = 0;

int	main()
{

	init_game();
	getmaxyx(wnd, board.y, board.x);
	Character		player(board.x / 2, board.y - 3);

	while (1)
	{
		int	input = wgetch(wnd);
		if (input == 'q')
		{
			endwin();
			break ;
		}
		else if (input == KEY_UP)
		{
			if (player.y > 1)
			{
				player.clear_position();
				player.y -= 1;
			}
		}
		else if (input == KEY_DOWN)
		{
			if (player.y < board.y - 2)
			{
				player.clear_position();
				player.y += 1;
			}
		}
		else if (input == KEY_LEFT)
		{
			if (player.x > 1)
			{
				player.clear_position();
				player.x -=1;
			}
		}
		else if (input == KEY_RIGHT)
		{
			if (player.x < board.x - 2)
			{
				player.clear_position();
				player.x += 1;
			}
		}
		else if (input == ' ')
		{
			Missile	*newbullet = new Missile(player.x, player.y);
			Missile	*bulletptr = &bullet;
			while (bulletptr->next != NULL)
				bulletptr = bulletptr->next;
			bulletptr->next = newbullet;
		}

		getmaxyx(wnd, board.y, board.x);
		attron(A_BOLD);
		box(wnd, 0, 0);
		attroff(A_BOLD);

		chtype curp7 = mvwinch(wnd, player.y, player.x);
		curp7 &= A_CHARTEXT;
		if ((curp7 >= '1') && (curp7 <= '9'))
		{
			lives -= 1;
		}
		std::string livestxt = " [ LIVES: ";
		std::string livesnum = std::to_string(lives);
		livestxt.append(livesnum);
		livestxt.append(" ] ");
		move(0, 4);
		unsigned long i = 0;
		while (i < livestxt.size())
		{
			waddch(wnd, livestxt[i]);
			i += 1;
		}
		draw_entity(&player);
		update_bullets(player.y);

		if ((level_flag == 0) || ( lives == 0))
			center_text();

		if (spawned < (3 + (level * 3)) )
			spawn_enemies();

		if (tick % 30 == 1)
			update_enemies();

		wrefresh(wnd);
		usleep(frame_rate);
		tick += 1;
	}
	return (0);
}
