/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:37:17 by asarandi         ###   ########.fr       */
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
									OSInfo();
		std::string					getName();
		std::vector<std::string>	getOutput();

		std::string OSName();
		std::string OSRelease();
		std::string ProductName();
		std::string ProductRelease();

	private:
		~OSInfo();
		OSInfo(const OSInfo &src);
		OSInfo &operator=(const OSInfo &src);
};

#endif
