/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:36:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkInfo.hpp"
#include <iostream>
#include <unistd.h>


NetworkInfo::NetworkInfo()
{
	this->_tick = 0;		//
	this->_refreshRate = 150; // will refresh every 2.5 seconds if FPS is 60
	return ;
}

std::string	NetworkInfo::getName()
{
	std::string result = "Network Info";
	return result;
}

std::string NetworkInfo::HostName() {
	char host[sysconf(_SC_HOST_NAME_MAX) + 1];
	gethostname(host, sysconf(_SC_HOST_NAME_MAX));
	std::string s = host;
	return (s);
}

std::string NetworkInfo::UserName() {
	char login[sysconf(_SC_LOGIN_NAME_MAX) + 1];
	getlogin_r(login, sysconf(_SC_LOGIN_NAME_MAX));
	std::string s = login;
	return (s);
}

std::vector<std::string> NetworkInfo::getOutput()
{
	if ((this->_tick == 0) || (this->_tick % this->_refreshRate == 0))
	{
		this->_tick = 1;

		std::string hostname = "Host: ";
		hostname.append(this->HostName());

		this->_result.clear();
		this->_result.push_back(hostname);

		std::string user = "User: ";
		user.append(this->UserName());
		this->_result.push_back(user);
	}
	else
		this->_tick += 1;

	return this->_result;
}
