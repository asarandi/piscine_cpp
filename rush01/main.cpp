/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:23:12 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 02:31:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include "IMonitorDisplay.hpp"
#include "GUI.hpp"
#include "CONSOLE.hpp"
#include "IMonitorModule.hpp"
#include "OSInfo.hpp"
#include "NetworkInfo.hpp"
#include "Date.hpp"
#include "CPUActivity.hpp"
#include "CPUInfo.hpp"
#include "Packets.hpp"

int main(int ac, char **av)
{
	std::vector<IMonitorModule *> modules;

	NetworkInfo *net = new NetworkInfo();
	OSInfo *os = new OSInfo();
	Date *date = new Date();
	CPUActivity *cpua = new CPUActivity();
	CPUInfo		*cpui = new CPUInfo();
	Packets		*pack = new Packets();

	modules.push_back(net);
	modules.push_back(os);
	modules.push_back(date);
	modules.push_back(cpua);
	modules.push_back(cpui);
	modules.push_back(pack);


	if (ac == 2)
	{
		if ((av[1][0] == '-') && (av[1][1] == 'c'))
		{
			CONSOLE *console = new CONSOLE();
			return (console->run(modules));
		}
	}
	else
	{
		GUI *window = new GUI();
		return (window->run(modules));
	}

    return EXIT_SUCCESS;
}
