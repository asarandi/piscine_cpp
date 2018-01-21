/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:56:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 02:15:35 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUInfo.hpp"
#include <iostream>
#include <sys/sysctl.h>
#include <sstream>
#include <math.h>

std::string	CPUInfo::getName()
{
	std::string result = "CPU Info";
	return result;
}

std::vector<std::string> CPUInfo::getOutput()
{
	std::vector<std::string> result;
	result.clear();

    size_t bufferlen = 128;
    char cputype[bufferlen];
    sysctlbyname("machdep.cpu.brand_string", &cputype, &bufferlen, NULL, 0); // CPU TYPE
	std::string s1(cputype);

    size_t len = sizeof(int);
    std::string s2("Number of Cores: ");
    int c;
    sysctlbyname("hw.ncpu", &c, &len, NULL, 0); // CPU CORES
	std::stringstream ss;
	ss << c;
	s2 += ss.str();
	ss.str(""); ss.clear();

    int nelem = 3;
    double loadavgs[nelem];
    getloadavg(loadavgs, nelem);
	double d1 = loadavgs[0];
	d1 = roundf(d1 * 100) / 100;

	double d2 = loadavgs[1];
	d2 = roundf(d2 * 100) / 100;

	double d3 = loadavgs[2];
	d3 = roundf(d3 * 100) / 100;


    ss << "CPU Load Avg: " << d1 << ", " << d2 << ", " << d3;
	std::string s3 = ss.str();
	ss.str(""); ss.clear();

	result.push_back(s1);
	result.push_back(s2);
	result.push_back(s3);

	return result;
}

