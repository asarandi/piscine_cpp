/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:51:26 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 22:47:18 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <iostream>
#include <vector>

class IMonitorModule;
class	IMonitorDisplay
{
	public:
		IMonitorDisplay();
		~IMonitorDisplay();
		IMonitorDisplay(const IMonitorDisplay& other);
		IMonitorDisplay& operator=( const IMonitorDisplay& rhs);

		virtual int	run(std::vector<IMonitorModule *> modules) = 0;
};

#endif
