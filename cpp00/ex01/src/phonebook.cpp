/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:21:15 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/09 01:21:15 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

Phonebook::Phonebook():nb_contacts(0){}
Phonebook::~Phonebook(){}

void Phonebook::add_contact()
{
	if (nb_contacts < 8)
		nb_contacts++;
	else
		nb_contacts = (nb_contacts + 1) % 8;
	std::string input;
	contacts[nb_contacts].set_first_name(input);
	contacts[nb_contacts].set_last_name(input);
	contacts[nb_contacts].set_nickname(input);
	contacts[nb_contacts].set_phone_number(input);
	contacts[nb_contacts].set_darkest_secret(input);
	contacts[nb_contacts] = contacts[nb_contacts];
	std::cout << GREEN << "Contact added successfully.\n" << RESET;
}

void Phonebook::search_contact()
{
	int			index;
	std::string	input;
	display_tab();
	while (1)
	{
		for(int i = 1; i <= 8; i++)
		{
			std::cout << BLUE << i << "| " << RESET;
			contacts[i].display_contact();
		}
		std::cout << BLUE << "Enter the index of the contact you want to display: " << RESET;
		if(std::cin.eof())
			break;
		std::getline(std::cin, input);
		std::stringstream ss(input);
		if (ss >> index)
		{
			if (index > 0 && index <= 8)
			{
				if (contacts[index].get_first_name().empty())
					std::cout << RED << "No contact found" << RESET << std::endl;
				else
				{
					std::cout << RED << "index: " << index << std::endl;
					std::cout << YELLOW << "First Name: " << RED << contacts[index].get_first_name() << std::endl;
					std::cout << YELLOW << "Last Name: " << RED << contacts[index].get_last_name() << std::endl;
					std::cout << YELLOW << "Nickname: " << RED << contacts[index].get_nickname() << std::endl;
					std::cout << YELLOW << "Phone Number: " << RED << contacts[index].get_phone_number() << std::endl;
					std::cout << YELLOW << "Darkest Secret: " << RED << contacts[index].get_darkest_secret().substr(0, 3) << "***" << std::endl;
				}
				break ;
			}
			else if (index == 0)
			{
				std::cout << RED << "Returning to main menu..." << RESET << std::endl;
				break;
			}
			else
			{
				std::cerr << RED << "Invalid index: index out of range. Try again: " << RESET << std::endl;
				display_tab();
			}
		}
		else if (input.empty())
		{
				std::cerr << RED << "Invalid input: empty input. Try again: " << RESET << std::endl;
				display_tab();
		}
		else
		{
			std::cerr << RED << "Invalid input: requires a number. Try again: " << RESET << std::endl;
			display_tab();
		}
	}
}

void Phonebook::display_tab()
{
	std::cout << MAGENTA << "0 = return to menu" << RESET << std::endl;
	std::cout << BLUE  << "-| " ;
	std::cout << std::setw(10) << "First Name |";
	std::cout << std::setw(10) << "  Last Name |";
	std::cout << std::setw(10) << "   Nickname |";
	std::cout << std::endl;
}
