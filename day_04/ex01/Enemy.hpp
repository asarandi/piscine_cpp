/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:37:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 21:09:01 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class	Enemy
{
	private:
		int				_hp;
		std::string		_type;

	public:
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy(const Enemy& other);
		Enemy& operator=(const Enemy& rhs);

		std::string		getType() const;
		int				getHP() const;
		virtual void	takeDamage(int damage);
};

#endif
