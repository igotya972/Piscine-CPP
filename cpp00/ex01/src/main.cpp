/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:25:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 19:49:42 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

int main ()
{
	Phonebook phonebook;
	std::string input;
	while (1)
	{
		std::cout << MAGENTA;
		std::cout << "Menu:\n";
		std::cout << "ADD = Add a contact\n";
		std::cout << "EXIT = Leave\n";
		std::cout << "SEARCH = Search for a contact\n";
		std::cout << BLUE;
		std::cout << "Enter a command: ";
		std::cout << RESET;
		std::getline(std::cin, input);
		if(std::cin.eof())
			break;
		if(input == "ADD" || input == "add")
			phonebook.add_contact();
		else if (input == "SEARCH" || input == "search" || input == "s")
			phonebook.search_contact();
		else if (input == "EXIT" || input == "exit")
		{
			std::cout << "Quiting..." << std::endl;
			return (0);
		}
		else
		{
			std::cout << RED;
			std::cout << std::endl << "Command not found" << std::endl;
			std::cout << RESET;
		}
	}
	return (0);
}
