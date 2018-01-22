/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:45:15 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 12:45:18 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <unistd.h>
#include <sstream>

class RamModule: public IMonitorModule {

public:
	RamModule();
	virtual ~RamModule();
	RamModule(const RamModule &src);
	RamModule& operator=(const RamModule& src);
	virtual std::string getName();
	virtual std::vector<std::string> getOutput();
	void Update();


private:
	std::string const _name;
	int const _page;
	std::vector<long> _vals;
	// std::vector<std::string> _out;
};

#endif

