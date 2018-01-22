/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONSOLE.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:51:26 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 23:17:25 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_HPP
# define CONSOLE_HPP

#include <iostream>
#include <vector>
#include "IMonitorDisplay.hpp"

class	CONSOLE : public IMonitorDisplay
{
	public:
		CONSOLE();
		int	run(std::vector<IMonitorModule *> modules);

	private:
		~CONSOLE();
		CONSOLE(const CONSOLE &src);
		CONSOLE &operator=(const CONSOLE &src);
};

#endif
