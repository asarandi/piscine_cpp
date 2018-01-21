/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 01:52:19 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <unistd.h> //usleep
#include "GUI.hpp"
#include <iostream>
#include "IMonitorModule.hpp"

int	GUI::run(std::vector<IMonitorModule *> modules)
{
	int	SCRWIDTH = 1000;
	int	SCRHEIGHT = 1200;
	int TEXTSIZE = 36;
	int FPS = 1;

	size_t j = 0; //used for keeping index of the text on screen
	size_t k = 0; //used to iterate through modules
	size_t i = 0; //temp

	std::string TITLE = "ft_gkrellm";

    sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), TITLE);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
				window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Q))
                window.close();
            if ((event.type == sf::Event::KeyPressed) && 
					(event.key.code >= sf::Keyboard::Num1) && 
					(event.key.code <= sf::Keyboard::Num9) )
			{
				i = event.key.code - sf::Keyboard::Num1;
				if (i < modules.size())
				{
					modules[i]->toggle();
				}
			}
		}
        window.clear();

		j = 0;
		k = 0;
		while (k < modules.size())
		{
			if (modules[k]->isEnabled() == 1)
			{
				sf::Text	*caption = new sf::Text;
				caption->setString(modules[k]->getName());
				caption->setFont(font);
				caption->setCharacterSize(TEXTSIZE);
				caption->setFillColor(sf::Color::Red);
				caption->setStyle(sf::Text::Bold);
				sf::FloatRect textRect = caption->getLocalBounds();
				caption->setOrigin(textRect.left + textRect.width / 2.0f, j * TEXTSIZE);
				caption->setPosition(sf::Vector2f(SCRWIDTH/2.0f, j * TEXTSIZE * 2.0f));
				window.draw(*caption);
				delete(caption);
				j++;

				std::vector<std::string> module_output = modules[k]->getOutput();
				module_output.push_back("\n");

				i = 0;
				while (i  < module_output.size())
				{
					sf::Text	*info = new sf::Text;
					info->setString(module_output[i]);
					info->setFont(font);
					info->setCharacterSize(TEXTSIZE);
					info->setFillColor(sf::Color::White);
					info->setStyle(sf::Text::Regular);
					sf::FloatRect textRect = info->getLocalBounds();
					info->setOrigin(textRect.left + textRect.width / 2.0f, j * TEXTSIZE);
					info->setPosition(sf::Vector2f(SCRWIDTH/2.0f, j * TEXTSIZE * 2.0f));
					window.draw(*info);
					delete(info);
					i++;
					j++;
				}
			}
			k++;
		}
        window.display();
		usleep(1000000 / FPS);
    }
    return EXIT_SUCCESS;
}

