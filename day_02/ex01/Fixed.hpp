/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:55:16 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/11 23:40:42 by asarandi         ###   ########.fr       */
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
		Fixed( const int i);
		Fixed( const float f);


		~Fixed();
		Fixed &	operator=( const Fixed & rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat ( void ) const;
		int		toInt ( void ) const;
};

std::ostream	&operator<<( std::ostream& os, const Fixed & rhs );


#endif
