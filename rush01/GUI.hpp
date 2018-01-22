/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:51:26 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/20 22:46:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_HPP
# define GUI_HPP

#include <iostream>
#include <vector>
#include "IMonitorDisplay.hpp"

class	GUI : public IMonitorDisplay
{
	public:
		GUI();
		int	run(std::vector<IMonitorModule *> modules);

	private:
		~GUI();
		GUI(const GUI &src);
		GUI &operator=(const GUI &src);
};

#endif
