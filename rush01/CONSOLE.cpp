/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONSOLE.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 01:24:30 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h> //usleep
#include "CONSOLE.hpp"
#include <iostream>
#include "IMonitorModule.hpp"

int	CONSOLE::run(std::vector<IMonitorModule *> modules)
{
	WINDOW	*wnd;
	int		FPS = 1;
	unsigned long	tick = 0;

	int	wnd_y = 0;
	int wnd_x = 0;

	size_t j = 0; //used for keeping index of the text on screen
	size_t k = 0; //used to iterate through modules
	size_t i = 0; //temp
	size_t m = 0; //temp
	size_t n = 0; //temp for iterating through string meh

	std::string TITLE = "ft_gkrellm";

	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);
	if (has_colors() == 1)
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_WHITE, COLOR_BLACK);
	}




	while (1)
	{

		getmaxyx(wnd, wnd_y, wnd_x);
		attron(A_BOLD);
		box(wnd, 0, 0);
		attroff(A_BOLD);

		j = 1;
		k = 0;
		while (k < modules.size())
		{
			if (modules[k]->isEnabled() == 1)
			{
				std::string caption = modules[k]->getName();
				wattron(wnd, COLOR_PAIR(1));
				wattron(wnd, A_BOLD);
				i = 0;
				m = (wnd_x - caption.size()) / 2;
				while (caption[i] != 0)
				{
					mvwaddch(wnd, j, m++, caption[i]);
					i++;
				}
				wattroff(wnd, A_BOLD);
				wattroff(wnd, COLOR_PAIR(1));

				j++; //index on screen

				std::vector<std::string> module_output = modules[k]->getOutput();
				module_output.push_back("\n"); //space between modules

				i = 0;
				wattron(wnd, COLOR_PAIR(2));
				while (i < module_output.size())
				{	
					n = 0;
					m = 1;
					std::string str = module_output[i];
					m = (wnd_x - str.size()) / 2;
					while (str[n])
					{
						if (str[n] != '\n')
							mvwaddch(wnd, j, m++, str[n]);
						n++;
					}
					j++;
					i++;
				}
				wattroff(wnd, COLOR_PAIR(2));

			}
			k++;
		}

		int	input = wgetch(wnd);
		if ((input == 'q') || (input == 'Q'))
		{
			endwin();
			break ;
		}
		if ((input >= '1') && (input <= '9'))
		{
			i = input - '1';
			if (i < modules.size())
			{
				modules[i]->toggle();
			}
		}

		wrefresh(wnd);
		usleep(1000000 / FPS);

		int y = 1;
		while (y < wnd_y)
		{
			int x = 1;
			while (x < wnd_x)
			{
				mvwaddch(wnd, y, x, ' ');
				x++;
			}
			y++;
		}

		tick += 1;

	}

    return EXIT_SUCCESS;
}

