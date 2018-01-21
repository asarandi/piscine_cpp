/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 19:04:10 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKINFO_HPP
# define NETWORKINFO_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>

class NetworkInfo : public IMonitorModule
{
	public:
		std::string					getName();
		std::vector<std::string>	getOutput();
};

#endif
