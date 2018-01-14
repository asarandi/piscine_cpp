#include <iostream>
#include "ClassContact.hpp"


void	show_short(Contact p, int index)
{
	std::cout.fill (' '); 	std::cout.width(10); std::cout << index << "|";

	if (p.first_name.length() > 10)
		std::cout << p.first_name.substr(0, 9) << ".|";
	else
	{
		std::cout.fill(' '); 	std::cout.width(10);
		std::cout << p.first_name << "|";
	}

	if (p.last_name.length() > 10)
		std::cout << p.last_name.substr(0, 9) << ".|";
	else
	{
		std::cout.fill(' '); 	std::cout.width(10);
		std::cout << p.last_name << "|";
	}

	if (p.nickname.length() > 10)
		std::cout << p.last_name.substr(0, 9) << "." << std::endl;
	else
	{
		std::cout.fill(' '); 	std::cout.width(10);
		std::cout << p.nickname << std::endl;
	}

}

void	search_record(Contact p, int index, std::string search)
{

	if (p.first_name.compare(search) == 0)
		return (show_short(p, index));
	else if (p.last_name.compare(search) == 0)
		return (show_short(p, index));
	else if (p.nickname.compare(search) == 0)
		return (show_short(p, index));
	else if (p.login.compare(search) == 0)
		return (show_short(p, index));
	else if (p.postal_address.compare(search) == 0)
		return (show_short(p, index));
	else
		return ;
}

int	main(void)
{
	Contact	phonebook[8];
	std::string msg1 = "--- welcome to 80's phonebook,";
	std::string msg2 = "what would you like to do?";
	std::string msg3 = "valid commands are: exit, add, search ";
	std::string msg4 = "please enter command: ";
	std::string cmd1;
	std::string search;
	int i;
	int j;
	int k;

	std::cout << msg1 << std::endl;

	i = 0;
	while (1)
	{
		std::cout << msg2 << std::endl;
		std::cout << msg3 << std::endl;
		std::cout << msg4;
		std::cin >> cmd1;

		if (cmd1.compare("exit") == 0)
		{
			std::cout << "bye" << std::endl;
			break ;
		}
		else if (cmd1.compare("add") == 0)
		{
			if ( i > 7 )
				std::cout << "can't add, phonebook is full, 8 contacts max" << std::endl;
			else
			{
				phonebook[i].add_contact();
				i++;
			}
		}
		else if (cmd1.compare("search") == 0)
		{
			std::cout << "enter search string :";
			std::cin >> search;
			while (1)
			{
				std::cout << " --- search results matching '" << search << "' ---" << std::endl;
				std::cout << "     index|first name| last name|  nickname" << std::endl;
				j = 0;
				while (j < 8)
				{
					search_record(phonebook[j], j, search);
					j++;
				}
				std::cout << std::endl << "enter index of the record you would like to see :";
				k = -1;
				std::cin >> k;
				if ((k >= 0) && (k <= 7))
				{
					phonebook[k].display_record();
				}
				else
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << std::endl << "invalid index, back to main menu" << std::endl << std::endl;
					break ;
				}
			}
		}
		else
			std::cout << "invalid command" << std::endl << std::endl;

	}
	return (0);
}
