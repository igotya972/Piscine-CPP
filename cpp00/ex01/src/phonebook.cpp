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
	if (nb_contacts >= 8) {
		for (int i = 1; i < 8; i++) {
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
	std::cout << "Contact added successfully.\n";
}

void Phonebook::search_contact()
{

}

