/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:53:10 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/19 04:19:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>

class	Span
{
	private:
		std::vector<int>	_array;
		unsigned int		_n;
		unsigned int		_count;

	public:
		Span(unsigned int n);
		~Span();
		Span( const Span& other );
		Span& operator=( const Span& rhs );

		void			addNumber(int n);
		void			fillWithRandoms();
		void			fillWithRandoms(int max_value);
		int				shortestSpan();
		int				longestSpan();
		void			print();

		class	vectorFullException : public std::exception
		{
			public:
				vectorFullException(void);
				~vectorFullException(void) throw();
				vectorFullException(const vectorFullException& other);
				vectorFullException& operator=(const vectorFullException& rhs);
				virtual	const char *what() const throw();
		};

		class	noSpanException : public std::exception
		{
			public:
				noSpanException(void);
				~noSpanException(void) throw();
				noSpanException(const noSpanException& other);
				noSpanException& operator=(const noSpanException& rhs);
				virtual	const char *what() const throw();
		};
};

#endif
