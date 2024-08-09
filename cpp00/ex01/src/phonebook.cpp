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
// Contact::Contact(){}
// Contact::~Contact(){}

void Phonebook::add_contact()
{
	if (nb_contacts >= 8) {
		for (int i = 1; i < 8; i++) {
			contacts[i - 1] = contacts[i];
		}
		nb_contacts--;
	}
	Contact new_contact;
	std::string input;
	//std::cout << "Enter first name: ";
	new_contact.set_first_name(input);
	//std::cout << "Enter last name: ";
	new_contact.set_last_name(input);
	//std::cout << "Enter nickname: ";
	new_contact.set_nickname(input);
	//std::cout << "Enter phone number: ";
	new_contact.set_phone_number(input);
	//std::cout << "Enter dark secret: ";
	new_contact.set_darkest_secret(input);
	contacts[nb_contacts] = new_contact;
	nb_contacts++;
	std::cout << "Contact added successfully.\n";
}

void Phonebook::search_contact()
{

}

