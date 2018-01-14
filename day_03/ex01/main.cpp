/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:01:23 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/12 17:46:57 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int	main()
{
	FragTrap a("Alpha");
	FragTrap b("Beta");
	FragTrap d("Delta");


	a.rangedAttack("Beta");		b.takeDamage(a.ranged_attack_damage);
	a.meleeAttack("Delta");		d.takeDamage(a.melee_attack_damage);
	FragTrap c = b;
	b.beRepaired(15);

	int damage =	a.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);
	damage = b.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);

	FragTrap g("Gamma");

	damage = g.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);
	damage = g.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);
	damage = g.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);
	damage = g.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);
	damage = g.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);
	damage = g.vaulthunter_dot_exe("Delta"); d.takeDamage(damage);

	a.showInfo();
	b.showInfo();
	d.showInfo();
	g.showInfo();

}
