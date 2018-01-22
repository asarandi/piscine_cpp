/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:35:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <iostream>

Date::Date()
{
	this->_tick = 0;
	this->_refreshRate = 60; // will update once per second if FPS is 60;
	return ;
}

std::string	Date::getName()
{
	std::string result = "Date/Time";
	return result;
}

std::vector<std::string> Date::getOutput()
{
	if ((this->_tick == 0) || (this->_tick % this->_refreshRate == 0))
	{
		this->_tick = 1;

		this->_result.clear();
		this->_result.push_back(timeFunction());
	}
	else
		this->_tick += 1;

	return this->_result;
}

std::string Date::timeFunction() {
	std::time_t result = time(nullptr);
	return (std::asctime(std::localtime(&result)));
}
