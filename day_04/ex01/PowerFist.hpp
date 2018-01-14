/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:34:14 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/13 19:09:33 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

class	PowerFist : public AWeapon
{
	public:
		PowerFist(void);
		~PowerFist();
		PowerFist(const PowerFist &other);
		PowerFist& operator=(const PowerFist& rhs);
		
		virtual void attack() const;
};

#endif
