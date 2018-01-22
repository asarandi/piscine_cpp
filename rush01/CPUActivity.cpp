/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUActivity.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:58:45 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUActivity.hpp"
#include <iostream>
#include <sstream>
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <unistd.h>
#include <math.h>

CPUActivity::CPUActivity()
{
	this->_tick = 0;
	this->_refreshRate = 75;	//will update every 1.25 seconds if FPS is 60;
	return ;
}

std::string	CPUActivity::getName()
{
	std::string result = "CPU Activity";
	return result;
}

std::vector<std::string> CPUActivity::getOutput()
{
	if ((this->_tick == 0) || (this->_tick % this->_refreshRate == 0))
	{
		this->_tick = 1;

	    static double oldTotal = 0;
	    static double oldSys = 0;
	    static double oldUser = 0;
	    static double oldIdle = 0;
	    natural_t cpuCount;
	    processor_cpu_load_info_t cpuInfo;
	    mach_msg_type_number_t nbInfo;

	    if (KERN_SUCCESS != host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &cpuCount, reinterpret_cast<processor_info_array_t *>(&cpuInfo), &nbInfo))
	        return this->_result;
	    size_t system = 0;
	    size_t user = 0;
	    size_t idle = 0;
	    size_t totalSystemTime = 0;
	    size_t totalUserTime = 0;
	    size_t totalIdleTime = 0;
	    for (natural_t i = 0; i < cpuCount; i++) {
	        system = cpuInfo[i].cpu_ticks[CPU_STATE_SYSTEM];
	        user = cpuInfo[i].cpu_ticks[CPU_STATE_USER] + cpuInfo[i].cpu_ticks[CPU_STATE_NICE];
	        idle = cpuInfo[i].cpu_ticks[CPU_STATE_IDLE];
	        totalSystemTime += system;
	        totalUserTime += user;
	        totalIdleTime += idle;
	    }
	    double Total = totalSystemTime + totalUserTime + totalIdleTime;
	    double UserPercent = (totalUserTime - oldUser) / (Total - oldTotal) * 100;
		double d1 = roundf(UserPercent * 100) / 100;
	    double SysPercent = (totalSystemTime - oldSys) / (Total - oldTotal) * 100;
		double d2 = roundf(SysPercent * 100) / 100;
	    double IdlePercent = (totalIdleTime - oldIdle) / (Total - oldTotal) * 100;
		double d3 = roundf(IdlePercent * 100) / 100;
	    oldTotal = Total;
	    oldSys = totalSystemTime;
	    oldUser = totalUserTime;
	    oldIdle = totalIdleTime;
	    std::ostringstream ss;
		std::string s1 = "User: ";
		ss << d1;
		s1.append(ss.str() + "%"); ss.str(""); ss.clear();
		std::string s2 = "System: ";
		ss << d2;
		s2.append(ss.str() + "%"); ss.str(""); ss.clear();
		std::string s3 = "Idle: ";
		ss << d3;
		s3.append(ss.str() + "%");  ss.str(""); ss.clear();
		this->_result.clear();
		this->_result.push_back(s1);
		this->_result.push_back(s2);
		this->_result.push_back(s3);
	}
	else
		this->_tick += 1;

	return this->_result;
}
