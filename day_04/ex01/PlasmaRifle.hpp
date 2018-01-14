/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:34:14 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 19:04:01 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

class	PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle(void);
		~PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &other);
		PlasmaRifle& operator=(const PlasmaRifle& rhs);
		
		virtual void attack() const;
};

#endif
