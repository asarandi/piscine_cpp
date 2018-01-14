/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 20:15:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character
{
	private:
		std::string	_name;
		AWeapon*	_gun;
		int			_ap;

	public:
		Character(std::string const & name);
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& rhs);

		void			recoverAP();
		void			equip(AWeapon* wep);
		void			attack(Enemy* enem);
		std::string		getName() const;
		int				getAP() const;
		AWeapon*		getWeapon() const;


};

std::ostream	&operator<<( std::ostream& os, const Character & rhs );

#endif
