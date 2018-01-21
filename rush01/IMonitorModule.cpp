/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 22:15:48 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"
#include <iostream>

IMonitorModule::IMonitorModule()
{
	this->_isEnabled = 1;
	return ;
}

IMonitorModule::~IMonitorModule()
{
	return ;
}

IMonitorModule::IMonitorModule( const IMonitorModule& other )
{
	*this = other;
	return ;
}

IMonitorModule &IMonitorModule::operator=( const IMonitorModule& rhs )
{
	(void)rhs;
	return *this;
}

std::string	IMonitorModule::exec(const char* cmd)
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void	IMonitorModule::toggle()
{
	if (this->_isEnabled == 1)
		this->_isEnabled = 0;
	else
		this->_isEnabled = 1;
}

int		IMonitorModule::isEnabled()
{
	return this->_isEnabled;
}
