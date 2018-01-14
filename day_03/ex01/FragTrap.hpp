/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:01:15 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/12 17:45:59 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

class FragTrap {

public:
	int				hit_points;
	int				max_hit_points;
	int				energy_points;
	int 			max_energy_points;
	int				level;
	std::string		name;
	int				melee_attack_damage;
	int				ranged_attack_damage;
	int				mitm_attack_damage;
	int				dos_attack_damage;
	int				bo_attack_damage;
	int				armor_damage_reduction;

	FragTrap(std::string name);
	~FragTrap();
	FragTrap( const FragTrap& other );
	FragTrap& operator=( const FragTrap& rhs );

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	mitmAttack(std::string const & target);
	void	dosAttack(std::string const & target);
	void	boAttack(std::string const & target);
	int		vaulthunter_dot_exe(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	showInfo();

};

#endif
