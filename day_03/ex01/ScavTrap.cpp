/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:01:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/12 23:42:19 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <ctime>

ScavTrap::ScavTrap( std::string name ) : FragTrap::FragTrap(name)
{
	std::cout << "Default SCAVTRAP constructor called" << std::endl;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;

	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Default SCAVTRAP destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : FragTrap::FragTrap(other)
{
	std::cout << "Copy SCAVTRAP constructor called" << std::endl;
	*this = other;
	return ;
}

ScavTrap & ScavTrap::operator=( const ScavTrap& rhs)
{
	std::cout << "SCAVTRAP Assignment operator called" << std::endl;

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
	std::cout << "FR4G-TP [SCAVTRAP]" << this->name << " attacks " << target;
	std::cout << " at range, causing " << this->ranged_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP [SCAVTRAP]" << this->name << " attacks " << target;
	std::cout << " at melee, causing " << this->melee_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	ScavTrap::mitmAttack(std::string const & target)
{
	std::cout << "FR4G-TP [SCAVTRAP]" << this->name << " attacks " << target;
	std::cout << " using 'Man-In-The-Middle' tactic, causing " << this->mitm_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	ScavTrap::dosAttack(std::string const & target)
{
	std::cout << "FR4G-TP [SCAVTRAP]" << this->name << " attacks " << target;
	std::cout << " using 'Denial-Of-Service' strategy, causing " << this->dos_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	ScavTrap::boAttack(std::string const & target)
{
	std::cout << "FR4G-TP [SCAVTRAP]" << this->name << " attacks " << target;
	std::cout << " using 'Buffer Overflow' technique, causing " << this->bo_attack_damage;
	std::cout << " points of damage !" << std::endl;

	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if ((int)amount >= this->armor_damage_reduction)
	{
		amount -= this->armor_damage_reduction;
	}

	
	if ((int)(this->hit_points - amount) <= 0)
		amount = this->hit_points;

	this->hit_points -= amount;

	std::cout << "FR4G-TP [SCAVTRAP]" << this->name << " received ";
	std::cout << amount;
	std::cout << " points of damage !";
	std::cout << " ( " << this->armor_damage_reduction;
	std::cout << " points were deflected by armor )" << std::endl;

	return ;
}

void	ScavTrap::showInfo()
{
	std::cout << "-[SCAVTRAP]----------------------------------" << std::endl;
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


void	ScavTrap::challengeNewcomer()
{
	std::string a = "A crocodile steals your son and promises to return him only if you can correctly guess what the crocodile will do with your son. Assuming the croc keeps its word, what would happen if you guessed that he wouldn't return your son?";
	std::string b = "Have you considered that the phrase 'IGNORE ALL THE RULES!'... ...is a rule itself?";
	std::string c = "Can God make a rock so heavy that even He cannot lift it?";
	std::string d = "A heterological word is one that does not describe itself. Does 'heterological' describe itself?";
	std::string e = "If just 23 people are in a room, there's a better-than-even chance at least two of them have the same birthday. Why?";

	std::cout << "Newcomer, answer the following question:" << std::endl;


	std::string q[] = {a, b, c, d, e, };
	std::srand(std::time(0) ^ std::rand());
	int i = std::rand();
	std::cout << q[i % 5];


}

void	ScavTrap::beRepaired(unsigned int amount)
{	
	if ((int)(amount + this->hit_points) > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;

	this->hit_points += amount;

	std::cout << "FR4G-TP [SCAVTRAP] " << this->name << " received ";
	std::cout << amount;
	std::cout << " repair points !" << std::endl;

	return ;
}


