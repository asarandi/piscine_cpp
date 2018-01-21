/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Packets.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 02:30:12 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/21 02:35:54 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Packets.hpp"
#include <iostream>

Packets::Packets(): _name("Network I/O") {
    Update();
}

Packets::~Packets() {}
Packets::Packets(const Packets &src): _name("Network I/O") {
    *this = src;
}

Packets &Packets::operator=(const Packets &src) {
    for (size_t i = 0; i < src._out.size(); ++i)
        this->_out[i] = src._out[i];
    return (*this);
}

std::string Packets::getName() {
    return (_name);
}

std::vector<std::string> Packets::getOutput() {
	Update();
    return (_out);
}

void Packets::Update() {
    struct  if_msghdr *ifm;
    char *next;
    int mib[] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};
    size_t len;
    sysctl(mib, 6, NULL, &len, NULL, 0);
    char buf[len];
    sysctl(mib, 6, buf, &len, NULL, 0);
    char *lim = buf + len;
    long ipackets = 0;
    long opackets = 0;
    long ibytes = 0;
    long obytes = 0;
    for (next = buf; next < lim; ) {
        ifm = (struct if_msghdr *)next;
        next += ifm->ifm_msglen;
        if (ifm->ifm_type == RTM_IFINFO2) {
            struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
            if (if2m->ifm_data.ifi_type != 18) {
                opackets += if2m->ifm_data.ifi_opackets;
                ipackets += if2m->ifm_data.ifi_ipackets;
                obytes += if2m->ifm_data.ifi_obytes;
                ibytes += if2m->ifm_data.ifi_ibytes;
            }
        }
    }
    size_t size;
    char prefix[] = "kMGT";
    if (!_out.empty())
        _out.erase(_out.begin(), _out.end());
    std::stringstream s1;
    for (size = 0; ibytes > 10240; size++)
        ibytes /= 1024;
    s1 << "Received: " << ipackets << "/" << ibytes;
    if (size > 0)
        s1 << prefix[size - 1];
    s1 << "B";
    std::stringstream s2;
    for (size = 0; obytes > 10240; size++)
        obytes /= 1024;
    s2 << "Sent: " << opackets << "/" << obytes;
    if (size > 0)
        s2 << prefix[size - 1];
    s2 << "B";
    _out.push_back(s1.str());
    _out.push_back(s2.str());
}
