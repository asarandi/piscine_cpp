/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 21:00:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>

class Date : public IMonitorModule
{
	public:
		std::string					getName();
		std::vector<std::string>	getOutput();
};

#endif
