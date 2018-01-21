/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Packets.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 02:30:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 02:30:52 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKETS_HPP
# define PACKETS_HPP
#include "IMonitorModule.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <sys/sysctl.h>
#include <net/route.h>
#include <net/if.h>

class Packets: public IMonitorModule {
public:
    Packets();
    virtual ~Packets();
    Packets(const Packets &src);
    Packets &operator=(const Packets &src);
    virtual std::string getName();
    virtual std::vector<std::string> getOutput();
    void Update();
private:
    std::string const _name;
    std::vector<std::string> _out;
};

#endif
