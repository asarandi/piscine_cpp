/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 21:53:12 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkInfo.hpp"
#include <iostream>

std::string	NetworkInfo::getName()
{
	std::string result = "Network Info";
	return result;
}

std::vector<std::string> NetworkInfo::getOutput()
{
	std::vector<std::string> result;

	std::string hostname = "Host: ";
	hostname.append(this->exec("hostname"));
	result.push_back(hostname);

	std::string user = "User: ";
	user.append(this->exec("whoami"));
	result.push_back(user);

	return result;
}

