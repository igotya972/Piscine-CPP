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

Phonebook::Phonebook(){}
Phonebook::~Phonebook(){}

void Phonebook::add_contact()
{
	if (nb_contacts >= 8)
	{
		for (int i = 1; i < 8; i++)
		{
			contacts[i - 1] = contacts[i];
		}
		nb_contacts--;
	}
	Contact new_contact;
	std::string input;
	new_contact.set_first_name(input);
	new_contact.set_last_name(input);
	new_contact.set_nickname(input);
	new_contact.set_phone_number(input);
	new_contact.set_darkest_secret(input);
	contacts[nb_contacts] = new_contact;
	nb_contacts++;
	std::cout << GREEN;
	std::cout << "Contact added successfully.\n";
	std::cout << RESET;
}

void Phonebook::search_contact()
{
	int			index;
	std::string	input;
	while (1)
	{
		for(int i = 0; i < 8; i++)
		{
			std::cout << BLUE << i << "| " << RESET;
			contacts[i].display_contact();
		}
		std::cout << BLUE << "Enter the index of the contact you want to display: " << RESET;
		std::getline(std::cin, input);
		std::stringstream ss(input);
		if (ss >> index)
		{
			if (index >= 0 && index < 8)
			{
				std::cout << RED << "index: " << index << std::endl;
				std::cout << YELLOW << "First Name: " << RED << contacts[index].get_first_name() << std::endl;
				std::cout << YELLOW << "Last Name: " << RED << contacts[index].get_last_name() << std::endl;
				std::cout << YELLOW << "Nickname: " << RED << contacts[index].get_nickname() << std::endl;
				std::cout << YELLOW << "Phone Number: " << RED << contacts[index].get_phone_number() << std::endl;
				std::cout << YELLOW << "Darkest Secret: " << RED << contacts[index].get_darkest_secret().substr(0, 3) << "***" << std::endl;
				std::cout << "";
				break ;
			}
			else if (index == 101)
			{
				std::cout << RED << "Returning to main menu..." << RESET << std::endl;
				break;
			}
			else
			{
				std::cerr << RED << "Invalid index: index out of range. Try again: " << RESET << std::endl;
			}
		}
		else if (input.empty())
				std::cerr << RED << "Invalid input: empty input. Try again: " << RESET << std::endl;
		else
		{
			std::cerr << RED << "Invalid input: requires a number. Try again: " << RESET << std::endl;
		}
	}
}
