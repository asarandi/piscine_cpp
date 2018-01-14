/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:33:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 21:33:30 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class	AWeapon
{
	private:
		std::string	_name;
		int			_damage;
		int			_apcost;
	
	public:
		AWeapon(std::string const & name, int damage, int apcost);
		virtual	~AWeapon();
		AWeapon( const AWeapon& other );
		AWeapon& operator=( const AWeapon& rhs );

		virtual std::string getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};

#endif
