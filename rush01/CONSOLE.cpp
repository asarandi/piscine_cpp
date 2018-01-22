/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONSOLE.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 12:50:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h> //usleep
#include "CONSOLE.hpp"
#include <iostream>
#include "IMonitorModule.hpp"

CONSOLE::CONSOLE() {}

int	CONSOLE::run(std::vector<IMonitorModule *> modules) {
	WINDOW	*wnd;
	int		FPS = 60;
	unsigned long	tick = 0;

	int	wnd_y = 0;
	int wnd_x = 0;

	size_t x_index; //temp

	std::string TITLE = "ft_gkrellm";

	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);
	if (has_colors() == 1) {
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

		size_t y_index = 1;
		for (size_t k = 0; k < modules.size(); k++) {
			if (modules[k]->isEnabled() == 1) {
				std::string caption = modules[k]->getName();
				wattron(wnd, COLOR_PAIR(1));
				wattron(wnd, A_BOLD);
				x_index = (wnd_x - caption.size()) / 2;
				for (size_t i = 0; caption[i] != 0; i++) {
					mvwaddch(wnd, y_index, x_index++, caption[i]);
				}
				wattroff(wnd, A_BOLD);
				wattroff(wnd, COLOR_PAIR(1));

				y_index++; //index on screen

				std::vector<std::string> module_output = modules[k]->getOutput();
				module_output.push_back("\n"); //space between modules

				wattron(wnd, COLOR_PAIR(2));
				for (size_t i = 0; i < module_output.size(); i++) {
					// m = 1;
					std::string str = module_output[i];
					x_index = (wnd_x - str.size()) / 2;
					for (size_t n = 0; str[n] != 0; n++) {
						if (str[n] != '\n')
							mvwaddch(wnd, y_index, x_index++, str[n]);
					}
					y_index++;
				}
				wattroff(wnd, COLOR_PAIR(2));
			}
			// k++;
		}

		int	input = wgetch(wnd);
		if ((input == 'q') || (input == 'Q')) {
			endwin();
			break ;
		}
		if ((input >= '1') && (input <= '9')) {
			size_t in = input - '1';
			if (in < modules.size())
			{
				modules[in]->toggle();
			}
		}

		wrefresh(wnd);
		usleep(1000000 / FPS);

		for (int y = 1; y < wnd_y; y++) {
			for (int x = 1; x < wnd_x; x++) {
				mvwaddch(wnd, y, x, ' ');
			}
		}
		// wclear(wnd);

		tick += 1;

	}

    return EXIT_SUCCESS;
}
