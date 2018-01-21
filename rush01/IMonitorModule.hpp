/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:51:26 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 22:16:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <vector>

class	IMonitorModule
{
	private:
		int		_isEnabled;
	public:
		IMonitorModule();
		~IMonitorModule();
		IMonitorModule(const IMonitorModule& other);
		IMonitorModule& operator=( const IMonitorModule& rhs);

		std::string	exec(const char* cmd);
		virtual std::string getName() = 0;
		virtual std::vector<std::string> getOutput() = 0;
		void toggle();
		int	isEnabled();
};

#endif
