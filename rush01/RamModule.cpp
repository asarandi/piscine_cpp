/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:45:22 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 17:50:40 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"
#include <cmath>

RamModule::RamModule(): _name("RAM Usage"), _page(getpagesize()) {
	long mem;
	size_t s = sizeof(mem);
	sysctlbyname("hw.memsize", &mem, &s, NULL, 0);
	_vals.push_back(mem);

	this->_tick = 0;
	this->_refreshRate = 90;	//every 1.5 seconds if FPS is 60;

}

RamModule::~RamModule() {}

RamModule::RamModule(const RamModule &src): _name("RAM Usage"), _page(getpagesize()) {
	*this = src;
}

RamModule& RamModule::operator=(const RamModule& src) {
	for (size_t i = 0; i < src._vals.size(); ++i)
		this->_vals[i] = src._vals[i];
	return (*this);
}

std::string RamModule::getName() {
	return (_name);
}

std::vector<std::string> RamModule::getOutput() {

	if ((this->_tick == 0) || (this->_tick % this->_refreshRate == 0))
	{
		this->_tick = 1;

		Update();
		std::string beg[] = {"Total RAM: ", "Wired: ", "Active: ", "Inactive: ", "Total Used: ", "Free: "};
		char prefix[] = "kMGT";
		std::vector<std::string> out;
		std::stringstream ss[_vals.size()];
		int size;
		for (size_t i = 0; i < _vals.size(); i++) {
			for (size = 0; _vals[i] > 10240; size++)
				_vals[i] /= 1024;
			ss[i] << beg[i] << _vals[i] << " ";
			if (size > 0)
				ss[i] << prefix[size - 1];
			if (i == 0)
				_vals[i] *= pow(1024, size);
			ss[i] << "B";
			out.push_back(ss[i].str());
			ss[i].flush();
			ss[i].str(""); ss[i].clear();
		}
		this->_result.clear();
		this->_result = out;
	}
	else
		this->_tick += 1;

	return this->_result;
}

void RamModule::Update() {
	if (_vals.size() > 1)
		_vals.erase(_vals.begin() + 1, _vals.end());
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	if(KERN_SUCCESS != host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count))
		return ;
	_vals.push_back(vmstat.wire_count * _page);
	_vals.push_back(vmstat.active_count * _page);
	_vals.push_back(vmstat.inactive_count * _page);
	_vals.push_back(_vals[1] + _vals[2] + _vals[3]);
	_vals.push_back(vmstat.free_count * _page);

}

