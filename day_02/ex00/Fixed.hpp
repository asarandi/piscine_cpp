/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:55:16 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/11 22:46:55 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

	private:
		int					_n;
		static const int	frac = 8;
	
	public:
		Fixed();
		Fixed( const Fixed & rhs);
		~Fixed();
		Fixed &	operator=( const Fixed & rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
