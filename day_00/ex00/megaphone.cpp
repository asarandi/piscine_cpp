/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 22:11:40 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/07 22:11:45 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *ft_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] -= 'a' - 'A';
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	int		i;
	char	msg[] = "* loud and unbearable feedback noise *";

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			std::cout << ft_uppercase(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << ft_uppercase(msg) << std::endl;
	return (0);
}
