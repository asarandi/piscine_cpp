/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 01:48:40 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUINFO_HPP
# define CPUINFO_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>

class CPUInfo : public IMonitorModule
{
	public:
		std::string					getName();
		std::vector<std::string>	getOutput();
};

#endif
