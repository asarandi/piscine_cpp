/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 18:48:32 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfo.hpp"
#include <iostream>

std::string	OSInfo::getName()
{
	std::string result = "OS Info";
	return result;
}

std::vector<std::string> OSInfo::getOutput()
{
	std::vector<std::string> result;
	std::string str = exec("sw_vers");
	size_t pos = 0;
	size_t prev = 0;
	std::string strnew;
	while ((pos = str.find("\n", prev)) != std::string::npos)
	{
		strnew = str.substr(prev, pos - prev);
		if (strnew != "")
			result.push_back(strnew);
		prev = pos + 1;
	}
	strnew = str.substr(prev);
	if (strnew != "")
		result.push_back(strnew);



	std::string osname = "OS Name: ";
	osname.append(this->exec("uname -s"));
	result.push_back(osname);

	std::string osrel = "OS Release: ";
	osrel.append(this->exec("uname -r"));
	result.push_back(osrel);

	return result;
}

