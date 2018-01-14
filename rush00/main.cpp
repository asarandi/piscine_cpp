/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 06:03:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

WINDOW	*wnd;

void init_game()
{
	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);
	if (has_colors() == 1)
		start_color();
	return ;
}

class	Entity
{
	public:
		int	x;
		int	y;
		int	color;
		int background;
};

class	Character : public Entity
{
	public:
		chtype	face;
};

class	Area : public Entity
{
};

class	Missile : public Entity
{
	public:
		chtype face;
		Missile	*next;
};

void	clear_position(Entity alpha)
{
	mvaddch(alpha.y, alpha.x, ' ');
}

void	draw_entity(Entity *alpha, chtype symbol, int pair)
{
	init_pair(pair, alpha->color, alpha->background);
	wattron(wnd, COLOR_PAIR(pair));
	wattron(wnd, A_BOLD);


	mvwaddch(wnd, alpha->y, alpha->x, symbol);
	wattroff(wnd, A_BOLD);
	wattroff(wnd, COLOR_PAIR(pair));
	
}

int	main()
{

	init_game();
	Area	board;

	getmaxyx(wnd, board.y, board.x);

	Character	player;
	player.x = board.x / 2;
	player.y = board.y / 2;
	player.face = ACS_DIAMOND;
	player.color = COLOR_YELLOW;
	player.background = COLOR_BLACK;

	Missile	bullet;
	bullet.next = NULL;
	bullet.x = -1;
	bullet.y = -1;
	bullet.face = ACS_BULLET;



	while (1)
	{
		getmaxyx(wnd, board.y, board.x);
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
				clear_position(player);
				player.y -= 1;
			}
		}
		else if (input == KEY_DOWN)
		{
			if (player.y < board.y - 2)
			{
				clear_position(player);
				player.y += 1;
			}
		}
		else if (input == KEY_LEFT)
		{
			if (player.x > 1)
			{
				clear_position(player);
				player.x -=1;
			}
		}
		else if (input == KEY_RIGHT)
		{
			if (player.x < board.x - 2)
			{
				clear_position(player);
				player.x += 1;
			}
		}
		else if (input == ' ')
		{
			Missile	*newbullet = new Missile;

			newbullet->x = player.x;
			newbullet->y = player.y;
			newbullet->face = ACS_BULLET;
			newbullet->color = COLOR_CYAN;
			newbullet->background = COLOR_BLACK;
			newbullet->next = NULL;
			Missile	*bulletptr = &bullet;
			while (bulletptr->next != NULL)
				bulletptr = bulletptr->next;
			bulletptr->next = newbullet;

		}

		draw_entity(&player, player.face, 1);
		attron(A_BOLD);
		box(wnd, 0, 0);
		attroff(A_BOLD);

		Missile *parent = &bullet;
		Missile *current = &bullet;
		current = current->next;
		while (current != NULL)
		{
			if (player.y != current->y)
				clear_position(*current);
			current->y -= 1;
			if (current->y <= 1)
			{
				parent->next = current->next;
				delete current;
				current = parent->next;
				continue ;
			}
			draw_entity(current, current->face, 2);
			current = current->next;

		}

		wrefresh(wnd);
		usleep(30000);


		 
	}
	return (0);
}
