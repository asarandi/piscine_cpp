/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:41:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfo.hpp"
#include <iostream>
#include <sys/sysctl.h>

OSInfo::OSInfo()
{
	this->_tick = 0;
	this->_refreshRate = 3600; //will refresh once per minute if FPS is 60;
}

std::string	OSInfo::getName()
{
	std::string result = "OS Info";
	return result;
}

std::string OSInfo::OSName() {
	size_t i = 64;
	char osname[i];
	sysctlbyname("kern.ostype", osname, &i, NULL, 0);
	std::string s = osname;
	return (s);
}

std::string OSInfo::OSRelease() {
	size_t size = 256;
	char osversion[size];
	sysctlbyname("kern.osrelease", osversion, &size, NULL, 0);
	std::string s = osversion;
	return (s);
}

std::vector<std::string> OSInfo::getOutput()
{
	if ((this->_tick == 0) || (this->_tick % this->_refreshRate == 0))
	{
		this->_tick = 1;
		this->_result.clear();

		std::string osname = "OS Name: ";
		osname.append(this->OSName());
		this->_result.push_back(osname);

		std::string osrel = "OS Release: ";
		osrel.append(this->OSRelease());
		this->_result.push_back(osrel);
	}
	else
		this->_tick += 1;

	return this->_result;
}
