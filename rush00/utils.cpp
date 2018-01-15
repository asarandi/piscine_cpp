/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:49:20 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/14 23:15:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

extern WINDOW	*wnd;
extern Area			board;
extern Missile			bullet;
extern Enemy			gamma;
extern int 			level_flag;
extern int				frame_rate;
extern int 			level;
extern int 			lives;
extern unsigned long	tick;
extern int				spawned;

void	center_text()
{
	spawned = 0;
	unsigned long	tmp = 0;

	std::string lvltxt = "LEVEL ";
	std::string lvlnum = std::to_string(level);
	lvltxt.append(lvlnum);
	if (lives == 0)
		lvltxt = "GAME OVER";

	move(board.y / 2, (board.x / 2) - (lvltxt.size()));
	while (tmp < lvltxt.size())
	{
		waddch(wnd, lvltxt[tmp]);
		waddch(wnd, ' ');
		tmp += 1;
	}
	wrefresh(wnd);
	usleep(frame_rate * 50);

	move(board.y / 2, (board.x / 2) - (lvltxt.size()));
	tmp = 0;
	while (tmp < lvltxt.size())
	{
		waddch(wnd, ' ');
		waddch(wnd, ' ');
		tmp += 1;
	}
	level_flag = 1;
	if (lives == 0)
	{
		usleep(frame_rate * 50);
		endwin();
		std::exit(0);
	}
}

void	draw_entity(Entity *alpha)
{
	init_pair(alpha->pair, alpha->color, alpha->background);
	wattron(wnd, COLOR_PAIR(alpha->pair));
	wattron(wnd, A_BOLD);
	mvwaddch(wnd, alpha->y, alpha->x, alpha->face);
	wattroff(wnd, A_BOLD);
	wattroff(wnd, COLOR_PAIR(alpha->pair));
}

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

void	spawn_enemies()
{	
	std::srand(std::time(0) ^ std::rand());
	int rnd = std::rand();

	chtype curp0;
	chtype curp1;
	chtype curp2;

	curp0 = mvwinch(wnd, 1, (rnd % board.x) - 1);
	curp1 = mvwinch(wnd, 1, (rnd % board.x));
	curp2 = mvwinch(wnd, 1, (rnd % board.x) + 1);

	if ((curp0 == ' ') && (curp1 == ' ') && (curp2 == ' '))
	{
		Enemy *omega	= new Enemy(rnd % board.x, 1);
		omega->face = (rnd % 9) + '1';

		Enemy *eptr = &gamma;
		while (eptr->next != NULL)
			eptr = eptr->next;
		eptr->next = omega;
		spawned += 1;
	}
}

void	update_enemies()
{

	Enemy *enparent = &gamma;
	Enemy *enptr = &gamma;
	enptr = enptr->next;

	if (enptr == NULL)
	{
		level += 1;
		level_flag = 0;
		spawned = 0;
	}
	while (enptr != NULL)
	{
		enptr->clear_previous();
		chtype curp3 = mvwinch(wnd, enptr->y, enptr->x + 1);
		curp3 &= A_CHARTEXT;
		chtype curp4 = mvwinch(wnd, enptr->y, enptr->x - 1);
		curp4 &= A_CHARTEXT;
		chtype curp5 = mvwinch(wnd, enptr->y, enptr->x);
		curp5 &= A_CHARTEXT;

		if ((curp3 == ' ') && (curp4 == ' '))
		{
			std::srand(std::time(0) ^ std::rand());
			int tmprnd = std::rand();
			if ((tmprnd % 3 == 1) && (enptr->x < board.x - 1))
				enptr->x += 1;
			if ((tmprnd % 3 == 2) && (enptr->x > 1))
				enptr->x -= 1;
			if (tmprnd % 3 == 0)
				enptr->y -= 1;
		}
		if ((enptr->x >= board.x - 1) && (curp4 == ' '))
			enptr->x -= 1;
		if ((enptr->x <= 1) && (curp3 == ' '))
			enptr->x += 1;

		enptr->y += 1;
		if (enptr->y >= board.y - 1)
		{
			lives -= 1;
			enparent->next = enptr->next;
			delete enptr;
			enptr = enparent->next;
		}
		else
		{
			draw_entity(enptr);
			enptr->px = enptr->x;
			enptr->py = enptr->y;
			enparent = enptr;
			enptr = enptr->next;
		}
	}
}

void	update_bullets(int player_y)
{
	Missile *parent = &bullet;
	Missile *current = &bullet;
	current = current->next;
	while (current != NULL)
	{
		if (player_y != current->y)
			current->clear_position();
		current->y -= 1;
		if (current->y < 1)
		{
			parent->next = current->next;
			delete current;
			current = parent->next;
			continue ;
		}
		chtype curp6 = mvwinch(wnd, current->y, current->x);
		curp6 &= A_CHARTEXT;
		if ( (curp6  >= '1') && (curp6 <= '9'))
		{
			current->face = '#';
			current->color = COLOR_RED;
			current->pair = 4;
			draw_entity(current);
			Enemy *enptr = &gamma;
			Enemy *parnt = enptr;
			enptr = enptr->next;
			while (enptr != NULL)
			{
				if ((enptr->x == current->x) && (enptr->y == current->y))
				{
					enptr->face -= 1;
					if (enptr->face == '0')
					{
						parnt->next = enptr->next;
						delete enptr;
					}
					break ;
				}
				parnt = enptr;
				enptr = enptr->next;
			}
			continue ;
		}
		draw_entity(current);
		current = current->next;
	}
}
