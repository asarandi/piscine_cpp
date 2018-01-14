/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 22:11:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/08 02:22:26 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClassContact.hpp"

void Contact::display_record(void)
{
	std::cout << "     first name: " << this->first_name << std::endl;
	std::cout << "      last name: " << this->last_name << std::endl;
	std::cout << "       nickname: " << this->nickname << std::endl;
	std::cout << "          login: " << this->login << std::endl;
	std::cout << " postal address: " << this->postal_address << std::endl;
	std::cout << "  email address: " << this->email_address << std::endl;
	std::cout << "   phone_number: " << this->phone_number << std::endl;
	std::cout << "  birthday date: " << this->birthday_date << std::endl;
	std::cout << "  favorite meal: " << this->favorite_meal << std::endl;
	std::cout << "underwear color: " << this->underwear_color << std::endl;
	std::cout << " darkest secret: " << this->darkest_secret << std::endl;
	std::cout << " --- end of record ---" << std::endl << std::endl;
}


void Contact::add_contact (void)
{
	std::cout << "     first name? ";
	std::cin >> this->first_name;
	std::cout << "      last name? ";
	std::cin >> this->last_name;
	std::cout << "       nickname? ";
	std::cin >> this->nickname;
	std::cout << "          login? ";
	std::cin >> this->login;
	std::cout << " postal address? ";
	std::cin >> this->postal_address;
	std::cout << "  email address? ";
	std::cin >> this->email_address;
	std::cout << "   phone_number? ";
	std::cin >> this->phone_number;
	std::cout << "  birthday date? ";
	std::cin >> this->birthday_date;
	std::cout << "  favorite meal? ";
	std::cin >> this->favorite_meal;
	std::cout << "underwear color? ";
	std::cin >> this->underwear_color;
	std::cout << " darkest secret? ";
	std::cin >> this->darkest_secret;

	std::cout << std::endl << "phonebook entry saved!" << std::endl;

}

Contact::Contact (void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->login = "";
	this->postal_address = "";
	this->email_address = "";
	this->phone_number = "";
	this->birthday_date = "";
	this->favorite_meal = "";
	this->underwear_color = "";
	this->darkest_secret = "";
}

Contact::~Contact (void)
{

}
