/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 17:59:49 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>

class OSInfo : public IMonitorModule
{
	public:
		std::string					getName();
		std::vector<std::string>	getOutput();
};

#endif
