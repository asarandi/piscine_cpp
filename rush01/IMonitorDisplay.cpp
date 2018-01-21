/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 22:32:28 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include <iostream>

IMonitorDisplay::IMonitorDisplay()
{
	return ;
}

IMonitorDisplay::~IMonitorDisplay()
{
	return ;
}

IMonitorDisplay::IMonitorDisplay( const IMonitorDisplay& other )
{
	*this = other;
	return ;
}

IMonitorDisplay &IMonitorDisplay::operator=( const IMonitorDisplay& rhs )
{
	(void)rhs;
	return *this;
}
