/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:51:26 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:20:19 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <vector>

class	IMonitorModule
{
	public:
		int							_isEnabled;
		unsigned long				_tick;
		int							_refreshRate;
		std::vector<std::string>	_result;

		IMonitorModule();
		~IMonitorModule();
		IMonitorModule(const IMonitorModule& other);
		IMonitorModule& operator=( const IMonitorModule& rhs);

		// std::string	exec(const char* cmd);
		virtual std::string getName() = 0;
		virtual std::vector<std::string> getOutput() = 0;
		void toggle();
		int	isEnabled();
};

#endif
