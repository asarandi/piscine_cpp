/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 19:21:11 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <unistd.h> //usleep
#include "GUI.hpp"
#include <iostream>
#include "IMonitorModule.hpp"

GUI::GUI() {}

int	GUI::run(std::vector<IMonitorModule *> modules)
{
	int	SCRWIDTH = 800;
	int	SCRHEIGHT = 1300;
	int TEXTSIZE = 36;
	int FPS = 60;

	size_t j = 0; //used for keeping index of the text on screen
	size_t k = 0; //used to iterate through modules
	size_t i = 0; //temp

	std::string TITLE = "ft_gkrellm";

    sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), TITLE);
    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf"))
        return EXIT_FAILURE;

	sf::Texture texture;
	texture.loadFromFile("resources/tile.png");
	sf::Sprite background(texture);

	int	cat_width = 400;
	int	cat_height = 200;

	int	cat_visible = 1;
//	int cat_number = 1;
	int	cat_frames = 12;
	sf::Texture cat_texture;
	cat_texture.loadFromFile("resources/cat_sprite.png");
	sf::IntRect rectSourceSprite(cat_width * 2, 0, cat_width, cat_height);
	sf::Sprite cat_sprite(cat_texture, rectSourceSprite);
	sf::Clock clock;

	float	cat_step = 7.0f;
	sf::Vector2f	cat_position = cat_sprite.getPosition();
	cat_visible = 0;
	cat_position.x = 0 - cat_width - cat_step;
	std::srand(std::time(0) ^ std::rand());
	cat_position.y = std::rand() % (SCRHEIGHT - cat_height);
	cat_sprite.setPosition(cat_position);




	int event_key;
    while (window.isOpen())
    {
		event_key = -1;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				event_key = event.key.code;
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
		window.draw(background);


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




		if (event_key == sf::Keyboard::C)
		{
			cat_visible = 1; // macaroni
		}

		if ((cat_visible == 1) && (clock.getElapsedTime().asSeconds() > 0.04))
		{
			clock.restart();
			cat_position.x += cat_step;

			rectSourceSprite.top += cat_height;
			if (rectSourceSprite.top == cat_height * cat_frames)
				rectSourceSprite.top = 0;
			cat_sprite.setTextureRect(rectSourceSprite);
			cat_sprite.setPosition(cat_position);
			if (cat_position.x > SCRWIDTH + cat_width)
			{
				cat_visible = 0;
				cat_position.x = 0 - cat_width;
				std::srand(std::time(0) ^ std::rand());
				cat_position.y = std::rand() % (SCRHEIGHT - cat_height);
			}

		}







		window.draw(cat_sprite);

        window.display();
		usleep(1000000 / FPS);
    }
    return EXIT_SUCCESS;
}
