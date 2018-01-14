/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:01:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/12 17:47:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <ctime>

FragTrap::FragTrap( std::string name )
{
	std::cout << "Default constructor called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 100;
	this->max_energy_points = 100;
	this->level = 1;
	this->melee_attack_damage = 30;
	this->ranged_attack_damage = 20;
	this->mitm_attack_damage = 25;
	this->dos_attack_damage = 15;
	this->bo_attack_damage = 10;
	this->armor_damage_reduction = 5;

	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( const FragTrap& other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

FragTrap & FragTrap::operator=( const FragTrap& rhs)
{
	std::cout << "Assignment operator called" << std::endl;

	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->max_hit_points = rhs.max_hit_points;
	this->energy_points = rhs.energy_points;
	this->max_energy_points = rhs.max_energy_points;
	this->level = rhs.level;
	this->melee_attack_damage = rhs.melee_attack_damage;
	this->ranged_attack_damage = rhs.ranged_attack_damage;
	this->armor_damage_reduction = rhs.armor_damage_reduction;
	this->mitm_attack_damage = rhs.mitm_attack_damage;
	this->dos_attack_damage = rhs.dos_attack_damage;
	this->bo_attack_damage = rhs.bo_attack_damage;

	return *this;
}

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target;
	std::cout << " at range, causing " << this->ranged_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target;
	std::cout << " at melee, causing " << this->melee_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	FragTrap::mitmAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target;
	std::cout << " using 'Man-In-The-Middle' tactic, causing " << this->mitm_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	FragTrap::dosAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target;
	std::cout << " using 'Denial-Of-Service' strategy, causing " << this->dos_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	FragTrap::boAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target;
	std::cout << " using 'Buffer Overflow' technique, causing " << this->bo_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}




int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{


	if (this->energy_points >= 25)
	{
		std::cout << this->name << " launches a vaulthunter_dot_exe attack against ";
		std::cout << target << std::endl;

		this->energy_points -= 25;

		void (FragTrap::*attack[])(std::string const &) = {
			&FragTrap::rangedAttack, 
			&FragTrap::meleeAttack,
			&FragTrap::mitmAttack,
			&FragTrap::dosAttack,
			&FragTrap::boAttack
		};

		int	damage[] = {
			FragTrap::ranged_attack_damage,
			FragTrap::melee_attack_damage,
			FragTrap::mitm_attack_damage,
			FragTrap::dos_attack_damage,
			FragTrap::bo_attack_damage
		};

		std::srand(std::time(0) ^ std::rand());
		int i = std::rand();
//		std::cout << i << std::endl;

		(this->*attack[i % 5])(target);
		return (damage[i % 5]);
	}
	else
	{
		std::cout << this->name << " unsuccessfully tries to launch a";
		std::cout << " vaulthunter_dot_exe attack, but is low on energy";
		std::cout << " (" << this->energy_points << " energy points available)" << std::endl;
		return (0);

	}


}


void	FragTrap::takeDamage(unsigned int amount)
{
	if ((int)amount >= this->armor_damage_reduction)
	{
		amount -= this->armor_damage_reduction;
	}

	
	if ((int)(this->hit_points - amount) <= 0)
		amount = this->hit_points;

	this->hit_points -= amount;

	std::cout << "FR4G-TP " << this->name << " received ";
	std::cout << amount;
	std::cout << " points of damage !";
	std::cout << " ( " << this->armor_damage_reduction;
	std::cout << " points were deflected by armor )" << std::endl;

	return ;
}

void	FragTrap::showInfo()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "               Name: " << this->name << std::endl;
	std::cout << "         Hit Points: " << this->hit_points << std::endl;
	std::cout << "     Max Hit Points: " << this->max_hit_points << std::endl;
	std::cout << "      Energy Points: " << this->energy_points << std::endl;
	std::cout << "  Max Energy Points: " << this->max_energy_points << std::endl;
	std::cout << "              Level: " << this->level << std::endl;
	std::cout << "Melee Attack Damage: " << this->melee_attack_damage << std::endl;
	std::cout << "Range Attack Damage: " << this->ranged_attack_damage << std::endl;
	std::cout << " MITM Attack Damage: " << this->mitm_attack_damage << std::endl;
	std::cout << "  DOS Attack Damage: " << this->dos_attack_damage << std::endl;
	std::cout << "   BO Attack Damage: " << this->bo_attack_damage << std::endl;
	std::cout << "Armor Damage Reduct: " << this->armor_damage_reduction << std::endl;




}

void	FragTrap::beRepaired(unsigned int amount)
{	
	if ((int)(amount + this->hit_points) > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;

	this->hit_points += amount;

	std::cout << "FR4G-TP " << this->name << " received ";
	std::cout << amount;
	std::cout << " repair points !" << std::endl;

	return ;
}


