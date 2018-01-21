/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 20:58:34 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <iostream>

std::string	Date::getName()
{
	std::string result = "Date/Time";
	return result;
}

std::vector<std::string> Date::getOutput()
{
	std::vector<std::string> result;
	result.push_back(this->exec("date"));

	return result;
}

