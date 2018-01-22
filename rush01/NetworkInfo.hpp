/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:20:41 by asarandi         ###   ########.fr       */
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
									NetworkInfo();
		std::string					getName();
		std::vector<std::string>	getOutput();
		std::string HostName();
		std::string UserName();

	private:
		~NetworkInfo();
		NetworkInfo(const NetworkInfo &src);
		NetworkInfo &operator=(const NetworkInfo &src);
};

#endif
