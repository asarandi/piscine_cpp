/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUActivity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:55:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 13:42:32 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUACTIVITY_HPP
# define CPUACTIVITY_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>

class CPUActivity : public IMonitorModule
{
	public:
									CPUActivity();
		std::string					getName();
		std::vector<std::string>	getOutput();

private:
	~CPUActivity();
	CPUActivity(const CPUActivity &src);
	CPUActivity &operator=(const CPUActivity &src);
};

#endif
