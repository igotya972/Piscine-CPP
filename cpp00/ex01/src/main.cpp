/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:25:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/09 02:46:28 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

	#include "../include/phonebook.hpp"
#endif

int main ()
{
	Phonebook phonebook;
	std::string input;
	while (1)
	{
		std::cout << "Menu:\n";
        std::cout << "ADD = Ajouter un contact\n";
        std::cout << "EXIT = Quitter\n";
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if(input == "ADD" || input == "add")
			phonebook.add_contact();
		else if (input == "SEARCH" || input == "search")
			phonebook.search_contact();
		else if (input == "EXIT" || input == "exit")
		{
			std::cout << "Quiting..." << std::endl;
			exit(EXIT_SUCCESS);
		}
		else
			std::cout << std::endl << "Command not found" << std::endl;
	}
	// contact.set_first_name(first_name);
	// contact.set_last_name(last_name);
	// contact.set_nickname(nickname);
	// contact.set_phone_number(phone_number);
	// contact.set_darkest_secret(darkest_secret);
	return (0);
}