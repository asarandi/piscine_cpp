/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:01:15 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/12 23:38:44 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap : public FragTrap
{

public:

	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap( const ScavTrap& other );
	ScavTrap& operator=( const ScavTrap& rhs );

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	mitmAttack(std::string const & target);
	void	dosAttack(std::string const & target);
	void	boAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	showInfo();
	void	challengeNewcomer();

};

#endif
