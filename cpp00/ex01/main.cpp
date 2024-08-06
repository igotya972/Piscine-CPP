/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:25:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/06 17:20:30 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main (int ac, char **av)
{
	(void) ac;
	(void) av;
	//Phonebook phonebook;
	int			Ages;
	std::string Nickname;
	std::cout << "Enter your nickname: ";
	std::cin >> Nickname;
	//std::getline(std::cin, Nickname);
	std::cout << "pseudo: ";
	std::cout << Nickname << std::endl;
	std::cout << "Enter your age: ";
	std::cin >> Ages;
	while (1)
	{
		//std::cin.clear();
		if (std::cin.fail() || (Ages <= 0 || Ages >= 100))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input.  Try again: " << std::endl;
			//std::cout << std::endl;
			std::cout << "Enter your age: ";
			std::cin >> Ages;
		}
		else if (Ages > 0 && Ages < 100)
		{
			std::cout << "age: ";
			std::cout << Ages << std::endl;
			break;
		}
		// else
		// {
		// 	std::cout << "Invalid input.  Try again: " << std::endl;
		// 	std::cout << "Enter your age: ";
		// 	std::cin >> Ages;
		// 	//std::cout << "Invalid age";
		// }
	}
	return (0);
}