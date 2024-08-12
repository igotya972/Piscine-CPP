/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:54:24 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/11 02:54:24 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
	std::cout << "-START-" << std::endl;
	//randomChump("Foo");
	std::string name;

	std::cout << "Enter a name for the zombie: " << std::endl;
	std::getline(std::cin, name);
	std::string *zombie = new std::string(name);
	std::cout << zombie << " : BraiiiiiiinnnzzzZ" << std::endl;
	//zombie.annouce();
	// while (1)
	// {
		
	// 	delete newZombie;
	// }
	delete zombie;
	return (0);
}